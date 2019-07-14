#ifndef JOGO_H
#define JOGO_H

#include "Jogador.h" 
#include "Tabuleiro.h"

typedef struct {
    tJogador jogador;
    tTabuleiro tabuleiro;
    int partida;
} tJogo;

#include "Jogada.h"


// LIMPA O BUFFER MESMO A ENTRADA SENDO PADRAO OU A PARTIR DE ARQUIVOS.
void LimpaBuffer(void);

// IMPRIME O RESULTADO FINAL DO JOGO.
void ImprimeResultado(int i, tJogo *pJogo);

// VERIFICA SE O JOGADOR DESEJA JOGAR NOVAMENTE.
char JogarNovamente(void);

// ORDENA O VETOR DE JOGADAS DE ACORDO COM O IMPACTO PARA CRIAR O ARQUIVO DE 
// ANALISE.
void AnalisedoJogo(int i, tJogada *jogadas, tJogo *pJogo);

// GERAR OS ARQUIVOS DE ANALISE DE CADA PARTIDA DO JOGO.
void GerarAnalise(tJogada *jogadas, int partida, int i);

// INICIA UMA PARTIDA DO JOGO.
int IniciaJogo(tJogo *pJogo);

// CRIA O JOGO.
tJogo CriaJogo(char dir []);


#endif /* JOGO_H */

