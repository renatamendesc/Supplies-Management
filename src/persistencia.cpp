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

    for(int i = 0; i < auxiliar.size(); i++){
        for(int j = 0; j < auxiliar[i].size(); j++){

            if(auxiliar[i].getInsumos()[j]->getTipo() == 1){ //vacina

                Vacina insumo = auxiliar[i].getInsumos()[j];

                vacina << insumo.getNome() << ","

            }
            if(auxiliar[i].getInsumos()[j]->getTipo() == 2){ //medicamento
                
                vector <Medicamento> insumo = auxiliar[i].getInsumos()[j];

            }
            if(auxiliar[i].getInsumos()[j]->getTipo() == 3){ //epi
                
                vector <EPI> insumo = auxiliar[i].getInsumos()[j];

            }

        }
    }
    
}