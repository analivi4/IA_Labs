#include "Mapa.h"
#include <iostream>
#include <algorithm> 
#include <stdexcept>

// Função auxiliar para verificar se a transição A -> B já existe
bool transicao_existe(Estado* origem, Estado* destino) {
    return std::find_if(origem->transicoes.begin(), origem->transicoes.end(),
                        [&](const Transicao& t) { return t.destino == destino; }) 
           != origem->transicoes.end();
}



Estado* Mapa::adicionar_estado(const std::string& nome_cidade) {
    if (conjunto_estados.find(nome_cidade) == conjunto_estados.end()) {
        conjunto_estados[nome_cidade] = std::make_unique<Estado>(nome_cidade);
    }
    return conjunto_estados[nome_cidade].get(); 
}

void Mapa::conectar_estados(const std::string& cidade_a, const std::string& cidade_b, int distancia) {
    Estado* estado_a = adicionar_estado(cidade_a);
    Estado* estado_b = adicionar_estado(cidade_b);

    if (estado_a == estado_b) {
        std::cerr << "AVISO: Cidades de origem e destino são as mesmas (" << cidade_a << "). Conexão ignorada.\n";
        return;
    }
    
     if (!transicao_existe(estado_a, estado_b)) {
        estado_a->adicionar_transicao(Transicao(estado_b, distancia));
        estado_b->adicionar_transicao(Transicao(estado_a, distancia));
    }

}

Estado* Mapa::get_estado(const std::string& nome_cidade) const {
    auto it = conjunto_estados.find(nome_cidade);
    if (it != conjunto_estados.end()) {
        return it->second.get();
    }
    return nullptr;
}

std::ostream& operator<<(std::ostream& os, const Mapa& mapa) {
    os << "======================================\n";
    os << "Mapa Rodoviário da Romênia (Grafo):\n";
    os << "Total de Estados: " << mapa.conjunto_estados.size() << "\n";
    os << "======================================\n";
    for (const auto& pair : mapa.conjunto_estados) {
        os << *pair.second << "\n"; 
    }
    os << "======================================\n";
    return os;
}