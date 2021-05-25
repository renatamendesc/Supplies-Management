#include <iostream>
#include <fstream>
#include <vector>

#include "controller.h"

using namespace std;

Controller controller;

int main(void){

    string s;
    string delimiter = ",";
    string token;
    size_t pos = 0;
    
    vector <vector<string>> dados;
    vector <string> informacoes;

    bool flag = false;

    ifstream file;
    file.open("../vacinas.csv");

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
    }

    else{
        cout << "---Problema ao abrir o arquivo---" <<endl;
    }

    for(int i = 0; i < dados.size(); i++){

        if(stoi(dados[i][1]) == 1){ // se vacina

            int index = controller.pesquisar(dados[i][0], "", 2)

            dados[i].erase(dados[i].begin());
            dados[i].erase(dados[i].begin());

            controller.getLocais()[index].setInsumo(dados[i])

        }

        if(stoi(dados[i][1]) == 2){ // se medicamento

        }

        if(stoi(dados[i][1]) == 3){ // se epi

        }


        for(int j = 0; j < informacoes.size(); j++){
            cout << dados[i][j] << endl;
        }
        cout <<endl;
    }

}