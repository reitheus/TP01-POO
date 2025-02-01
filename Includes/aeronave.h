// Definição de Biblioteca para classe Aeronave

#ifndef AERONAVE_H
#define AERONAVE_H

#include "Unidade.h"

class Aeronave : public Unidade{
    private: // atributos da classe
        int manobrabilidade;
        int alcance;

    public: // métodos 
        Aeronave();// construtor 
        int getPoderAtaque();  
};

#endif
