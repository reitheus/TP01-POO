#include "../include/Batalha.h"

Batalha::Batalha(string nomeA, string nomeB) {
    Exercito *exercA = new Exercito(nomeA);
    Exercito *exercB = new Exercito(nomeB);
    Date *data = new Date();

}

Batalha::~Batalha(){
    delete exercA;
    delete exercB;
    delete data;

}


void Batalha::setVitoriasDoExercitoA(){
    exercitoA->setVitorias();
    exercitoB->setDerrotas();

}
void Batalha::setVitoriasDoExercitoB(){
    exercitoA->setDerrotas();
    exercitoB->setVitorias();

}
void Batalha::setEmpateDosExercitos(){
    exercitoA->setEmpates();
    exercitoB->setEmpates();

}

int Batalha::getVitoriasA(){
    exercitoA->getVitorias();

}

int Batalha::getVitoriasB(){
   exercitoB->getVitorias();

}

int Batalha::getDerrotasA(){
   exercitoA->getDerrotas();

}

int Batalha::getDerrotasB(){
   exercitoB->getDerrotas();

}

int Batalha::getEmpatesA(){
    exercitoA->getEmpates();
    

}

int Batalha::getEmpatesB(){
    exercitoB->getEmpates();
}


void Batalha::ataqueExercitoA(string nomeA){
    cout << "Simulação ataque do exército A"<< endl;
    double somaDePoder;

    somaDePoder = exercitoA->Attacktotal();
    cout << "Poder de ataque total do Exercito " <<  nomeA << "é" << somaDePoder << endl;
 
}
void Batalha::ataqueExercitoB(string nomeB){
    cout << "Simulação ataque do exército B";
    double somaDePoder;

    somaDePoder = exercitoB->Attacktotal();
    cout << "Poder de ataque total do Exercito " <<  nomeB << "é" << somaDePoder << endl;

}
string Batalha::getResultado(){
    int poderTotalA, poderTotalB;
    string placar;
    poderTotalA = exercitoA->Attacktotal();
    poderTotalB = exercitoB->Attacktotal();
    placar = nomeA + " " + poderTotalA + " x " + poderTotalB + " " + nomeB;
    //cout << nomeA << vitoriasA << "x" << vitoriasB << nomeB << endl;
    cout << placar << endl;
    return placar;
}