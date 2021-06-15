#include "vacina.h"

using namespace std;

// Seta o tipo do insumo vacina como 1
Vacina :: Vacina(){
    this->tipo = 1; 
}

void Vacina :: setTecnologia(string tecnologia){
    this->tecnologia = tecnologia;
}

void Vacina :: setDosesNecessarias(string doses){
    this->dosesNecessarias = doses;
}

void Vacina :: setIntervaloDoses(string intervaloDoses){
    this->intervaloDoses = intervaloDoses;
}

void Vacina :: setEficaciaGeral(string eficacia){
    this->eficaciaGeral = eficacia;
}

void Vacina :: setTemperaturaArmazenada(string temperatura){
    this->temperaturaArmazenada = temperatura;
}

string Vacina :: getTecnologia(){
    return this->tecnologia;
}

string Vacina :: getDosesNecessarias(){
    return this->dosesNecessarias;
}

string Vacina :: getIntervaloDoses(){
    return this->intervaloDoses;
}

string Vacina :: getEficaciaGeral(){
    return this->eficaciaGeral;
}

string Vacina :: getTemperaturaArmazenada(){
    return this->temperaturaArmazenada;
}

// Método para cadastro de vacinas
void Vacina :: cadastraAtributos(){ 

    Insumo::cadastraAtributos(); // Chama o método que cadastra as informações das vacinas existentes em comum com medicamentos e EPIs
 
    getchar();

    cout << "Tecnologia utilizada: ";
    getline(cin, this->tecnologia);

    cout << "Doses necessárias: ";
    getline(cin, this->dosesNecessarias);

    if(this->dosesNecessarias == "1"){
        this->intervaloDoses = "0";
    }else{
        cout << "Intervalo de dias entre doses: ";
        getline(cin, this->intervaloDoses);
    }

    cout << "Eficácia geral: ";
    getline(cin, this->eficaciaGeral);

    cout << "Temperatura de armazenamento: ";
    getline(cin, this->temperaturaArmazenada);

}

void Vacina :: exibeInformacoes(){ 

    Insumo::exibeInformacoes(); // Chama o método que exibe as informações das vacinas existentes em comum com vacinas e EPIs

    cout << "Tecnologia utilizada: " << this->tecnologia << endl;
    cout << "Doses necessárias: " << this->dosesNecessarias << endl;
    cout << "Intervalo entre doses: " << this->intervaloDoses << endl;
    cout << "Eficácia geral: " << this->eficaciaGeral << endl;
    cout << "Temperatura de armazenamento: " << this->temperaturaArmazenada << endl;

}

void Vacina :: salvarDados(string estado){

    ofstream vacina;
    vacina.open("dados/vacinas.csv", ios_base::app);

    Insumo :: salvarDados(estado);

    if(vacina.is_open()){
        vacina << this->tecnologia << ",";
        vacina << this->dosesNecessarias << ",";
        vacina << this->intervaloDoses << ",";
        vacina << this->eficaciaGeral << ",";
        vacina << this->temperaturaArmazenada;

        vacina.close();
    }
    else{
        cout << "---Problema ao abrir o arquivo---" <<endl;
    }
}

void Vacina :: coletaDados(vector <string> dados){

    Insumo::coletaDados(dados);

    this->setTecnologia(dados[6]);
    this->setDosesNecessarias(dados[7]);
    this->setIntervaloDoses(dados[8]);
    this->setEficaciaGeral(dados[9]);
    this->setTemperaturaArmazenada(dados[10]);

}
