#include "State.h"
#include <iostream>
#include <vector>

int main() {

    // 1. Criação dos 8 Estados
    std::vector<State*> model;
    
    State* s0 = new State("s0", true, true, 'A'); 
    
    State* s1 = new State("s1", false, true, 'A');

    State* s2 = new State("s3", false, true, 'B');

    State* s3 = new State("s4", false, false, 'B');

    State* s4 = new State("s4", false, false, 'A');

    State* s5 = new State("s5", true, true, 'B');

    State* s6 = new State("s6", true, false, 'B');

    State* s7 = new State("s7", true, false, 'A');


    // Adiciona todos os estados ao vetor modelo
    model.push_back(s0); 
    model.push_back(s1); 
    model.push_back(s2); 
    model.push_back(s3);
    model.push_back(s4); 
    model.push_back(s5); 
    model.push_back(s6); 
    model.push_back(s7);


// 2. Criação das Transições baseada no Diagrama
    
    // ESTADO s0:
    s0->addTransition("aspirar", s1);    // Limpa A -> s1 ([A: Robô Limpo] [B: Sujo])
    s0->addTransition("direita", s5);     // Move para B -> s5 ([A: Sujo] [B: Robô Sujo])
    s0->addTransition("esquerda", s0);    // Permanece em A
    
    // ESTADO s1: 
    s1->addTransition("aspirar", s1);    // A já limpo -> s1
    s1->addTransition("direita", s2);     // Move para B -> s2 ([A: Limpo] [B: Robô Sujo])
    s1->addTransition("esquerda", s1);    // Permanece em A

    // ESTADO s2: 
    s2->addTransition("aspirar", s3);    // Limpa B -> s3 ([A: Limpo] [B: Robô Limpo])
    s2->addTransition("direita", s2);     // Permanece em B
    s2->addTransition("esquerda", s1);    // Move para A -> s1 ([A: Robô Limpo] [B: Sujo])

    // ESTADO s3: 
    s3->addTransition("aspirar", s3);    // B já limpo -> s3
    s3->addTransition("direita", s3);     // Permanece em B
    s3->addTransition("esquerda", s4);    // Move para A -> s4 ([A: Robô Limpo] [B: Limpo])
    
    // ESTADO s4:
    s4->addTransition("aspirar", s4);    // A já limpo -> s4
    s4->addTransition("direita", s3);     // Move para B -> s3 ([A: Limpo] [B: Robô Limpo])
    s4->addTransition("esquerda", s4);    // Permanece em A

    // ESTADO s5:
    s5->addTransition("aspirar", s6);    // Limpa B -> s6 ([A: Sujo] [B: Robô Limpo])
    s5->addTransition("direita", s5);     // Permanece em B
    s5->addTransition("esquerda", s0);    // Move para A -> s0 ([A: Robô Sujo] [B: Sujo])

    // ESTADO s6:
    s6->addTransition("aspirar", s6);    // B já limpo -> s6
    s6->addTransition("direita", s6);     // Permanece em B
    s6->addTransition("esquerda", s7);    // Move para A -> s7 ([A: Robô Sujo] [B: Limpo])

    // ESTADO s7:
    s7->addTransition("aspirar", s4);    // Limpa A -> s4 ([A: Robô Limpo] [B: Limpo])
    s7->addTransition("direita", s6);     // Move para B -> s6 ([A: Sujo] [B: Robô Limpo])
    s7->addTransition("esquerda", s7);    // Permanece em A

    std::cout << "\n--- Visualização Completa do Modelo ---" << std::endl;

    // Imprime todos os estados e suas transições
    for (State* state : model) {
        state->printState();
        std::cout << std::endl;
    }

    // Limpeza da memória alocada com 'new'
    for (State* state : model) {
        delete state;
    }
    
    return 0;
}