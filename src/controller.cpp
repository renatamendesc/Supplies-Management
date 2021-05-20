#include "controller.h"

using namespace std;

Controller :: Controller(){
    vector <string> siglas = {"BR", "AC", "AL", "AP", "AM", "BA", "CE", "DF", "ES", "GO", "MA", "MT", "MS", "MG", "PA", "PB", "PR", "PE", "PI", "RJ", "RN", "RS", "RR", "RO", "SC", "SP", "SE", "TO"};
    
    // Incializa vector de locais com estados e Ministério da Saúde
    for(int i = 0; i < siglas.size(); i++){
        Local local;

        local.setSigla(siglas[i]);
        this->locais.push_back(local);
    }
}

void Controller :: cadastraInsumosMinisterio(int tipo){
    
    Insumo *insumo;

    // Verifica o tipo do insumo
    switch(tipo){
        case 1:
            insumo = new Vacina();
            break;

        case 2:
            insumo = new Medicamento();
            break;

        case 3:
            insumo = new EPI();
            break;
    }

    // Faz a leitura das informações do insumo em questão
    insumo->cadastraAtributos();

    // Adiciona o insumo no estoque do Ministério da Saúde
    this->locais[0].setInsumo(insumo);
     
}

void Controller :: distribuiInsumos(int iInsumo, int iLocal, int unidades){
    bool flag = false;
    int iInsumoEstado;

    // Verificação se o insumo em questão já existe no estoque do estado
    for(int i = 0; i < this->locais[iLocal].getInsumos().size(); i++){
        if(this->locais[iLocal].getInsumos()[i]->getNome() == this->locais[0].getInsumos()[iInsumo]->getNome()){
            flag = true;
            iInsumoEstado = i;
            break;
        }
    }

    if(!flag){ // Caso o insumo não exista no estado
        this->locais[iLocal].setInsumo(this->locais[0].getInsumos()[iInsumo]);
        this->locais[iLocal].getInsumos()[this->locais[iLocal].getInsumos().size()-1]->setEstoque(unidades);

    } else { // Caso já exista o insumo no estado
        int estoqueAtual = this->locais[iLocal].getInsumos()[iInsumoEstado]->getEstoque();
        this->locais[iLocal].getInsumos()[iInsumoEstado]->setEstoque(estoqueAtual + unidades);

    }

    // A quantidade enviada é debitada do estoque do Ministério da Saúde
    int estoqueAtual = this->locais[0].getInsumos()[iInsumo]->getEstoque();
    this->locais[0].getInsumos()[iInsumo]->setEstoque(estoqueAtual - unidades);

}

void Controller :: consultaInsumos(int iLocal){

}

void Controller :: consultaInsumosDescricao(int iLocal){

    // Percorre insumos existentes no local
    for(int i = 0; i < this->locais[iLocal].getInsumos().size(); i++){

        // Exibe informações do insumo
        this->locais[iLocal].getInsumos()[i]->exibeInformacoes();
        cout << endl;
    }
}

void Controller :: consultaTipoInsumos(int iLocal, int tipo){

}