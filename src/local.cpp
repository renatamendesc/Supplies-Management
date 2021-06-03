#include "local.h"

using namespace std;

void Local :: setSigla(string sigla){
    this->sigla = sigla;
}

void Local :: setInsumo(Insumo *insumo){
    insumos.push_back(insumo);
}

string Local :: getSigla(){
    return this->sigla;
}

vector <Insumo *> Local :: getInsumos(){
    return this->insumos;
}

void Local :: recadastraInsumo(int iInsumo){
    this->insumos[iInsumo]->cadastraAtributos();
}

void Local :: apagarInsumo(int iInsumo){
    this->insumos.erase(this->insumos.begin() + iInsumo);
}

void Local :: apagarTodosInsumos(){
    this->insumos.clear();
}

void Local :: setInsumoEstado(Insumo *insumoMS, int unidades){

    Insumo *insumoEstado;

    int tipo = insumoMS->getTipo();


    // Verifica o tipo do insumo
    if(tipo == 1){

        insumoEstado = new Vacina();

        insumoEstado->setNome(insumoMS->getNome());
        insumoEstado->setFabricante(insumoMS->getFabricante());
        insumoEstado->setDataDeValidade(insumoMS->getDataDeValidade());
        insumoEstado->setDescricao(insumoMS->getDescricao());
        insumoEstado->setValor(insumoMS->getValor());
        insumoEstado->setEstoque(unidades);
        insumoEstado->setTipo(tipo);

        ((Vacina*)insumoEstado)->setTecnologia(((Vacina*)insumoMS)->getTecnologia());
        ((Vacina*)insumoEstado)->setDosesNecessarias(((Vacina*)insumoMS)->getDosesNecessarias());
        ((Vacina*)insumoEstado)->setIntervaloDoses(((Vacina*)insumoMS)->getIntervaloDoses());
        ((Vacina*)insumoEstado)->setEficaciaGeral(((Vacina*)insumoMS)->getEficaciaGeral());
        ((Vacina*)insumoEstado)->setTemperaturaArmazenada(((Vacina*)insumoMS)->getTemperaturaArmazenada());
 
    }else if(tipo == 2){

        insumoEstado = new Medicamento();

        insumoEstado->setNome(insumoMS->getNome());
        insumoEstado->setFabricante(insumoMS->getFabricante());
        insumoEstado->setDataDeValidade(insumoMS->getDataDeValidade());
        insumoEstado->setDescricao(insumoMS->getDescricao());
        insumoEstado->setValor(insumoMS->getValor());
        insumoEstado->setEstoque(unidades);
        insumoEstado->setTipo(tipo);

        ((Medicamento*)insumoEstado)->setModoAdministracao(((Medicamento*)insumoMS)->getModoAdministracao());
        ((Medicamento*)insumoEstado)->setTipoDisponibilizado(((Medicamento*)insumoMS)->getTipoDisponibilizado());
        ((Medicamento*)insumoEstado)->setContraIndicacao(((Medicamento*)insumoMS)->getContraIndicacao());
        ((Medicamento*)insumoEstado)->setEfeitosColaterais(((Medicamento*)insumoMS)->getEfeitosColaterais());

    }else if(tipo == 3){

        insumoEstado = new EPI();

        insumoEstado->setNome(insumoMS->getNome());
        insumoEstado->setFabricante(insumoMS->getFabricante());
        insumoEstado->setDataDeValidade(insumoMS->getDataDeValidade());
        insumoEstado->setDescricao(insumoMS->getDescricao());
        insumoEstado->setValor(insumoMS->getValor());
        insumoEstado->setEstoque(unidades);
        insumoEstado->setTipo(tipo);

        ((EPI*)insumoEstado)->setMaterial(((EPI*)insumoMS)->getMaterial());
        ((EPI*)insumoEstado)->setQuantidadeDeUsos(((EPI*)insumoMS)->getQuantidadeDeUsos());
    
    }

    this->insumos.push_back(insumoEstado);
    
}