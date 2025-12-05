// No.h

#ifndef NO_H
#define NO_H

#include "Problema/Estado.h" 
#include <string>
#include <vector>

class No {
public:
    std::string estado; 
    
    No* pai; 
    
    std::string acao;
    
    int custoCaminho; 

    No(const std::string& estadoInicial) : 
        estado(estadoInicial), 
        pai(nullptr), 
        acao("Nenhuma"), 
        custoCaminho(0) {}

    No(const std::string& estadoAtual, No* noPai, const std::string& acaoAplicada, int custoAcumulado) :
        estado(estadoAtual), 
        pai(noPai), 
        acao(acaoAplicada), 
        custoCaminho(custoAcumulado) {}
};

#endif // NO_H