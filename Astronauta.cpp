#include "Astronauta.hpp"

// Construtor
Astronauta::Astronauta(const std::string& nome, int saude, bool atendimentoUrgente, int x, int y)
    : nome(nome), saude(saude), atendimentoUrgente(atendimentoUrgente), x(x), y(y) {}

// Métodos Get
std::string Astronauta::getNome() const {
    return nome;
}

int Astronauta::getSaude() const {
    return saude;
}

bool Astronauta::precisaAtendimentoUrgente() const {
    return atendimentoUrgente;
}

int Astronauta::getX() const {
    return x;
}

int Astronauta::getY() const {
    return y;
}

// Métodos Set
void Astronauta::setSaude(int novaSaude) {
    if (novaSaude >= 0 && novaSaude <= 100) {
        saude = novaSaude;
    }
}

void Astronauta::setAtendimentoUrgente(bool urgente) {
    atendimentoUrgente = urgente;
}

void Astronauta::setPosicao(int novoX, int novoY) {
    x = novoX;
    y = novoY;
}
