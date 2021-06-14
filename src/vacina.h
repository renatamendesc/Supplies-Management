#ifndef VACINA_H
#define VACINA_H

#include "insumo.h"

class Vacina: public Insumo {

    private:
        std::string tecnologia;
        std::string dosesNecessarias;
        std::string intervaloDoses;
        std::string eficaciaGeral;
        std::string temperaturaArmazenada;

    public:
        Vacina();

        void setTecnologia(std::string);
        void setDosesNecessarias(std::string);
        void setIntervaloDoses(std::string);
        void setEficaciaGeral(std::string);
        void setTemperaturaArmazenada(std::string);

        std::string getTecnologia();
        std::string getDosesNecessarias();
        std::string getIntervaloDoses();
        std::string getEficaciaGeral();
        std::string getTemperaturaArmazenada();

        void cadastraAtributos(); // Método para cadastrar as informações das vacinas
        void exibeInformacoes(); // Método para exibir as informações cadastradas das vacinas
        void salvarDados(std::string); // Método que salva os dados das vacinas em arquivos
        void coletaDados(std::vector <std::string>); // Método que coleta os dados das vacinas dos arquivos

};

#endif