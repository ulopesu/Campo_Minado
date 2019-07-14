#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Jogo.h"
#include "Jogador.h"
#include "Tabuleiro.h"
#include "Jogada.h"
#include "CampoMinado.h"

// LIMPA O BUFFER MESMO A ENTRADA SENDO PADRAO OU A PARTIR DE ARQUIVOS.

void LimpaBuffer(void) {
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// IMPRIME O RESULTADO FINAL DO JOGO.

void ImprimeResultado(int i, tJogo *pJogo) {
    if (i == 1) {
        printf("%s Venceu!\n", pJogo->jogador.nome);
    } else if (i == 2) {
        printf("%s Perdeu!\n", pJogo->jogador.nome);
    } else {
        printf("OCORREU UM ERRO NA IMPRESSÃO DO RESULTADO\n");
    }
}

// VERIFICA SE O JOGADOR DESEJA JOGAR NOVAMENTE.

char JogarNovamente(void) {
    char op = 'o';
    printf("Jogar novamente? (s,n)\n");
    while (op != 's' && op != 'n' && op != 'S' && op != 'N') {
        scanf("%c^\n", &op);
        LimpaBuffer();
        printf("Digitado (%c)\n", op);
        if (op != 's' && op != 'n' && op != 'S' && op != 'N') {
            printf("Opcao Invalida, digite novamente:\n");
        }
    }
    return op;
}

// ORDENA O VETOR DE JOGADAS DE ACORDO COM O IMPACTO PARA CRIAR O ARQUIVO DE 
// ANALISE.

void AnalisedoJogo(int i, tJogada *jogadas, tJogo *pJogo) {
    int k, j, cont;
    tJogada aux;
    for (k = 0; k != j; k++) {
        j = -1;
        for (cont = 0; cont < i; cont++) {
            if (jogadas[cont].impacto < jogadas[cont + 1].impacto) {
                aux = jogadas[cont];
                jogadas[cont] = jogadas[cont + 1];
                jogadas[cont + 1] = aux;
            }
            if (cont == (i - 1)) {
                cont++;
            }
        }
        for (cont = 0; cont < i; cont++) {
            if (jogadas[cont].impacto < jogadas[cont + 1].impacto) {
                j--;
            }
        }
        if (j == -1) {
            j = k + 1;
        }
    }
}

// GERAR OS ARQUIVOS DE ANALISE DE CADA PARTIDA DO JOGO.

void GerarAnalise(tJogada *jogadas, int partida, int i) {
    int k;
    char vet[80];
    sprintf(vet, "analiseJogo%02d.txt", partida);

    FILE *AnaliseJogo = fopen(vet, "w");

    for (k = 0; k < i; k++) {
        fprintf(AnaliseJogo, "JOGADA %d:(%d,%d) %d\n", jogadas[k].rodada,
                jogadas[k].posy, jogadas[k].posx, jogadas[k].impacto);
    }
    fclose(AnaliseJogo);
}

// INICIA UMA PARTIDA DO JOGO.

int IniciaJogo(tJogo *pJogo) {
    int i, j = 0, jv = 0, v;
    tJogada jogadas[100];
    tCampoMinado CM;

    CM.campo = rCampo(pJogo->tabuleiro.lin, pJogo->tabuleiro.col);

    LimpaCampo(CM, pJogo);
    ImprimeCampo(CM, pJogo);

    for (i = 0; i != -1; i++) {
        j++;
        jogadas[i].rodada = j;
        for (jv = 0; jv == 0;) {
            printf("%s Jogada: %d", pJogo->jogador.nome, jogadas[i].rodada);
            printf("\nDigite a posicao (x e y):\n");

            if (scanf("%d %d", &jogadas[i].posy, &jogadas[i].posx) != 2) {
                printf("VOCE DIGITOU UM CARACTER NAO ESPERADO!\n");
                LimpaBuffer();
            } else {
                LimpaBuffer();
                printf("Digitado (%d,%d)\n", jogadas[i].posy, jogadas[i].posx);

                if (JogadaValida(CM, jogadas[i], pJogo)) {
                    jv++;
                } else {
                    jv = 0;
                }
            }
        }
        v = VerificaJogada(&jogadas[i], &CM, pJogo);

        ImprimeCampo(CM, pJogo);

        if (v == 1 || v == 2) {
            i = -2;
        }
    }

    AnalisedoJogo(j - 1, jogadas, pJogo);
    GerarAnalise(jogadas, pJogo->partida, j);

    return v;
}

// CRIA O JOGO.

tJogo CriaJogo(char dir []) {
    tJogo jogo;
    jogo.tabuleiro = CriaTabuleiro(dir);
    jogo.jogador = CriaJogador();
    return jogo;
}
