// Definição de Biblioteca para classe Veículo

#ifndef VEICULO_H
#define VEICULO_H

using namespace std;

class Veiculo{
    private: // atritubos da classe 
        int ataque; 
        int blindagem;
        int potencia;

    public: // métodos
        Veiculo(); // construtor
        int getPoderAtaque();
};

#endif