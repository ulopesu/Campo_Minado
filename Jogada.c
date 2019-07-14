#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Jogo.h"
#include "Jogador.h"
#include "Tabuleiro.h"
#include "Jogada.h"
#include "CampoMinado.h"

// VERIFICA SE O JOGADOR GANHOU.

int Vitoria(int x, int y, tCampoMinado *pCM, tJogo *pJogo) {
    int i, j, a = 0, b = 0, lin, col;
    char fechada, bomba;

    lin = pJogo->tabuleiro.lin;
    col = pJogo->tabuleiro.col;
    fechada = pJogo->tabuleiro.fechada;
    bomba = pJogo->tabuleiro.bomba;

    for (i = 0; i < lin; i++) {
        for (j = 0; j < col; j++) {
            if (pCM->campo[i][j] == fechada) {
                a++;
                if (pJogo->tabuleiro.campo[i][j] == bomba) {
                    b++;
                }
            }
        }
    }

    if (a == b) {
        return 1;
    } else {
        return 0;
    }
}

// REALIZA A VERIFICAÇÃO DE JOGADAS INVALIDAS COM PARAMETROS VOLTADOS PARA O 
// FLOOD FILL

int Invalida(int x, int y, tJogo *pJogo) {
    if ((x >= 0 && x < pJogo->tabuleiro.lin) && (y >= 0 && y < pJogo->tabuleiro.col)) {
        return 0;
    } else {
        return 1;
    }
}

// REALIZA AS JOGADAS QUE ENVOLVEM POSIÇOES VAZIAS.

int FloodFill(int x, int y, tCampoMinado *CM, tJogo *pJogo) {
    int ff = 0, a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, h = 0;
    char bomba, vazia, fechada, pos;
    bomba = pJogo->tabuleiro.bomba;
    vazia = pJogo->tabuleiro.vazia;
    fechada = pJogo->tabuleiro.fechada;

    if (Invalida(x, y, pJogo)) {
        return 0;
    }

    pos = pJogo->tabuleiro.campo[x][y];

    if (CM->campo[x][y] != fechada || pos == bomba) {
        return 0;
    } else if (pos != vazia) {
        CM->campo[x][y] = pos;
        ff++;
        return ff;
    } else {
        CM->campo[x][y] = pos;
        ff++;
    }

    if (Invalida(x, y + 1, pJogo) == 0) {
        a = FloodFill(x, (y + 1), CM, pJogo);
    }
    if (Invalida(x + 1, y, pJogo) == 0) {
        b = FloodFill((x + 1), y, CM, pJogo);
    }
    if (Invalida(x, y - 1, pJogo) == 0) {
        c = FloodFill(x, (y - 1), CM, pJogo);
    }
    if (Invalida(x - 1, y, pJogo) == 0) {
        d = FloodFill((x - 1), y, CM, pJogo);
    }
    if (Invalida((x + 1), (y + 1), pJogo) == 0) {
        e = FloodFill((x + 1), (y + 1), CM, pJogo);
    }
    if (Invalida((x - 1), (y - 1), pJogo) == 0) {
        f = FloodFill((x - 1), (y - 1), CM, pJogo);
    }
    if (Invalida((x - 1), (y + 1), pJogo) == 0) {
        g = FloodFill((x - 1), (y + 1), CM, pJogo);
    }
    if (Invalida((x + 1), (y - 1), pJogo) == 0) {
        h = FloodFill((x + 1), (y - 1), CM, pJogo);
    }

    ff = ff + a + b + c + d + e + f + g + h;
    return ff;
}


// VERIFICA SE O JOGADOR GANHOU E ALTERA O CAMPO MINADO.

int VerificaJogada(tJogada *jogada, tCampoMinado *CM, tJogo *pJogo) {
    int lin, col, v;
    char bomba, vazia;
    lin = jogada->posx;
    col = jogada->posy;

    bomba = pJogo->tabuleiro.bomba;
    vazia = pJogo->tabuleiro.vazia;
    jogada->impacto = 0;

    if (pJogo->tabuleiro.campo[lin][col] == bomba) {
        CM->campo[lin][col] = bomba;
        jogada->impacto = 0;
        v = 2;
        return v;
    } else if (pJogo->tabuleiro.campo[lin][col] == vazia) {
        jogada->impacto = FloodFill(jogada->posx, jogada->posy, CM, pJogo);
    } else {
        CM->campo[lin][col] = pJogo->tabuleiro.campo[lin][col];
        jogada->impacto = 1;
    }

    v = Vitoria(lin, col, CM, pJogo);

    return v;
}

// VERIFICA SE A JOGADA É VALIDA;

int JogadaValida(tCampoMinado CM, tJogada jog, tJogo *pJogo) {
    if ((jog.posx >= 0 && jog.posx < pJogo->tabuleiro.lin) &&
            (jog.posy >= 0 && jog.posy < pJogo->tabuleiro.col)) {
        if (CM.campo[jog.posx][jog.posy] == pJogo->tabuleiro.fechada) {
            return 1;
        } else {
            printf("Posicao invalida (JA ABERTA)!\n");
            return 0;
        }
    } else {
        printf("Posicao invalida (FORA DO TABULEIRO)!\n");
        return 0;
    }
}