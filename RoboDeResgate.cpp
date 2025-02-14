#include "RoboDeResgate.hpp"
#include <iostream>

// Construtor
RoboDeResgate::RoboDeResgate(EstacaoEspacial* estacao, int startX, int startY)
    : estacao(estacao), x(startX), y(startY) {
    int linhas = estacao->getLinhas();
    int colunas = estacao->getColunas();
    visitado.resize(linhas, std::vector<bool>(colunas, false));
}

// Verifica se o robô pode se mover para determinada posição
bool RoboDeResgate::podeMover(int novaX, int novaY) {
    return (novaX >= 0 && novaX < estacao->getLinhas() &&
            novaY >= 0 && novaY < estacao->getColunas() &&
            estacao->podeAcessar(novaX, novaY) &&
            !visitado[novaX][novaY]);
}

// Percorre a matriz usando BFS (Busca em Largura)
void RoboDeResgate::percorrerMatriz() {
     std::queue<std::pair<int, int>> fila;
     fila.push({x, y});
     visitado[x][y] = true;
 
     // Movimentos possíveis: cima, baixo, esquerda, direita
     int dx[] = {-1, 1, 0, 0};
     int dy[] = {0, 0, -1, 1};
 
     while (!fila.empty()) {
         int atualX = fila.front().first;
         int atualY = fila.front().second;
         fila.pop();
 
         // Deixa um rastro na posição visitada
         Modulo* moduloAtual = estacao->getModulo(atualX, atualY);
         if (moduloAtual) {
             moduloAtual->setTipo('-');  // Marca o caminho do robô
         }
 
         // Verifica se há astronauta nessa posição
         for (const auto& astro : estacao->getAstronautas()) {
             if (astro.getX() == atualX && astro.getY() == atualY) {
                 resgatados.push_back(astro);
                 estacao->removerAstronauta(astro.getNome());
               //   std::cout << " Astronauta resgatado: " << astro.getNome() 
               //             << " em (" << atualX << ", " << atualY << ")\n";
             }
         }
 
         // Tenta mover para as posições adjacentes
         for (int i = 0; i < 4; i++) {
             int novoX = atualX + dx[i];
             int novoY = atualY + dy[i];
 
             if (podeMover(novoX, novoY)) {
                 visitado[novoX][novoY] = true;
                 fila.push({novoX, novoY});
             }
         }
     }
 }
 
 

// Inicia o processo de resgate
void RoboDeResgate::iniciarResgate() {
    std::cout << " Robo iniciando resgate na posicao (" << x << ", " << y << ")\n";
    percorrerMatriz();
}

void RoboDeResgate::gerarRelatorio() {
     std::cout << "\n Relatorio Final:\n";
     std::cout << "Astronautas resgatados: " << resgatados.size() << "\n";
     for (const auto& astro : resgatados) {
         std::cout << "- " << astro.getNome() << " | Posicao: (" << astro.getX() 
                   << ", " << astro.getY() << ")" << "| Saude: " << astro.getSaude() <<  " | Precisa Atendimento Urgente: " << (astro.precisaAtendimentoUrgente() ? "Sim" : "Nao") << "\n";
     }
 }
 