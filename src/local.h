#ifndef LOCAL_H
#define LOCAL_H

#include "insumo.h"
#include "vacina.h"
#include "medicamento.h"
#include "epi.h"
#include <iostream>
#include <vector>

class Local {

    private:
        std::string sigla;
        std::vector <Insumo *> insumos; // Vector de insumos de determinado local
    
    public:
        std::string getSigla();
        std::vector <Insumo *> getInsumos();

        void setSigla(std::string);
        void setInsumo(Insumo *);

        void apagarInsumo(int); // Método para apagar determinado insumo
        void apagarTodosInsumos(); // Método para apagar todos os insumos de determinado local
        
        void recadastraInsumo(int);

        void setInsumoEstado(Insumo *, int); // Adiciona um insumo para um estado

};

#endif