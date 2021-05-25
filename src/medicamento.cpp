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

    std::cout << "\n----------------- CADASTRAR UM MEDICAMENTO -------------------\n\n";

    Insumo::cadastraAtributos();

    getchar();

    cout << "Modo de administração: ";
    getline(cin, this->modoAdministracao);

    cout << "Tipo disponibilizado: ";
    getline(cin, this->tipoDisponibilizado);

    cout << "Contra indicação: ";
    getline(cin, this->contraIndicacao);

    cout << "Efeitos colaterais: ";
    getline(cin, this->efeitosColaterais);
}

void Medicamento ::exibeInformacoes(){

    Insumo::exibeInformacoes();

    cout << "Modo de administração: " << this->modoAdministracao << endl;
    cout << "Tipo disponibilizado: " << this->tipoDisponibilizado << endl;
    cout << "Contra indicação: " << this->contraIndicacao << endl;
    cout << "Efeitos colaterais: " << this->efeitosColaterais << endl;
    
}

void Medicamento :: salvarDados(int estado){
    
    ofstream medicamento;
    medicamento.open("medicamentos.csv", ios_base::app);

    Insumo::salvarDados(estado);

    medicamento << this->modoAdministracao << ",";
    medicamento << this->tipoDisponibilizado << ",";
    medicamento << this->contraIndicacao << ",";
    medicamento << this->efeitosColaterais;

    medicamento.close();

}