#ifndef NO_H
#define NO_H

#include "Estado.h" 
#include <vector>
#include <string>
#include <memory> 

class No {
public:
    Estado* estado;        
    No* pai;          
    std::string acao;       
    int custoDeCaminho;  


    No(Estado* s);

    No(Estado* s, No* p, const std::string& a, int c);

    std::vector<std::string> get_caminho() const;

    std::vector<std::string> get_acoes() const;
};

#endif