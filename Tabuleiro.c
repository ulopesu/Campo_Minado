#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Tabuleiro.h"

// REALOCA ESPAÇO PARA A MATRIZ DO CAMPO COM O TAMANHO DADO POR X E Y.

char** rCampo(int x, int y) {
    char **camp;
    int i;
    camp = (char**) calloc(sizeof (char*), x);
    for (i = 0; i < x; i++) {
        camp[i] = (char*) calloc(sizeof (char), y);
    }
    return camp;
}

// CONTA E RETORNA A QUANDIDADE DE BOMBAS EM VOLTA DO PONTO DADO

char QuantBombas(tTabuleiro *pTab, int linha, int coluna) {
    int x = 0;
    char c, bomba;

    bomba = pTab->bomba;

    // 1 CANTO SUPERIOR ESQUERDO.
    if (linha == 0 && coluna == 0) {
        if (pTab->campo[0][1] == bomba) {
            x++;
        }
        if (pTab->campo[1][1] == bomba) {
            x++;
        }
        if (pTab->campo[0][1] == bomba) {
            x++;
        }
    }// 2 MEIO SUPERIOR.
    else if (linha == 0 && coluna != 0 && (coluna < (pTab->col - 1))) {
        if (pTab->campo[0][(coluna - 1)] == bomba) {
            x++;
        }
        if (pTab->campo[0][(coluna + 1)] == bomba) {
            x++;
        }
        if (pTab->campo[1][(coluna - 1)] == bomba) {
            x++;
        }
        if (pTab->campo[1][coluna] == bomba) {
            x++;
        }
        if (pTab->campo[1][(coluna + 1)] == bomba) {
            x++;
        }
    }// 3 CANTO SUPERIOR DIREITO.
    else if (linha == 0 && (coluna == (pTab->col - 1))) {
        if (pTab->campo[0][(coluna - 1)] == bomba) {
            x++;
        }
        if (pTab->campo[1][(coluna - 1)] == bomba) {
            x++;
        }
        if (pTab->campo[1][coluna] == bomba) {
            x++;
        }
    }// 4 MEIO DO LATERAL ESQUERDO.
    else if (linha != 0 && (linha < (pTab->lin - 1)) && coluna == 0) {
        if (pTab->campo[(linha - 1)][(coluna)] == bomba) {
            x++;
        }
        if (pTab->campo[(linha - 1)][(coluna + 1)] == bomba) {
            x++;
        }
        if (pTab->campo[linha][(coluna + 1)] == bomba) {
            x++;
        }
        if (pTab->campo[(linha + 1)][(coluna)] == bomba) {
            x++;
        }
        if (pTab->campo[(linha + 1)][(coluna + 1)] == bomba) {
            x++;
        }
    }// 5 MEIO DO LATERAL DIREITO
    else if (linha != 0 && (linha < (pTab->lin - 1)) &&
            (coluna == (pTab->col - 1))) {
        if (pTab->campo[(linha - 1)][(coluna)] == bomba) {
            x++;
        }
        if (pTab->campo[(linha - 1)][(coluna - 1)] == bomba) {
            x++;
        }
        if (pTab->campo[linha][(coluna - 1)] == bomba) {
            x++;
        }
        if (pTab->campo[(linha + 1)][(coluna)] == bomba) {
            x++;
        }
        if (pTab->campo[(linha + 1)][(coluna - 1)] == bomba) {
            x++;
        }
    }// 6 CANTO INFERIOR ESQUERDO.
    else if ((linha == (pTab->lin - 1)) && coluna == 0) {
        if (pTab->campo[linha - 1][coluna] == bomba) {
            x++;
        }
        if (pTab->campo[(linha - 1)][(coluna + 1)] == bomba) {
            x++;
        }
        if (pTab->campo[linha][coluna + 1] == bomba) {
            x++;
        }
    }// 7 MEIO INFERIOR
    else if ((linha == (pTab->lin - 1)) && coluna != 0 && coluna < pTab->col) {
        if (pTab->campo[(linha - 1)][(coluna)] == bomba) {
            x++;
        }
        if (pTab->campo[(linha - 1)][(coluna - 1)] == bomba) {
            x++;
        }
        if (pTab->campo[(linha - 1)][(coluna + 1)] == bomba) {
            x++;
        }
        if (pTab->campo[linha][(coluna + 1)] == bomba) {
            x++;
        }
        if (pTab->campo[linha][(coluna - 1)] == bomba) {
            x++;
        }
    }//8 CANTO INFERIOR DIREITO.
    else if ((linha == (pTab->lin - 1)) && (coluna == (pTab->col - 1))) {
        if (pTab->campo[linha - 1][coluna] == bomba) {
            x++;
        }
        if (pTab->campo[(linha - 1)][(coluna - 1)] == bomba) {
            x++;
        }
        if (pTab->campo[linha][coluna - 1] == bomba) {
            x++;
        }
    }// 9 MEIO.
    else {
        if (pTab->campo[linha - 1][coluna - 1] == bomba) {
            x++;
        }
        if (pTab->campo[linha - 1][coluna] == bomba) {
            x++;
        }
        if (pTab->campo[linha - 1][coluna + 1] == bomba) {
            x++;
        }
        if (pTab->campo[linha][coluna - 1] == bomba) {
            x++;
        }
        if (pTab->campo[linha][coluna + 1] == bomba) {
            x++;
        }
        if (pTab->campo[linha + 1][coluna - 1] == bomba) {
            x++;
        }
        if (pTab->campo[linha + 1][coluna] == bomba) {
            x++;
        }
        if (pTab->campo[linha + 1][coluna + 1] == bomba) {
            x++;
        }
    }
    c = '0' + x;
    if (c == '0') {
        c = pTab->vazia;
    }
    return c;
}

// PREPARA UMA MATRIZ PARA CAMPO BASE DO JOGO.

void PreencheCampo(tTabuleiro *pTab) {
    int i, j;
    char c;

    for (i = 0; i < pTab->lin; i++) {
        for (j = 0; j < pTab->col; j++) {
            if (pTab->campo[i][j] == '1') {
                pTab->campo[i][j] = pTab->bomba;
            } else {
                pTab->campo[i][j] = pTab->vazia;
            }
        }
    }

    for (i = 0; i < pTab->lin; i++) {
        for (j = 0; j < pTab->col; j++) {
            if (pTab->campo[i][j] != pTab->bomba) {
                pTab->campo[i][j] = QuantBombas(pTab, i, j);
            }
        }
    }
}

// CRIA O TABULEIRO A PARTIR DOS PARAMETROS DEFINIDOS NO 
// DOCUMENTO(tabuleiro.txt).

tTabuleiro CriaTabuleiro(char dir[100]) {
    tTabuleiro tab;
    int i = 0, j = 0;
    FILE* arqv_entrada;
    arqv_entrada = fopen(dir, "r+");

    if (arqv_entrada == NULL) {
        printf("Nao foi possivel ler o arquivo do diretorio informado pelo "
                "usuario.\nDiretorio: %s\n", dir);
        exit(0);
    }

    fscanf(arqv_entrada, "%c%c%c\n", &tab.fechada, &tab.bomba, &tab.vazia);
    fscanf(arqv_entrada, "%d %d\n", &tab.lin, &tab.col);

    //REALOCA ESPAÇO NA MEMORIA PARA O CAMPO.
    tab.campo = rCampo(tab.lin, tab.col);

    // SCAN MATRIX BASE!
    char aux;
    for (i = 0; i < tab.lin; i++) {
        for (j = 0; j < tab.col; j++) {
            fscanf(arqv_entrada, "%c", &aux);
            tab.campo[i][j] = aux;
        }
        fscanf(arqv_entrada, "\n");
    }

    // PREPARA UM CAMPO BASE PARA COMEÇAR O JOGO, DEFININDO AS 
    // POSSIÇÕES COM BOMBAS EM VOLTA.
    PreencheCampo(&tab);
    return tab;
}