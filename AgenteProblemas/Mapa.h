#ifndef MAPA_HPP
#define MAPA_HPP

#include <string>
#include <map>
#include <memory>
#include "Estado.h"

/**
 * Classe Mapa: Representa o conjunto de estados e a topologia do grafo.
 */
class Mapa {
public:

    std::map<std::string, std::unique_ptr<Estado>> conjunto_estados; 

    Mapa() = default;
    ~Mapa() = default;

    Estado* adicionar_estado(const std::string& nome_cidade);

    /**
     * Conecta duas cidades com transições bidirecionais (grafo não-direcionado),
     * garantindo que não haja duplicação de transições.
     */
    void conectar_estados(const std::string& cidade_a, const std::string& cidade_b, int distancia);

    Estado* get_estado(const std::string& nome_cidade) const;
   
    friend std::ostream& operator<<(std::ostream& os, const Mapa& mapa);
};

#endif // MAPA_HPP