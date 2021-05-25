/**
Programa de cadastro de insumos
Autores: Gabriela Gomes Cavalcanti Alves Monteiro, Guilherme Jácome Cavalcante, Renata Mendes Pereira Campos
Ultima atualização: 24/05/2021
Breve descrição: Programa que cadastra informações sobre insumos, ligados ao covid 19.
**/

#include "menu.h"
#include "persistencia.h"
#include <iostream>

using namespace std;

int main(void){
    
    Menu menu;
    Persistencia persistencia;

    persistencia.inicializacao();

    menu.menuPrincipal();

    persistencia.finalizacao(menu.getController());

    return 0;
}