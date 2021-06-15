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


// Método que cadastra as informações dos insumos em comum a todos os tipos
void Insumo :: cadastraAtributos(){ 

    cout << "Nome: ";
    getline(cin, this->nome);

    cout << "Fabricante: ";
    getline(cin, this->fabricante);

    cout << "Data de validade: ";
    getline(cin, this->dataDeValidade);

    cout << "Descrição: ";
    getline(cin, this->descricao);

    while(true){
        cout << "Valor unitário (R$): ";

        // Try/Catch usado no tratamento de erros
        try{
            cin >> this->valor;

            if(this->valor <= 0){
                cout << "\n--------------------------------------------------------------\n";

                cout << "\n             Valor inválido, tente novamente!\n";
                cout << "\n          [Pressione enter para tentar novamente]\n";
            
                cout << "\n--------------------------------------------------------------\n";
                getchar();
                getchar();
                continue;
            }
            
            break;

        }catch(ios_base::failure &fail){
            this->e.treat(false);
            
        }
    }
}

// Método que exibe as informações
void Insumo :: exibeInformacoes(){ 

    cout << "Nome: " << this->nome << endl;
    cout << "Fabricante: " << this->fabricante << endl;
    cout << "Data de validade: " << this->dataDeValidade << endl;
    cout << "Descrição: " << this->descricao << endl;
    cout << "Valor unitário (R$): " << this->valor << endl;
    cout << "Quantidade no estoque: " << this->estoque << endl;
    
}

void Insumo :: salvarDados(string estado){

    if(this->tipo == 1){

        ofstream vacina;
        vacina.open("dados/vacinas.csv", ios_base::app);

        if(vacina.is_open()){
            vacina << endl << estado << ",";
            vacina << "Vacina,";
            vacina << this->nome << ",";
            vacina << this->fabricante << ",";
            vacina << this->dataDeValidade << ",";
            vacina << this->descricao << ",";
            vacina << this->valor << ",";
            vacina << this->estoque << ",";

            vacina.close();
        }
        else{
            cout << "---Problema ao abrir o arquivo---" <<endl;
        }

    }

    if(this->tipo == 2){

        ofstream medicamento;
        medicamento.open("dados/medicamentos.csv", ios_base::app);

        if(medicamento.is_open()){

            medicamento << endl << estado << ",";
            medicamento << "Medicamento,";
            medicamento << this->nome << ",";
            medicamento << this->fabricante << ",";
            medicamento << this->dataDeValidade << ",";
            medicamento << this->descricao << ",";
            medicamento << this->valor << ",";
            medicamento << this->estoque << ",";

            medicamento.close();

        }
        else{
            cout << "---Problema ao abrir o arquivo---" <<endl;
        }
    }

    if(this->tipo == 3){

        ofstream epi;
        epi.open("dados/epi.csv", ios_base::app);

        if(epi.is_open()){
            epi << endl << estado << ",";
            epi << "EPI,";
            epi << this->nome << ",";
            epi << this->fabricante << ",";
            epi << this->dataDeValidade << ",";
            epi << this->descricao << ",";
            epi << this->valor << ",";
            epi << this->estoque << ",";

            epi.close();
        }
        else{
            cout << "---Problema ao abrir o arquivo---" <<endl;
        }   
    }
}

void Insumo :: coletaDados(vector <string> dados){

        this->setNome(dados[0]);
        this->setFabricante(dados[1]);
        this->setDataDeValidade(dados[2]);
        this->setDescricao(dados[3]);
        this->setValor(stof(dados[4]));
        this->setEstoque(stoi(dados[5]));

}