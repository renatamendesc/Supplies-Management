#include <iostream

class ExceptionTypeError{

    public:
        ExceptionTypeError();
        void treat();

};

ExceptionTypeError :: ExceptionTypeError(){
    cin.exceptions(istream::failbit);
}

void ExceptionTypeError :: treat(){
    cout << "Valor inválido, tente novamente!" << endl;
    cin.clear();
    string tmp;
    getline(cin, tmp);
    getchar();
    continue;
}