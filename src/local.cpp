#include "local.h"

using namespace std;

void Local :: setSigla(string sigla){
    this->sigla = sigla;
}

void Local :: setInsumo(Insumo *insumo){

    cout << insumo->getNome() << endl;

    insumos.push_back(insumo);

    cout << insumos[insumos.size()-1]->getNome();

    getchar();
}

string Local :: getSigla(){
    return this->sigla;
}

vector <Insumo *> Local :: getInsumos(){
    return this->insumos;
}