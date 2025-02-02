// Definição de Biblioteca para classe Veículo

#ifndef VEICULO_H
#define VEICULO_H

#include "../Includes/Unidade.h"

class Veiculo : public Unidade{
    private: // atritubos da classe 
        int blindagem;
        int potenciadeFogo;

    public: // métodos
        Veiculo(); // construtor
        int getPoderAtaque();
        void imprimiDetalhes();

};

#endif
