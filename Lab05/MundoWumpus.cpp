#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

#define RESET   "\033[0m"
#define RED     "\033[1;31m"
#define YELLOW  "\033[1;33m"
#define CYAN    "\033[1;36m"
#define BLUE    "\033[94m"
#define GREEN   "\033[1;32m"

class MundoWumpus {
private:
    char grid[4][4];
    string kb[4][4];
    int pos_agente[2];
    int pos_ouro[2];
    bool vitoria = false;
    bool derrota = false;
    bool tem_flecha = true;
    bool wumpus_vivo = true;
    string status_msg = "Sua jornada começou!";

    void gerar_mapa() {
        for(int i=0; i<4; i++)
            for(int j=0; j<4; j++) grid[i][j] = '.';

        vector<pair<int, int>> posicoes;
        for(int r=0; r<4; r++) 
            for(int c=0; c<4; c++) 
                if(!(r == 3 && c == 0)) posicoes.push_back({r, c});

        srand(time(0));
        random_shuffle(posicoes.begin(), posicoes.end());

        pos_ouro[0] = posicoes.back().first;
        pos_ouro[1] = posicoes.back().second;
        grid[pos_ouro[0]][pos_ouro[1]] = 'G';
        posicoes.pop_back();

        int wr = posicoes.back().first;
        int wc = posicoes.back().second;
        grid[wr][wc] = 'W';
        posicoes.pop_back();

        for(int i=0; i<3; i++) {
            grid[posicoes.back().first][posicoes.back().second] = 'P';
            posicoes.pop_back();
        }
    }

public:
    MundoWumpus() {
        pos_agente[0] = 3; pos_agente[1] = 0;
        for(int i=0; i<4; i++)
            for(int j=0; j<4; j++) kb[i][j] = "?";
        gerar_mapa();
    }

    void atirar(char direcao) {
        if (!tem_flecha) {
            status_msg = RED + string("Voce ja usou sua unica flecha!") + RESET;
            return;
        }

        tem_flecha = false;
        int r = pos_agente[0];
        int c = pos_agente[1];
        
        // Determina a casa alvo
        int tr = r, tc = c;
        if (direcao == 'w') tr--;
        else if (direcao == 's') tr++;
        else if (direcao == 'a') tc--;
        else if (direcao == 'd') tc++;

        // Verifica se acertou o Wumpus
        if (tr >= 0 && tr < 4 && tc >= 0 && tc < 4 && grid[tr][tc] == 'W') {
            wumpus_vivo = false;
            grid[tr][tc] = '.'; // Remove o Wumpus do mapa
            status_msg = GREEN + string("--- GRITO! O Wumpus morreu! ---") + RESET;
        } else {
            status_msg = "A flecha atingiu o chao e nada aconteceu...";
        }
    }

    vector<string> obter_percepcoes() {
        vector<string> p;
        int r = pos_agente[0], c = pos_agente[1];

        if (r == pos_ouro[0] && c == pos_ouro[1]) 
            p.push_back(string(YELLOW) + "BRILHO" + RESET);

        bool fedor = false, brisa = false;
        int dr[] = {0, 0, 1, -1}, dc[] = {1, -1, 0, 0};

        for(int i=0; i<4; i++) {
            int nr = r + dr[i], nc = c + dc[i];
            if(nr >= 0 && nr < 4 && nc >= 0 && nc < 4) {
                // Fedor só existe se o Wumpus estiver vivo
                if(grid[nr][nc] == 'W' && wumpus_vivo) fedor = true;
                if(grid[nr][nc] == 'P') brisa = true;
            }
        }

        if(fedor) p.push_back(string(RED) + "FEDOR" + RESET);
        if(brisa) p.push_back(string(CYAN) + "BRISA" + RESET);
        return p;
    }

    void atualizar_kb(vector<string> percepcoes) {
        int r = pos_agente[0], c = pos_agente[1];
        kb[r][c] = "V";
        bool perigo = false;
        for(auto const& s : percepcoes) 
            if(s.find("FEDOR") != string::npos || s.find("BRISA") != string::npos) perigo = true;

        if(!perigo) {
            int dr[] = {0, 0, 1, -1}, dc[] = {1, -1, 0, 0};
            for(int i=0; i<4; i++) {
                int nr = r + dr[i], nc = c + dc[i];
                if(nr >= 0 && nr < 4 && nc >= 0 && nc < 4) 
                    if(kb[nr][nc] == "?") kb[nr][nc] = "OK";
            }
        }
    }

    void exibir(vector<string> percepcoes) {
        cout << "\n      BASE DE CONHECIMENTO (" << (tem_flecha ? "1" : "0") << " Flecha)" << endl;
        for(int r=0; r<4; r++) {
            cout << "          ";
            for(int c=0; c<4; c++) {
                if(r == pos_agente[0] && c == pos_agente[1]) cout << " [A] ";
                else if(kb[r][c] == "V") cout << "  .  ";
                else if(kb[r][c] == "OK") cout << BLUE << " OK " << RESET;
                else cout << "  ?  ";
            }
            cout << endl;
        }
        cout << "--------------------------------------------------" << endl;
        cout << "PERCEPCOES: ";
        if(percepcoes.empty()) cout << "NADA";
        else {
            for(size_t i=0; i<percepcoes.size(); i++) 
                cout << percepcoes[i] << (i == percepcoes.size()-1 ? "" : ", ");
        }
        cout << "\nSTATUS: " << status_msg << endl;
    }

    void mover(char tecla) {
        int r = pos_agente[0], c = pos_agente[1];
        if(tecla == 'w') r--; else if(tecla == 's') r++;
        else if(tecla == 'a') c--; else if(tecla == 'd') c++;

        if(r < 0 || r >= 4 || c < 0 || c >= 4) { status_msg = "PAREDE!"; return; }

        pos_agente[0] = r; pos_agente[1] = c;
        char item = grid[r][c];
        
        if(item == 'W' && wumpus_vivo) { 
            derrota = true; 
            status_msg = RED + string("O Wumpus te devorou!") + RESET; 
        }
        else if(item == 'P') { 
            derrota = true; 
            status_msg = "Voce caiu no poco!"; 
        }
        else if(item == 'G') { 
            vitoria = true; 
            status_msg = YELLOW + string("Voce achou o OURO!") + RESET; 
        }
        else { 
            status_msg = "Voce ainda esta seguro!"; 
        }
    }

    bool encerrado() { return vitoria || derrota; }
};

int main() {
    MundoWumpus jogo;
    char comando;

    cout << "--- MUNDO WUMPUS C++ ---" << endl;
    cout << "WASD: Mover | Q: Preparar Flecha" << endl;

    while(!jogo.encerrado()) {
        vector<string> p = jogo.obter_percepcoes();
        jogo.atualizar_kb(p);
        jogo.exibir(p);

        cout << "\nComando: ";
        cin >> comando;
        comando = (char)tolower(comando);
        
        if (comando == 'q') {
            cout << "ATIRAR EM QUAL DIRECAO? (W, A, S, D): ";
            char direcao;
            cin >> direcao;
            jogo.atirar((char)tolower(direcao));
        } else {
            jogo.mover(comando);
        }
    }

    jogo.exibir(jogo.obter_percepcoes());
    cout << "\n*** FIM DA PARTIDA ***" << endl;
    return 0;
}