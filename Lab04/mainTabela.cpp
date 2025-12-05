#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <utility>

#include "Problema/Mapa.h" 
#include "BuscaHeuristica/No.h"          
#include "Problema/Estado.h" 
#include "BuscaHeuristica/BuscasHeuristicas.h"

using namespace std;

// Estrutura auxiliar para definir os problemas (Origem e Destino)
struct ProblemaBusca {
    string origem;
    string destino;
};

// Estrutura para armazenar todos os resultados de uma linha da tabela
struct ResultadoTabela {
    ProblemaBusca problema;
    ResultadoBusca gulosa;
    ResultadoBusca astar;
};

void CriarMapaRomenia(Mapa& mapa_romenia) {
    
    // 1. CRIAÇÃO DOS OBJETOS ESTADO (Alocação dinâmica)
    // Usamos ponteiros para garantir que os objetos existam após a função terminar.
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
    
    // 2. ADIÇÃO DAS TRANSIÇÕES NOS OBJETOS ESTADO (Definindo vizinhos)
    // Usamos o ponteiro diretamente (sem o &) nas chamadas.
    
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
    // O Mapa assume a responsabilidade de liberar a memória (delete) no seu destrutor.
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
        {"Sibiu", "Bucharest"},
        {"Oradea", "Bucharest"},
        {"Timisoara", "Bucharest"},
        {"Zerind", "Bucharest"},
        {"Lugoj", "Bucharest"},
        {"Craiova", "Bucharest"},
        {"Mehadia", "Bucharest"},
        {"Giurgiu", "Bucharest"}
    };
    
    // Vetor para armazenar os resultados completos de todas as execuções
    vector<ResultadoTabela> resultadosCompletos;

    const int w_origem = 12; 
    const int w_data_cost = 10;   
    const int w_data_time = 12;   

    std::cout << "\n===========================================================================================================" << std::endl;
    std::cout << " Tabela de Experimentos (Gulosa vs. A*)" << std::endl;
    std::cout << "===========================================================================================================" << std::endl;
    
    // Cabeçalho da Tabela
    std::cout << std::left << std::setw(w_origem) << "Origem";
    std::cout << std::left << std::setw(w_origem) << "Destino";
    std::cout << std::left << std::setw(w_data_time) << "Gulosa T";
    std::cout << std::left << std::setw(w_data_cost) << "Gulosa C";
    std::cout << std::left << std::setw(w_data_time) << "A* T";
    std::cout << std::left << std::setw(w_data_cost) << "A* C";
    std::cout << std::endl;
    std::cout << "-----------------------------------------------------------------------------------------------------------" << std::endl;

    for (const auto& problema : problemas) {
        
        // Executar as Buscas
        ResultadoBusca resultado_gulosa = buscaGulosa(mapa_romenia, problema.origem, problema.destino);
        ResultadoBusca resultado_astar = buscaAStar(mapa_romenia, problema.origem, problema.destino);
        
        // Armazenar para impressão detalhada
        resultadosCompletos.push_back({problema, resultado_gulosa, resultado_astar});
        
        // Linha da Tabela (Resumo)
        std::cout << std::left << std::setw(w_origem) << problema.origem;
        std::cout << std::left << std::setw(w_origem) << problema.destino;
        
        // Gulosa (Tempo e Custo)
        if (resultado_gulosa.sucesso) {
            std::cout << std::left << std::setw(w_data_time) << resultado_gulosa.tempoExecucaoUs;
            std::cout << std::left << std::setw(w_data_cost) << resultado_gulosa.custoTotal;
        } else {
            std::cout << std::left << std::setw(w_data_time) << "FALHA";
            std::cout << std::left << std::setw(w_data_cost) << "N/A";
        }

        // A* (Tempo e Custo)
        if (resultado_astar.sucesso) {
            std::cout << std::left << std::setw(w_data_time) << resultado_astar.tempoExecucaoUs;
            std::cout << std::left << std::setw(w_data_cost) << resultado_astar.custoTotal;
        } else {
            std::cout << std::left << std::setw(w_data_time) << "FALHA";
            std::cout << std::left << std::setw(w_data_cost) << "N/A";
        }
        
        std::cout << std::endl;
    }
    
    std::cout << "-----------------------------------------------------------------------------------------------------------" << std::endl;


    std::cout << "\n\n=================================================================" << std::endl;
    std::cout << "## Sequência de Ações Detalhada (Gulosa e A*)" << std::endl;
    std::cout << "=================================================================" << std::endl;

    for (const auto& resultadoTabela : resultadosCompletos) {
        const auto& p = resultadoTabela.problema;
        
        std::cout << "\n--- De " << p.origem << " para " << p.destino << " ---\n" << std::endl;

        // Caminho Guloso
        if (resultadoTabela.gulosa.sucesso) {
            std::cout << "[GULOSA] Custo Final: " << resultadoTabela.gulosa.custoTotal << std::endl;
            std::cout << "  Caminho: ";
            for (const auto& acao : resultadoTabela.gulosa.sequenciaAcoes) {
                std::cout << acao << " / ";
            }
            std::cout << "\n" << std::endl;
        } else {
            std::cout << "[GULOSA] Não encontrou solução." << std::endl;
        }

        // Caminho A*
        if (resultadoTabela.astar.sucesso) {
            std::cout << "[A*] Custo Final: " << resultadoTabela.astar.custoTotal << std::endl;
            std::cout << "  Caminho: ";
            for (const auto& acao : resultadoTabela.astar.sequenciaAcoes) {
                std::cout << acao << " / ";
            }
            std::cout << "\n" << std::endl;
        } else {
            std::cout << "[A*] Não encontrou solução." << std::endl;
        }
    }

    std::cout << "=================================================================" << std::endl;

    return 0;

}