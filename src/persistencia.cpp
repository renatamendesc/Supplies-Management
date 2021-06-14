#include "persistencia.h"

using namespace std;

void Persistencia :: inicializacao(Controller &controller){ // função para coletar os dados

    string s;
    string delimiter = ","; //delimitador dos atributos no arquivo (csv)
    string token;
    size_t pos = 0;
    
    vector <vector <string>> dados;
    vector <string> informacoes;

    bool flag = false; //booleano para evitar a leitura do nome das colunas

    string arquivos[3] = {"dados/vacinas.csv", "dados/medicamentos.csv", "dados/epi.csv"}; //array do path dos arquivos

    for(int i = 0; i < 3; i++){ //repete para cada arquivo

        ifstream file; //instancia objeto de leitura de arquivo
        file.open(arquivos[i]); // abre arquivo do insumo

        if(file.is_open()){ //garante abertura do arquivo
            while(getline(file, s)){ //pega insumo por insumo

                if(!flag){ // evitar a leitura do nome das colunas
                    flag = true;
                    continue;
                }

                informacoes.clear(); // limpa o vetor de informações

                while((pos = s.find(delimiter)) != std::string::npos) { // para cada atributo
                    token = s.substr(0, pos);
                    informacoes.push_back(token); // salva seu valor em informações
                    s.erase(0, pos + delimiter.length());
                }

                informacoes.push_back(s); // salva o ultimo elemento, depois da ultima virgula

                dados.push_back(informacoes); // salva no vetor de dados

            }
            
            file.close(); // fecha o arquivo
            
        }else{
            cout << "---Problema ao abrir o arquivo---" <<endl;
        }

        flag = false;
    }

    Insumo *insumo;

    for(int i = 0; i < dados.size(); i++){ // para cada estado

        int index = controller.pesquisar(dados[i][0], "", 2); //pega o indice do estado

        if(dados[i][1] == "Vacina"){ // se vacina

            dados[i].erase(dados[i].begin()); // apaga os atributos estado e tipo que não serão mais usadas
            dados[i].erase(dados[i].begin()); 

            insumo = new Vacina;
            insumo->coletaDados(dados[i]); // chamada da coleta de dados

        }

        if(dados[i][1] == "Medicamento"){ // se medicamento

            dados[i].erase(dados[i].begin());// apaga os atributos estado e tipo que não serão mais usadas
            dados[i].erase(dados[i].begin());

            insumo = new Medicamento;
            insumo->coletaDados(dados[i]); // chamada da coleta de dados

        }

        if(dados[i][1] == "EPI"){ // se epi

            dados[i].erase(dados[i].begin());// apaga os atributos estado e tipo que não serão mais usadas
            dados[i].erase(dados[i].begin()); 

            insumo = new EPI;
            insumo->coletaDados(dados[i]); // chamada da coleta de dados

        }

        controller.setarDado(index, insumo); // salva o insumo no seu estado (em locais)
    }
}

void Persistencia :: finalizacao(Controller &controller){ // função para salvar os dados

    ofstream del;
    ofstream init;

    string arquivos[3] = {"dados/vacinas.csv", "dados/medicamentos.csv", "dados/epi.csv"};  // array de paths dos arquivos
    string arquivosInfo[3] = {

    "estado,tipo,nome,fabricante,dataDeValidade,descricao,valor,estoque,tecnologia,dosesNecessarias,intervaloDoses,eficaciaGeral,temperaturaArmazenada", 
    "estado,tipo,nome,fabricante,dataDeValidade,descricao,valor,estoque,modoAdministracao,tipoDisponibilizado,contraIndicacao,efeitosColaterais", 
    "estado,tipo,nome,fabricante,dataDeValidade,descricao,valor,estoque,material,quantidadeDeUsos"
    
    }; // array de nomes das colunas

    for(int i = 0; i < 3; i++){ // para cada arquivo
        del.open(arquivos[i], ofstream::out | ofstream::trunc); // abre o arquivo apagando tudo
        del.close();

        init.open(arquivos[i], ios_base::app); // abre o arquivo salvando o nome das colunas
        init << arquivosInfo[i];
        init.close();
    }

    vector <Local> auxiliar = controller.getLocais(); // pega todo o vetor de locais

    Insumo *insumo;

    for(int i = 0; i < auxiliar.size(); i++){ // para cada estado

        for(int j = 0; j < auxiliar[i].getInsumos().size(); j++){ // para cada insumo

            if(auxiliar[i].getInsumos()[j]->getTipo() == 1){ // se Vacina

                insumo = new Vacina;
                insumo = auxiliar[i].getInsumos()[j]; //pega os dados do insumo

                insumo->salvarDados(auxiliar[i].getSigla());//chama fumção para salvar dados

            }
            
            if(auxiliar[i].getInsumos()[j]->getTipo() == 2){ // se Medicamento

                insumo = new Medicamento;    
                insumo = auxiliar[i].getInsumos()[j]; //pega os dados do insumo

                insumo->salvarDados(auxiliar[i].getSigla()); //chama fumção para salvar dados

            }
            
            if(auxiliar[i].getInsumos()[j]->getTipo() == 3){ // se EPI

                insumo = new EPI;    
                insumo = auxiliar[i].getInsumos()[j]; //pega os dados do insumo

                insumo->salvarDados(auxiliar[i].getSigla()); //chama fumção para salvar dados

            }
        }
    }
}