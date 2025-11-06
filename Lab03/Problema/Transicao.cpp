#include "Transicao.h"
#include "Estado.h" // Precisa da definição de Estado aqui

Transicao::Transicao(Estado* dest, int c) 
    : destino(dest), custo(c) {}

// A implementação é simples, apenas o construtor.