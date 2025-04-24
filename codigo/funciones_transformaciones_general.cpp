#include <iostream>

using namespace std;

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
