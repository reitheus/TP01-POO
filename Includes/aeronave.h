// Definição de Biblioteca para classe Aeronave

#ifndef AERONAVE_H
#define AERONAVE_H

using namespace std;

class Aeronave{
    private: // atributos da classe
        int ataque;
        int manobra;
        int alcance;

    public: // métodos 
        Aeronave();// construtor 
        int getPoderAtaque();  
};

#endif