#include "../Includes/Campanha.h"

Campanha::Campanha() {
    
    this->numBatalhas = 0;
}

Campanha::~Campanha(){
    //desaloca as batalhas
    for(Batalha* p: batalhas){
        delete p;
    }

    //desalocas os exercitos
    for(Exercito* q: exercitos){
        delete q;
    }
}

void Campanha::limparTela2() {
    #ifdef _WIN32
        system("cls");   // Windows
    #else
        system("clear"); // Linux e macOS
    #endif
}

vector <Exercito*> Campanha::getExercitos(){
    return exercitos;
}

void Campanha::simularBatalhas(){
    setlocale(LC_ALL, "");
    srand(time(0));
    int ano, dia, mes;
    string diaS, mesS;
    string nomeA, nomeB;
    string data;
    string opcao;
    Exercito* exercitoA;
    Exercito* exercitoB;
    int poderAtaqueA, poderAtaqueB;
    ano = rand() % 125 + 1900;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    //Adiciona uma nova batalha ao Vector de batalhas

    limparTela2();
    //Laços que controla as partidas entre os exercitos
    for(long unsigned int i = 0; i < exercitos.size(); i++){//Laço que controla o exercito A
        for(long unsigned int j = 0; j < exercitos.size(); j++){//Laço que controla o exercito B
            ano++;
            if(exercitos[i] != exercitos[j]){//Verifica se os exercitos são diferentes
                //Gera datas aleatorias para a batalhas
                dia = rand() % 30 + 1;
                mes = rand() % 11 + 1;
                if(dia < 10){
                    diaS = "0" + to_string(dia);
                }else{
                    diaS = to_string(dia);
                }
                if(mes < 10){
                    mesS = "0" + to_string(mes);
                }else{
                    mesS = to_string(mes);
                }
                data = diaS + "/" + mesS + "/" + to_string(ano);
                cout << "==============================================" << endl;
                cout << "Batalha número: " << numBatalhas + 1 << endl;
                cout << "Data da batalha ⏳: " << data << endl; 
                //busca os exercitos que vão batalhar no momento
                exercitoA = exercitos[i];
                exercitoB = exercitos[j];
                nomeA = exercitoA->getNome();
                nomeB = exercitoB->getNome();
                batalhas.push_back(new Batalha(exercitoA, exercitoB));//cria uma nova batalha
                batalhas[numBatalhas]->formataData(data);
                
                //executa o ataque dos exercitos
                poderAtaqueA = batalhas[numBatalhas]->ataqueExercitoA();
                poderAtaqueB = batalhas[numBatalhas]->ataqueExercitoB();

                cout << batalhas[numBatalhas]->getResultado() << endl;
                //confere qual exercito ganhou a batalha e da a vitória, derrota ou empate corretamente
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
                numBatalhas++;
                
            } 
            
        }
    }
    cout << "==============================================" << endl;
    cout << "Digite qualquer coisa e aperte ENTER para continuar" << endl;
    cin >> opcao;

}

void Campanha::gerarTabelaDePosicoes(bool existe){
    string opcao;
    Exercito *exercitoTemp;
    vector <Exercito*> exercOrd(exercitos.size());//Exercito Ordenado
    copy(exercitos.begin(), exercitos.end(), exercOrd.begin());

    bool trocado;

    if(numBatalhas <= 0 && existe == false){
        cout << "Execute as batalhas antes de ver quem venceu a campanha!!!" << endl;
        cout << "Digite qualquer coisa e aperte ENTER para continuar" << endl;
        cin >> opcao;
        return;
    }

    for(long unsigned int i = 0; i < exercOrd.size() - 1; i++){
        trocado = false;
        for(long unsigned int j = 0; j < exercOrd.size() - i - 1; j++){

            if(exercOrd[j]->getVitorias() < exercOrd[j+1]->getVitorias()){
                exercitoTemp = exercOrd[j];
                exercOrd[j] = exercOrd[j+1];
                exercOrd[j+1] = exercitoTemp;
                trocado = true;
            }else if(exercOrd[j]->getVitorias() == exercOrd[j+1]->getVitorias()){
                if(exercOrd[j]->Attacktotal() < exercOrd[j+1]->Attacktotal()){
                    exercitoTemp = exercOrd[j];
                    exercOrd[j] = exercOrd[j+1];
                    exercOrd[j+1] = exercitoTemp;
                    trocado = true;
                }
            }
        }
        if (!trocado) break;
    }

    cout << "==============================================" << endl;

    cout << "\n────────────────█████████───────────────" ;
    cout << "\n──────────────█████████████─────────────"  ;
    cout << "\n───────────███████████████████──────────"  ;
    cout << "\n────────────────────────────────────────"  ;
    cout << "\n────────████████████████████████────────"  ;
    cout << "\n────────████████████████████████────────"  ;
    cout << "\n────────────────────────────────────────"  ;
    cout << "\n█████████─████████████████████─█████████"  ;
    cout << "\n█████████─████████████████████─█████████"  ;
    cout << "\n███───────████████────████████───────███"  ;
    cout << "\n███───────██████───██───██████───────███"  ;
    cout << "\n─███──────█████──████────█████──────███─"  ;
    cout << "\n──███─────████─────██─────████─────███──"  ;
    cout << "\n───███────████─────██─────████────███───"  ;
    cout << "\n────███───█████────██────█████───███────"  ;
    cout << "\n─────███──█████────██────█████──███─────"  ;
    cout << "\n──────███─███████──────███████─███──────"  ;
    cout << "\n───────██─████████████████████─██───────"  ;
    cout << "\n────────█─████████████████████─█────────"  ;
    cout << "\n────────────────────────────────────────"  ;
    cout << "\n──────────████████████████████──────────"  ;
    cout << "\n───────────██████████████████───────────"  ;
    cout << "\n─────────────██████████████─────────────"  ;
    cout << "\n───────────────███████████──────────────"  ;
    cout << "\n────────────────────────────────────────"  ;
    cout << "\n────────────────█████████───────────────"  ;
    cout << "\n──────────────█████████████─────────────"  ;

    cout << "\n==============================================" << endl;

    cout << "\n\nTabela de posições dos Exercitos:" << endl;

    for(long unsigned int k = 0; k < exercOrd.size(); k++){
        cout << "==============================================" << endl;
        if(k == 0){
            
            
            cout << k+1 <<"º Lugar exercito: 🏆 " << exercOrd[k]->getNome() << " 🏆" << endl;
            cout << "Vitorias: " << exercOrd[k]->getVitorias() << endl;
            cout << "Derrotas: " << exercOrd[k]->getDerrotas() << endl;
            cout << "Empates:  " << exercOrd[k]->getEmpates() << endl;

        }else{

            cout << k+1 <<"º Lugar exercito: " << exercOrd[k]->getNome() << endl;
            cout << "Vitorias: " << exercOrd[k]->getVitorias() << endl;
            cout << "Derrotas: " << exercOrd[k]->getDerrotas() << endl;
            cout << "Empates:  " << exercOrd[k]->getEmpates() << endl;
        }
    }
    cout << "==============================================" << endl;

    cout << "Digite qualquer coisa e aperte ENTER para continuar" << endl;
    cin >> opcao;

}


void Campanha::mostrarUnidadeMaisDestrutiva(){
    string opcao;
    Unidade *unidadeMaisDestrutiva = NULL;
    vector<Unidade*> unidades;
    string nome;
    int exercitoDono;

    for(long unsigned int i = 0; i < exercitos.size(); i++){
        unidades = exercitos[i]->getUnidades();
        for(Unidade *p: unidades){
            if(unidadeMaisDestrutiva == NULL){
                unidadeMaisDestrutiva = p;
                exercitoDono = i;
            }else if(p->getDestruicoes() > unidadeMaisDestrutiva->getDestruicoes()){
                unidadeMaisDestrutiva = p;
                exercitoDono = i;
            }
        }
    }
    nome = exercitos[exercitoDono]->getNome();
    limparTela2();
    cout << "A unidade mais Destrutiva é do exercito: 💀 " << nome << " 💀" << endl;
    unidadeMaisDestrutiva->imprimiDetalhes();
    
    cout << "Digite qualquer coisa e aperte ENTER para continuar" << endl;
    cin >> opcao;

}

void Campanha::imprimeTodasUnidades(){
    long unsigned int opcao = -1;
    string nome;
    vector<Unidade*> unidades;
    string x;
    limparTela2(); 
    if(numBatalhas == 0){
        cout << "Primeiro Execute as batalhas" << endl;
    }else if(numBatalhas > 0){
        
        //Escolhe qual exercto vai ser utilizado
        while(opcao <= 0 || opcao > exercitos.size()){
            limparTela2();
            cout << "Escolha o exercito que deseja ver as unidades: " << endl;

            //faz o print dos exercitos disponiveis
            for(long unsigned int i = 0; i < exercitos.size(); i++ ){   
                cout << i+1 << " - " << exercitos[i]->getNome() << endl;
            }
            cin >> opcao;

            if(opcao <= 0 || opcao > exercitos.size()){
                limparTela2();
                cout << "Valor inválido!!!" << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(1600));
            }
        }
        opcao--;
        limparTela2(); 
        nome = exercitos[opcao]->getNome();
        unidades = exercitos[opcao]->getUnidades();
        cout << "Unidades do Exercito :" << nome << endl;
        for(Unidade* p: unidades){
            cout << "============================================" << endl;
            p->imprimiDetalhes();
        }
        cout << "============================================" << endl;

    }

    cout << "\nDigite qualquer coisa e aperte ENTER para continuar" << endl;
    cin >> x;
    limparTela2();
}


void Campanha::setNumBatalhas(){
    numBatalhas++;
}

//metodo que adiciona um novo exercito na campanha
//nome do Exercito, vitorias, derrotas, empates, número do exercito
void Campanha::newExercito(string nome, int vitorias, int derrotas, int empates, int i){
    exercitos.push_back(new Exercito(nome, vitorias, derrotas, empates));

    exercitos[i]->adicionarUnidade(new Infantaria());
    exercitos[i]->adicionarUnidade(new Infantaria());
    exercitos[i]->adicionarUnidade(new Veiculo());
    exercitos[i]->adicionarUnidade(new Veiculo());
    exercitos[i]->adicionarUnidade(new Aeronave());
}

