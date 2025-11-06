#include "State.h"

// ----------------------------------------------------
// Implementação da Classe State
// ----------------------------------------------------

/**
 * Construtor da classe State.
 */
State::State(const std::string& name, bool isDirtyA, bool isDirtyB, char agentLocation)
    : name(name), isDirtyA(isDirtyA), isDirtyB(isDirtyB), agentLocation(agentLocation) {}

/**
 * Adiciona uma transição à lista de vizinhos.
 */
void State::addTransition(const std::string& action, State* successor_state) {
    neighbors.emplace_back(action, successor_state);
}

/**
 * Imprime os detalhes do estado e suas transições.
 */
void State::printState() const {
    std::cout << "Estado: " << name
              << " | Atributos: DirtyA=" << (isDirtyA ? "True" : "False")
              << ", DirtyB=" << (isDirtyB ? "True" : "False")
              << ", Loc=" << agentLocation << std::endl;
    
    std::cout << "  Transições (Vizinhança):" << std::endl;
    for (const auto& transition : neighbors) {
        const std::string& action = std::get<0>(transition);
        State* successor = std::get<1>(transition);
        
        std::cout << "    - Ação '" << action << "' -> Sucessor: " << successor->name
                  << " (Loc=" << successor->agentLocation
                  << ", DirtyA=" << (successor->isDirtyA ? "T" : "F")
                  << ", DirtyB=" << (successor->isDirtyB ? "T" : "F") << ")" << std::endl;
    }
}