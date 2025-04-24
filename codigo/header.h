#ifndef HEADER_H
#define HEADER_H

#include <QCoreApplication>

unsigned short int *crearArrayCopia(unsigned char *arrayOriginal, int semilla, int numBytesMascara);

unsigned char* loadPixels(QString input, int &width, int &height);

bool exportImage(unsigned char* pixelData, int width,int height, QString archivoSalida);

unsigned int* loadSeedMasking(const char* nombreArchivo, int &seed, int &n_pixels);

void desplazamientoDerecha(unsigned char *array,
                           int semilla,
                           unsigned short int *arrayCopia,
                           int bytesMascara,
                           unsigned char numDesplazamiento);

void desplazamientoIzquierda(unsigned char *array,
                             int semilla,
                             unsigned short int *arrayCopia,
                             int bytesMascara,
                             unsigned char numDesplazamiento);

void rotacionDerecha(unsigned char *array,
                     int semilla,
                     unsigned short int *arrayCopia,
                     int bytesMascara,
                     unsigned char numRotacion);

void rotacionIzquierda(unsigned char *array,
                       int semilla,
                       unsigned short int *arrayCopia,
                       int bytesMascara,
                       unsigned char numRotacion);

void xorEntreImagenes(unsigned short int *arrayCopia,
                      int semilla,
                      unsigned char *arrayI_M,
                      int bytesMascara);

bool comparar(unsigned int *arrayTexto, int nBytes, unsigned short int *arrayCopia);

void desplazamientoDerechaImagen(unsigned char *arrayImagen,
                                 int numBytesImagen,
                                 unsigned char numDesplazamiento);

void desplazamientoIzquierdaImagen(unsigned char *arrayImagen,
                                   int numBytesImagen,
                                   unsigned char numDesplazamiento);

void rotacionDerechaImagen(unsigned char *arrayImagen,
                           int numBytesImagen,
                           unsigned char numRotacionn);

void rotacionIzquierdaImagen(unsigned char *arrayImagen,
                             int numBytesImagen,
                             unsigned char numRotacionn);

void xorImagenCompleta(unsigned char *arrayImagen, int numBytesImagen, unsigned char *arrayI_M);

void sumarMascara(unsigned short int *arrayCopia, unsigned char *arrayMascara, int numBytesMascara);

#endif // HEADER_H
