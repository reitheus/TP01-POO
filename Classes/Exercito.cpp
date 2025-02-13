#include "../Includes/Exercito.h"

Exercito::Exercito(string nomeExercito, int vitorias, int derrotas, int empates){
    this->vitorias = vitorias;
    this->derrotas = derrotas;
    this->empates = empates;
    nome = nomeExercito;
    
}

Exercito::~Exercito(){

    //desaloca as Unidades
    for(Unidade* p: unidades){
        delete p;
    }

}

void Exercito::adicionarUnidade(Unidade* divisao){
  unidades.push_back(divisao);
}

// string Exercito::getResultado(){
//     return  "Vitórias: " + to_string(vitorias) + 
//             ",Derrotas: " + to_string(derrotas) + 
//             ",Empate: " + to_string(empates);
// }

void Exercito::imprimeUnidades(){

    // for(int i = 0;i < unidades.size();i++){
    //     cout << unidades[i] << endl;
    // }

    for (const auto& p : unidades) {
        p->imprimiDetalhes();
    }

}

double Exercito::Attacktotal(){
    double soma = 0;
    for(Unidade* p: unidades){
        soma += p->getPoderAtaque();
    }
    return soma;
}

string Exercito::getNome()const{

    return nome;
}


vector<Unidade* > Exercito::getUnidades()const{

    return unidades;
}

void Exercito::setDestruicoes(int destruicoes){

    this->destruicoes = destruicoes;


}

void Exercito::setVitorias(){
    vitorias++;
}
int Exercito::getVitorias(){
    return vitorias;
}
void Exercito::setDerrotas(){
    derrotas++;
}
int Exercito::getDerrotas(){
    return derrotas;
}
void Exercito::setEmpates(){
    empates++;
}
int Exercito::getEmpates(){
    return empates;
}
