#ifndef CAMPANHA_H
#define CAMPANHA_H

#pragma once
#include <string>
#include <iostream>
#include <charconv>
//#include <format>
#include <vector>
#include "../include/Unidade.h"
#include "../include/Batalha.h"

using namespace std;

class Campanha
{
    vector <Batalha*> batalhas;
    string nomeA, nomeB;
    Unidade* unidadeMaisDestrutivaA;
    Unidade* unidadeMaisDestrutivaB;

    int vitoriasA , vitoriasB ;
    int derrotasA , derrotasB ;
    int empatesA , empatesB ;
    int numBatalhas;
    
	
public:
    Campanha(string nomeA, string nomeB);
    ~Campanha( );
    
    void simularBatalhas();
    void gerarTabelaDePosicoes();
    void mostrarUnidadeMaisDestrutiva();
    

    void setVDE();

    string getNomeA();
    string getNomeB();

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