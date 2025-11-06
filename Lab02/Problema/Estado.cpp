#include "Estado.h"
#include <iostream>
#include <algorithm>

Estado::Estado(const std::string& n) 
    : nome(n) {}

void Estado::adicionar_transicao(const Transicao& t) {
    transicoes.push_back(t);
}

// Implementação da sobrecarga para impressão
std::ostream& operator<<(std::ostream& os, const Estado& estado) {
    os << "Estado: " << estado.nome;
    if (!estado.transicoes.empty()) {
        os << " -> Conexões: [";
        for (size_t i = 0; i < estado.transicoes.size(); ++i) {
            os << estado.transicoes[i].destino->nome << " (" << estado.transicoes[i].custo << " km)";
            if (i < estado.transicoes.size() - 1) {
                os << ", ";
            }
        }
        os << "]";
    } else {
        os << " (Sem Conexões)";
    }
    return os;
}