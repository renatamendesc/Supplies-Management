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
        std::vector <Insumo *> insumos;
    
    public:
        std::string getSigla();
        std::vector <Insumo *> getInsumos();

        void setSigla(std::string);
        void setInsumo(Insumo *);

        void apagarInsumo(int);
        void apagarTodosInsumos();
        
        void recadastraInsumo(int);

        void setInsumoEstado(Insumo *, int);

};

#endif