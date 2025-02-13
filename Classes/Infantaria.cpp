#include "../Includes/Infantaria.h"
#include <cstdlib>

//Geração dos números aleatórios para os valores dos atributos
Infantaria::Infantaria() {
    poderAtaque = rand() % 31 + 30; // Gera um número entre 30 e 60
    forca = rand() % 31 + 20;  // Gera um número entre 20 e 50
    velocidade = rand() % 31 + 10; // Gera um número entre 10 e 40
}

//Cálculo do poder de ataque 
int Infantaria::getPoderAtaque() {

    poderAtaque = rand() % 31 + 30; // Gera um número entre 30 e 60
    forca = rand() % 31 + 20;  // Gera um número entre 20 e 50
    velocidade = rand() % 31 + 10; // Gera um número entre 10 e 40

    return ((poderAtaque* 5) + (forca * 3) + (velocidade * 2)) / 10;
}

// Sobrecarga do operador de saída <<
void Infantaria::imprimiDetalhes() {
    cout << "Unidade: Infantaria \n" << "-> Poder de Ataque: " << poderAtaque << "\n-> Força: " << forca << "\n-> Velocidade: " << velocidade << endl;
    cout << "-> Destruições: " << destruicoes << endl;
}


