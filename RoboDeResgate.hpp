#ifndef ROBO_DE_RESGATE_HPP
#define ROBO_DE_RESGATE_HPP

#include "EstacaoEspacial.hpp"
#include <vector>
#include <queue>

class RoboDeResgate {
private:
    int x, y;  // Posição do robô
    EstacaoEspacial* estacao;  // Ponteiro para a estação espacial
    std::vector<std::vector<bool>> visitado;  // Matriz de controle de visitação
    std::vector<Astronauta> resgatados;  // Lista de astronautas resgatados

public:
    // Construtor
    RoboDeResgate(EstacaoEspacial* estacao, int startX, int startY);

    // Método para iniciar o resgate
    void iniciarResgate();

    // Percorre a matriz respeitando as regras dos módulos
    void percorrerMatriz();

    // Verifica se uma posição pode ser acessada
    bool podeMover(int novaX, int novaY);

    // Mostra o relatório final
    void gerarRelatorio();
};

#endif
