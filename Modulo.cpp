#include "Modulo.hpp"

Modulo::Modulo(char tipo) {
    this->tipo = tipo;
}

char Modulo::getTipo() const {
    return this->tipo;
}

void Modulo::setTipo(char tipo) {
    this->tipo = tipo;
}

bool Modulo::podeAcessar() const { 
    return tipo != '#' && tipo != '~' && tipo != 'F';  // Para a classe base, módulos especiais não são acessíveis
}
