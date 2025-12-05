// main.cpp

#include <iostream>
#include <vector>
#include "Mapa.h" 


int main() {

    Mapa mapa_romenia;

    // 1. CRIAÇÃO DOS OBJETOS ESTADO
    Estado arad("Arad");
    Estado zerind("Zerind");
    Estado oradea("Oradea");
    Estado sibiu("Sibiu");
    Estado timisoara("Timisoara");
    Estado lugoj("Lugoj");
    Estado mehadia("Mehadia");
    Estado drobeta("Drobeta");
    Estado craiova("Craiova");
    Estado rimnicuVilcea("RimnicuVilcea");
    Estado fagaras("Fagaras");
    Estado pitesti("Pitesti");
    Estado bucharest("Bucharest");
    Estado giurgiu("Giurgiu");
    Estado urziceni("Urziceni");
    Estado hirsova("Hirsova");
    Estado eforie("Eforie");
    Estado vaslui("Vaslui");
    Estado iasi("Iasi");
    Estado neamt("Neamt");
    
    // 2. ADIÇÃO DAS TRANSIÇÕES NOS OBJETOS ESTADO 
    
    // Arad
    arad.adicionarTransicao("Zerind", 75);      
    arad.adicionarTransicao("Timisoara", 118);
    arad.adicionarTransicao("Sibiu", 140);
    // Zerind
    zerind.adicionarTransicao("Arad", 75);
    zerind.adicionarTransicao("Oradea", 71);
    // Oradea
    oradea.adicionarTransicao("Zerind", 71);
    oradea.adicionarTransicao("Sibiu", 151);
    // Sibiu
    sibiu.adicionarTransicao("Arad", 140);
    sibiu.adicionarTransicao("Oradea", 151);
    sibiu.adicionarTransicao("Fagaras", 99);
    sibiu.adicionarTransicao("RimnicuVilcea", 80);
    // Timisoara
    timisoara.adicionarTransicao("Arad", 118);
    timisoara.adicionarTransicao("Lugoj", 111);
    // Lugoj
    lugoj.adicionarTransicao("Timisoara", 111);
    lugoj.adicionarTransicao("Mehadia", 70);
    // Mehadia
    mehadia.adicionarTransicao("Lugoj", 70);
    mehadia.adicionarTransicao("Drobeta", 75);
    // Drobeta
    drobeta.adicionarTransicao("Mehadia", 75);
    drobeta.adicionarTransicao("Craiova", 120);
    // Craiova
    craiova.adicionarTransicao("Drobeta", 120);
    craiova.adicionarTransicao("RimnicuVilcea", 146);
    craiova.adicionarTransicao("Pitesti", 138);
    // RimnicuVilcea
    rimnicuVilcea.adicionarTransicao("Sibiu", 80);
    rimnicuVilcea.adicionarTransicao("Craiova", 146);
    rimnicuVilcea.adicionarTransicao("Pitesti", 97);
    // Fagaras
    fagaras.adicionarTransicao("Sibiu", 99);
    fagaras.adicionarTransicao("Bucharest", 211);
    // Pitesti
    pitesti.adicionarTransicao("RimnicuVilcea", 97);
    pitesti.adicionarTransicao("Craiova", 138);
    pitesti.adicionarTransicao("Bucharest", 101);
    // Bucharest
    bucharest.adicionarTransicao("Fagaras", 211);
    bucharest.adicionarTransicao("Pitesti", 101);
    bucharest.adicionarTransicao("Giurgiu", 90);
    bucharest.adicionarTransicao("Urziceni", 85);
    // Giurgiu
    giurgiu.adicionarTransicao("Bucharest", 90);
    // Urziceni
    urziceni.adicionarTransicao("Bucharest", 85);
    urziceni.adicionarTransicao("Hirsova", 98);
    urziceni.adicionarTransicao("Vaslui", 142);
    // Hirsova
    hirsova.adicionarTransicao("Urziceni", 98);
    hirsova.adicionarTransicao("Eforie", 86);
    // Eforie
    eforie.adicionarTransicao("Hirsova", 86);
    // Vaslui
    vaslui.adicionarTransicao("Urziceni", 142);
    vaslui.adicionarTransicao("Iasi", 92);
    // Iasi
    iasi.adicionarTransicao("Vaslui", 92);
    iasi.adicionarTransicao("Neamt", 87);
    // Neamt
    neamt.adicionarTransicao("Iasi", 87);

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
    
    // Teste Final
    mapa_romenia.imprimirMapa();

    return 0;
}