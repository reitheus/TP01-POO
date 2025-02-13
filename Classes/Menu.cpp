#include "../Includes/Menu.h"

Menu::Menu() {
   
}

Menu::~Menu(){

}

//metodo que limpa o terminal
void Menu::limparTela() {
    #ifdef _WIN32
        system("cls");   // Windows
    #else
        system("clear"); // Linux e macOS
    #endif
}

//Metodo que salva a campanha atual
void Menu::salvarCampanha(Campanha* pCampanha){
    int opcao = 0;
    string nomeDaCampanha;
    vector <Exercito*> exercitos;
    cout << "-- AVISO!!! --" << endl;
    cout << "Jogos não salvos serão perdidos ao retornar para o menu" << endl;
    exercitos = pCampanha->getExercitos();
    while(opcao != 1 && opcao != 2){
        cout << "Deseja salvar campanha atual?" << endl;
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

            arqv << exercitos.size() << endl;

            for(long unsigned int k = 0; k < exercitos.size(); k++){
                arqv << exercitos[k]->getNome() << endl;
                arqv << exercitos[k]->getVitorias() << endl;
                arqv << exercitos[k]->getDerrotas() << endl;
                arqv << exercitos[k]->getEmpates() << endl;
            }
            arqv.close();
        }else if(opcao == 2){
            cout << "O jogo não será salvo"<< endl;
        }else{
            cout << "Comando inválido"<< endl;
        }
    }
}

//metodo que carrega uma campanha salva
Campanha* Menu::carregarCampanha(){
    string nomeCampanha;
    string quant, nome, vitorias, derrotas, empates;
    int quantExercitos;
    int  v, d, e;
    pCampanha = new Campanha();
    cout << "Digite o nome da Campanha salva" << endl;
    cout << "Exemplo: 'campanha1' " << endl;
    cout << "OBS: NÃO inclua a extensão " << endl;
    cin >> nomeCampanha;
    nomeCampanha = nomeCampanha + ".txt";

    ifstream arqv;
    arqv.open(nomeCampanha);//Abre o arquivo para leitura
    if(arqv.is_open()){

        getline(arqv, quant);
        quantExercitos = stoi(quant);

        //Le os dados do arquivo
        for(int i = 0; i < quantExercitos; i++){
            getline(arqv, nome);
            getline(arqv, vitorias);
            getline(arqv, derrotas);
            getline(arqv, empates);
            v = stoi(vitorias);
            d = stoi(derrotas);
            e = stoi(empates);
            //inseri um novo exercito passando o nome, vitorias, derrotas, empates e o numero do exercito
            pCampanha->newExercito(nome, v, d, e, i);

        }
    }else{
        cout << "Erro ao abrir arquivo";
    }
    
    return pCampanha;
}

void Menu::campanhaAtual(Campanha* pCampanha,bool existe){
    //std::this_thread::sleep_for(std::chrono::seconds(1));
    limparTela();
    string nome;
    
    int quantExercitos = -1;
    if(existe == false){
        while(quantExercitos <= 1 || quantExercitos > 200){
            cout << "==============================================" << endl;
            cout << "Digite a quantidade de Exercitos participantes" << endl;
            cout << "É obrigatorio no minimo 2 exercitos" << endl;
            cout << "==============================================" << endl;
            cin >> quantExercitos;
            if(quantExercitos <= 1 || quantExercitos > 200){
                cout << "⚠️ Quantidade inválida de exercítos ⚠️" << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(800));
                limparTela();
            }
        }
        limparTela();
        int i = 0;
        while(i < quantExercitos){
            cout << "==============================================" << endl;
            cout << "Digite o nome do Exercito " << i + 1 << endl;
            cin >> nome;
            pCampanha->newExercito(nome, 0, 0, 0, i);
            i++;
        }
    }

    int opcao = -1;//inicializa a opção
    while(opcao != 5){//Loop do menu de batalhas
        limparTela();

        cout << "Simulador de guerras" << endl;
        //cout << "Campanha em andamento" << endl;
        //cout << "Selecione uma das opções:" << endl;
        cout << "==============================================" << endl;
        cout << " 1 - Simular batalhas 🕹️" << endl;
        cout << " 2 - Gerar tabela de posições 📊" << endl;
        cout << " 3 - Mostrar unidade mais destrutiva 💀" << endl;
        cout << " 4 - Imprimir todas as unidades dos Exercitos 🎯" << endl;
        cout << " 5 - Voltar ao menu 🏠" << endl;
        cout << "==============================================" << endl;

        cin >> opcao;
        switch (opcao){
            case 1:
                limparTela();
                cout << "Simulando batalha..." << endl;
                pCampanha->simularBatalhas();
                limparTela();
                break;
            case 2:
                limparTela();
                cout << "Gerando tabela de posições" << endl;
                std::this_thread::sleep_for(std::chrono::seconds(1));
                pCampanha->gerarTabelaDePosicoes(existe);
                break;
            case 3:
                limparTela();
                cout << "Mostrando unidade mais destruitiva" << endl;
                std::this_thread::sleep_for(std::chrono::seconds(1));
                pCampanha->mostrarUnidadeMaisDestrutiva();
                break;
            case 4:
                limparTela();
                cout << "Imprimindo todas as unidades dos Exercitos" << endl;
                pCampanha->imprimeTodasUnidades();
                break;
            case 5:
                limparTela();
                cout << "Voltando para o menu" << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(600));
                break;
            default:
                limparTela();
                cout << "❌ ERRO: Comando inválido ❌" << endl;
                std::this_thread::sleep_for(std::chrono::seconds(1));
            break;
        }//fim switch

    }//fim while

}

void Menu::telaMenu(){
    setlocale(LC_ALL, "");
    Menu menu;
    int opcao = -1;
    string nomeA, nomeB;
    bool existe;

    limparTela();
    while(opcao != 3){//loop do menu principal
        limparTela();
        //cout << " Simulador de guerras" << endl;
        cout << "                  Menu" << endl;
        //cout << "Selecione uma das opções:" << endl;
        cout << "============================================" << endl;
        cout << " 1 - Iniciar uma nova campanha 🕹️" << endl;
        cout << " 2 - Ler jogo salvo 📜" << endl;
        cout << " 3 - Sair do Menu 🏠" << endl;
        cout << "============================================" << endl;
        cin >> opcao;
        switch (opcao){
            case 1:
                existe = false;
                limparTela();
                cout << "Iniciando nova campanha ... Bom jogo ..." << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(900));
                limparTela();
                pCampanha = new Campanha();
                menu.campanhaAtual(pCampanha, existe);
                std::this_thread::sleep_for(std::chrono::milliseconds(500));
                menu.salvarCampanha(pCampanha);
                delete pCampanha;
                break;
            case 2:
                limparTela();
                existe = true;
                cout << "Carregando Campanha..." << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(600));
                pCampanha = carregarCampanha();
                menu.campanhaAtual(pCampanha, existe);
                menu.salvarCampanha(pCampanha);
                delete pCampanha;
                break;
            case 3:
                limparTela();
                cout << "👋 Fechando Jogo..." << endl;
                std::this_thread::sleep_for(std::chrono::seconds(1));
                break;
            default:
                limparTela();
                cout << "❌ ERRO: Comando inválido!!! ❌" << endl;
                std::this_thread::sleep_for(std::chrono::seconds(1));
                opcao = -1;
                break;

        }//Fim do Switch case
    }//Fim do While
}
