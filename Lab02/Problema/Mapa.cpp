#include "Mapa.h"
#include <iostream>
#include <algorithm> 
#include <stdexcept>



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