#ifndef EXERCITO_H
#define EXERCITO_H

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Unidade.h"

using namespace std;

class Exercito
{
    string nome;
    int vitorias,derrotas,empates;
    vector<Unidade* > unidades;
public:
    Exercito(string& );
    ~Exercito( );
    void adicionarUnidade(Unidade* );
    string getResultado();
    void imprimeResultado();
};

#endif//Exercito.h