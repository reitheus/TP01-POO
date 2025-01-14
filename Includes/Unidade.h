#ifndef UNIDADE_H
#define UNIDADE_H

#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Unidade : public Exercito{
    
    int poderAtaque, Destruicoes;

public:
    int getPoderAtaque();
    int somaDestruicao();
};

#endif//Unidade.h