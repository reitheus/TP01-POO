#include "../Includes/Campanha.h"
#include "../Includes/Batalha.h"

Campanha::Campanha(nomeA, nomeB ) {
    this->nomeA = nomeA;
    this->nomeB = nomeB;
    this->numBatalhas = 0;
    this->vitoriasA = 0;
    this->vitoriasB = 0;
    this->derrotasA = 0;
    this->derrotasB = 0;
    this->empatesA = 0;
    this->empatesB = 0;
    
}

Campanha::~Campanha(){
    

}

void Campanha::simularBatalhas(){
    
    int poderAtaqueA, poderAtaqueB;

    //Adiciona uma nova batalha ao Vector de batalhas
    batalhas.push_back(new Batalha(nomeA, nomeB));

    //calcular o poder de batalha de cada exercito
    poderAtaqueA = batalhas[numBatalhas]->ataqueExercitoA();
    poderAtaqueB = batalhas[numBatalhas]->ataqueExercitoB();

    //confere qual exercito ganhou a batalha e da a vitória, derroa ou empate corretamente
    if(poderAtaqueA > poderAtaqueB){
        cout << "Vitoria do exército:" << nomeA << endl;
        batalhas[numBatalhas]->setVitoriasDoExercitoA();
    }else if (poderAtaqueA < poderAtaqueB){
        cout << "Vitoria do exército:" << nomeB << endl;
        batalhas[numBatalhas]->setVitoriasDoExercitoB();
    }else{
        cout << "Empate entre os exercitos" << endl;
        batalhas[numBatalhas]->setEmpateDosExercitos();
    }


}
void Campanha::gerarTabelaDePosicoes(){

    int i = 0;

    while(i < batalhas.size()){
        vitoriasA += batalhas[i].getVitoriasA();
        vitoriasB += batalhas[i].getVitoriasB();

        derrotasA += batalhas[i].getDerrotasA();
        derrotasB += batalhas[i].getDerrotasB();

        empatesA += batalhas[i].getEmpatesA();
        empatesB += batalhas[i].getEmpatesB();
    }

    cout << "Exercito: " << nomeA << endl;
    cout << "Vitórias: " << vitoriasA << endl;
    cout << "Derrotas: " << derrotasA << endl;
    cout << "Empates:  " << empatesA << endl;

    cout << "Exercito: " << nomeB << endl;
    cout << "Vitórias: " << vitoriasB << endl;
    cout << "Derrotas: " << derrotasB << endl;
    cout << "Empates:  " << empatesB << endl;

}
void Campanha::mostrarUnidadeMaisDestrutiva(){
    

    if(){


        
    }

}

void setNumBatalhas(){
    numBatalhas++;
}

void Campanha::setVDE(int vitoriasA, int vitoriasB, int derrotasA, int derrotasB, int empatesA, int empatesB){
    this->vitoriasA = vitoriasA;
    this->vitoriasB = vitoriasB;
    this->derrotasA = derrotasA;
    this->derrotasB = derrotasB;
    this->empatesA = empatesA;
    this->empatesB = empatesB;

}

string Campanha::getNomeA(){

    return this->nomeA;

}
string Campanha::getNomeB(){

    return this->nomeB;

}

int Batalha::getVitoriasA(){
    this->vitoriasA;

}

int Batalha::getVitoriasB(){
   this->vitoriasB;

}

int Batalha::getDerrotasA(){
   this->derrotasA;

}

int Batalha::getDerrotasB(){
   this->derrotasB;

}

int Batalha::getEmpatesA(){
    this->empatesA;
    

}

int Batalha::getEmpatesB(){
    this->empatesB;
}

