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
    double poderAtaque;
    int destruicoes;

public:
    Unidade();
    virtual ~Unidade(); 
    virtual int getPoderAtaque();
    int getDestruicoes();
    virtual void imprimiDetalhes();
    void somaDestruicao();

};

#endif//Unidade.h
