#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "insumo.h"
#include "local.h"
#include <iostream>
#include <vector>

using namespace std;

class Controller {

    private:
        vector <Local> locais;

    public:
        void cadastraInsumosMinisterio(); // Cadastra insumos no MS

        void distribuiInsumos(Local local, Insumo insumo); // Distribui insumos para estados

        void consultaInsumos(Local local); // Consulta de insumos em determinado local
        void consultaInsumosDescricao(Local local); // Consulta descrição de insumos de determinado local
        void consultaTipoInsumos(Local local, int tipo); // Consulta de insumos por tipo

};

#endif