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

    cout << "Material utilizado: ";
    getline(cin, this->material);

    cout << "Quantidade indicada de usos: ";
    getline(cin, this->quantidadeDeUsos);

}

void EPI::exibeInformacoes(){

    Insumo::exibeInformacoes();

    cout << "Material utilizado: " << this->material << endl;
    cout << "Quantidade indicada de usos: " << this->quantidadeDeUsos << endl;
    
}

void EPI::salvarDados(string estado){
    ofstream epi;
    epi.open("dados/epi.csv", ios_base::app);

    Insumo::salvarDados(estado);

    if(epi.is_open()){
        epi << this->material << ",";
        epi << this->quantidadeDeUsos;

        epi.close();
    }
    else{
        cout << "---Problema ao abrir o arquivo---" <<endl;
    }
}

void EPI :: coletaDados(vector <string> dados){

    Insumo::coletaDados(dados);

    this->setMaterial(dados[6]);
    this->setQuantidadeDeUsos(dados[7]);
    
}