#include "../Includes/Campanha.h"

Campanha::Campanha(string nomeA,string nomeB ) {
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
    for(Batalha* p: batalhas){
        delete p;
    }

}

void Campanha::limparTela2() {
    #ifdef _WIN32
        system("cls");   // Windows
    #else
        system("clear"); // Linux e macOS
    #endif
}

void Campanha::simularBatalhas(){
    
    string data;
    string opcao;
    int poderAtaqueA, poderAtaqueB;
    cout << numBatalhas << endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    //Adiciona uma nova batalha ao Vector de batalhas
    batalhas.push_back(new Batalha(nomeA, nomeB));

    cout << "Digite a data da batalha" << endl;
    cout << "Digite no formato DD/MM/AAAA" << endl;
    //cin >> data;
    data = "00/00/0000";

    limparTela2(); 

    batalhas[numBatalhas]->formataData(data);

    //calcular o poder de batalha de cada exercito
    poderAtaqueA = batalhas[numBatalhas]->ataqueExercitoA(nomeA);
    poderAtaqueB = batalhas[numBatalhas]->ataqueExercitoB(nomeB);
    cout << "poderA" << poderAtaqueA << endl;
    cout << "poderB" << poderAtaqueB << endl;
    
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    limparTela2(); 

    //confere qual exercito ganhou a batalha e da a vitória, derrota ou empate corretamente
    if(poderAtaqueA > poderAtaqueB){
        cout << "Vitoria do exército:" << nomeA << endl;
        batalhas[numBatalhas]->setVitoriasDoExercitoA();
        vitoriasA++;
        derrotasB++;
    }else if (poderAtaqueA < poderAtaqueB){
        cout << "Vitoria do exército:" << nomeB << endl;
        batalhas[numBatalhas]->setVitoriasDoExercitoB();
        vitoriasB++;
        derrotasA++;
    }else{
        empatesA++;
        empatesB++;
        cout << "Empate entre os exercitos" << endl;
        batalhas[numBatalhas]->setEmpateDosExercitos();
    }
    numBatalhas++;
    cout << "Digite qualquer coisa e aperte ENTER para continuar" << endl;
    cin >> opcao;

}


void Campanha::gerarTabelaDePosicoes(){
    string opcao;
   
    cout << "Exercito: " << nomeA << endl;
    cout << "Vitórias: " << vitoriasA << endl;
    cout << "Derrotas: " << derrotasA << endl;
    cout << "Empates:  " << empatesA << endl;

    cout << "Exercito: " << nomeB << endl;
    cout << "Vitórias: " << vitoriasB << endl;
    cout << "Derrotas: " << derrotasB << endl;
    cout << "Empates:  " << empatesB << endl;

    cout << "Digite qualquer coisa e aperte ENTER para continuar" << endl;
    cin >> opcao;

}


// void Campanha::mostrarUnidadeMaisDestrutiva(){
    

//     if(){


        
//     }

// }

void Campanha::imprimeTodasUnidades(){
    int opcao = -1;
    string x;
    limparTela2(); 
    if(numBatalhas == 0){
        cout << "Primeiro Execute uma batalha" << endl;
    }else if(numBatalhas > 0){


        while(opcao < 1 || opcao > numBatalhas){

            limparTela2(); 

            cout << "Escolha a batalha que gostaria de imprimir as unidades" << endl;
            cout << "Esolha uma batalha até o número " << numBatalhas << endl;
            cin >> opcao;

            if(opcao < 1 || opcao > numBatalhas){
                limparTela2();
                cout << "Número invalido" << endl;
                std::this_thread::sleep_for(std::chrono::seconds(1));
            }
        }
        limparTela2();
        batalhas[opcao - 1]->imprimeTodasUnidades();
    }

    cout << "\nDigite qualquer coisa e aperte ENTER para continuar" << endl;
    cin >> x;


}


void Campanha::setNumBatalhas(){
    numBatalhas++;
}

// void Campanha::setVDE(int vitoriasA, int vitoriasB, int derrotasA, int derrotasB, int empatesA, int empatesB){
//     this->vitoriasA = vitoriasA;
//     this->vitoriasB = vitoriasB;
//     this->derrotasA = derrotasA;
//     this->derrotasB = derrotasB;
//     this->empatesA = empatesA;
//     this->empatesB = empatesB;

// }

// string Campanha::getNomeA(){

//     return this->nomeA;

// }
// string Campanha::getNomeB(){

//     return this->nomeB;

// }

// int Campanha::getVitoriasA(){
//     this->vitoriasA;

// }

// int Campanha::getVitoriasB(){
//    this->vitoriasB;

// }

// int Campanha::getDerrotasA(){
//    this->derrotasA;

// }

// int Campanha::getDerrotasB(){
//    this->derrotasB;

// }

// int Campanha::getEmpatesA(){
//     this->empatesA;
    

// }

// int Campanha::getEmpatesB(){
//     this->empatesB;
// }

