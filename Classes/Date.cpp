#include "../Includes/Date.h"

Date::Date(){



}

Date::~Date(){


    
}


void Date::formatDate(string data){

    dia = stoi(data.substr(0, 2));  // Pega os 2 primeiros caracteres (dia)
    mes = stoi(data.substr(3, 2));  // Pega os 2 do meio (mês)
    ano = stoi(data.substr(6, 4));  // Pega os 4 últimos (ano)

}