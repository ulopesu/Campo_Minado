#ifndef JOGADA_H
#define JOGADA_H

#ifdef __cplusplus
extern "C" {
#endif

    typedef struct{
        int impacto;
        int rodada;
        int posx;
        int posy;
    }tJogada;

#include "CampoMinado.h"    
#include"Jogo.h"
#include"Tabuleiro.h"
    
    // VERIFICA SE O JOGADOR GANHOU.
    int Vitoria(int x, int y, tCampoMinado* pCM, tJogo* pJogo);
    
    // REALIZA A VERIFICAÇÃO DE JOGADAS INVALIDAS COM PARAMETROS VOLTADOS PARA O 
    // FLOOD FILL
    int Invalida(int x, int y, tJogo *pJogo);
    
    // REALIZA AS JOGADAS QUE ENVOLVEM POSIÇOES VAZIAS.
    int FloodFill(int x, int y, tCampoMinado *CM, tJogo *pJogo);
    
    // VERIFICA SE O JOGADOR GANHOU E ALTERA O CAMPO MINADO.
    int VerificaJogada(tJogada *jogada, tCampoMinado* CM, tJogo* pJogo);
    
    // VERIFICA SE A JOGADA É VALIDA;
    int JogadaValida(tCampoMinado CM, tJogada jog, tJogo* pJogo);

    
#ifdef __cplusplus
}
#endif

#endif /* JOGADA_H */

