#ifndef CAMPOMINADO_H
#define CAMPOMINADO_H

#ifdef __cplusplus
extern "C" {
#endif

    typedef struct {
        char **campo;
    } tCampoMinado;

#include "Jogo.h"

    // IMPRIME PARA O USUARIO O CAMPO MINADO.
    void ImprimeCampo(tCampoMinado CM, tJogo *pJogo);
    
    // FECHA TODAS AS POSIÇÕES DO CAMPO MINADO.
    void LimpaCampo(tCampoMinado CM, tJogo *pJogo);


#ifdef __cplusplus
}
#endif

#endif /* CAMPOMINADO_H */

