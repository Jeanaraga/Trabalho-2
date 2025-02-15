#include "EstacaoEspacial.hpp"
#include "RoboDeResgate.hpp"
#include <iostream>

int main() {

    
    EstacaoEspacial estacao(0, 0);  // Ajuste o tamanho da matriz conforme necessário
    estacao.inicializarEstacao("estacao.txt");  // O arquivo 'estacao.txt' deve conter a matriz da estação

    // Criar robô na posição inicial (0,0)
    RoboDeResgate robo(&estacao, 0, 0);

    // Mostrar estado inicial
    std::cout << "\n ESTACAO ESPACIAL:\n";
    estacao.mostrarEstacao();

    // Iniciar resgate
    robo.iniciarResgate();

    // Exibir relatório final
    robo.gerarRelatorio();

    return 0;
}
