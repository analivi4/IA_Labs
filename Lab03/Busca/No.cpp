#include "No.h"
#include <algorithm>


No::No(Estado *s) 
    : estado(s), pai(nullptr), acao(""), custoDeCaminho(0) {} 

No::No(Estado *s, No* p, const std::string& a, int c) 
    : estado(s), pai(p), acao(a), custoDeCaminho(c) {}

std::vector<std::string> No::get_caminho() const {
    std::vector<std::string> caminho;

    const No* atual = this;

    while (atual != nullptr) {
        caminho.push_back(atual->estado->nome);
        atual = atual->pai;
    }
    // O caminho foi construído do fim para o início, então invertemos.
    std::reverse(caminho.begin(), caminho.end());
    return caminho;
}

std::vector<std::string> No::get_acoes() const {
    std::vector<std::string> acoes;

    const No* atual = this;
    
    // Começamos do pai, pois o nó inicial não tem ação.
    while (atual->pai != nullptr) {
        acoes.push_back(atual->acao);
        atual = atual->pai;
    }
    // As ações foram construídas do fim para o início, então invertemos.
    std::reverse(acoes.begin(), acoes.end());
    return acoes;
}