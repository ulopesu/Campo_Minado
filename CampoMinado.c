#include <stdio.h>
#include "Jogo.h"
#include "Jogador.h"
#include "Tabuleiro.h"
#include "CampoMinado.h"

// IMPRIME PARA O USUARIO O CAMPO MINADO.

void ImprimeCampo(tCampoMinado CM, tJogo *pJogo) {
    int i, j, lin, col;
    char fechada;

    lin = pJogo->tabuleiro.lin;
    col = pJogo->tabuleiro.col;
    fechada = pJogo->tabuleiro.fechada;

    printf("    ");

    for (j = 0; j < col; j++) {
        printf("%03d ", j);
    }
    printf("\n");

    for (i = 0; i < lin; i++) {
        printf("%03d ", i);
        for (j = 0; j < col; j++) {
            if (CM.campo[i][j] == fechada) {
                printf("%c", CM.campo[i][j]);
                printf("%c", CM.campo[i][j]);
                printf("%c ", CM.campo[i][j]);
            } else {
                printf(" %c  ", CM.campo[i][j]);
            }
        }
        printf("\n");
    }
}

// FECHA TODAS AS POSIÇÕES DO CAMPO MINADO.

void LimpaCampo(tCampoMinado CM, tJogo *pJogo) {
    int i, j;
    char lin, col, fechada;

    lin = pJogo->tabuleiro.lin;
    col = pJogo->tabuleiro.col;
    fechada = pJogo->tabuleiro.fechada;

    for (i = 0; i < lin; i++) {
        for (j = 0; j < col; j++) {
            CM.campo[i][j] = fechada;
        }
    }
}
