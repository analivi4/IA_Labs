// main.cpp

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "Problema/Mapa.h" 
#include "BuscaHeuristica/BuscasHeuristicas.h"



void CriarMapaRomenia(Mapa& mapa_romenia){
    
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

    const string estadoInicial = "Arad";
    const string estadoObjetivo = "Bucharest";

  
    cout << "INÍCIO: " << estadoInicial << " | OBJETIVO: " << estadoObjetivo << endl;
    cout << "=================================================================" << endl;

    cout << "EXECUÇÃO: Busca Gulosa de Melhor Escolha (f(n) = h(n))" << endl;
  

    ResultadoBusca resultado_gulosa = buscaGulosa(mapa_romenia, estadoInicial, estadoObjetivo);

    if (resultado_gulosa.sucesso) {
    
        cout << "Custo Final do Caminho (g(n)): " << resultado_gulosa.custoTotal << " km" << endl;
        
        cout << "Tempo de Execução: " << resultado_gulosa.tempoExecucaoUs << " µs" << endl;

        cout << "\nSequência de Ações (Caminho Percorrido):" << endl;
        for (const string& acao : resultado_gulosa.sequenciaAcoes) {
            cout << "  -> " << acao << endl;
        }

    } else {
        cout << "FALHA: A busca Gulosa não conseguiu encontrar o caminho de " 
             << estadoInicial << " para " << estadoObjetivo << "." << endl;
        cout << "Tempo de Execução: " << resultado_gulosa.tempoExecucaoUs << " µs" << endl;
    }

    cout << "=================================================================" << endl;


    cout << "EXECUÇÃO: Busca A* (A-Star) (f(n) = g(n) + h(n))" << endl;

    ResultadoBusca resultado_astar = buscaAStar(mapa_romenia, estadoInicial, estadoObjetivo);

    if (resultado_astar.sucesso) {
        cout << "Custo Mínimo do Caminho (g(n)): " << resultado_astar.custoTotal << " km" << endl; 
        cout << "Tempo de Execução: " << resultado_astar.tempoExecucaoUs << " µs" << endl;
        cout << "Sequência de Ações:" << endl;
        for (const string& acao : resultado_astar.sequenciaAcoes) {
            cout << "  -> " << acao << endl;
        }
    } else {
        cout << "FALHA: Busca A* não encontrou o caminho." << endl;
    }


    return 0;
}
