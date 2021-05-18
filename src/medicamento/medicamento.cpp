#include "medicamento.h"

using namespace std;


Medicamento :: Medicamento(){
    this->tipo = 2;
}


void Medicamento :: setModoAdministracao(string modoAdministracao){
    this->modoAdministracao = modoAdministracao;
}

void Medicamento :: setTipoDisponibilizado(string tipoDisponibilizado){
    this->tipoDisponibilizado = tipoDisponibilizado;
}

void Medicamento :: setContraIndicacao(string contraIndicacao){
    this->contraIndicacao = contraIndicacao;
}

void Medicamento :: setEfeitosColaterais(string efeitosColaterais){
    this->efeitosColaterais = efeitosColaterais;
}


string Medicamento :: getModoAdministracao(){
    return this->modoAdministracao;
}

string Medicamento :: getTipoDisponibilizado(){
    return this->tipoDisponibilizado;
}

string Medicamento :: getContraIndicacao(){
    return this->contraIndicacao;
}

string Medicamento :: getEfeitosColaterais(){
    return this->efeitosColaterais;
}

void Medicamento::cadastraAtributos(){

    Insumo::cadastraAtributos();

    getchar();
    getline(cin, this->modoAdministracao);
    getline(cin, this->tipoDisponibilizado);
    getline(cin, this->contraIndicacao);
    getline(cin, this->efeitosColaterais);
}