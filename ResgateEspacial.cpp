#include "EstacaoEspacial.hpp"
#include "RoboDeResgate.hpp"
#include <iostream>

int main() {

    
    EstacaoEspacial estacao(0, 0);  // Ajuste o tamanho da matriz conforme necessário
    estacao.inicializarEstacao("estacao.txt");  // ESTE ARQUIVO DEVE TER AS INFORMAÇÕES DA MATRIZ E DO ASTRONAUTA

    // Criar robô na posição inicial (0,0)
    RoboDeResgate robo(&estacao, 0, 0);

    // Mostrar estado inicial
    std::cout << "\n ESTACAO ESPACIAL:\n";
    estacao.mostrarEstacao();

    // Iniciar resgate
    robo.iniciarResgate();

    // Exibir relatório final
    robo.gerarRelatorio("saida.txt"); // AQUI VAI TER A SAIDA DO RELATORIO
    return 0;
}
