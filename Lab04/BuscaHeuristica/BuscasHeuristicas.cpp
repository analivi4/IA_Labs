// BuscaHeuristica/BuscasHeuristicas.cpp

#include "BuscasHeuristicas.h"
#include "No.h"
#include "Problema/Mapa.h"

ResultadoBusca buscaGulosa(Mapa& problema, const string& estadoInicial, const string& estadoObjetivo) {
    auto inicioTempo = chrono::high_resolution_clock::now();
    
    No* noInicial = new No(estadoInicial);
    
    priority_queue<No*, vector<No*>, GulosaCompare> borda;
    borda.push(noInicial);

    unordered_set<string> explorados;

    while (!borda.empty()) {
        
        No* noAtual = borda.top();
        borda.pop();

        if (explorados.count(noAtual->estado)) {
            delete noAtual;
            continue;
        }

        if (noAtual->estado == estadoObjetivo) {
            auto fimTempo = chrono::high_resolution_clock::now();
            
            ResultadoBusca resultado;
            resultado.sucesso = true;
            resultado.custoTotal = noAtual->custoCaminho;
            resultado.sequenciaAcoes = reconstruirCaminho(noAtual);
            resultado.tempoExecucaoUs = chrono::duration_cast<chrono::microseconds>(fimTempo - inicioTempo).count();
            
            return resultado;
        }

        explorados.insert(noAtual->estado);

        Estado* estadoAtual = problema.getEstado(noAtual->estado);
        if (!estadoAtual) continue; 

        for (const auto& transicao : estadoAtual->transicoes) {

                
        
            string estadoFilho = transicao.destinoPtr->nome;   
            string acaoAplicada = "IrPara " + estadoFilho;
            int novoCustoCaminho = noAtual->custoCaminho + transicao.custo; 


            No* filho = new No(estadoFilho, noAtual, acaoAplicada, novoCustoCaminho);
            
            borda.push(filho);

        }
    }

    auto fimTempo = chrono::high_resolution_clock::now();
    ResultadoBusca resultado;
    resultado.sucesso = false;
    resultado.tempoExecucaoUs = chrono::duration_cast<chrono::microseconds>(fimTempo - inicioTempo).count();
    return resultado;
}

ResultadoBusca buscaAStar(Mapa& problema, const string& estadoInicial, const string& estadoObjetivo) {
    auto inicioTempo = chrono::high_resolution_clock::now();
    
    No* noInicial = new No(estadoInicial);
    
    priority_queue<No*, vector<No*>, AStarCompare> borda;
    borda.push(noInicial);

    unordered_map<string, int> custoMinimoEncontrado;
    custoMinimoEncontrado[noInicial->estado] = noInicial->custoCaminho;

    unordered_set<string> explorados;

    while (!borda.empty()) {
        
        No* noAtual = borda.top();
        borda.pop();

        if (noAtual->custoCaminho > custoMinimoEncontrado[noAtual->estado]) {
            delete noAtual;
            continue;
        }

        if (noAtual->estado == estadoObjetivo) {
            auto fimTempo = chrono::high_resolution_clock::now();
            
            ResultadoBusca resultado;
            resultado.sucesso = true;
            resultado.custoTotal = noAtual->custoCaminho;
            resultado.sequenciaAcoes = reconstruirCaminho(noAtual);
            resultado.tempoExecucaoUs = chrono::duration_cast<chrono::microseconds>(fimTempo - inicioTempo).count();
            
            return resultado;
        }

        explorados.insert(noAtual->estado);

        Estado* estadoAtual = problema.getEstado(noAtual->estado);
        if (!estadoAtual) continue; 

        for (const auto& transicao : estadoAtual->transicoes) {
            
            string estadoFilho = transicao.destinoPtr->nome; 
            string acaoAplicada = "IrPara " + estadoFilho;
            int novoCustoCaminho = noAtual->custoCaminho + transicao.custo; 

            if (explorados.count(estadoFilho)) {
                // Se já explorado, ignorar (pois o UCS garante que o explorado é o melhor)
                continue;
            }
            
            No* filho = new No(estadoFilho, noAtual, acaoAplicada, novoCustoCaminho);
            
            if (custoMinimoEncontrado.find(estadoFilho) == custoMinimoEncontrado.end()) {
                
                borda.push(filho);
                custoMinimoEncontrado[estadoFilho] = novoCustoCaminho;
                
            } 
            else if (novoCustoCaminho < custoMinimoEncontrado[estadoFilho]) {
                
                custoMinimoEncontrado[estadoFilho] = novoCustoCaminho;
                
                borda.push(filho); 
            } else {
                // Caminho encontrado é igual ou pior que o existente, deletar o nó recém-criado
                delete filho;
            }
        }
    }

    auto fimTempo = chrono::high_resolution_clock::now();
    ResultadoBusca resultado;
    resultado.sucesso = false;
    resultado.tempoExecucaoUs = chrono::duration_cast<chrono::microseconds>(fimTempo - inicioTempo).count();
    return resultado;
}