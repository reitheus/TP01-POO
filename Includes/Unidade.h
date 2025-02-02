#ifndef UNIDADE_H
#define UNIDADE_H

#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Unidade
{
protected: 
    int poderAtaque, Destruicoes;

public:
    Unidade(int poderAtaque = 0, int Destruicoes = 0); 
    virtual int getPoderAtaque();
    virtual void imprimiDetalhes();
    int somaDestruicao();
};

#endif//Unidade.h
