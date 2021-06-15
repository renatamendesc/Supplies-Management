#include "persistencia.h"

using namespace std;

void Persistencia :: inicializacao(Controller &controller){ // Método para coletar os dados

    string s;
    string delimiter = ","; // Delimitador dos atributos no arquivo (csv)
    string token;
    size_t pos = 0;
    
    vector <vector <string>> dados;
    vector <string> informacoes;

    bool flag = false;

    string arquivos[3] = {"dados/vacinas.csv", "dados/medicamentos.csv", "dados/epi.csv"}; // Array do path dos arquivos

    for(int i = 0; i < 3; i++){ 

        ifstream file; 
        file.open(arquivos[i]); // Abre arquivo do insumo

        if(file.is_open()){
            while(getline(file, s)){ 

                if(!flag){ // Evitar a leitura do nome das colunas
                    flag = true;
                    continue;
                }

                informacoes.clear(); // Limpa o vetor de informações

                while((pos = s.find(delimiter)) != std::string::npos) { // Para cada atributo
                    token = s.substr(0, pos);
                    informacoes.push_back(token); // Salva seu valor em informações
                    s.erase(0, pos + delimiter.length());
                }

                informacoes.push_back(s); // Salva o ultimo elemento, depois da ultima virgula

                dados.push_back(informacoes); // Salva no vetor de dados

            }
            
            file.close(); // Fecha o arquivo
            
        }else{
            cout << "---Problema ao abrir o arquivo---" <<endl;
        }

        flag = false;
    }

    Insumo *insumo;

    for(int i = 0; i < dados.size(); i++){

        int index = controller.pesquisar(dados[i][0], "", 2); // Pega o indice do estado

        if(dados[i][1] == "Vacina"){

            dados[i].erase(dados[i].begin()); // Apaga os atributos estado e tipo que não serão mais usadas
            dados[i].erase(dados[i].begin()); 

            insumo = new Vacina;
            insumo->coletaDados(dados[i]); // Chamada da coleta de dados

        }

        if(dados[i][1] == "Medicamento"){

            dados[i].erase(dados[i].begin()); // Apaga os atributos estado e tipo que não serão mais usadas
            dados[i].erase(dados[i].begin());

            insumo = new Medicamento;
            insumo->coletaDados(dados[i]); // Chamada da coleta de dados

        }

        if(dados[i][1] == "EPI"){

            dados[i].erase(dados[i].begin()); // Apaga os atributos estado e tipo que não serão mais usadas
            dados[i].erase(dados[i].begin()); 

            insumo = new EPI;
            insumo->coletaDados(dados[i]); // Chamada da coleta de dados

        }

        controller.setarDado(index, insumo); // Salva o insumo no seu estado (em locais)
    }
}

void Persistencia :: finalizacao(Controller &controller){ // Método para salvar os dados

    ofstream del;
    ofstream init;

    string arquivos[3] = {"dados/vacinas.csv", "dados/medicamentos.csv", "dados/epi.csv"};  // Array de paths dos arquivos
    string arquivosInfo[3] = {

    "estado,tipo,nome,fabricante,dataDeValidade,descricao,valor,estoque,tecnologia,dosesNecessarias,intervaloDoses,eficaciaGeral,temperaturaArmazenada", 
    "estado,tipo,nome,fabricante,dataDeValidade,descricao,valor,estoque,modoAdministracao,tipoDisponibilizado,contraIndicacao,efeitosColaterais", 
    "estado,tipo,nome,fabricante,dataDeValidade,descricao,valor,estoque,material,quantidadeDeUsos"
    
    }; // Array de nomes das colunas

    for(int i = 0; i < 3; i++){
        del.open(arquivos[i], ofstream::out | ofstream::trunc); // Abre o arquivo apagando tudo
        del.close();

        init.open(arquivos[i], ios_base::app); // Abre o arquivo salvando o nome das colunas
        init << arquivosInfo[i];
        init.close();
    }

    vector <Local> auxiliar = controller.getLocais(); // Pega todo o vetor de locais

    Insumo *insumo;

    for(int i = 0; i < auxiliar.size(); i++){ // Para cada estado

        for(int j = 0; j < auxiliar[i].getInsumos().size(); j++){ // Para cada insumo

            if(auxiliar[i].getInsumos()[j]->getTipo() == 1){

                insumo = new Vacina;
                insumo = auxiliar[i].getInsumos()[j]; // Pega os dados do insumo

                insumo->salvarDados(auxiliar[i].getSigla()); // Chama fumção para salvar dados

            }
            
            if(auxiliar[i].getInsumos()[j]->getTipo() == 2){ 

                insumo = new Medicamento;    
                insumo = auxiliar[i].getInsumos()[j]; // Pega os dados do insumo

                insumo->salvarDados(auxiliar[i].getSigla()); // Chama fumção para salvar dados

            }
            
            if(auxiliar[i].getInsumos()[j]->getTipo() == 3){

                insumo = new EPI;    
                insumo = auxiliar[i].getInsumos()[j]; // Pega os dados do insumo

                insumo->salvarDados(auxiliar[i].getSigla()); // Chama fumção para salvar dados

            }
        }
    }
}