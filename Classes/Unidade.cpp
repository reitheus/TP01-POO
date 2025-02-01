#include "../Includes/Unidade.h"

Unidade::Unidade(int poderAtaque, int Destruicoes) {
    this->poderAtaque = poderAtaque;
    this->Destruicoes = Destruicoes;
}

int Unidade::getPoderAtaque(){
    return poderAtaque;
}

int Unidade::somaDestruicao(){
    return Destruicoes + 1;
}
