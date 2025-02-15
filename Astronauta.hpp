#pragma once
#include <string>

class Astronauta {
private:
    std::string nome;
    int saude;  
    bool atendimentoUrgente;  
    int x, y;  // Posição na matriz da estação espacial

public:
    Astronauta(const std::string& nome, int saude, bool atendimentoUrgente, int x, int y);

    
    std::string getNome() const;
    int getSaude() const;
    bool precisaAtendimentoUrgente() const;
    int getX() const;
    int getY() const;

    
    void setSaude(int novaSaude);
    void setAtendimentoUrgente(bool urgente);
    void setPosicao(int novoX, int novoY);
};
