#include "insumo.h"

using namespace std;

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

    cout << "Nome: ";
    getline(cin, this->nome);

    cout << "Fabricante: ";
    getline(cin, this->fabricante);

    cout << "Data de validade: ";
    getline(cin, this->dataDeValidade);

    cout << "Descrição: ";
    getline(cin, this->descricao);

    cout << "Valor unitário: ";
    cin >> this->valor;
}

void Insumo :: exibeInformacoes(){

    cout << "Nome: " << this->nome << endl;
    cout << "Fabricante: " << this->fabricante << endl;
    cout << "Data de validade: " << this->dataDeValidade << endl;
    cout << "Descrição: " << this->dataDeValidade << endl;
    cout << "Valor unitário: " << this->valor << endl;
    
}

