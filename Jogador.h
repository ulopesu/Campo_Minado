#ifndef JOGADOR_H
#define JOGADOR_H

#ifdef __cplusplus
extern "C" {
#endif

    typedef struct {
        char nome[1000];
    } tJogador;
    

    // CRIA UM JOGADOR A PARTIR DOS DADOS PASSADOS PELO USUARIO.
    tJogador CriaJogador(void);

    
#ifdef __cplusplus
}
#endif

#endif /* JOGADOR_H */

