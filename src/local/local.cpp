#include "local.h"

using namespace std;

void Local :: setSigla(string sigla){
    this->sigla = sigla;
}

void Local :: setInsumo(Insumo *insumo){
    insumos.push_back(insumo);
}


string Local :: getSigla(){
    return this->sigla;
}

vector <Insumo *> Local :: getInsumos(){
    return this->insumos;
}