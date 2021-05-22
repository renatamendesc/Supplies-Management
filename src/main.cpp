#include "controller.h"
#include "insumo.h"
#include "vacina.h"
#include "medicamento.h"
#include "epi.h"
#include "local.h"
#include <iostream>

using namespace std;

int main(void){

    Controller controller;

    controller.cadastraInsumosMinisterio(1);
    controller.consultaInsumosDescricao(0);
    

    return 0;
}