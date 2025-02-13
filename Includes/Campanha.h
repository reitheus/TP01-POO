#ifndef CAMPANHA_H
#define CAMPANHA_H

#pragma once
#include <string>
#include <iostream>
#include <charconv>
#include <chrono>
#include <thread>
#include <locale>
#include <cstdlib>
#include <ctime>
//#include <format>
#include <vector>
// #include "../Includes/Unidade.h"
#include "../Includes/Exercito.h"
#include "../Includes/Batalha.h"

using namespace std;

class Campanha
{
    vector <Batalha*> batalhas;
    vector <Exercito*> exercitos;
    
    // Unidade* unidadeMaisDestrutivaA;
    // Unidade* unidadeMaisDestrutivaB;
    

    // int vitoriasA , vitoriasB ;
    // int derrotasA , derrotasB ;
    // int empatesA , empatesB ;
    int numBatalhas;
    
	
public:
    Campanha();
    ~Campanha();
    static void limparTela2(); 
    vector <Exercito*> getExercitos();
    void simularBatalhas();
    void gerarTabelaDePosicoes(bool);
    void mostrarUnidadeMaisDestrutiva();
    void imprimeTodasUnidades();
    
    void setNumBatalhas();

    //nome do Exercito, vitorias, derrotas, empates
    void newExercito(string, int, int , int, int );

    //void setAlgumaCoisa();
    //double getAlgumaCoisa();
    
    //friend Exemplo algumaCoisa(Exemplo&);
};

#endif