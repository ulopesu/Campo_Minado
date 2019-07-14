#include <stdio.h>
#include <stdlib.h>
#include "Jogador.h"
#include "Jogo.h"

// CRIA UM JOGADOR A PARTIR DOS DADOS PASSADOS PELO USUARIO.

tJogador CriaJogador(void) {
    tJogador jog;

    printf("Digite o nome do jogador:\n");
    scanf("%[^\n]s", jog.nome);
    printf("Digitado (%s)\n", jog.nome);
    LimpaBuffer();
    return jog;
}

