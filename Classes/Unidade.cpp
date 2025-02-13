#include "../Includes/Unidade.h"

Unidade::Unidade() {
    destruicoes = 0;
    
}

Unidade::~Unidade() {
    
}

int Unidade::getPoderAtaque(){
    return poderAtaque;
}

int Unidade::getDestruicoes(){
    return destruicoes;
}

void Unidade::imprimiDetalhes(){
    cout << "Unidade" << endl;


}


void Unidade::somaDestruicao(){
    destruicoes += 1;
}
