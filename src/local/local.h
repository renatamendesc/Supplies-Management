#ifndef LOCAL_H
#define LOCAL_H

#include "insumo.h"
#include <iostream>
#include <vector>

class Local {

    private:
        std::string sigla;
        std::vector <Insumo> insumos;
    
    public:
        std::string getSigla();
        vector <Insumo> getInsumos();

        void setSigla(std::string);

};

#endif