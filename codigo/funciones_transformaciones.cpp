#include <iostream>

using namespace std;

//Funciones de transformaciones sobre la porcion del arreglo

void desplazamientoDerecha(unsigned char *array,
                           int semilla,
                           unsigned short int *arrayCopia,
                           int bytesMascara,
                           unsigned char numDesplazamiento)
{
    for (int i = 0; i < bytesMascara; semilla ++, i ++) {
        *(arrayCopia + i) = *(array + semilla) >> numDesplazamiento;
    }
}

void desplazamientoIzquierda(unsigned char *array,
                             int semilla,
                             unsigned short int *arrayCopia,
                             int bytesMascara,
                             unsigned char numDesplazamiento)
{
    for (int i = 0; i < bytesMascara; semilla ++, i ++) {
        *(arrayCopia + i) = *(array + semilla) << numDesplazamiento;
    }
}

void rotacionDerecha(unsigned char *array,
                     int semilla,
                     unsigned short int *arrayCopia,
                     int bytesMascara,
                     unsigned char numRotacion)
{
    for (int i = 0; i < bytesMascara; semilla ++, i ++) {
        unsigned char byte = *(array + semilla);
        unsigned char bitsDerecha = byte >> numRotacion;
        unsigned char bitsMovidoAIzquierda = byte << (8 - numRotacion);
        *(arrayCopia + i) = bitsDerecha | bitsMovidoAIzquierda;
    }
}

void rotacionIzquierda(unsigned char *array,
                       int semilla,
                       unsigned short int *arrayCopia,
                       int bytesMascara,
                       unsigned char numRotacion)
{
    for (int i = 0; i < bytesMascara; semilla ++, i ++) {
        unsigned char byte = *(array + semilla);
        unsigned char bitsIzquierda = byte << numRotacion;
        unsigned char bitsMovidoADerecha = byte >> (8 - numRotacion);
        *(arrayCopia + i) = bitsIzquierda | bitsMovidoADerecha;
    }
}

void xorEntreImagenes(unsigned short int *arrayCopia,
                      int semilla,
                      unsigned char *arrayI_M,
                      int bytesMascara)
{
    for (int i = 0; i < bytesMascara; semilla++, i++) {
        *(arrayCopia + i) = *(arrayCopia + i) ^ *(arrayI_M + semilla);
    }
}

bool comparar(unsigned int *arrayTexto, int nBytes, unsigned short int *arrayCopia)
{
    for (int i = 0; i < nBytes; i ++){
        if (static_cast<unsigned short int>(*(arrayCopia + i)) != *(arrayTexto + i)) {
            return false;
        }
    }
    return true;
}

//Funciones de transformaciones sobre el arreglo completo
void desplazamientoDerechaImagen(unsigned char *arrayImagen,
                                 int numBytesImagen,
                                 unsigned char numDesplazamiento)
{
    for (int i = 0; i < numBytesImagen; i++) {
        *(arrayImagen + i) = *(arrayImagen + i) >> numDesplazamiento;
    }
}

void desplazamientoIzquierdaImagen(unsigned char *arrayImagen,
                                   int numBytesImagen,
                                   unsigned char numDesplazamiento)
{
    for (int i = 0; i < numBytesImagen; i++) {
        *(arrayImagen + i) = *(arrayImagen + i) << numDesplazamiento;
    }
}

void rotacionDerechaImagen(unsigned char *arrayImagen, int numBytesImagen, unsigned char numRotacion)
{
    for (int i = 0; i < numBytesImagen; i++) {
        unsigned char byte = *(arrayImagen + i);
        unsigned char bitsDerecha = byte >> numRotacion;
        unsigned char bitsMovidoAIzquierda = byte << (8 - numRotacion);
        *(arrayImagen + i) = bitsDerecha | bitsMovidoAIzquierda;
    }
}

void rotacionIzquierdaImagen(unsigned char *arrayImagen,
                             int numBytesImagen,
                             unsigned char numRotacion)
{
    for (int i = 0; i < numBytesImagen; i++) {
        unsigned char byte = *(arrayImagen + i);
        unsigned char bitsDerecha = byte << numRotacion;
        unsigned char bitsMovidoAIzquierda = byte >> (8 - numRotacion);
        *(arrayImagen + i) = bitsDerecha | bitsMovidoAIzquierda;
    }
}

void xorImagenCompleta(unsigned char *arrayImagen, int numBytesImagen, unsigned char *arrayI_M)
{
    for (int i = 0; i < numBytesImagen; i++) {
        *(arrayImagen + i) = *(arrayImagen + i) ^ *(arrayI_M + i);
    }
}
