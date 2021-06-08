#include "inputInvalidoException.h"
#include <cstdlib>

#include <iostream>

using namespace std;

InputInvalidoException :: InputInvalidoException(){
    cin.exceptions(istream::failbit);
}

void InputInvalidoException :: treat(bool erase){

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

    cin.clear();
    string tmp;
    getline(cin, tmp);
    getchar();

    if(erase){
        system("clear");
    }

}