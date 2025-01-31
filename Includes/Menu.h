#ifndef MENU_H
#define MENU_H

#pragma once
#include <string>
#include <iostream>
#include <charconv>
//#include <format>
#include <vector>
#include <fstream>
#include <chrono>
#include <thread>
#include "../Includes/Campanha.h"

using namespace std;

class Menu
{
    Campanha *pCampanha;
	
public:
    Menu(  );
    ~Menu( );
    static void limparTela();
    void telaMenu();
    
    Campanha* carregarCampanha();
    void salvarCampanha(Campanha*);
   
    void campanhaAtual(Campanha*);


    //void setAlgumaCoisa();
    //double getAlgumaCoisa();
    
    //friend Exemplo algumaCoisa(Exemplo&);
};

#endif