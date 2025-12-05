// mainTabela.cpp

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <utility>

#include "Problema/Mapa.h" 
#include "Busca/Buscas.h"


struct ProblemaBusca {
    std::string origem;
    std::string destino;
};

void CriarMapaRomenia(Mapa& mapa_romenia) {
    
    // 1. CRIAÇÃO DOS OBJETOS ESTADO
    Estado* arad = new Estado("Arad");
    Estado* zerind = new Estado("Zerind");
    Estado* oradea = new Estado("Oradea");
    Estado* sibiu = new Estado("Sibiu");
    Estado* timisoara = new Estado("Timisoara");
    Estado* lugoj = new Estado("Lugoj");
    Estado* mehadia = new Estado("Mehadia");
    Estado* drobeta = new Estado("Drobeta");
    Estado* craiova = new Estado("Craiova");
    Estado* rimnicuVilcea = new Estado("RimnicuVilcea");
    Estado* fagaras = new Estado("Fagaras");
    Estado* pitesti = new Estado("Pitesti");
    Estado* bucharest = new Estado("Bucharest");
    Estado* giurgiu = new Estado("Giurgiu");
    Estado* urziceni = new Estado("Urziceni");
    Estado* hirsova = new Estado("Hirsova");
    Estado* eforie = new Estado("Eforie");
    Estado* vaslui = new Estado("Vaslui");
    Estado* iasi = new Estado("Iasi");
    Estado* neamt = new Estado("Neamt");
    
    // 2. ADIÇÃO DAS TRANSIÇÕES NOS OBJETOS ESTADO 
    // Arad
    arad->adicionarTransicao(zerind, 75);      
    arad->adicionarTransicao(timisoara, 118);
    arad->adicionarTransicao(sibiu, 140);
    // Zerind
    zerind->adicionarTransicao(arad, 75);
    zerind->adicionarTransicao(oradea, 71);
    // Oradea
    oradea->adicionarTransicao(zerind, 71);
    oradea->adicionarTransicao(sibiu, 151);
    // Sibiu
    sibiu->adicionarTransicao(arad, 140);
    sibiu->adicionarTransicao(oradea, 151);
    sibiu->adicionarTransicao(fagaras, 99);
    sibiu->adicionarTransicao(rimnicuVilcea, 80);
    // Timisoara
    timisoara->adicionarTransicao(arad, 118);
    timisoara->adicionarTransicao(lugoj, 111);
    // Lugoj
    lugoj->adicionarTransicao(timisoara, 111);
    lugoj->adicionarTransicao(mehadia, 70);
    // Mehadia
    mehadia->adicionarTransicao(lugoj, 70);
    mehadia->adicionarTransicao(drobeta, 75);
    // Drobeta
    drobeta->adicionarTransicao(mehadia, 75);
    drobeta->adicionarTransicao(craiova, 120);
    // Craiova
    craiova->adicionarTransicao(drobeta, 120);
    craiova->adicionarTransicao(rimnicuVilcea, 146);
    craiova->adicionarTransicao(pitesti, 138);
    // RimnicuVilcea
    rimnicuVilcea->adicionarTransicao(sibiu, 80);
    rimnicuVilcea->adicionarTransicao(craiova, 146);
    rimnicuVilcea->adicionarTransicao(pitesti, 97);
    // Fagaras
    fagaras->adicionarTransicao(sibiu, 99);
    fagaras->adicionarTransicao(bucharest, 211);
    // Pitesti
    pitesti->adicionarTransicao(rimnicuVilcea, 97);
    pitesti->adicionarTransicao(craiova, 138);
    pitesti->adicionarTransicao(bucharest, 101);
    // Bucharest
    bucharest->adicionarTransicao(fagaras, 211);
    bucharest->adicionarTransicao(pitesti, 101);
    bucharest->adicionarTransicao(giurgiu, 90);
    bucharest->adicionarTransicao(urziceni, 85);
    // Giurgiu
    giurgiu->adicionarTransicao(bucharest, 90);
    // Urziceni
    urziceni->adicionarTransicao(bucharest, 85);
    urziceni->adicionarTransicao(hirsova, 98);
    urziceni->adicionarTransicao(vaslui, 142);
    // Hirsova
    hirsova->adicionarTransicao(urziceni, 98);
    hirsova->adicionarTransicao(eforie, 86);
    // Eforie
    eforie->adicionarTransicao(hirsova, 86);
    // Vaslui
    vaslui->adicionarTransicao(urziceni, 142);
    vaslui->adicionarTransicao(iasi, 92);
    // Iasi
    iasi->adicionarTransicao(vaslui, 92);
    iasi->adicionarTransicao(neamt, 87);
    // Neamt
    neamt->adicionarTransicao(iasi, 87);

    // 3. ADIÇÃO DOS ESTADOS COMPLETOS NO MAPA
    mapa_romenia.adicionarEstado(arad);
    mapa_romenia.adicionarEstado(zerind);
    mapa_romenia.adicionarEstado(oradea);
    mapa_romenia.adicionarEstado(sibiu);
    mapa_romenia.adicionarEstado(timisoara);
    mapa_romenia.adicionarEstado(lugoj);
    mapa_romenia.adicionarEstado(mehadia);
    mapa_romenia.adicionarEstado(drobeta);
    mapa_romenia.adicionarEstado(craiova);
    mapa_romenia.adicionarEstado(rimnicuVilcea);
    mapa_romenia.adicionarEstado(fagaras);
    mapa_romenia.adicionarEstado(pitesti);
    mapa_romenia.adicionarEstado(bucharest);
    mapa_romenia.adicionarEstado(giurgiu);
    mapa_romenia.adicionarEstado(urziceni);
    mapa_romenia.adicionarEstado(hirsova);
    mapa_romenia.adicionarEstado(eforie);
    mapa_romenia.adicionarEstado(vaslui);
    mapa_romenia.adicionarEstado(iasi);
    mapa_romenia.adicionarEstado(neamt);
}

int main() {

    
    Mapa mapa_romenia;
    CriarMapaRomenia(mapa_romenia); 

    std::vector<ProblemaBusca> problemas = {
        {"Arad", "Bucharest"},
        {"Sibiu", "Fagaras"},
        {"Oradea", "Craiova"},
        {"Timisoara", "Bucharest"},
        {"Zerind", "Pitesti"},
        {"Lugoj", "Urziceni"},
        {"Arad", "Neamt"},
        {"Craiova", "Iasi"},
        {"Mehadia", "Vaslui"},
        {"Giurgiu", "Eforie"}
    };

    // 2. Configuração da Tabela de Impressão
    const int w_origem = 12; 
    const int w_data = 10;   

    std::cout << "\n================================================================================================================================" << std::endl;
    std::cout << "## 7. Tabela de Resultados (BFS, UCS, DFS)" << std::endl;
    std::cout << "================================================================================================================================" << std::endl;
    
    // Cabeçalho da Tabela
    std::cout << std::left << std::setw(w_origem) << "Origem";
    std::cout << std::left << std::setw(w_origem) << "Destino";
    std::cout << std::left << std::setw(w_data)   << "BFS C";
    std::cout << std::left << std::setw(w_data)   << "BFS T";
    std::cout << std::left << std::setw(w_data)   << "UCS C";
    std::cout << std::left << std::setw(w_data)   << "UCS T";
    std::cout << std::left << std::setw(w_data)   << "DFS C";
    std::cout << std::left << std::setw(w_data)   << "DFS T";
    std::cout << std::endl;
    std::cout << "--------------------------------------------------------------------------------------------------------------------------------" << std::endl;

    for (const auto& problema : problemas) {
        
        // Executar as 3 Buscas
        ResultadoBusca resultado_bfs = buscaEmLargura(mapa_romenia, problema.origem, problema.destino);
        ResultadoBusca resultado_ucs = buscaDeCustoUniforme(mapa_romenia, problema.origem, problema.destino);
        ResultadoBusca resultado_dfs = buscaEmProfundidade(mapa_romenia, problema.origem, problema.destino);
        
        // Linha da Tabela
        std::cout << std::left << std::setw(w_origem) << problema.origem;
        std::cout << std::left << std::setw(w_origem) << problema.destino;
        
        // BFS
        if (resultado_bfs.sucesso) {
            std::cout << std::left << std::setw(w_data) << resultado_bfs.custoTotal;
            std::cout << std::left << std::setw(w_data) << resultado_bfs.tempoExecucaoUs;
        } else {
            std::cout << std::left << std::setw(w_data) << "FALHA";
            std::cout << std::left << std::setw(w_data) << "N/A";
        }

        // UCS
        if (resultado_ucs.sucesso) {
            std::cout << std::left << std::setw(w_data) << resultado_ucs.custoTotal;
            std::cout << std::left << std::setw(w_data) << resultado_ucs.tempoExecucaoUs;
        } else {
            std::cout << std::left << std::setw(w_data) << "FALHA";
            std::cout << std::left << std::setw(w_data) << "N/A";
        }
        
        // DFS
        if (resultado_dfs.sucesso) {
            std::cout << std::left << std::setw(w_data) << resultado_dfs.custoTotal;
            std::cout << std::left << std::setw(w_data) << resultado_dfs.tempoExecucaoUs;
        } else {
            std::cout << std::left << std::setw(w_data) << "FALHA";
            std::cout << std::left << std::setw(w_data) << "N/A";
        }
        
        std::cout << std::endl;
    }
    
    std::cout << "--------------------------------------------------------------------------------------------------------------------------------" << std::endl;

    return 0;
}