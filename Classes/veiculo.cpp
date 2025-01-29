#include "Veiculo.h"
#include <cstdlib>

//Geração dos números aleatórios para os valores dos atributos
Veiculo::Veiculo() {
    ataque= rand() % 41 + 40;// Gera um número entre 40 e 80
    blindagem = rand() % 41 + 30;// Gera um número entre 30 e 70
    potencia = rand() % 31 + 20;// Gera um número entre 20 e 50
}

//Cálculo do poder de ataque 
int Veiculo::getPoderAtaque() {
    return ((ataque* 5) + (blindagem * 4) + (potencia * 1)) / 10;
}
