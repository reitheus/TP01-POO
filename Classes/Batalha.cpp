#include "../Includes/Batalha.h"

Batalha::Batalha(Exercito* exercito1, Exercito* exercito2) {
    exercitoA = exercito1;
    exercitoB = exercito2;
    data = new Date();
}

Batalha::~Batalha(){
    
    delete data;

}

void Batalha::formataData(string dat){
    data->formatDate(dat);
}


void Batalha::imprimeTodasUnidades(){
    cout << "Unidades do Exercito: " << nomeA << endl  << endl;
    exercitoA->imprimeUnidades();
    cout << "\nUnidades do Exercito:" << nomeB << endl << endl;
    exercitoB->imprimeUnidades();
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
    return exercitoA->getVitorias();
}

int Batalha::getVitoriasB(){
   return exercitoB->getVitorias();
}

int Batalha::getDerrotasA(){
   return exercitoA->getDerrotas();
}

int Batalha::getDerrotasB(){
   return exercitoB->getDerrotas();
}

int Batalha::getEmpatesA(){
    return exercitoA->getEmpates();
}

int Batalha::getEmpatesB(){
    return exercitoB->getEmpates();
}

double Batalha::ataqueExercitoA(){
    string nomeA, nomeB;
    //cout << "Simulação ataque do exército A "<< endl;
    double somaDePoder;
    int quantidadeDestruicoes = 0;
    vector<Unidade*> unidadesA;
    vector<Unidade*> unidadesB;

    nomeA = exercitoA->getNome();
    nomeB = exercitoB->getNome();

    unidadesA = exercitoA->getUnidades();
    unidadesB = exercitoB->getUnidades();

    for(long unsigned int i = 0; i < unidadesA.size(); i++){
    
        if(unidadesA[i]->getPoderAtaque() > unidadesB[i]->getPoderAtaque()){
            unidadesA[i]->somaDestruicao();
            quantidadeDestruicoes++;  
        }
        
    }
   
    exercitoA->setDestruicoes(quantidadeDestruicoes);

    somaDePoder = exercitoA->Attacktotal();
    return somaDePoder;
}
double Batalha::ataqueExercitoB(){
    string nomeA, nomeB;
    //cout << "Simulação ataque do exército B "<< endl;
    double somaDePoder;
    int quantidadeDestruicoes = 0;
    vector<Unidade*> unidadesA;
    vector<Unidade*> unidadesB;

    nomeA = exercitoA->getNome();
    nomeB = exercitoB->getNome();
    unidadesA = exercitoA->getUnidades();
    unidadesB = exercitoB->getUnidades();

    for(long unsigned int i = 0; i < unidadesB.size(); i++){
    
        if(unidadesB[i]->getPoderAtaque() > unidadesA[i]->getPoderAtaque()){
            unidadesB[i]->somaDestruicao();
            quantidadeDestruicoes++;
        }
    }
    exercitoB->setDestruicoes(quantidadeDestruicoes);

    somaDePoder = exercitoB->Attacktotal();
    return somaDePoder;
}

// string Batalha::getResultado(){
//     int poderTotalA, poderTotalB;
//     string placar;
//     poderTotalA = exercitoA->Attacktotal();
//     poderTotalB = exercitoB->Attacktotal();
//     placar = nomeA + " " + poderTotalA + " x " + poderTotalB + " " + nomeB;
//     //cout << nomeA << vitoriasA << "x" << vitoriasB << nomeB << endl;
//     cout << placar << endl;
//     return placar;
// }