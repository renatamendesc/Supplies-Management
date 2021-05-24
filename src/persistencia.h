#ifndef PERSISTENCIA_H
#define PERSISTENCIA_H

#include <iostream>
#include "controller.h"
#include <fstream>

class Persistencia {
    private:
        Controller controller;

    public:

        void inicializacao();
        void finalizacao();

};

#endif