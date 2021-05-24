#ifndef MENU_H
#define MENU_H

#include "controller.h"
#include <iostream>

class Menu {

    private:
        Controller controller;

    public:
        void menuPrincipal();
        
        void menuConsulta();
        void menuCadastro();
        void menuAcrescentar();
        void menuModificar();
        void menuEnviarParaEstado();

        void menuEnviarInsumo(int estado);

        void menuConsultaGeral(int iLocal);
        void menuConsultaEstado();

        void menuConsultaEstoque(int iLocal);
        void menuConsultaEstoqueTipo(int iLocal);

};

#endif