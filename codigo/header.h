#ifndef HEADER_H
#define HEADER_H

#include <QCoreApplication>

unsigned char* crearArrayCopia(unsigned char*arrayOriginal, int semilla, int numBytesMascara);

unsigned char* loadPixels(QString input, int &width, int &height);

bool exportImage(unsigned char* pixelData, int width,int height, QString archivoSalida);

unsigned int* loadSeedMasking(const char* nombreArchivo, int &seed, int &n_pixels);

unsigned char *desplazamientoDerecha(unsigned char* array, int semilla, unsigned char *arrayCopia, int bytesMascara, unsigned char numDesplazamiento);

unsigned char *desplazamientoIzquierda(unsigned char* array, int semilla, unsigned char *arrayCopia, int bytesMascara, unsigned char numDesplazamiento);

unsigned char *rotacionDerecha(unsigned char* array, int semilla, unsigned char *arrayCopia, int bytesMascara, unsigned char numRotacion);

unsigned char *rotacionIzquierda(unsigned char* array, int semilla, unsigned char *arrayCopia, int bytesMascara, unsigned char numRotacion);

unsigned char *xorEntreImagenes(unsigned char *arrayImagen, unsigned char *arrayImagenI_M, int bytesImagenes);

bool comparar(unsigned int* arrayTexto, int nBytes, unsigned char *arrayTransformado, unsigned char *arrayMascara);

unsigned char *desplazamientoDerechaImagen(unsigned char *arrayImagen,
                                           int numBytesImagen,
                                           unsigned char numDesplazamiento);

unsigned char *desplazamientoIzquierdaImagen(unsigned char *arrayImagen,
                                             int numBytesImagen,
                                             unsigned char numDesplazamiento);

unsigned char *rotacionDerechaImagen(unsigned char *arrayImagen,
                                     int numBytesImagen,
                                     unsigned char numRotacion);

unsigned char *rotacionIzquierdaImagen(unsigned char *arrayImagen,
                                       int numBytesImagen,
                                       unsigned char numRotacion);

#endif // HEADER_H
