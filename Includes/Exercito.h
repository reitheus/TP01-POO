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
    int destruicoes;
    int vitorias,derrotas,empates;
    vector<Unidade* > unidades;
public:
    Exercito(string , int, int, int);
    ~Exercito( );
    void adicionarUnidade(Unidade* );
    string getResultado();
    void imprimeUnidades();

    double Attacktotal();

    //retorna um ponteiro para o vector Unidades
    vector<Unidade* > getUnidades()const;
    void setDestruicoes(int);

    string getNome()const;

    void setVitorias();
    int getVitorias();

    void setDerrotas();
    int getDerrotas();

    void setEmpates();
    int getEmpates();
    
};

#endif//Exercito.h