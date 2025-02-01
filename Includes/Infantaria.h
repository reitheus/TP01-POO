// Definição de Biblioteca para classe Infantaria 

#ifndef INFANTARIA_H
#define INFANTARIA_H

#include "../Includes/Unidade.h"

class Infantaria : public Unidade {
private:
    int forca;
    int velocidade;

public:
    Infantaria();
    int getPoderAtaque();
};

#endif
