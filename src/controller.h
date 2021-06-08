#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "inputInvalidoException.h"
#include "insumo.h"
#include "vacina.h"
#include "medicamento.h"
#include "epi.h"
#include "local.h"
#include <iostream>
#include <vector>

class Controller {

    private:
        std::vector <Local> locais;
        InputInvalidoException e = InputInvalidoException();

    public:
        Controller();

        std::vector <Local> getLocais();

        void cadastraInsumosMinisterio(int); // Cadastra insumos no MS

        void distribuiInsumos(int, int, int); // Distribui insumos para estados

        void consultaInsumosEstoque(int); // Consulta de estoque de insumos em determinado local
        void consultaTipoInsumosEstoque(int, int); // Consulta de estoque de insumos por tipo
        void consultaInsumosDescricao(int); // Consulta descrição de insumos de determinado local
        
        void modificarInsumo(int);
        void apagarInsumo(int);
        void apagarDados();

        void acrescentarInsumos(int, int);

        int pesquisar(std::string, std::string, int);

        void setarDado(int, Insumo *);

        void pause();

};

#endif