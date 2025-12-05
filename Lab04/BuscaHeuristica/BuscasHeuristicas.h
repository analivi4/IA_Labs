// BuscaHeuristica/BuscasHeuristicas.h

#ifndef BUSCAS_HEURISTICAS_H
#define BUSCAS_HEURISTICAS_H

#include <iostream>
#include <vector>
#include <string>
#include <queue> 
#include <unordered_set>
#include <unordered_map>
#include <chrono>
#include <algorithm>

#include "No.h"     
#include "Problema/Mapa.h"


using namespace std;

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


const unordered_map<string, int> H = {
    {"Arad", 366}, {"Bucharest", 0}, {"Craiova", 160}, {"Drobeta", 242}, {"Eforie", 161},
    {"Fagaras", 176}, {"Giurgiu", 77}, {"Hirsova", 151}, {"Iasi", 226}, {"Lugoj", 244},
    {"Mehadia", 241}, {"Neamt", 234}, {"Oradea", 380}, {"Pitesti", 100}, {"RimnicuVilcea", 193},
    {"Sibiu", 253}, {"Timisoara", 329}, {"Urziceni", 80}, {"Vaslui", 199}, {"Zerind", 374}
};

// Comparador para a Busca Gulosa (f(n) = h(n))
struct GulosaCompare {
    bool operator()(const No* a, const No* b) const {
        int h_a = H.at(a->estado);
        int h_b = H.at(b->estado);
        return h_a > h_b; 
    }
};

// Comparador para a Busca A* (f(n) = g(n) + h(n))
struct AStarCompare {
    bool operator()(const No* a, const No* b) const {
        int f_a = a->custoCaminho + H.at(a->estado);
        int f_b = b->custoCaminho + H.at(b->estado);
        return f_a > f_b; 
    }
};


ResultadoBusca buscaGulosa(Mapa& problema, const string& estadoInicial, const string& estadoObjetivo);

ResultadoBusca buscaAStar(Mapa& problema, const string& estadoInicial, const string& estadoObjetivo);

#endif // BUSCAS_HEURISTICAS_H