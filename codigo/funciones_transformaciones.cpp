#include <iostream>

using namespace std;

unsigned char *desplazamientoDerecha(unsigned char* array, int semilla, unsigned char *arrayCopia, int bytesMascara, unsigned char numDesplazamiento){
    for (int i = 0; i < bytesMascara; semilla ++, i ++) {
        *(arrayCopia + i) = *(array + semilla) >> numDesplazamiento;
    }
    return arrayCopia;
}

unsigned char *desplazamientoIzquierda(unsigned char* array, int semilla, unsigned char *arrayCopia,int bytesMascara, unsigned char numDesplazamiento){
    for (int i = 0; i < bytesMascara; semilla ++, i ++) {
        *(arrayCopia + semilla) = *(array + semilla) << numDesplazamiento;
    }
    return arrayCopia;
}

unsigned char *rotacionDerecha(unsigned char* array, int semilla, unsigned char *arrayCopia,int bytesMascara, unsigned char numRotacion){
    for (int i = 0; i < bytesMascara; semilla ++, i ++) {
        unsigned char byte = *(array + semilla);
        unsigned char bitsDerecha = byte >> numRotacion;
        unsigned char bitsMovidoAIzquierda = byte << (8 - numRotacion);
        *(arrayCopia + i) = bitsDerecha | bitsMovidoAIzquierda;
    }

    return arrayCopia;
}

unsigned char *rotacionIzquierda(unsigned char* array, int semilla, unsigned char *arrayCopia, int bytesMascara, unsigned char numRotacion){
    for (int i = 0; i < bytesMascara; semilla ++, i ++) {
        unsigned char byte = *(array + semilla);
        unsigned char bitsIzquierda = byte << numRotacion;
        unsigned char bitsMovidoADerecha = byte >> (8 - numRotacion);
        *(arrayCopia + i) = bitsIzquierda | bitsMovidoADerecha;
    }

    return arrayCopia;
}

unsigned char *xorEntreImagenes(unsigned char *arrayImagen, unsigned char *arrayImagenI_M, int bytesImagenes){
    for (int i = 0; i < bytesImagenes; i++) {
        *(arrayImagen + i) = *(arrayImagen + i) ^ *(arrayImagenI_M + i);
    }
    return arrayImagen;
}

bool comparar(unsigned int* arrayTexto, int nBytes, unsigned char *arrayTransformado, unsigned char *arrayMascara){
    for (int i = 0; i < nBytes; i ++){
        if( (*(arrayTransformado + i))-(*(arrayMascara+i)) != (*(arrayTexto+i)) ){
            return false;
        }
    }
    return true;
}
