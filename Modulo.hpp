#pragma once

class Modulo {
private:
    char tipo;
public:
    Modulo(char tipo);
    char getTipo() const;
    virtual bool podeAcessar() const; 
    void setTipo(char tipo);
};
