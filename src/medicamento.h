#ifndef MEDICAMENTO_H
#define MEDICAMENTO_H

#include "insumo.h"
#include <iostream>

class Medicamento: public Insumo {

    private:
        std::string modoAdministracao;
        std::string tipoDisponibilizado;
        std::string contraIndicacao;
        std::string efeitosColaterais;

    public:
        Medicamento();

        void setModoAdministracao(std::string);
        void setTipoDisponibilizado(std::string);
        void setContraIndicacao(std::string);
        void setEfeitosColaterais(std::string);

        std::string getModoAdministracao();
        std::string getTipoDisponibilizado();
        std::string getContraIndicacao();
        std::string getEfeitosColaterais();

        void cadastraAtributos(); // Método para cadastrar as informações dos medicamentos
        void exibeInformacoes(); // Método para exibir as informações cadastradas dos medicamentos
        void salvarDados(std::string); // Método que salva os dados dos medicamentos em arquivos
        void coletaDados(std::vector <std::string>); // Método que coleta os dados dos medicamentos dos arquivos

};

#endif