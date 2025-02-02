#include "../Includes/Unidade.h"

Unidade::Unidade(int poderAtaque, int Destruicoes) {
    this->poderAtaque = poderAtaque;
    this->Destruicoes = Destruicoes;
}

int Unidade::getPoderAtaque(){
    return poderAtaque;
}

void Unidade::imprimiDetalhes(){
    cout << "Unidade" << endl;


}


int Unidade::somaDestruicao(){
    return Destruicoes + 1;
}
