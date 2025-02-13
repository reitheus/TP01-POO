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
    string nomeA, nomeB;
	int resultadoA, resultadoB;
public:
    Batalha(Exercito* , Exercito* );
    ~Batalha( );

    void formataData(string );

    void imprimeTodasUnidades();

    double ataqueExercitoA( );
    double ataqueExercitoB( );
    string getResultado();

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