#ifndef ESTADO_H
#define ESTADO_H

#include <string>
#include <vector>
#include "Transicao.h" 

/**
 * Representa uma cidade/estado no mapa.
 */

class Estado {
public:
    std::string nome;
    std::vector<Transicao> transicoes; 


    Estado(const std::string& n);

    void adicionar_transicao(const Transicao& t);

    friend std::ostream& operator<<(std::ostream& os, const Estado& estado);
};

#endif // ESTADO_H