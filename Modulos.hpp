#pragma once
#include "Modulo.hpp"

// ModuloSeguranca (S)
class ModuloSeguranca : public Modulo {
public:
    ModuloSeguranca() : Modulo('S') {}
};          

// ModuloAstronauta (A)
class ModuloAstronauta : public Modulo {
public:
    ModuloAstronauta() : Modulo('A') {}
};

// ModuloObstaculo (#)
class ModuloObstaculo : public Modulo {
public:
    ModuloObstaculo() : Modulo('#') {}
    bool podeAcessar() const override { return false; }  // Módulo de obstáculo não é acessível
};

// ModuloVazio (~)
class ModuloVazio : public Modulo {
public:
    ModuloVazio() : Modulo('~') {}
    bool podeAcessar() const override { return false; }  // Módulo vazio não é acessível
};

// ModuloFogo (F)
class ModuloFogo : public Modulo {
public:
    ModuloFogo() : Modulo('F') {}
    bool podeAcessar() const override { return false; }  // Módulo de fogo não é acessível
};

// ModuloNormal (.)
// Este módulo é acessível, pois é o módulo normal.
class ModuloNormal : public Modulo {
public:
    ModuloNormal() : Modulo('.') {}
};


class ModuloRastro : public Modulo {
    public:
        ModuloRastro() : Modulo('-') {}
    };