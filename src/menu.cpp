#include "menu.h"

using namespace std;

void Menu :: menuPrincipal(Controller &controller){

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
                this->menuCadastro(controller);
                continue;

            case 2:
                this->menuConsulta(controller);
                continue;
            
            case 3:
                this->menuAcrescentar(controller);
                continue;
            
            case 4:
                this->menuAlteracoes(controller);
                continue;
            
            case 5:
                this->menuEnviarParaEstado(controller);
                continue;

            case 0:
                flag = true;
                continue;

            default:
                std::cout << "\nOpção inválida!" << endl;

                std::cout << "\n[Pressione enter para tentar novamente]\n";
                
                controller.pause();
                continue;
        }
    }
}

void Menu :: menuConsulta(Controller &controller){

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
                this->menuConsultaGeral(controller, 0);
                continue;

            case 2:
                this->menuConsultaEstado(controller);
                continue;

            case 0:
                flag = true;
                continue;

            default:
                std::cout << "\nOpção inválida!" << endl;

                std::cout << "\n[Pressione enter para tentar novamente]\n";
                
                controller.pause();
                continue;
        }
    }  
}


void Menu :: menuConsultaGeral(Controller &controller, int iLocal){

    int selection;
    bool flag = false;
    string local;

    if(iLocal == 0){
        local = "MS";
    } else {
        local = controller.getLocais()[iLocal].getSigla();
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
                this->menuConsultaEstoque(controller, iLocal);
                continue;

            case 2:
                controller.consultaInsumosDescricao(iLocal);
                continue;

            case 0:
                flag = true;
                continue;

            default:
                std::cout << "\nOpção inválida!" << endl;

                std::cout << "\n[Pressione enter para tentar novamente]\n";
                
                controller.pause();
                continue;
        }
    }
}

void Menu :: menuConsultaEstado(Controller &controller){
    
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
            int index = controller.pesquisar(selection, "", 2);

            if(index == -1){
                std::cout << "\nNão foi identificado nenhum estado com a sigla \"" << selection << "\".\n";

                std::cout << "\n[Pressione enter para tentar novamente]\n";
                getchar();

            }else{
                this->menuConsultaGeral(controller, index);
            
            }
        }
    } 
}

void Menu :: menuConsultaEstoque(Controller &controller, int iLocal){

    int selection;
    bool flag = false;
    string local;

    if(iLocal == 0){
        local = "MS";
    } else {
        local = controller.getLocais()[iLocal].getSigla();
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
                this->menuConsultaEstoqueTipo(controller, iLocal);
                continue;

            case 2:
                controller.consultaInsumosEstoque(iLocal);
                continue;

            case 0:
                flag = true;
                continue;

            default:
                std::cout << "\nOpção inválida!" << endl;

                std::cout << "\n[Pressione enter para tentar novamente]\n";
                
                controller.pause();
                continue;
        }
    }
}

void Menu :: menuConsultaEstoqueTipo(Controller &controller, int iLocal){

    int selection;
    bool flag = false;
    string local;

    if(iLocal == 0){
        local = "MS";
    } else {
        local = controller.getLocais()[iLocal].getSigla();
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
                controller.consultaTipoInsumosEstoque(iLocal, 1);
                continue;

            case 2:
                controller.consultaTipoInsumosEstoque(iLocal, 2);
                continue;

            case 3:
                controller.consultaTipoInsumosEstoque(iLocal, 3);
                continue;

            case 0:
                flag = true;
                continue;

            default:
                std::cout << "\nOpção inválida!\n" << endl;

                std::cout << "\n[Pressione enter para tentar novamente]\n";
                
                controller.pause();
                continue;       
        }
    }
}

void Menu :: menuCadastro(Controller &controller){

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
                controller.cadastraInsumosMinisterio(1);
                continue;

            case 2:
                controller.cadastraInsumosMinisterio(2);
                continue;

            case 3:
                controller.cadastraInsumosMinisterio(3);
                continue;

            case 0:
                flag = true;
                continue;

            default:
                std::cout << "\nOpção inválida!\n" << endl;

                std::cout << "\n[Pressione enter para tentar novamente]\n";
                
                controller.pause();
                continue;
                
        }
    }
}

void Menu :: menuAcrescentar(Controller &controller){

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

            int index = controller.pesquisar("BR", selection, 1);

            system("clear");

            if(index == -1){

                std::cout << "\nNão foi identificado nenhum insumo com nome \"" << selection << "\".\n";

                std::cout << "\n[Pressione enter para tentar novamente]\n\n";
                getchar();

            } else {
                int quantidade;
                
                std::cout << "\n-------------- ACRESCENTAR INSUMOS AO ESTOQUE ----------------\n\n";

                std::cout << "Informe a quantidade de insumos que deseja adquirir" << endl;

                std::cout << "\n[Pressione 0 para voltar]\n";

                std::cout << "\n-------------------------------------------------------------\n";

                std::cin >> quantidade;

                getchar();

                if(quantidade == 0){
                    continue;

                }else{
                    controller.acrescentarInsumos(index, quantidade);

                }
            }
        }
    }
}

void Menu :: menuAlteracoes(Controller &controller){
    int selection; 
    bool flag = false;

    while(true){
        if(flag){
            break;
        }

        system("clear");

        std::cout << "\n--------------------- MODIFICAR INSUMOS --------------------\n\n";
        
        std::cout << "[1] Modificar dados de insumos\n";
        std::cout << "[2] Apagar dados de insumos\n";
        std::cout << "[0] Voltar\n";

        std::cout << "\n------------------------------------------------------------\n";

        std::cin >> selection;

        getchar();

        switch(selection){

            case 0:
                flag = true;
                continue;

            case 1:
                this->menuModificar(controller);
                continue;

            case 2:
                this->menuApagar(controller); // Chama função de modificar cadastro
                continue;

            default:
                std::cout << "\nOpção inválida!\n";

                std::cout << "\n[Pressione enter para tentar novamente]\n";
                controller.pause();
                continue;
        }
    }
}

void Menu :: menuApagar(Controller &controller){
    int selection; 
    bool flag = false;

    while(true){
        if(flag){
            break;
        }

        system("clear");

        std::cout << "\n----------------------- APAGAR INSUMOS ---------------------\n\n";
        
        std::cout << "[1] Apagar um insumo\n";
        std::cout << "[2] Apagar todos os insumos\n";
        std::cout << "[0] Voltar\n";

        std::cout << "\n------------------------------------------------------------\n";

        std::cin >> selection;

        getchar();

        switch(selection){

            case 0:
                flag = true;
                continue;

            case 1:
                this->menuApagarInsumo(controller);
                continue;

            case 2:

                while(true){
                    int selection;

                    cout << "Deseja salvar as alterações?" <<endl;
                    cout << "[1] Sim" << endl;
                    cout << "[2] Não" << endl;

                    cin >> selection;

                    system("clear");

                    switch(selection){

                        case 1:
                            controller.apagarDados();
                            cout << "Alterações salvas com sucesso!" << endl;
                            cout << "\n[Pressione enter para prosseguir]\n";
                            getchar();
                            break;
                        
                        case 2:
                            cout << "Alterações não salvas!" << endl;
                            cout << "\n[Pressione enter para prosseguir]\n";
                            getchar();
                            break;

                        default:
                            cout << "\nOpção inválida!\n";
                            cout << "\n[Pressione enter para tentar novamente]\n";
                            getchar();
                            continue;
                            
                    }
                }

            default:
                std::cout << "\nOpção inválida!\n";

                std::cout << "\n[Pressione enter para tentar novamente]\n";
                controller.pause();
                continue;
        }
    }
}

void Menu :: menuApagarInsumo(Controller &controller){
    std::string selection; 
    bool flag = false;
    int index;

    while(true){
        if(flag){
            break;
        }

        system("clear");

        std::cout << "\n---------------------- APAGAR INSUMOS ----------------------\n\n";
        
        std::cout << "Informe o nome do insumo que será apagado\n";

        std::cout << "\n[Pressione 0 para voltar]\n";        
        
        std::cout << "\n------------------------------------------------------------\n";

        std::getline(std::cin, selection);

        if(selection == "0"){
            flag = true;
            
        }else{
            
            index = controller.pesquisar("BR", selection, 1);

            system("clear");

            if(index == -1){
                std::cout << "\nNão foi identificado nenhum insumo com nome \"" << selection << "\".\n";

                std::cout << "\n[Pressione enter para tentar novamente]\n\n";
                getchar();

            } else {

                    while(true){
                        int selection;

                        cout << "Deseja salvar as alterações?" <<endl;
                        cout << "[1] Sim" << endl;
                        cout << "[2] Não" << endl;

                        cin >> selection;

                        system("clear");

                        switch(selection){

                            case 1:
                                controller.apagarInsumo(index);
                                cout << "Alterações salvas com sucesso!" << endl;
                                cout << "\n[Pressione enter para prosseguir]\n";
                                getchar();
                                break;
                            
                            case 2:
                                cout << "Alterações não salvas!" << endl;
                                cout << "\n[Pressione enter para prosseguir]\n";
                                getchar();
                                break;

                            default:
                                cout << "\nOpção inválida!\n";
                                cout << "\n[Pressione enter para tentar novamente]\n";
                                getchar();
                                continue;
                                
                    }
                }
            }
        }
    }
}

void Menu :: menuModificar(Controller &controller){

    std::string selection; 
    bool flag = false;
    int index;

    while(true){
        if(flag){
            break;
        }

        system("clear");

        std::cout << "\n--------------------- MODIFICAR INSUMOS --------------------\n\n";
        
        std::cout << "Informe o nome do insumo que será modificado\n";

        std::cout << "\n[Pressione 0 para voltar]\n";        
        
        std::cout << "\n------------------------------------------------------------\n";

        std::getline(std::cin, selection);

        if(selection == "0"){
            flag = true;
            
        }else{            
            index = controller.pesquisar("BR", selection, 1);

            system("clear");

            if(index == -1){
                std::cout << "\nNão foi identificado nenhum insumo com nome \"" << selection << "\".\n";

                std::cout << "\n[Pressione enter para tentar novamente]\n\n";
                getchar();

            } else {

                while(true){
                    int selection;

                    cout << "Deseja salvar as alterações?" <<endl;
                    cout << "[1] Sim" << endl;
                    cout << "[2] Não" << endl;

                    cin >> selection;

                    system("clear");

                    switch(selection){

                        case 1:
                            controller.modificarInsumo(index);
                            cout << "Alterações salvas com sucesso!" << endl;
                            cout << "\n[Pressione enter para prosseguir]\n";
                            getchar();
                            break;
                        
                        case 2:
                            cout << "Alterações não salvas!" << endl;
                            cout << "\n[Pressione enter para prosseguir]\n";
                            getchar();
                            break;

                        default:
                            cout << "\nOpção inválida!\n";
                            cout << "\n[Pressione enter para tentar novamente]\n";
                            getchar();
                            continue;
                            
                    }
                }
            }
        }
    }
}

void Menu :: menuEnviarInsumo(Controller &controller,int estado){

    bool flag = 0;
    string selection;
    int index;

    getchar();
    
    while(1){

        system("clear");

        if(flag)
            break;

        std::cout << "\n------------ SELECIONE O NOME DO INSUMO DESEJADO -----------\n\n";

        std::cout << "Informe o nome do insumo que será enviado\n";

        std::cout << "\n[Pressione 0 para voltar]\n";        
        
        std::cout << "\n-------------------------------------------------------------\n";
        
        std::getline(std::cin, selection);

        if(selection == "0"){
            flag = true;
            
        }else{
            
            index = controller.pesquisar("BR", selection, 1);

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
                
                } else if(quantidade > controller.getLocais()[0].getInsumos()[index]->getEstoque() || quantidade < 1){ 
                    std::cout << "\nQuantidade inválida!\n";

                    std::cout << "\n[Pressione enter para tentar novamente]\n\n";
                    getchar();

                } else {
                    controller.distribuiInsumos(index, estado, quantidade);

                }
            }
        }
    }
}

void Menu :: menuEnviarParaEstado(Controller &controller){

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
            int index = controller.pesquisar(selection, "", 2);

            if(index == -1){
                std::cout << "\nNão foi identificado nenhum estado com a sigla \"" << selection << "\".\n";

                std::cout << "\n[Pressione enter para tentar novamente]\n";
                getchar();

            }else{
                menuEnviarInsumo(controller, index); // Chama menu para selecionar tipo de insumo a ser enviado
            
            }
        }
    } 
}