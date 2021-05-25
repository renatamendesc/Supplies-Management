#ifndef EPI_H
#define EPI_H

#include "insumo.h"
#include <iostream>

class EPI: public Insumo {
   
    private:
        std::string material;
        std::string quantidadeDeUsos;
    
    public:
        EPI();

        void setMaterial(std::string);
        void setQuantidadeDeUsos(std::string);

        std::string getMaterial();
        std::string getQuantidadeDeUsos();

        void cadastraAtributos();
        void exibeInformacoes();
        void salvarDados(std::string);
        void coletaDados(std::vector <std::string>);
};

#endif