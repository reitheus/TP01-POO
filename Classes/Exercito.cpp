#include "../Includes/Exercito.h"

Exercito::Exercito(string nomeexercito){
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

// string Exercito::getResultado(){
//     return  "Vitórias: " + to_string(vitorias) + 
//             ",Derrotas: " + to_string(derrotas) + 
//             ",Empate: " + to_string(empates);
// }

// void Exercito::imprimeResultado(){

//     for(int i = 0;i < unidades.size();i++){
//         cout << unidades[i] << endl;
//     }
// }

double Exercito::Attacktotal(){
    double soma = 0;
    for(Unidade* p: unidades){
        soma += p->getPoderAtaque();
    }
    return soma;
}


void Exercito::setVitorias(){
    vitorias++;
}
// int Exercito::getVitorias(){
//     return vitorias;
// }
void Exercito::setDerrotas(){
    derrotas++;
}
// int Exercito::getDerrotas(){
//     return derrotas;
// }
void Exercito::setEmpates(){
    empates++;
}
// int Exercito::getEmpates(){
//     return empates;
// }
