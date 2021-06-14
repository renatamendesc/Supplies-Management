/**
Programa de cadastro de insumos
Autores: Gabriela Gomes Cavalcanti Alves Monteiro, Guilherme Jácome Cavalcante, Renata Mendes Pereira Campos
Ultima atualização: 08/06/2021
Breve descrição: Programa que cadastra informações sobre insumos, ligados ao covid 19.
**/

#include "menu.h"
#include "persistencia.h"
#include "controller.h"
#include <iostream>

using namespace std;

int main(void){

    Controller controller;
    Persistencia persistencia;
    Menu menu;

    persistencia.inicializacao(controller);
    menu.menuPrincipal(controller);
    persistencia.finalizacao(controller);

    return 0;
}