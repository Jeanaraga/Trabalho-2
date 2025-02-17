#include "EstacaoEspacial.hpp"
#include "RoboDeResgate.hpp"
#include <iostream>
#include <string>


void processarResgate(const std::string& arquivoEntrada, const std::string& arquivoSaida) {
    EstacaoEspacial estacao(0, 0);  
    estacao.inicializarEstacao(arquivoEntrada);

    
    RoboDeResgate robo(&estacao, 0, 0);

    
    std::cout << "\n ESTACAO ESPACIAL:\n";
    estacao.mostrarEstacao();

   
    robo.iniciarResgate();

    
    robo.gerarRelatorio(arquivoSaida);
}

int main() {

    processarResgate("entrada1.txt", "saida1.txt");
    processarResgate("entrada2.txt", "saida2.txt");

    return 0;
}
