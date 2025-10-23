#ifndef TRANSICAO_H
#define TRANSICAO_H

#include <string>

// Declaração forward para evitar dependência circular
class Estado; 

/**
 * Representa uma estrada/aresta do grafo.
 */
class Transicao {
public:
    Estado* destino; // Ponteiro para o objeto Estado de destino
    int custo;       // Custo da estrada (distância em km)

    /**
     * Construtor da Transicao.
     * @param dest Ponteiro para o Estado de destino.
     * @param c O custo (distância).
     */
    Transicao(Estado* dest, int c);
};

#endif // TRANSICAO_HPP