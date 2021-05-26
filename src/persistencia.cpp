#include "persistencia.h"

using namespace std;

void Persistencia :: inicializacao(Controller &controller){

    string s;
    string delimiter = ",";
    string token;
    size_t pos = 0;
    
    vector <vector <string>> dados;
    vector <string> informacoes;

    bool flag = false;

    string arquivos[3] = {"vacinas.csv", "medicamentos.csv", "epi.csv"};

    for(int i = 0; i < 3; i++){

        ifstream file;
        file.open(arquivos[i]);

        if(file.is_open()){
            while(getline(file, s)){

                if(!flag){
                    flag = true;
                    continue;
                }

                informacoes.clear();

                while((pos = s.find(delimiter)) != std::string::npos) {
                    token = s.substr(0, pos);
                    informacoes.push_back(token);
                    s.erase(0, pos + delimiter.length());
                }

                informacoes.push_back(s);

                dados.push_back(informacoes);

            }
            
            file.close();
            
        }else{
            cout << "---Problema ao abrir o arquivo---" <<endl;
        }

        flag = false;
    }

    Insumo *insumo;

    for(int i = 0; i < dados.size(); i++){

        int index = controller.pesquisar(dados[i][0], "", 2);

        if(dados[i][1] == "Vacina"){ // se vacina

            dados[i].erase(dados[i].begin());
            dados[i].erase(dados[i].begin()); 

            insumo = new Vacina;
            insumo->coletaDados(dados[i]);

        }

        if(dados[i][1] == "Medicamento"){ // se medicamento

            dados[i].erase(dados[i].begin());
            dados[i].erase(dados[i].begin());

            insumo = new Medicamento;
            insumo->coletaDados(dados[i]);

        }

        if(dados[i][1] == "EPI"){ // se epi

            dados[i].erase(dados[i].begin());
            dados[i].erase(dados[i].begin()); 

            insumo = new EPI;
            insumo->coletaDados(dados[i]);

        }

        controller.setarDado(index, insumo);
    }
}

void Persistencia :: finalizacao(Controller &controller){

    ofstream del;
    ofstream init;

    string arquivos[3] = {"vacinas.csv", "medicamentos.csv", "epi.csv"};  
    string arquivosInfo[3] = {

    "estado,tipo,nome,fabricante,dataDeValidade,descricao,valor,estoque,tecnologia,dosesNecessarias,intervaloDoses,eficaciaGeral,temperaturaArmazenada", 
    "estado,tipo,nome,fabricante,dataDeValidade,descricao,valor,estoque,modoAdministracao,tipoDisponibilizado,contraIndicacao,efeitosColaterais", 
    "estado,tipo,nome,fabricante,dataDeValidade,descricao,valor,estoque,material,quantidadeDeUsos"
    
    };

    for(int i = 0; i < 3; i++){
        del.open(arquivos[i], ofstream::out | ofstream::trunc);
        del.close();

        init.open(arquivos[i], ios_base::app);
        init << arquivosInfo[i];
        init.close();
    }

    vector <Local> auxiliar = controller.getLocais();

    Insumo *insumo;

    for(int i = 0; i < auxiliar.size(); i++){

        for(int j = 0; j < auxiliar[i].getInsumos().size(); j++){

            if(auxiliar[i].getInsumos()[j]->getTipo() == 1){ // Vacina

                insumo = new Vacina;
                insumo = auxiliar[i].getInsumos()[j];

                insumo->salvarDados(auxiliar[i].getSigla());

            }
            
            if(auxiliar[i].getInsumos()[j]->getTipo() == 2){ // Medicamento

                insumo = new Medicamento;    
                insumo = auxiliar[i].getInsumos()[j];

                insumo->salvarDados(auxiliar[i].getSigla());

            }
            
            if(auxiliar[i].getInsumos()[j]->getTipo() == 3){ // EPI

                insumo = new EPI;    
                insumo = auxiliar[i].getInsumos()[j];

                insumo->salvarDados(auxiliar[i].getSigla());

            }
        }
    }
}