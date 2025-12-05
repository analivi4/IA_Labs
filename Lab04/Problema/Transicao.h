// Transicao.h

#ifndef TRANSICAO_H
#define TRANSICAO_H

#include <string>

class Estado;

class Transicao {
public:
    Estado* destinoPtr; 
    int custo;

    // Construtor
    Transicao(Estado* dest, int c) : destinoPtr(dest), custo(c) {}
};

#endif // TRANSICAO_H