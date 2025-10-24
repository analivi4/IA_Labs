#ifndef BUSCA_L_H
#define BUSCA_L_H

#include "Mapa.h" 
#include "No.h" 
#include "Estado.h" 


No* BUSCA_EM_LARGURA(
    const Mapa& mapa, 
    Estado* estado_inicial, 
    Estado* estado_objetivo
);

#endif // BUSCA_L_H