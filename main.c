#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Jogo.h"
#include "Jogador.h"
#include "Tabuleiro.h"

int main(int argc, char** argv) {
    int result, partida = 0;
    char opcao = 's';
    tJogo jogo;
    tTabuleiro tabuleiro;
    tJogador jogador;


    if (argc < 2) {
        printf("ERRO: O diretorio de arquivos de configuracao nao foi "
                "informado!");
        return 1;
    }
    while (opcao == 's' || opcao == 'S') {
        partida++;
        char dir[100];
        strcpy(dir, argv[1]);
        strcat(dir, "/tabuleiro.txt");
        jogo = CriaJogo(dir);
        jogo.partida = partida;
        result = IniciaJogo(&jogo);
        ImprimeResultado(result, &jogo);
        opcao = JogarNovamente();
    }
    return 0;
}

