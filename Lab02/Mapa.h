// Mapa.h

#ifndef MAPA_H
#define MAPA_H

#include <string>
#include <map>
#include <utility>
#include "Estado.h" 

class Mapa {
private:
    std::map<std::string, Estado*> estados;

public:
    void adicionarEstado(Estado* estado) {
        if (estado) {
            estados[estado->nome] = estado; 
        }
    }

    Estado* getEstado(const std::string& nome) {
        if (estados.count(nome)) {
            return estados.at(nome);
        }
        return nullptr;
    }

  
    ~Mapa() {
        for (auto it = estados.begin(); it != estados.end(); ++it) {
            delete it->second;
        }
    }
    
    // Imprime o mapa para visualização
    void imprimirMapa() const {
        std::cout << "\n=== Mapa Rodoviário da Romênia ===" << std::endl;
        for (const auto& par : estados) {
            par.second->imprimir();
        }
        std::cout << "===================================" << std::endl;
    }
};

#endif // MAPA_H