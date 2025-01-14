#include "..\Includes/Exercito.h"

Exercito::Exercito(string &nome){
    vitorias = 0;
    derrotas = 0;
    empates = 0;
    this->nome = nome;
}

Exercito::~Exercito(){

}

void Exercito::adicionarUnidades(Unidade* ){
    unidades.push_back();
}

string Exercito::getResultado(){
    return  "Vitórias: " + to_string(vitorias) + 
            ",Derrotas: " + to_string(derrotas) + 
            ",Empate: " + to_string(empates);
}

void Exercito::imprimeResultado(){
    for(int i=0;i < unidades.size();i++){

    }
}