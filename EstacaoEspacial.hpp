#pragma once
#include "Modulos.hpp"
#include "Astronauta.hpp"
#include <vector>
#include <string>
#include <stdexcept>

class EstacaoEspacial {
private:
    std::vector<std::vector<Modulo*>> matriz;  // Matriz de módulos
    std::vector<Astronauta> astronautas;  // Lista dinâmica de astronautas
    int linhas;
    int colunas;

public:
    // Construtor e destrutor
    EstacaoEspacial(int linhas, int colunas);
    ~EstacaoEspacial();

    // Métodos relacionados à matriz
    void inicializarEstacao(const std::string& arquivo);
    void mostrarEstacao() const;
    bool podeAcessar(int linha, int coluna) const;

    // Métodos relacionados aos astronautas
    void adicionarAstronauta(const Astronauta& astro);
    void removerAstronauta(const std::string& nome);
    std::vector<Astronauta> getAstronautas() const;
    void mostrarAstronautas() const;

    // Métodos auxiliares
    int getLinhas() const;
    int getColunas() const;
    Modulo* getModulo(int x, int y) const;  // <-- Adicionando esse método

};
