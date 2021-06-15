#include "inputInvalidoException.h"
#include <cstdlib>

#include <iostream>

using namespace std;

InputInvalidoException :: InputInvalidoException(){
    cin.exceptions(istream::failbit);
}

void InputInvalidoException :: treat(bool erase){
    
    // Verifica se é necessario apagar a exibição anterior
    if(erase){

        system("clear");

        cout << "\n-------------------------------------------------------------\n";

        cout << "\nOpção inválida!\n";
        cout << "\n[Pressione enter para tentar novamente]\n";

        cout << "\n-------------------------------------------------------------\n";

    }else{

        cout << "\n--------------------------------------------------------------\n";

        cout << "\n             Valor inválido, tente novamente!\n";
        cout << "\n          [Pressione enter para tentar novamente]\n";
    
        cout << "\n--------------------------------------------------------------\n";

    }

    cin.clear(); // Limpa o cin
    string tmp;
    getline(cin, tmp); // Pega o que restou com uma string auxiliar
    getchar(); 

    // Verifica se é necessario apagar a exibição anterior
    if(erase){
        system("clear");
    }

}