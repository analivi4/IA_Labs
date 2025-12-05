// Busca/Buscas.h

#ifndef BUSCAS_H
#define BUSCAS_H

#include <iostream>
#include <vector>
#include <string>
#include <queue> 
#include <stack> 
#include <unordered_set>
#include <unordered_map>
#include <chrono>
#include <algorithm>

#include "No.h"
#include "Problema/Mapa.h" 

using namespace std;

// Estrutura para o resultado
struct ResultadoBusca {
    bool sucesso = false;
    int custoTotal = -1;
    vector<string> sequenciaAcoes;
    long long tempoExecucaoUs = 0;
};

inline vector<string> reconstruirCaminho(No* noFinal) {
    vector<string> caminho;
    No* atual = noFinal;

    while (atual != nullptr) {
        if (atual->pai != nullptr) {
            caminho.push_back("IrPara " + atual->estado);
        } else {
            caminho.push_back("Início em " + atual->estado);
        }
        atual = atual->pai;
    }
    
    reverse(caminho.begin(), caminho.end());
    return caminho;
}

struct NoCompare {
    bool operator()(const No* a, const No* b) const {
        return a->custoCaminho > b->custoCaminho; 
    }
};

// 1. Busca em Largura (BFS)
ResultadoBusca buscaEmLargura(Mapa& problema, const string& estadoInicial, const string& estadoObjetivo);

// 2. Busca de Custo Uniforme (UCS)
ResultadoBusca buscaDeCustoUniforme(Mapa& problema, const string& estadoInicial, const string& estadoObjetivo);

// 3. Busca em Profundidade (DFS)
ResultadoBusca buscaEmProfundidade(Mapa& problema, const string& estadoInicial, const string& estadoObjetivo);


#endif // BUSCAS_H