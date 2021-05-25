#include "menu.h"

using namespace std;

void Menu :: menuPrincipal(){

    int selection;
    bool flag = false;

    while(true){
        system("clear");

        if(flag){
            break;
        }
        
        std::cout << "\n-------------- SISTEMA PARA CADASTRO DE INSUMOS --------------\n\n";

        std::cout << "[1] Cadastrar um insumo\n";
        std::cout << "[2] Consultar dados\n";
        std::cout << "[3] Comprar um insumo\n";
        std::cout << "[4] Modificar dados\n";
        std::cout << "[5] Enviar um insumo\n";
        std::cout << "[0] Sair\n";
        
        std::cout << "\n-------------------------------------------------------------\n";

        std::cin >> selection;

        getchar();

        switch(selection){
            
            case 1:
                this->menuCadastro();
                continue;

            case 2:
                this->menuConsulta();
                continue;
            
            case 3:
                this->menuAcrescentar();
                continue;
            
            case 4:
                this->menuModificar();
                continue;
            
            case 5:
                this->menuEnviarParaEstado();
                continue;

            case 0:
                flag = true;
                continue;

            default:
                std::cout << "\nOpção inválida!" << endl;

                std::cout << "\n[Pressione enter para tentar novamente]\n";
                
                this->controller.pause();
                continue;
        }
    }
}

void Menu :: menuConsulta(){

    int selection;
    bool flag = false;

    while(true){
        system("clear");

        if(flag){
            break;
        }
        
        std::cout << "\n--------------------- CONSULTA DE DADOS ---------------------\n\n";

        std::cout << "[1] Consultar dados do Ministério da Saúde\n";
        std::cout << "[2] Consultar dados de estados\n";
        std::cout << "[0] Voltar\n";
        
        std::cout << "\n-------------------------------------------------------------\n";

        std::cin >> selection;

        getchar();

        switch(selection){
            
            case 1:
                this->menuConsultaGeral(0);
                continue;

            case 2:
                this->menuConsultaEstado();
                continue;

            case 0:
                flag = true;
                continue;

            default:
                std::cout << "\nOpção inválida!" << endl;

                std::cout << "\n[Pressione enter para tentar novamente]\n";
                
                this->controller.pause();
                continue;
        }
    }  
}


void Menu :: menuConsultaGeral(int iLocal){

    int selection;
    bool flag = false;
    string local;

    if(iLocal == 0){
        local = "MS";
    } else {
        local = this->controller.getLocais()[iLocal].getSigla();
    }

    while(true){
        system("clear");

        if(flag){
            break;
        }
        
        std::cout << "\n-------------------- CONSULTA DE DADOS (" << local << ") -------------------\n\n";

        std::cout << "[1] Consultar estoque\n";
        std::cout << "[2] Consultar informações gerais\n";
        std::cout << "[0] Voltar\n";
        
        std::cout << "\n-------------------------------------------------------------\n";

        std::cin >> selection;

        getchar();

        switch(selection){
            
            case 1:
                this->menuConsultaEstoque(iLocal);
                continue;

            case 2:
                this->controller.consultaInsumosDescricao(iLocal);
                continue;

            case 0:
                flag = true;
                continue;

            default:
                std::cout << "\nOpção inválida!" << endl;

                std::cout << "\n[Pressione enter para tentar novamente]\n";
                
                this->controller.pause();
                continue;
        }
    }
}

void Menu :: menuConsultaEstado(){
    
    std::string selection;
    bool flag = false;
    
    while(1){

        system("clear");

        if(flag){
            break;
        }

        std::cout << "\n---------------- CONSULTA DE DADOS DE ESTADOS ----------------\n\n";

        std::cout << "Informe qual estado você deseja consultar (sigla do estado)\n";

        std::cout << "\n[Pressione 0 para voltar]\n"; 
        
        std::cout << "\n-------------------------------------------------------------\n";
        
        std::getline(std::cin, selection);

        if(selection == "0"){
            break;  

        }else{

            // Análisa se o estado selecionado existe 
            int index = this->controller.pesquisar(selection, "", 2);

            if(index == -1){
                std::cout << "\nNão foi identificado nenhum estado com a sigla \"" << selection << "\".\n";

                std::cout << "\n[Pressione enter para tentar novamente]\n";
                getchar();

            }else{
                this->menuConsultaGeral(index);
            
            }
        }
    } 
}

void Menu :: menuConsultaEstoque(int iLocal){

    int selection;
    bool flag = false;
    string local;

    if(iLocal == 0){
        local = "MS";
    } else {
        local = this->controller.getLocais()[iLocal].getSigla();
    }

    while(true){
        system("clear");

        if(flag){
            break;
        }
        
        std::cout << "\n-------------------- CONSULTA DE DADOS (" << local << ") -------------------\n\n";

        std::cout << "[1] Consultar estoque por tipo\n";
        std::cout << "[2] Consultar estoque geral\n";
        std::cout << "[0] Voltar\n";
        
        std::cout << "\n-------------------------------------------------------------\n";

        std::cin >> selection;

        getchar();

        switch(selection){
            
            case 1:
                this->menuConsultaEstoqueTipo(iLocal);
                continue;

            case 2:
                this->controller.consultaInsumosEstoque(iLocal);
                continue;

            case 0:
                flag = true;
                continue;

            default:
                std::cout << "\nOpção inválida!" << endl;

                std::cout << "\n[Pressione enter para tentar novamente]\n";
                
                this->controller.pause();
                continue;
        }
    }
}

void Menu :: menuConsultaEstoqueTipo(int iLocal){

    int selection;
    bool flag = false;
    string local;

    if(iLocal == 0){
        local = "MS";
    } else {
        local = this->controller.getLocais()[iLocal].getSigla();
    }

    while(true){
        system("clear");

        if(flag){
            break;
        }

        std::cout << "\n------------- CONSULTA DE INSUMOS POR TIPO (" << local << ") --------------\n\n";
        
        std::cout << "[1] Consultar estoque de vacinas\n";
        std::cout << "[2] Cadastrar estoque de medicamentos\n";
        std::cout << "[3] Cadastrar estoque de EPIs\n";
        std::cout << "[0] Voltar\n";
        
        std::cout << "\n-------------------------------------------------------------\n";
        
        std::cin >> selection;
        getchar();

        switch(selection){
            
            case 1:
                this->controller.consultaTipoInsumosEstoque(iLocal, 1);
                continue;

            case 2:
                this->controller.consultaTipoInsumosEstoque(iLocal, 2);
                continue;

            case 3:
                this->controller.consultaTipoInsumosEstoque(iLocal, 3);
                continue;

            case 0:
                flag = true;
                continue;

            default:
                std::cout << "\nOpção inválida!\n" << endl;

                std::cout << "\n[Pressione enter para tentar novamente]\n";
                
                this->controller.pause();
                continue;       
        }
    }
}

// -------------------------------------------------------------------------------------------------

void Menu :: menuCadastro(){

    int selection;
    bool flag = false;

    while(true){
        system("clear");

        if(flag){
            break;
        }

        std::cout << "\n-------------------- CADASTRO DE INSUMOS ---------------------\n\n";
        
        std::cout << "[1] Cadastrar uma vacina\n";
        std::cout << "[2] Cadastrar um medicamento\n";
        std::cout << "[3] Cadastrar um EPI\n";
        std::cout << "[0] Voltar\n";
        
        std::cout << "\n-------------------------------------------------------------\n";
        
        std::cin >> selection;

        getchar();

        switch(selection){
            
            case 1:
                this->controller.cadastraInsumosMinisterio(1);
                continue;

            case 2:
                this->controller.cadastraInsumosMinisterio(2);
                continue;

            case 3:
                this->controller.cadastraInsumosMinisterio(3);
                continue;

            case 0:
                flag = true;
                continue;

            default:
                std::cout << "\nOpção inválida!\n" << endl;

                std::cout << "\n[Pressione enter para tentar novamente]\n";
                
                this->controller.pause();
                continue;
                
        }
    }
}

void Menu :: menuAcrescentar(){
    
    string selection;
    bool flag = false;
    
    while(true){

        system("clear");

        if(flag){
            break;
        }

        std::cout << "\n-------------- ACRESCENTAR INSUMOS AO ESTOQUE ---------------\n\n";

        std::cout << "Informe o nome do insumo que será comprado\n";

        std::cout << "\n[Pressione 0 para voltar]\n";

        std::cout << "\n-------------------------------------------------------------\n";
        
        std::getline(std::cin, selection);
        
        if(selection == "0"){
            flag = true;

        }else{

            int index = this->controller.pesquisar("BR", selection, 1);

            system("clear");

            if(index == -1){

                std::cout << "\nNão foi identificado nenhum insumo com nome \"" << selection << "\".\n";

                std::cout << "\n[Pressione enter para tentar novamente]\n\n";
                getchar();

            }

            else{
                int quantidade;
                
                std::cout << "\n-------------- ACRESCENTAR INSUMOS AO ESTOQUE ----------------\n\n";

                std::cout << "Informe a quantidade de insumos que deseja adquirir" << endl;

                std::cout << "\n[Pressione 0 para voltar]\n";

                std::cout << "\n-------------------------------------------------------------\n";

                std::cin >> quantidade;

                if(quantidade == 0)
                    continue;
                
                else{

                    this->controller.acrescentarInsumos(index, quantidade);

                }
            }
        }
    }
}

void Menu :: menuModificar(){

    int selection; 
    bool flag = false;

    while(true){
        if(flag){
            break;
        }

        system("clear");

        std::cout << "\n--------------------- MODIFICAR INSUMOS --------------------\n\n";
        
        std::cout << "[1] Modificar vacinas\n";
        std::cout << "[2] Modificar medicamentos\n";
        std::cout << "[3] Modificar EPIs\n";
        std::cout << "[0] Voltar\n";

        std::cout << "\n------------------------------------------------------------\n";

        std::cin >> selection;

        getchar();

        switch(selection){

            case 0:
                flag = true;
                continue;

            case 1:
                this->controller.modificarInsumo(1); // Chama função de modificar cadastro
                continue;

            case 2:
                this->controller.modificarInsumo(2); // Chama função de modificar cadastro
                continue;
                
            case 3:
                this->controller.modificarInsumo(3); // Chama função de modificar cadastro
                continue;

            default:
                std::cout << "\nOpção inválida!\n";

                std::cout << "\n[Pressione enter para tentar novamente]\n";
                this->controller.pause();
                continue;
        }
    }
}

void Menu :: menuEnviarInsumo(int estado){

    bool flag = 0;
    string selection;
    int index;

    getchar();
    
    while(1){

        system("clear");

        if(flag)
            break;

        std::cout << "\n------------ SELECIONE O NOME DO INSUMO DESEJADO -----------\n\n";

        std::cout << "Informe o nome do insumo que será enviado.\n";

        std::cout << "\n[Pressione 0 para voltar]\n";        
        
        std::cout << "\n-------------------------------------------------------------\n";
        
        std::getline(std::cin, selection);

        if(selection == "0"){
            flag = true;
            
        }else{
            
            index = this->controller.pesquisar("BR", selection, 1);

            system("clear");

            if(index == -1){

                std::cout << "\nNão foi identificado nenhum insumo com nome \"" << selection << "\".\n";

                std::cout << "\n[Pressione enter para tentar novamente]\n\n";
                getchar();

            } else {
                
                int quantidade;
                
                std::cout << "\n---------------- ENVIAR INSUMOS AOS ESTADOS ------------------\n\n";

                std::cout << "Informe a quantidade de insumos que deseja enviar" << endl;

                std::cout << "\n[Pressione 0 para voltar]\n";

                std::cout << "\n-------------------------------------------------------------\n";

                std::cin >> quantidade;

                getchar();

                if(quantidade == 0){
                    continue;
                
                } else if(quantidade > this->controller.getLocais()[estado].getInsumos()[index]->getEstoque() || quantidade < 1){ 
                    std::cout << "\nQuantidade inválida!\n";

                    std::cout << "\n[Pressione enter para tentar novamente]\n\n";
                    getchar();

                } else {
                    this->controller.distribuiInsumos(index, estado, quantidade);

                }
            }
        }
    }
}

void Menu :: menuEnviarParaEstado(){

    string selection;
    bool flag = false;
    
    while(true){

        system("clear");

        if(flag){
            break;
        }

        std::cout << "\n----------------- ENVIAR INSUMOS PARA ESTADOS ----------------\n\n";

        std::cout << "Informe para qual estado você deseja enviar (sigla do estado)\n";

        std::cout << "\n[Pressione 0 para voltar]\n"; 
        
        std::cout << "\n-------------------------------------------------------------\n";
        
        std::getline(std::cin, selection);

        if(selection == "0"){
            break;  

        }else{

            // Analise se o estado selecionado existe: 
            int index = this->controller.pesquisar(selection, "", 2);

            if(index == -1){
                std::cout << "\nNão foi identificado nenhum estado com a sigla \"" << selection << "\".\n";

                std::cout << "\n[Pressione enter para tentar novamente]\n";
                getchar();

            }else{
                menuEnviarInsumo(index); // Chama menu para selecionar tipo de insumo a ser enviado
            
            }
        }
    } 
}

Controller Menu :: getController(){
    return controller;
}