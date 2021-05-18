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
    getline(cin, this->tecnologia);
    getline(cin, this->dosesNecessarias);
    getline(cin, this->intervaloDoses);
    getline(cin, this->eficaciaGeral);
    getline(cin, this->temperaturaArmazenada);

}