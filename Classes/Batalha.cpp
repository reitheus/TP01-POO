#include "../Includes/Batalha.h"

Batalha::Batalha(string nomeA, string nomeB) {
    this->nomeA = nomeA;
    this->nomeB = nomeB;
    exercitoA = new Exercito(nomeA);
    exercitoB = new Exercito(nomeB);
    data = new Date();

}

Batalha::~Batalha(){
    delete exercitoA;
    delete exercitoB;
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


double Batalha::ataqueExercitoA(string nomeA){
    cout << "Simulação ataque do exército A "<< endl;
    double somaDePoder;

    exercitoA->adicionarUnidade(new Infantaria());
    exercitoA->adicionarUnidade(new Infantaria());
    exercitoA->adicionarUnidade(new Veiculo());
    exercitoA->adicionarUnidade(new Veiculo());
    exercitoA->adicionarUnidade(new Aeronave());

    somaDePoder = exercitoA->Attacktotal();
    cout << "Poder de ataque total do Exercito " <<  nomeA << " é " << somaDePoder << endl;
    return somaDePoder;
}
double Batalha::ataqueExercitoB(string nomeB){
    cout << "Simulação ataque do exército B " << endl;
    double somaDePoder;

    exercitoB->adicionarUnidade(new Infantaria());
    exercitoB->adicionarUnidade(new Infantaria());
    exercitoB->adicionarUnidade(new Veiculo());
    exercitoB->adicionarUnidade(new Veiculo());
    exercitoB->adicionarUnidade(new Aeronave());

    somaDePoder = exercitoB->Attacktotal();
    cout << "Poder de ataque total do Exercito " <<  nomeB << " é " << somaDePoder << endl;
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