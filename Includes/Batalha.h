#ifndef BATALHA_H
#define BATALHA_H

#pragma once
#include <string>
#include <iostream>
#include <charconv>
#include <chrono>
#include <thread>
//#include <format>
#include <vector>
#include "../Includes/Exercito.h"
#include "../Includes/Date.h"
#include "../Includes/Unidade.h"
#include "../Includes/Aeronave.h"
#include "../Includes/Infantaria.h"
#include "../Includes/Veiculo.h"


using namespace std;

class Batalha
{
    Date *data;
    Exercito *exercitoA;
    Exercito *exercitoB;
	int resultadoA, resultadoB;
public:
    Batalha(string nomeA, string nomeB);
    ~Batalha( );

    void formataData(string );

    double ataqueExercitoA(string );
    double ataqueExercitoB(string );
    string getResultado(string nomeA, string nomeB);

    void setVitoriasDoExercitoA();
    void setVitoriasDoExercitoB();
    void setEmpateDosExercitos();

    int getVitoriasA();
    int getVitoriasB();

    int getDerrotasA();
    int getDerrotasB();

    int getEmpatesA();
    int getEmpatesB();
  
    //void setAlgumaCoisa();
    //double getAlgumaCoisa();
    
    //friend Exemplo algumaCoisa(Exemplo&);
};

#endif