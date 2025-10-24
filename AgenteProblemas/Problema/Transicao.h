#ifndef TRANSICAO_H
#define TRANSICAO_H

#include <string>

class Estado; 


class Transicao {
public:
    Estado* destino; // Ponteiro para o objeto Estado de destino
    int custo;       // Custo da estrada (distância em km)

    Transicao(Estado* dest, int c);
};

#endif // TRANSICAO_HPP