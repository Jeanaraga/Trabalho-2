#pragma once
#include "Modulo.hpp"


class ModuloSeguranca : public Modulo {
public:
    ModuloSeguranca() : Modulo('S') {}
};          


class ModuloAstronauta : public Modulo {
public:
    ModuloAstronauta() : Modulo('A') {}
};


class ModuloObstaculo : public Modulo {
public:
    ModuloObstaculo() : Modulo('#') {}
    bool podeAcessar() const override { return false; }  // Módulo de obstáculo não é acessível
};


class ModuloVazio : public Modulo {
public:
    ModuloVazio() : Modulo('~') {}
    bool podeAcessar() const override { return false; }  // Módulo vazio não é acessível
};


class ModuloFogo : public Modulo {
public:
    ModuloFogo() : Modulo('F') {}
    bool podeAcessar() const override { return false; }  // Módulo de fogo não é acessível
};



class ModuloNormal : public Modulo {
public:
    ModuloNormal() : Modulo('.') {}
};


class ModuloRastro : public Modulo {
    public:
        ModuloRastro() : Modulo('-') {}
    };