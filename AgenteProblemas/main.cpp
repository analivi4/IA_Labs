#include <iostream>
#include <string>
#include "Problema/Mapa.h"
#include "Problema/Estado.h"


void construir_mapa_romenia(Mapa& mapa) {
    std::cout << "Construindo o mapa rodoviário da Romênia com base na Figura 1...\n";
    
    // Conexões (Transições/Estradas) e Distâncias (Custos)
    
    // ARAD
    mapa.conectar_estados("Arad", "Zerind", 75);
    mapa.conectar_estados("Arad", "Timisoara", 118);
    mapa.conectar_estados("Arad", "Sibiu", 140);
    
    // ZERIND
    mapa.conectar_estados("Zerind", "Oradea", 71); // Zerind <-> Arad já foi feita
    
    // TIMISOARA
    mapa.conectar_estados("Timisoara", "Lugoj", 111); // Timisoara <-> Arad já foi feita
    
    // ORADEA
    mapa.conectar_estados("Oradea", "Sibiu", 151); // Oradea <-> Zerind já foi feita
    
    // LUGOJ
    mapa.conectar_estados("Lugoj", "Mehadia", 70); // Lugoj <-> Timisoara já foi feita
    
    // MEHADIA
    mapa.conectar_estados("Mehadia", "Dobreta", 75); // Mehadia <-> Lugoj já foi feita
    
    // DOBRETA
    mapa.conectar_estados("Dobreta", "Craiova", 120); // Dobreta <-> Mehadia já foi feita
    
    // SIBIU
    mapa.conectar_estados("Sibiu", "Fagaras", 99);
    mapa.conectar_estados("Sibiu", "Rimnicu Vilcea", 80); // Sibiu <-> Arad, Oradea já foram feitas
    
    // RIMNICU VILCEA
    mapa.conectar_estados("Rimnicu Vilcea", "Pitesti", 97);
    mapa.conectar_estados("Rimnicu Vilcea", "Craiova", 146); // Rimnicu Vilcea <-> Sibiu já foi feita
    
    // FAGARAS
    mapa.conectar_estados("Fagaras", "Bucharest", 211); // Fagaras <-> Sibiu já foi feita
    
    // CRAIOVA
    mapa.conectar_estados("Craiova", "Pitesti", 138); // Craiova <-> Dobreta, Rimnicu Vilcea já foram feitas
    
    // PITESTI
    mapa.conectar_estados("Pitesti", "Bucharest", 101); // Pitesti <-> Rimnicu Vilcea, Craiova já foram feitas
    
    // BUCHAREST
    mapa.conectar_estados("Bucharest", "Giurgiu", 90);
    mapa.conectar_estados("Bucharest", "Urziceni", 85); // Bucharest <-> Fagaras, Pitesti já foram feitas
    
    // URZICENI
    mapa.conectar_estados("Urziceni", "Hirsova", 98);
    mapa.conectar_estados("Urziceni", "Vaslui", 142); // Urziceni <-> Bucharest já foi feita
    
    // HIRSOVA
    mapa.conectar_estados("Hirsova", "Eforie", 86); // Hirsova <-> Urziceni já foi feita
    
    // VASLUI
    mapa.conectar_estados("Vaslui", "Iasi", 92); // Vaslui <-> Urziceni já foi feita
    
    // IASI
    mapa.conectar_estados("Iasi", "Neamt", 87); // Iasi <-> Vaslui já foi feita
    
    std::cout << "Mapa construído com " << mapa.conjunto_estados.size() << " cidades (estados).\n";
}

int main() {
    Mapa mapa_romenia;
    
    construir_mapa_romenia(mapa_romenia);

    // 1. Imprime todo o grafo (Teste de Estrutura)
    std::cout << mapa_romenia;

    return 0;
}