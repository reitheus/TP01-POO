#ifndef EXERCITO_H
#define EXERCITO_H

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <thread>
#include "../Includes/Unidade.h"

using namespace std;

class Exercito
{
    string nome;
    int vitorias,derrotas,empates;
    vector<Unidade* > unidades;
public:
    Exercito(string );
    ~Exercito( );
    void adicionarUnidade(Unidade* );
    string getResultado();
    void imprimeUnidades();

    double Attacktotal();

    void setVitorias();
    int getVitorias();

    void setDerrotas();
    int getDerrotas();

    void setEmpates();
    int getEmpates();
    
};

#endif//Exercito.h