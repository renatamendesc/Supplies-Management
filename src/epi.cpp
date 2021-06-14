#include "epi.h"

using namespace std;

EPI :: EPI(){
    this->tipo = 3; // Construtor inicializa EPI como tipo 3
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

// Lê informações de EPIs
void EPI::cadastraAtributos(){

    Insumo::cadastraAtributos(); // Chama método para leitura de todos atributos (independente de tipo)

    getchar();

    cout << "Material utilizado: ";
    getline(cin, this->material);

    cout << "Quantidade indicada de usos: ";
    getline(cin, this->quantidadeDeUsos);

}

// Exibe informações de EPIs
void EPI::exibeInformacoes(){

    Insumo::exibeInformacoes(); // Chama método para exibição de todos atributos (independente de tipo)

    cout << "Material utilizado: " << this->material << endl;
    cout << "Quantidade indicada de usos: " << this->quantidadeDeUsos << endl;
    
}

// Método para enviar dados dos arquivos
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

// Método para coletar dados dos arquivos
void EPI :: coletaDados(vector <string> dados){

    Insumo::coletaDados(dados);

    this->setMaterial(dados[6]);
    this->setQuantidadeDeUsos(dados[7]);
    
}