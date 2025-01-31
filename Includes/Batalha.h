#ifndef BATALHA_H
#define BATALHA_H

#pragma once
#include <string>
#include <iostream>
#include <charconv>
//#include <format>
#include <vector>
#include "../Includes/Exercito.h"
#include "../Includes/Date.h"

using namespace std;

class Batalha
{
    Date data;
    Exercito *exercitoA;
    Exercito *exercitoB;
	int resultadoA, resultadoB;
public:
    Batalha(string nomeA, string nomeB);
    ~Batalha( );

    void ataqueExercitoA(string nomeA);
    void ataqueExercitoB(string nomeB);
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