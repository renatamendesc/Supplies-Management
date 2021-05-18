#include "epi.h"

using namespace std;

EPI :: EPI(){
    this->tipo = 3;
}

void EPI :: setMaterial(string material){
    this->material =  material;
}

void EPI :: setQuantidadeDeUsos(string quantidadeUsos){
    this->quantidadeDeUsos = quantidadeUsos;
}


string EPI :: getMaterial(){
    return this->material;
}

string EPI :: getQuantidadeDeUsos(){
    return this->quantidadeDeUsos;
}

void EPI::cadastraAtributos(){

    Insumo::cadastraAtributos();

    getchar();
    getline(cin, this->material);
    getline(cin, this->quantidadeDeUsos);
}