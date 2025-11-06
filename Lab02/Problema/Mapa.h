#ifndef MAPA_HPP
#define MAPA_HPP

#include <string>
#include <map>
#include <memory>
#include "Estado.h"


class Mapa {
public:

    std::map<std::string, std::unique_ptr<Estado>> conjunto_estados; 

    Mapa() = default;
    ~Mapa() = default;

    Estado* adicionar_estado(const std::string& nome_cidade);

    Estado* get_estado(const std::string& nome_cidade) const;
   
    friend std::ostream& operator<<(std::ostream& os, const Mapa& mapa);
};

#endif // MAPA_HPP