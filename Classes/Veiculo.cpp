#include "../Includes/Veiculo.h"
#include <cstdlib>

//Geração dos números aleatórios para os valores dos atributos
Veiculo::Veiculo() {
    poderAtaque= rand() % 41 + 40;// Gera um número entre 40 e 80
    blindagem = rand() % 41 + 30;// Gera um número entre 30 e 70
    potenciadeFogo = rand() % 31 + 20;// Gera um número entre 20 e 50
}

//Cálculo do poder de ataque 
int Veiculo::getPoderAtaque() {
    return ((poderAtaque* 5) + (blindagem * 4) + (potenciadeFogo * 1)) / 10;
}


// Sobrecarga do operador de saída <<
void Veiculo::imprimiDetalhes() {
    cout << "\nUnidade: veiculo \n" << "-> Poder de Ataque: " << poderAtaque << "\n-> blindagem: " << blindagem << "\n-> Potencia de Fogo: " << potenciadeFogo << endl;
    
}
