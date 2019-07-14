#ifndef TABULEIRO_H
#define TABULEIRO_H

#ifdef __cplusplus
extern "C" {
#endif

    // DEFINIR STRUCT

    typedef struct {
        char fechada; // POSIÇAO FECHADA
        char bomba; // BOMBA
        char vazia; // POSIÇÃO ABERTA E VAZIA
        char **campo; // CAMPO DO TABULEIRO
        int lin; // QUANTIDADE DE LINHAS DO CAMPO       
        int col; // QUANTIDADE DE COLUNAS DO CAMPO
    } tTabuleiro;

    
    // REALOCA ESPAÇO PARA A MATRIZ DO CAMPO COM O TAMANHO DADO POR X E Y.
    char** rCampo(int x, int y);
    
    // CONTA E RETORNA A QUANDIDADE DE BOMBAS EM VOLTA DO PONTO DADO.
    char QuantBombas(tTabuleiro* pTab, int linha, int coluna);
    
    // PREPARA UMA MATRIZ PARA CAMPO BASE DO JOGO.
    void PreencheCampo(tTabuleiro* pTab);
    
    // CRIA O TABULEIRO A PARTIR DOS PARAMETROS DEFINIDOS NO 
    // DOCUMENTO(tabuleiro.txt).
    tTabuleiro CriaTabuleiro(char dir[100]);


#ifdef __cplusplus
}
#endif

#endif /* TABULEIRO_H */

