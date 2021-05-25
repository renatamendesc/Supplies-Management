#ifndef MENU_H
#define MENU_H

#include "controller.h"
#include <iostream>

class Menu {

    public:
        void menuPrincipal(Controller &);
        
        void menuConsulta(Controller &);
        void menuCadastro(Controller &);
        void menuAcrescentar(Controller &);
        void menuModificar(Controller &);
        void menuEnviarParaEstado(Controller &);

        void menuEnviarInsumo(Controller &, int estado);

        void menuConsultaGeral(Controller &, int iLocal);
        void menuConsultaEstado(Controller &);

        void menuConsultaEstoque(Controller &, int iLocal);
        void menuConsultaEstoqueTipo(Controller &, int iLocal);

};

#endif