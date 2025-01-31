#include "../Includes/Exercito.h"

Exercito::Exercito(string& nomeexercito){
    vitorias = 0;
    derrotas = 0;
    empates = 0;
    nome = nomeexercito;
    
}

Exercito::~Exercito(){

}

void Exercito::adicionarUnidade(Unidade* divisao){
    unidades.push_back(divisao);
}

string Exercito::getResultado(){
    return  "Vitórias: " + to_string(vitorias) + 
            ",Derrotas: " + to_string(derrotas) + 
            ",Empate: " + to_string(empates);
}

void Exercito::imprimeResultado(){

    for(int i = 0;i < unidades.size();i++){
        cout << unidades[i] << endl;
    }
}