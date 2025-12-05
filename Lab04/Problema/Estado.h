// Estado.h

#ifndef ESTADO_H
#define ESTADO_H

#include <string>
#include <vector>
#include <iostream>
#include "Transicao.h"

class Estado {
public:
    std::string nome;
    std::vector<Transicao> transicoes;

    Estado(const std::string& n) : nome(n) {}

    void adicionarTransicao(Estado* destino, int custo) {
        transicoes.emplace_back(destino, custo);
    }

    void imprimir() const {
        std::cout << "Estado: " << nome << " -> ";
        for (const auto& t : transicoes) {
            std::cout << "[" << t.destinoPtr->nome << " (" << t.custo << ")] ";
        }
        std::cout << std::endl;
    }
};

#endif // ESTADO_H