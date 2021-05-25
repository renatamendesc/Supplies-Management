#include "insumo.h"

using namespace std;

Insumo::~Insumo(){

}

void Insumo :: setNome(string nome){
    this->nome = nome;
}

void Insumo :: setFabricante(string fabricante){
    this->fabricante = fabricante;
}

void Insumo :: setDataDeValidade(string validade){
    this->dataDeValidade = validade;
}

void Insumo :: setDescricao(string descricao){
    this->descricao = descricao;
}

void Insumo :: setEstoque(int estoque){
    this->estoque = estoque;
}

void Insumo :: setTipo(int tipo){
    this->tipo = tipo;
}

void Insumo :: setValor(float valor){
    this->valor = valor;
}


string Insumo :: getNome(){
    return this->nome;
}

string Insumo :: getFabricante(){
    return this->fabricante;
}

string Insumo :: getDataDeValidade(){
    return this->dataDeValidade;
}

string Insumo :: getDescricao(){
    return this->descricao;
}

int Insumo:: getEstoque(){
    return this->estoque;
}

int Insumo :: getTipo(){
    return this->tipo;
} 

float Insumo :: getValor(){
    return this->valor;
}


void Insumo :: cadastraAtributos(){

    cin.exceptions(istream::failbit);

    cout << "Nome: ";
    getline(cin, this->nome);

    cout << "Fabricante: ";
    getline(cin, this->fabricante);

    cout << "Data de validade: ";
    getline(cin, this->dataDeValidade);

    cout << "Descrição: ";
    getline(cin, this->descricao);

    while(true){
        cout << "Valor unitário: ";
        try{
            cin >> this->valor;
            break;
        }
        catch(ios_base::failure &fail){
            cout << "Valor inválido, tente novamente!" << endl;
            cin.clear();
            string tmp;
            getline(cin, tmp);
            getchar();
            continue;
        }
    }
}

void Insumo :: exibeInformacoes(){

    cout << "Nome: " << this->nome << endl;
    cout << "Fabricante: " << this->fabricante << endl;
    cout << "Data de validade: " << this->dataDeValidade << endl;
    cout << "Descrição: " << this->descricao << endl;
    cout << "Valor unitário: " << this->valor << endl;
    cout << "Quantidade no estoque: " << this->estoque << endl;
    
}

void Insumo :: salvarDados(int estado){

    cout << "3-Entrando insumo" << endl;

    if(this->tipo == 1){

        ofstream vacina;
        vacina.open("vacinas.csv", ios_base::app);

        cout << "4-Detectado insumo vacina" << endl;

        vacina << endl << estado << ",";
        vacina << this->tipo << ",";
        vacina << this->nome << ",";
        vacina << this->fabricante << ",";
        vacina << this->dataDeValidade << ",";
        vacina << this->descricao << ",";
        vacina << this->valor << ",";
        vacina << this->estoque << ",";

        vacina.close();
    }

    if(this->tipo == 2){

        ofstream medicamento;
        medicamento.open("medicamentos.csv", ios_base::app);

        medicamento << endl << estado << ",";
        medicamento << this->tipo << ",";
        medicamento << this->nome << ",";
        medicamento << this->fabricante << ",";
        medicamento << this->dataDeValidade << ",";
        medicamento << this->descricao << ",";
        medicamento << this->valor << ",";
        medicamento << this->estoque << ",";

        medicamento.close();
    }

    if(this->tipo == 3){

        ofstream epi;
        epi.open("epi.csv", ios_base::app);

        epi << endl << estado << ",";
        epi << this->tipo << ",";
        epi << this->nome << ",";
        epi << this->fabricante << ",";
        epi << this->dataDeValidade << ",";
        epi << this->descricao << ",";
        epi << this->valor << ",";
        epi << this->estoque << ",";

        epi.close();
    }

}