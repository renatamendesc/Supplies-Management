#include "controller.h"

using namespace std;

Controller :: Controller(){
    vector <string> siglas = {"BR", "AC", "AL", "AP", "AM", "BA", "CE", "DF", "ES", "GO", "MA", "MT", "MS", "MG", "PA", "PB", "PR", "PE", "PI", "RJ", "RN", "RS", "RR", "RO", "SC", "SP", "SE", "TO"};
    
    // Incializa vector de locais com estados e Ministério da Saúde
    for(int i = 0; i < siglas.size(); i++){
        Local local;

        local.setSigla(siglas[i]);
        this->locais.push_back(local);
    }
}

vector <Local> Controller :: getLocais(){
    return locais;
}

void Controller :: cadastraInsumosMinisterio(int tipo){
    
    Insumo *insumo;

    // Verifica o tipo do insumo
    switch(tipo){
        case 1:
            insumo = new Vacina();
            break;

        case 2:
            insumo = new Medicamento();
            break;

        case 3:
            insumo = new EPI();
            break;
    }

    // Faz a leitura das informações do insumo em questão
    insumo->cadastraAtributos();

    while(true){
        int selection;

        system("clear");

        std::cout << "\n-------------------------------------------------------------\n";

        cout << "\nDeseja mesmo salvar o cadastro?" <<endl;
        cout << "[1] Sim" << endl;
        cout << "[2] Não" << endl;

        std::cout << "\n-------------------------------------------------------------\n";

        cin >> selection;

        system("clear");

        if(selection == 1){            
            this->locais[0].setInsumo(insumo); // Adiciona o insumo no estoque do Ministério da Saúde
            
            cout << "\n-------------------------------------------------------------\n";
            
            cout << "\nCadastro salvo com sucesso!\n";
            cout << "\n[Pressione enter para prosseguir]\n";

            cout << "\n-------------------------------------------------------------\n";

            this->pause();
            break;
        
        } else if(selection == 2){
            cout << "\n-------------------------------------------------------------\n";

            cout << "\nCadastro descartado!\n";
            cout << "\n[Pressione enter para prosseguir]\n";

            cout << "\n-------------------------------------------------------------\n";
            
            this->pause();
            break;

        } else {
            cout << "\n-------------------------------------------------------------\n";

            cout << "\nOpção inválida!" << endl;
            cout << "\n[Pressione enter para tentar novamente]\n";

            cout << "\n-------------------------------------------------------------\n";
            
            this->pause();
            continue;

        }
    } 
}

void Controller :: distribuiInsumos(int iInsumo, int iLocal, int unidades){
    bool flag = false;
    int iInsumoEstado;

    // Verificação se o insumo em questão já existe no estoque do estado
    for(int i = 0; i < this->locais[iLocal].getInsumos().size(); i++){
        if(this->locais[iLocal].getInsumos()[i]->getNome() == this->locais[0].getInsumos()[iInsumo]->getNome()){
            flag = true;
            iInsumoEstado = i;
            break;
        }
    }

    if(!flag){ // Caso o insumo não exista no estado
        this->locais[iLocal].setInsumo(this->locais[0].getInsumos()[iInsumo]);
        this->locais[iLocal].adicionarEstoque(unidades);

    } else { // Caso já exista o insumo no estado
        int estoqueAtual = this->locais[iLocal].getInsumos()[iInsumoEstado]->getEstoque();
        this->locais[iLocal].adicionarEstoque(estoqueAtual + unidades);

    }

    // A quantidade enviada é debitada do estoque do Ministério da Saúde
    int estoqueAtual = this->locais[0].getInsumos()[iInsumo]->getEstoque();

    this->locais[0].getInsumos()[iInsumo]->setEstoque(estoqueAtual - unidades);

}

void Controller :: consultaInsumosEstoque(int iLocal){

    if(this->locais[iLocal].getInsumos().size() == 0){
        cout << "\nNão há nada cadastrado no sistema!\n";
    }

    // Percorre insumos existentes no local
    for(int i = 0; i < this->locais[iLocal].getInsumos().size(); i++){

        // Exibe informações do insumo
        cout << this->locais[iLocal].getInsumos()[i]->getNome() << ": " << this->locais[iLocal].getInsumos()[i]->getEstoque() << endl;
    }

    cout << "\n[Pressione enter para voltar]\n";
    getchar();
}

void Controller :: consultaTipoInsumosEstoque(int iLocal, int tipo){

    int contador = 0;
    
    // Percorre insumos existentes no local
    for(int i = 0; i < this->locais[iLocal].getInsumos().size(); i++){

        // Exibe informações do insumo se for do tipo em questão
        if(this->locais[iLocal].getInsumos()[i]->getTipo() == tipo){
            cout << this->locais[iLocal].getInsumos()[i]->getNome() << ": " << this->locais[iLocal].getInsumos()[i]->getEstoque() << endl;
            contador++;
        }
    }

    if(contador == 0){
        cout << "\nNão há nada cadastrado no sistema!\n";
    }

    cout << "\n[Pressione enter para voltar]\n";
    getchar();
}

void Controller :: consultaInsumosDescricao(int iLocal){
    
    if(this->locais[iLocal].getInsumos().size() == 0){
        cout << "\nNão há nada cadastrado no sistema!\n";
    }

    // Percorre insumos existentes no local
    for(int i = 0; i < this->locais[iLocal].getInsumos().size(); i++){

        // Exibe informações do insumo
        this->locais[iLocal].getInsumos()[i]->exibeInformacoes();
        cout << endl;

    }

    cout << "[Pressione enter para voltar]\n";
    getchar();

}

void Controller :: modificarInsumo(int iInsumo){

    this->locais[0].recadastraInsumo(iInsumo);
}

void Controller :: apagarInsumo(int iInsumo){

    this->locais[0].apagarInsumo(iInsumo);

}

void Controller :: apagarDados(){
    for(int i = 0; i < this->locais.size(); i++){
        this->locais[i].getInsumos().clear();
    }
}

void Controller :: acrescentarInsumos(int iInsumo, int unidades){

    int estoqueAtual = this->locais[0].getInsumos()[iInsumo]->getEstoque();
    this->locais[0].getInsumos()[iInsumo]->setEstoque(estoqueAtual + unidades);

}

int Controller :: pesquisar(string estado, string insumo, int tipo){ // (1- insumo) (2- estado)

    switch(tipo){

        case 1: {
            int index = this->pesquisar(estado, "", 2);
            
            for(int i = 0; i < this->locais[index].getInsumos().size(); i++){
                if(this->locais[index].getInsumos()[i]->getNome() == insumo){
                    return i;
                }
            }

            return -1;
        }

        case 2: {

            for(int i = 0; i < this->locais.size(); i++){
                if(this->locais[i].getSigla() == estado){
                    return i;
                }
            }

            return -1;
        }
    }
}

void Controller :: setarDado(int iLocal, Insumo *insumo){

    this->locais[iLocal].setInsumo(insumo);
}

void Controller :: pause(){
    getchar();
    getchar();
}