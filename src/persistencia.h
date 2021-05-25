#ifndef PERSISTENCIA_H
#define PERSISTENCIA_H

#include <iostream>
#include "controller.h"
#include "insumo.h"
#include <fstream>

class Persistencia {

    public:
        void inicializacao(Controller &);
        void finalizacao(Controller &);

};

#endif