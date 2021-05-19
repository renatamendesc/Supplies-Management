#include "controller.h"

using namespace std;

Controller :: Controller(){
    vector <string> siglas = {"BR", "AC", "AL", "AP", "AM", "BA", "CE", "DF", "ES", "GO", "MA", "MT", "MS", "MG", "PA", "PB", "PR", "PE", "PI", "RJ", "RN", "RS", "RR", "RO", "SC", "SP", "SE", "TO"};
    
    for(int i = 0; i < siglas.size(); i++){
        Local local;

        local.setSigla(siglas[i]);
        this->locais.push_back(local);
    }
}

void Controller :: cadastraInsumosMinisterio(int tipo){
    
    Insumo *insumo;

    if(tipo == 1){
        insumo = new Vacina();

    }else if(tipo == 2){
        insumo = new Medicamento();

    }else if(tipo == 3){
        insumo = new EPI();
    }

    insumo->cadastraAtributos();

    this->locais[0].getInsumos().push_back(insumo);
     
}

void Controller :: distribuiInsumos(Local local, Insumo insumo){

}

void Controller :: consultaInsumos(Local local){

}

void Controller :: consultaInsumosDescricao(Local local){

}

void Controller :: consultaTipoInsumos(Local local, int tipo){

}