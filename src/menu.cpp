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
        
        cout << "\n-------------- SISTEMA PARA CADASTRO DE INSUMOS --------------\n\n";

        cout << "[1] Cadastrar um insumo\n";
        cout << "[2] Consultar dados\n";
        cout << "[3] Comprar um insumo\n";
        cout << "[4] Modificar dados\n";
        cout << "[5] Enviar um insumo\n";
        cout << "[0] Sair\n";
        
        cout << "\n--------------------------------------------------------------\n";

        cin >> selection;

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
                system("clear");

                cout << "\n-------------------------------------------------------------\n";

                cout << "\nOpção inválida!" << endl;
                cout << "\n[Pressione enter para tentar novamente]\n";

                cout << "\n-------------------------------------------------------------\n";
                
                getchar();
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
        
        cout << "\n--------------------- CONSULTA DE DADOS ---------------------\n\n";

        cout << "[1] Consultar dados do Ministério da Saúde\n";
        cout << "[2] Consultar dados de estados\n";
        cout << "[0] Voltar\n";
        
        cout << "\n-------------------------------------------------------------\n";

        cin >> selection;

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
                system("clear");

                cout << "\n-------------------------------------------------------------\n";

                cout << "\nOpção inválida!" << endl;
                cout << "\n[Pressione enter para tentar novamente]\n";

                cout << "\n-------------------------------------------------------------\n";
                
                getchar();
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
        
        cout << "\n-------------------- CONSULTA DE DADOS (" << local << ") -------------------\n\n";

        cout << "[1] Consultar estoque\n";
        cout << "[2] Consultar informações gerais\n";
        cout << "[0] Voltar\n";
        
        cout << "\n-------------------------------------------------------------\n";

        cin >> selection;

        getchar();

        switch(selection){
            
            case 1:
                this->menuConsultaEstoque(controller, iLocal);
                continue;

            case 2:
                system("clear");

                cout << "\n------------ CONSULTA DE INFORMAÇÕES GERAIS (" << local << ")------------\n\n";

                controller.consultaInsumosDescricao(iLocal);
                continue;

            case 0:
                flag = true;
                continue;

            default:
                system("clear");

                cout << "\n-------------------------------------------------------------\n";

                cout << "\nOpção inválida!" << endl;

                cout << "\n[Pressione enter para tentar novamente]\n";

                cout << "\n-------------------------------------------------------------\n";
                
                getchar();
                continue;
        }
    }
}

void Menu :: menuConsultaEstado(Controller &controller){
    
    string selection;
    bool flag = false;
    
    while(1){

        system("clear");

        if(flag){
            break;
        }

        cout << "\n---------------- CONSULTA DE DADOS DE ESTADOS ----------------\n\n";

        cout << "Informe qual estado você deseja consultar (sigla do estado)\n";

        cout << "\n[Pressione 0 para voltar]\n"; 
        
        cout << "\n-------------------------------------------------------------\n";
        
        getline(cin, selection);

        if(selection == "0"){
            break;  

        }else{

            // Análisa se o estado selecionado existe 
            int index = controller.pesquisar(selection, "", 2);

            if(index == -1){
                system("clear");

                cout << "\n-------------------------------------------------------------\n";

                cout << "\nNão foi identificado nenhum estado com a sigla \"" << selection << "\".\n";

                cout << "\n[Pressione enter para tentar novamente]\n";

                cout << "\n-------------------------------------------------------------\n";

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
        
        cout << "\n------------------ CONSULTA DE ESTOQUE (" << local << ") -----------------\n\n";

        cout << "[1] Consultar estoque por tipo\n";
        cout << "[2] Consultar estoque geral\n";
        cout << "[0] Voltar\n";
        
        cout << "\n-------------------------------------------------------------\n";

        cin >> selection;

        getchar();

        switch(selection){
            
            case 1:
                this->menuConsultaEstoqueTipo(controller, iLocal);
                continue;

            case 2:
                system("clear");

                cout << "\n--------------- CONSULTA DE ESTOQUE GERAL (" << local << ") --------------\n\n";

                controller.consultaInsumosEstoque(iLocal);
                continue;

            case 0:
                flag = true;
                continue;

            default:
                system("clear");

                cout << "\n-------------------------------------------------------------\n";

                cout << "\nOpção inválida!" << endl;
                cout << "\n[Pressione enter para tentar novamente]\n";

                cout << "\n-------------------------------------------------------------\n";
                
                getchar();
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

        cout << "\n------------- CONSULTA DE INSUMOS POR TIPO (" << local << ") --------------\n\n";
        
        cout << "[1] Consultar estoque de vacinas\n";
        cout << "[2] Cadastrar estoque de medicamentos\n";
        cout << "[3] Cadastrar estoque de EPIs\n";
        cout << "[0] Voltar\n";
        
        cout << "\n-------------------------------------------------------------\n";
        
        cin >> selection;
        getchar();

        switch(selection){
            
            case 1:
                system("clear");

                cout << "\n------------ CONSULTA DE ESTOQUE DE VACINAS (" << local << ") ------------\n\n";

                controller.consultaTipoInsumosEstoque(iLocal, 1);
                continue;

            case 2:
                system("clear");

                cout << "\n--------- CONSULTA DE ESTOQUE DE MEDICAMENTOS (" << local << ") ---------\n\n";

                controller.consultaTipoInsumosEstoque(iLocal, 2);
                continue;

            case 3:
                system("clear");

                cout << "\n------------- CONSULTA DE ESTOQUE DE EPIS (" << local << ") --------------\n\n";

                controller.consultaTipoInsumosEstoque(iLocal, 3);
                continue;

            case 0:
                flag = true;
                continue;

            default:
                system("clear");

                cout << "\n-------------------------------------------------------------\n";

                cout << "\nOpção inválida!" << endl;
                cout << "\n[Pressione enter para tentar novamente]\n";

                cout << "\n-------------------------------------------------------------\n";
                
                getchar();
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

        cout << "\n-------------------- CADASTRO DE INSUMOS ---------------------\n\n";
        
        cout << "[1] Cadastrar uma vacina\n";
        cout << "[2] Cadastrar um medicamento\n";
        cout << "[3] Cadastrar um EPI\n";
        cout << "[0] Voltar\n";
        
        cout << "\n-------------------------------------------------------------\n";
        
        cin >> selection;

        getchar();

        switch(selection){
            
            case 1:
                system("clear");

                cout << "\n------------------- CADASTRAR UMA VACINA --------------------\n\n";
                
                controller.cadastraInsumosMinisterio(1);
                continue;

            case 2:
                system("clear");

                cout << "\n----------------- CADASTRAR UM MEDICAMENTO ------------------\n\n";

                controller.cadastraInsumosMinisterio(2);
                continue;

            case 3:
                system("clear");

                cout << "\n--------------------- CADASTRAR UM EPI ----------------------\n\n";

                controller.cadastraInsumosMinisterio(3);
                continue;

            case 0:
                flag = true;
                continue;

            default:
                system("clear");

                cout << "\n-------------------------------------------------------------\n";

                cout << "\nOpção inválida!" << endl;
                cout << "\n[Pressione enter para tentar novamente]\n";

                cout << "\n-------------------------------------------------------------\n";
                
                getchar();
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

        cout << "\n-------------- ACRESCENTAR INSUMOS AO ESTOQUE ---------------\n\n";

        cout << "Informe o nome do insumo que será comprado\n";

        cout << "\n[Pressione 0 para voltar]\n";

        cout << "\n-------------------------------------------------------------\n";
        
        getline(cin, selection);
        
        if(selection == "0"){
            flag = true;

        }else{

            int index = controller.pesquisar("BR", selection, 1);

            system("clear");

            if(index == -1){

                cout << "\n-------------------------------------------------------------\n";

                cout << "\nNão foi identificado nenhum insumo com nome \"" << selection << "\".\n";

                cout << "\n[Pressione enter para tentar novamente]\n";

                cout << "\n-------------------------------------------------------------\n";
                getchar();

            } else {
                int quantidade;
                
                cout << "\n-------------- ACRESCENTAR INSUMOS AO ESTOQUE ----------------\n\n";

                cout << "Informe a quantidade de insumos que deseja adquirir" << endl;

                cout << "\n[Pressione 0 para voltar]\n";

                cout << "\n-------------------------------------------------------------\n";

                cin >> quantidade;

                getchar();

                if(quantidade == 0){
                    continue;
                }

                else if(quantidade < 0){
                    system("clear");

                    cout << "\n-------------------------------------------------------------\n";

                    cout << "\nNão é possível adicionar uma quantidade negativa.\n";

                    cout << "\n[Pressione enter para tentar novamente]\n";

                    cout << "\n-------------------------------------------------------------\n";
                    getchar();

                    continue;
                }

                else{
                    controller.acrescentarInsumos(index, quantidade);

                    system("clear");

                    cout << "\n-------------------------------------------------------------\n\n";

                    cout << "Estoque atualizado com sucesso!" << endl;

                    cout << "\n[Pressione enter para prosseguir]\n";

                    cout << "\n-------------------------------------------------------------\n";

                    getchar();

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

        cout << "\n--------------------- MODIFICAR INSUMOS --------------------\n\n";
        
        cout << "[1] Modificar dados de insumos\n";
        cout << "[2] Apagar dados de insumos\n";
        cout << "[0] Voltar\n";

        cout << "\n------------------------------------------------------------\n";

        cin >> selection;

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
                system("clear");

                cout << "\n-------------------------------------------------------------\n";

                cout << "\nOpção inválida!" << endl;
                cout << "\n[Pressione enter para tentar novamente]\n";

                cout << "\n-------------------------------------------------------------\n";
                
                getchar();
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

        cout << "\n----------------------- APAGAR INSUMOS ---------------------\n\n";
        
        cout << "[1] Apagar um insumo\n";
        cout << "[2] Apagar todos os insumos\n";
        cout << "[0] Voltar\n";

        cout << "\n------------------------------------------------------------\n";

        cin >> selection;

        getchar();

        switch(selection){

            case 0:
                flag = true;
                continue;

            case 1:
                this->menuApagarInsumo(controller);
                continue;

            case 2:

                int selection; 

                while(true){
                    system("clear");

                    cout << "\n-------------------------------------------------------------\n";

                    cout << "\nDeseja mesmo apagar todos os insumos?\n";
                    cout << "[1] Sim\n";
                    cout << "[2] Não\n";

                    cout << "\nATENÇÃO: Ao confirmar esta ação, todos os dados cadastrados\nno sistema serão deletados!\n";

                    cout << "\n-------------------------------------------------------------\n";

                    cin >> selection;

                    system("clear");

                    if(selection == 1){            
                        controller.apagarDados();

                        cout << "\n-------------------------------------------------------------\n";

                        cout << "\nDados apagados com sucesso!\n";
                        cout << "\n[Pressione enter para prosseguir]\n";

                        cout << "\n-------------------------------------------------------------\n";

                        controller.pause();
                        break;
                    
                    } else if(selection == 2){
                        cout << "\n-------------------------------------------------------------\n";

                        cout << "\nAlterações descartadas!\n";
                        cout << "\n[Pressione enter para prosseguir]\n";

                        cout << "\n-------------------------------------------------------------\n";

                        controller.pause();
                        break;

                    } else {
                        cout << "\n-------------------------------------------------------------\n";

                        cout << "\nOpção inválida!" << endl;
                        cout << "\n[Pressione enter para tentar novamente]\n";

                        cout << "\n-------------------------------------------------------------\n";
                        
                        controller.pause();
                        continue;

                    }
                }
                continue;

            default:
                system("clear");

                cout << "\n-------------------------------------------------------------\n";

                cout << "\nOpção inválida!\n";
                cout << "\n[Pressione enter para tentar novamente]\n";

                cout << "\n-------------------------------------------------------------\n";

                getchar();
                continue;
        }
    }
}

void Menu :: menuApagarInsumo(Controller &controller){
    string selection; 
    bool flag = false;
    int index;

    while(true){
        if(flag){
            break;
        }

        system("clear");

        cout << "\n---------------------- APAGAR INSUMOS ----------------------\n\n";
        
        cout << "Informe o nome do insumo que será apagado\n";

        cout << "\n[Pressione 0 para voltar]\n";        
        
        cout << "\n------------------------------------------------------------\n";

        getline(cin, selection);

        if(selection == "0"){
            flag = true;
            
        }else{
            
            index = controller.pesquisar("BR", selection, 1);

            system("clear");

            if(index == -1){
                cout << "\n-------------------------------------------------------------\n";

                cout << "\nNão foi identificado nenhum insumo com nome \"" << selection << "\".\n";

                cout << "\n[Pressione enter para tentar novamente]\n";

                cout << "\n-------------------------------------------------------------\n";
                getchar();
                
            } else {

                while(true){
                    system("clear");

                    cout << "\n-------------------------------------------------------------\n";

                    cout << "\nDeseja mesmo apagar \"" << selection << "\" e todos os dados relacionados\na esse insumo?\n";
                    cout << "[1] Sim\n";
                    cout << "[2] Não\n";

                    cout << "\n-------------------------------------------------------------\n";

                    int selection; 
                    cin >> selection;

                    system("clear");

                    if(selection == 1){            
                        controller.apagarInsumo(index);

                        cout << "\n-------------------------------------------------------------\n";

                        cout << "\nInsumo deletado com sucesso!\n";
                        cout << "\n[Pressione enter para prosseguir]\n";

                        cout << "\n-------------------------------------------------------------\n";

                        controller.pause();
                        break;
                    
                    } else if(selection == 2){
                        cout << "\n-------------------------------------------------------------\n";

                        cout << "\nAlterações descartadas!\n";
                        cout << "\n[Pressione enter para prosseguir]\n";

                        cout << "\n-------------------------------------------------------------\n";

                        controller.pause();
                        break;

                    } else {
                        cout << "\n-------------------------------------------------------------\n";

                        cout << "\nOpção inválida!" << endl;
                        cout << "\n[Pressione enter para tentar novamente]\n";

                        cout << "\n-------------------------------------------------------------\n";
                        
                        controller.pause();
                        continue;

                    }
                }
            }
        }
    }
}

void Menu :: menuModificar(Controller &controller){

    string selection; 
    bool flag = false;
    int index;

    while(true){
        if(flag){
            break;
        }

        system("clear");

        cout << "\n--------------------- MODIFICAR INSUMOS --------------------\n\n";
        
        cout << "Informe o nome do insumo que será modificado\n";

        cout << "\n[Pressione 0 para voltar]\n";        
        
        cout << "\n------------------------------------------------------------\n";

        getline(cin, selection);

        if(selection == "0"){
            flag = true;
            
        }else{            
            index = controller.pesquisar("BR", selection, 1);

            system("clear");

            if(index == -1){
                cout << "\n-------------------------------------------------------------\n";

                cout << "\nNão foi identificado nenhum insumo com nome \"" << selection << "\".\n";

                cout << "\n[Pressione enter para tentar novamente]\n";

                cout << "\n-------------------------------------------------------------\n";
                getchar();

            } else {
                cout << "\n--------------------- MODIFICAR INSUMOS --------------------\n\n";

                controller.modificarInsumo(index);    

                system("clear");

                cout << "\n-------------------------------------------------------------\n";

                cout << "\nAlterações salvas com sucesso!\n";
                cout << "\n[Pressione enter para prosseguir]\n";

                cout << "\n-------------------------------------------------------------\n";
                getchar();
                
            }
        }
    }
}

void Menu :: menuEnviarInsumo(Controller &controller,int estado){

    bool flag = 0;
    string selection;
    int index;
    
    while(true){

        system("clear");

        if(flag)
            break;

        cout << "\n------------ SELECIONE O NOME DO INSUMO DESEJADO -----------\n\n";

        cout << "Informe o nome do insumo que será enviado\n";

        cout << "\n[Pressione 0 para voltar]\n";        
        
        cout << "\n-------------------------------------------------------------\n";
        
        getline(cin, selection);

        if(selection == "0"){
            flag = true;
            
        }else{
            
            index = controller.pesquisar("BR", selection, 1);

            system("clear");

            if(index == -1){
                cout << "\n-------------------------------------------------------------\n";

                cout << "\nNão foi identificado nenhum insumo com nome \"" << selection << "\".\n";

                cout << "\n[Pressione enter para tentar novamente]\n";

                cout << "\n-------------------------------------------------------------\n";
                getchar();

            } else {
                
                int quantidade;
                
                cout << "\n---------------- ENVIAR INSUMOS AOS ESTADOS ------------------\n\n";

                cout << "Informe a quantidade de insumos que deseja enviar" << endl;

                cout << "\n[Pressione 0 para voltar]\n";

                cout << "\n-------------------------------------------------------------\n";

                cin >> quantidade;

                getchar();

                if(quantidade == 0){
                    continue;
                
                } else if(quantidade > controller.getLocais()[0].getInsumos()[index]->getEstoque() || quantidade < 1){ 
                    system("clear");

                    cout << "\n-------------------------------------------------------------\n";
                    
                    cout << "\nQuantidade inválida!\n";
                    cout << "\n[Pressione enter para tentar novamente]\n";

                    cout << "\n-------------------------------------------------------------\n";
                    getchar();

                } else {
                    system("clear");

                    controller.distribuiInsumos(index, estado, quantidade);

                    cout << "\n-------------------------------------------------------------\n";

                    cout << "\nInsumo enviado com sucesso!\n";
                    cout << "\n[Pressione enter para prosseguir]\n";

                    cout << "\n-------------------------------------------------------------\n";
                    getchar();
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

        cout << "\n----------------- ENVIAR INSUMOS PARA ESTADOS ----------------\n\n";

        cout << "Informe para qual estado você deseja enviar (sigla do estado)\n";

        cout << "\n[Pressione 0 para voltar]\n"; 
        
        cout << "\n-------------------------------------------------------------\n";
        
        getline(cin, selection);

        if(selection == "0"){
            break;  

        }else{

            // Analise se o estado selecionado existe: 
            int index = controller.pesquisar(selection, "", 2);

            if(index == -1){
                system("clear");

                cout << "\n-------------------------------------------------------------\n";

                cout << "\nNão foi identificado nenhum estado com a sigla \"" << selection << "\".\n";

                cout << "\n[Pressione enter para tentar novamente]\n";

                cout << "\n-------------------------------------------------------------\n";
                getchar();

            }else{
                menuEnviarInsumo(controller, index); // Chama menu para selecionar tipo de insumo a ser enviado
            
            }
        }
    } 
}