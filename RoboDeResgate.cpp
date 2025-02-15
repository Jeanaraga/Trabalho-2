#include "RoboDeResgate.hpp"
#include <iostream>
#include <queue>
#include <vector>

// Construtor
RoboDeResgate::RoboDeResgate(EstacaoEspacial* estacao, int startX, int startY)
    : estacao(estacao), x(startX), y(startY), passos(0) {
    int linhas = estacao->getLinhas();
    int colunas = estacao->getColunas();
    visitado.resize(linhas, std::vector<bool>(colunas, false)); // Inicializa visitado
}


// Verifica se o robô pode se mover para determinada posição
bool RoboDeResgate::podeMover(int novaX, int novaY) {
    return (novaX >= 0 && novaX < estacao->getLinhas() &&
            novaY >= 0 && novaY < estacao->getColunas() &&
            estacao->podeAcessar(novaX, novaY) &&
            !visitado[novaX][novaY]);
}

void RoboDeResgate::marcarFogo() {
    // Percorre a matriz para marcar as células próximas ao fogo
    for (int i = 0; i < estacao->getLinhas(); i++) {
        for (int j = 0; j < estacao->getColunas(); j++) {
            Modulo* modulo = estacao->getModulo(i, j);
            if (modulo && modulo->getTipo() == 'F') {
                // Marca as células ao redor do fogo como inacessíveis
                for (int dx = -1; dx <= 1; dx++) {
                    for (int dy = -1; dy <= 1; dy++) {
                        int novoX = i + dx;
                        int novoY = j + dy;
                        // Verifica se a nova posição está dentro da matriz e não é o fogo
                        if (novoX >= 0 && novoX < estacao->getLinhas() &&
                            novoY >= 0 && novoY < estacao->getColunas()) {
                            Modulo* adjModulo = estacao->getModulo(novoX, novoY);
                            if (adjModulo && adjModulo->getTipo() != 'F' && adjModulo->getTipo() != '#' && adjModulo->getTipo() != '~') {
                                // Marca a célula adjacente como inacessível
                                adjModulo->setTipo('~');
                            }
                        }
                    }
                }
            }
        }
    }
}

// Percorre a matriz usando BFS (Busca em Largura)
void RoboDeResgate::percorrerMatriz() {
    std::queue<std::pair<int, int>> fila;  // Declara fila
    fila.push({x, y});
    visitado[x][y] = true;

    // Movimentos possíveis: cima, baixo, esquerda, direita
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while (!fila.empty()) {
        int atualX = fila.front().first;
        int atualY = fila.front().second;
        fila.pop();

        Modulo* moduloAtual = estacao->getModulo(atualX, atualY);
        if (moduloAtual) {
            moduloAtual->setTipo('-');
        }

        for (const auto& astro : estacao->getAstronautas()) {
            if (astro.getX() == atualX && astro.getY() == atualY) {
                resgatados.push_back(astro);
                estacao->removerAstronauta(astro.getNome());
            }
        }

        for (int i = 0; i < 4; i++) {
            int novoX = atualX + dx[i];
            int novoY = atualY + dy[i];

            if (podeMover(novoX, novoY)) {
                visitado[novoX][novoY] = true;
                fila.push({novoX, novoY});
                passos++;  // Incrementa o número de passos
            }
        }
    }
}




// Gera um relatório final
void RoboDeResgate::gerarRelatorio() {
    std::cout << "\nRelatorio Final:\n";
    std::cout << "Astronautas resgatados: " << resgatados.size() << "\n";
    
    // Exibe astronautas resgatados
    for (const auto& astro : resgatados) {
        std::cout << "- " << astro.getNome() << " | Posicao: (" << astro.getX() 
                  << ", " << astro.getY() << ")" << "| Saude: " << astro.getSaude() 
                  << " | Precisa Atendimento Urgente: " << (astro.precisaAtendimentoUrgente() ? "Sim" : "Nao") << "\n";
    }

    // Exibe astronautas não resgatados
    std::cout << "\nAstronautas nao resgatados:\n";
    for (const auto& astro : estacao->getAstronautas()) {
        bool resgatado = false;
        for (const auto& resgatadoAstronauta : resgatados) {
            if (astro.getNome() == resgatadoAstronauta.getNome()) {
                resgatado = true;
                break;
            }
        }
        if (!resgatado) {
            std::cout << "- " << astro.getNome() << " | Posicao: (" << astro.getX() 
                      << ", " << astro.getY() << ")" << "| Saude: " << astro.getSaude() 
                      << " | Precisa Atendimento Urgente: " << (astro.precisaAtendimentoUrgente() ? "Sim" : "Nao") << "\n";
        }
    }

    // Exibe o número total de passos
    std::cout << "\nTempo total da operacao de resgate: " << getPassos() << " passos.\n";
}

// Inicia o processo de resgate
void RoboDeResgate::iniciarResgate() {
    std::cout << "Robo iniciando resgate na posicao (" << x << ", " << y << ")\n";
    marcarFogo();  // Marca as áreas próximas ao fogo como inacessíveis
    percorrerMatriz();
}

// Retorna o número de passos
// Em RoboDeResgate.cpp

int RoboDeResgate::getPassos() const {
    return passos;
}


