#include "../include/Menu.h"

Menu::Menu() {
   
}

Menu::~Menu(){


}

static void limparTela() {
    #ifdef _WIN32
        system("cls");   // Windows
    #else
        system("clear"); // Linux e macOS
    #endif
}

void Menu::salvarCampanha(Campanha* pCampanha){
    int opcao = 0;
    string nomeDaCampanha;
    cout << "-- AVISO!!! --" << endl;
    cout << "Jogos não salvos serão perdidos ao retornar para o menu" << endl;
   

    while(opcao != 1 || opcao != 2){
        cout << "Deseja salvar campanha atual?" << endl;
        pCampanha->gerarTabelaDePosicoes();
        cout << "1 - Salvar campanha" << endl;
        cout << "2 - Não salvar campanha" << endl;
        cin >> opcao;

        if(opcao == 1){
            cout << "O jogo será salvo"<< endl;
            cout << "Deseja salvar a campanha com qual nome?"<< endl;
            cout << "OBS: NÃO inclua a extensão " << endl;
            cin >> nomeDaCampanha;
            nomeDaCampanha = nomeDaCampanha + ".txt";
            ofstream arqv;
            arqv.open(nomeDaCampanha, ios::out);
            arqv << pCampanha->getNomeA() << endl;
            arqv << pCampanha->getVitoriasA() << endl;
            arqv << pCampanha->getDerrotasA() << endl;
            arqv << pCampanha->getEmpatesA() << endl;

            arqv << pCampanha->getNomeB() << endl;
            arqv << pCampanha->getVitoriasB() << endl;
            arqv << pCampanha->getDerrotasB() << endl;
            arqv << pCampanha->getEmpatesB() << endl;

            arqv.close();

        }else if(opcao == 2){
            cout << "O jogo não será salvo"<< endl;
        }else{
            cout << "Comando inválido"<< endl;
        }
    }
}

Campanha* Menu::carregarCampanha(){
    string nomeCampanha;
    string nomeA, nomeB;
    string vitoriasA, derrotasA, empatesA;
    string vitoriasB, derrotasB, empatesB;
    int vA, dA, eA, vB, dB, eB;
    cout << "Digite o nome da Campanha salva" << endl;
    cout << "Exemplo: 'campanha1' " << endl;
    cout << "OBS: NÃO inclua a extensão " << endl;
    cin >> nomeCampanha;
    nomeCampanha = nomeCampanha + ".txt"

    ifstream arqv;
    arqv.open(nomecampanha);//Abre o arquivo para leitura
    if(arqv.is_open()){
        getline(arqv, nomeA);
        getline(arqv, vitoriasA);
        getline(arqv, derrotasA);
        getline(arqv, empatesA);
        getline(arqv, nomeB);
        getline(arqv, vitoriasB);
        getline(arqv, derrotasB);
        getline(arqv, empatesB);
        vA = stoi(vitoriasA);
        dA = stoi(derrotasA);
        eA = stoi(empatesA);
        vB = stoi(vitoriasB);
        dB = stoi(derrotasB);
        eB = stoi(empatesB)

    }else{
        cout << "Erro ao abrir arquivo";
    }
    pCampanha = new Campanha(nomeA, nomeB);
    pCampanha->setVDE(vA, vB, dA, dB, eA, eB);
    return pCampanha;
}

void Menu::campanhaAtual(Campanha* pCampanha){
    //std::this_thread::sleep_for(std::chrono::seconds(1.5));
    limparTela();
    cout << "Campanha iniciada" << endl;
    std::this_thread::sleep_for(std::chrono::seconds(1.5));
    limparTela();
    int opcao = -1;//inicializa a opção
    while(opcao != 4){

        cout << "Simulador de guerras" << endl;
        cout << "Campanha em andamento" << endl;
        cout << "Selecione uma das opções:" << endl;
        cout << "1 - Simular batalhas" << endl;
        cout << "2 - Gerar tabela de posições" << endl;
        cout << "3 - Mostrar unidade mais destrutiva" << endl;
        cout << "4 - Voltar ao menu" << endl;
        cin >> opcao;
        switch (opcao){
            case 1:
                pCampanha->simularBatalhas();
                pCampanha->setNumBatalhas();
                break;
            case 2:
                pCampanha->gerarTabelaDePosicoes();
                break;
            case 3:
                pCampanha->mostrarUnidadeMaisDestrutiva();
                break;
            case 4:
                cout << "Voltando para o menu" << endl;
                break;
            default:
                cout << "Comando inválido" << endl;
            break;
        }

    }

}

void Menu::telaMenu(){
    Menu menu;
    int opcao = -1;
    string nomeA, nomeB;


    
    limparTela();
    while(opcao != 3){
        limparTela();
        cout << "Simulador de guerras" << endl;
        cout << "Menu" << endl;
        cout << "Selecione uma das opções:" << endl;
        cout << "1 - Iniciar uma nova campanha" << endl;
        cout << "2 - Continuar uma campanha" << endl;
        cout << "3 - Sair do Menu" << endl;
        cin >> opcao;
        switch (opcao){
            case 1:

                limparTela();
                cout << "Iniciando nova campanha ... Bom jogo ..." << endl;
                std::this_thread::sleep_for(std::chrono::seconds(1.5));
                limparTela();
                cout << "Digite o nome do Exército A" << endl;
                cin >> nomeA;
                cout << "Digite o nome do Exército B" << endl;
                cin >> nomeB;
                
                pCampanha = new Campanha(nomeA, nomeB);

                menu.campanhaAtual(pCampanha);
                menu.salvarCampanha(Campanha*);

                delete pCampanha;

                break;
            case 2:
                cout << "Carregar Campanha" << endl;
                pCampanha = carregarCampanha();

                menu.campanhaAtual(pCampanha);
                menu.salvarCampanha(Campanha);
                delete pCampanha;
                break;
            case 3:
                cout << "Fechando Jogo" << endl;
                break;
            default:
                cout << "Comando inválido" << endl;
            break;

        }//Fim do Switch case
    }//Fim do While
}