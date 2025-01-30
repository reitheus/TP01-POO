// Definição de Biblioteca para classe Infantaria

#ifndef INFANTARIA_H
#define INFANTARIA_H

using namespace std;

class Infantaria{
    private: // atritubos da classe 
        int ataque;
        int forca;
        int velocidade; 

    public: // métodos
        Infantaria(); //construtor
        int getPoderAtaque();
};

#endif