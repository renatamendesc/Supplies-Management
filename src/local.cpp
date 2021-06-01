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

void Local :: recadastraInsumo(int iInsumo){

    this->insumos[iInsumo]->cadastraAtributos();
}

void Local :: apagarInsumo(int iInsumo){

    this->insumos.erase(this->insumos.begin() + iInsumo);

}

void Local :: apagarTodosInsumos(){

    this->insumos.clear();

}

void Local :: alterarEstoque(int iInsumo, int unidades){

    this->insumos[iInsumo]->setEstoque(unidades);

}