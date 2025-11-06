#include <iostream>
#include <string>


//commit teste 

enum class Action
{
    ASPIRAR,
    DIREITA,
    ESQUERDA
};

// Função auxiliar para converter a Ação em string para Saída
std::string actionToString(Action action)
{
    switch (action)
    {
    case Action::ASPIRAR:
        return "Aspirar";
    case Action::DIREITA:
        return "Direita";
    case Action::ESQUERDA:
        return "Esquerda";
    default:
        return "Nenhuma";
    }
}


class Perception
{
public:
    std::string location; 
    bool isDirty;         

    Perception(std::string loc, bool dirty) : location(loc), isDirty(dirty) {}
};


class Environment
{
private:
    bool isDirtyA;
    bool isDirtyB;
    std::string agentLocation; 

public:
    
    Environment(bool dirtyA, bool dirtyB, std::string initialLocation)
        : isDirtyA(dirtyA), isDirtyB(dirtyB), agentLocation(initialLocation) {}


    Perception getPerception() const
    {
        bool dirty = (agentLocation == "A") ? isDirtyA : isDirtyB;
        return Perception(agentLocation, dirty);
    }

    void update(Action action)
    {
        if (action == Action::ASPIRAR)
        {
            if (agentLocation == "A")
                isDirtyA = false;
            else
                isDirtyB = false;
        }
        else if (action == Action::DIREITA && agentLocation == "A")
        {
            agentLocation = "B";
        }
        else if (action == Action::ESQUERDA && agentLocation == "B")
        {
            agentLocation = "A";
        }
    }


    void displayState() const
    {
        std::cout << "Situação do Ambiente: ";
        std::cout << "A: " << (isDirtyA ? "SUJA" : "Limpa");
        std::cout << ", B: " << (isDirtyB ? "SUJA" : "Limpa");
        std::cout << ", Agente em: " << agentLocation << std::endl;
    }
};


class Agent
{
public:
    Agent() {}

    
    Action act(const Perception &p) const
    {
        
        if (p.isDirty)
        {
            return Action::ASPIRAR;
        }
     
        else
        {
            if (p.location == "A")
            {
                // Mover para B
                return Action::DIREITA;
            }
            else // location == "B"
            {
                // Mover para A
                return Action::ESQUERDA;
            }
        }
    }
};


void runSimulation()
{
    // === Entrada: Configuração Inicial ===
    char startA, startB, startLocChar;
    int numSteps;

    std::cout << "--- Configuração Inicial do VacuumWorld ---\n";
    std::cout << "A sala A está suja? (s/n): ";
    std::cin >> startA;
    std::cout << "A sala B está suja? (s/n): ";
    std::cin >> startB;
    std::cout << "Posição inicial do agente (A/B): ";
    std::cin >> startLocChar;
    std::cout << "Número de passos da simulação: ";
    std::cin >> numSteps;

    // Tratamento de entrada para inicialização
    std::string startLoc = (startLocChar == 'a' || startLocChar == 'A') ? "A" : "B";

    // Inicializa Componentes
    Environment environment(
        (startA == 's' || startA == 'S'),
        (startB == 's' || startB == 'S'),
        startLoc
    );
    Agent agent;

    std::cout << "\n--- Início da Simulação ---\n";
    environment.displayState();

    // === Loop Principal da Simulação ===
    for (int step = 1; step <= numSteps; ++step)
    {
        std::cout << "\n[Passo " << step << "]\n";

        // 1. Agente Percebe (Perceives)
        Perception perception = environment.getPerception();

        // 2. Agente Age (Act)
        Action chosenAction = agent.act(perception);

        // 3. Saída: Ação Executada
        std::string actionName = actionToString(chosenAction);
        std::cout << "Ação escolhida: " << actionName << std::endl;

        // 4. Ambiente Atualiza
        environment.update(chosenAction);

        // 5. Saída: Situação do Ambiente após cada ação
        environment.displayState();
    }

    std::cout << "\n--- Fim da Simulação ---\n";
}

int main()
{
    runSimulation();
    return 0;
}