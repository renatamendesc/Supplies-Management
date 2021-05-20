#include "vacina.h"

using namespace std;

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


void Vacina :: cadastraAtributos(){

    Insumo::cadastraAtributos();

    getchar();

    cout << "Tecnologia utilizada: ";
    getline(cin, this->tecnologia);

    cout << "Doses necessárias: ";
    getline(cin, this->dosesNecessarias);

    cout << "Intervalo entre doses: ";
    getline(cin, this->intervaloDoses);

    cout << "Eficácia geral: ";
    getline(cin, this->eficaciaGeral);

    cout << "Temperatura de armazenamento: ";
    getline(cin, this->temperaturaArmazenada);

}

void Vacina :: exibeInformacoes(){

    Insumo::exibeInformacoes();

    cout << "Tecnologia utilizada: " << this->tecnologia << endl;
    cout << "Doses necessárias: " << this->dosesNecessarias << endl;
    cout << "Intervalo entre doses: " << this->intervaloDoses << endl;
    cout << "Eficácia geral: " << this->eficaciaGeral << endl;
    cout << "Temperatura de armazenamento: " << this->temperaturaArmazenada << endl;

}