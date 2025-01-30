#include "Aeronave.h"
#include <cstdlib>

//Geração dos números aleatórios para os valores dos atributos
Aeronave::Aeronave() {
    poderAtaque = rand() % 41 + 50;// Gera um número entre 50 e 90
    manobrabilidade = rand() % 41 + 30;// Gera um número entre 30 e 70
    alcance = rand() % 31 + 20;// Gera um número entre 20 e 50
}

//Cálculo do poder de ataque 
int Aeronave::getPoderAtaque() {
    return ((poderAtaque * 5) + (manobrabilidade * 3) + (alcance * 2)) / 10;
}
