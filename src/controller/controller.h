#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../insumo/insumo.h"
#include "../vacina/vacina.h"
#include "../medicamento/medicamento.h"
#include "../epi/epi.h"
#include "../local/local.h"
#include <iostream>
#include <vector>

class Controller {

    private:
        std::vector <Local> locais;

    public:
        Controller();

        void cadastraInsumosMinisterio(int); // Cadastra insumos no MS

        void distribuiInsumos(int, int, int); // Distribui insumos para estados

        void consultaInsumos(int); // Consulta de insumos em determinado local
        void consultaInsumosDescricao(int); // Consulta descrição de insumos de determinado local
        void consultaTipoInsumos(int, int); // Consulta de insumos por tipo

};

#endif