#pragma once
#include <string>

class Astronauta {
private:
    std::string nome;
    int saude;  // Nível de saúde (0 a 100)
    bool atendimentoUrgente;  // Se precisa de atendimento médico (true ou false)
    int x, y;  // Posição na matriz da estação espacial

public:
    // Construtor
    Astronauta(const std::string& nome, int saude, bool atendimentoUrgente, int x, int y);

    // Getters
    std::string getNome() const;
    int getSaude() const;
    bool precisaAtendimentoUrgente() const;
    int getX() const;
    int getY() const;

    // Setters
    void setSaude(int novaSaude);
    void setAtendimentoUrgente(bool urgente);
    void setPosicao(int novoX, int novoY);
};
