#include "controller/controller.h"
#include "insumo/insumo.h"
#include "vacina/vacina.h"
#include "medicamento/medicamento.h"
#include "epi/epi.h"
#include "local/local.h"
#include <iostream>

using namespace std;

int main(void){

    Controller controller;

    controller.cadastraInsumosMinisterio(1);
    controller.consultaInsumosDescricao(0);

    return 0;
}