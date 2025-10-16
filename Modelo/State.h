#ifndef STATE_H
#define STATE_H

#include <string>
#include <vector>
#include <iostream>
#include <tuple>
#include <algorithm>
#include <stdexcept>

class State;
using Transition = std::tuple<std::string, State*>; // (action, successor_state)

class State {
public:
    std::string name;
    bool isDirtyA;
    bool isDirtyB;
    char agentLocation; // 'A' ou 'B'
    std::vector<Transition> neighbors;

    // Construtor
    State(const std::string& name, bool isDirtyA, bool isDirtyB, char agentLocation);

    // Método para adicionar transições
    void addTransition(const std::string& action, State* successor_state);

    // Método para imprimir o estado e suas transições
    void printState() const;
    
    // Destrutor para evitar vazamento de memória (se usarmos new)
    ~State() = default; 
};

#endif // STATE_H