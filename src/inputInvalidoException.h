#ifndef INPUT_INVALIDO_H
#define INPUT_INVALIDO_H

#include <iostream>

class InputInvalidoException : public std::exception{

    public:
        InputInvalidoException();
        void treat(bool);

};

#endif