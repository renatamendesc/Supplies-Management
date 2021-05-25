#include "persistencia.h"

using namespace std;

void Persistencia :: inicializacao(){

    ifstream vacina("/vacinas.csv");
    ifstream medicamento("/medicamentos.csv");
    ifstream epi("/epi.csv");

    
    
}

void Persistencia :: finalizacao(){
    
    ofstream vacina("/vacinas.csv");
    ofstream medicamento("/medicamentos.csv");
    ofstream epi("/epi.csv");

    vector <Local> auxiliar = this->controller.getLocais();

    Insumo *insumo;

    for(int i = 0; i < auxiliar.size(); i++){
        for(int j = 0; j < auxiliar[i].getInsumos().size(); j++){

            if(auxiliar[i].getInsumos()[j]->getTipo() == 1){ //vacina

                insumo = new Vacina;
                insumo = auxiliar[i].getInsumos()[j];

                vacina << insumo->getNome() << ",";
                vacina << insumo->getFabricante() << ",";
                vacina << insumo->getDataDeValidade() << ",";
                vacina << insumo->getDescricao() << ",";

            }
            if(auxiliar[i].getInsumos()[j]->getTipo() == 2){ //medicamento

                insumo = new Medicamento;    
                insumo = auxiliar[i].getInsumos()[j];

            }
            if(auxiliar[i].getInsumos()[j]->getTipo() == 3){ //epi

                insumo = new EPI;    
                insumo = auxiliar[i].getInsumos()[j];

            }

        }
    }
    
}