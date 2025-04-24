#include <iostream>

using namespace std;

//Funciones para proceso de comparacion
void sumarMascara(unsigned short int *arrayCopia, unsigned char *arrayMascara, int numBytesMascara)
{
    for (int i = 0; i < numBytesMascara; i++) {
        *(arrayCopia + i) = *(arrayCopia + i) + *(arrayMascara + i);
    }
}

bool comparar(unsigned int *arrayTexto, int nBytes, unsigned short int *arrayCopia)
{
    for (int i = 0; i < nBytes; i++) {
        if (static_cast<unsigned short int>(*(arrayCopia + i)) != *(arrayTexto + i)) {
            return false;
        }
    }
    return true;
}
