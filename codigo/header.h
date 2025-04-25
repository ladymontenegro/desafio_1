#ifndef HEADER_H
#define HEADER_H

#include <QCoreApplication>

unsigned short int *crearArrayCopia(unsigned char *arrayOriginal, int semilla, int numBytesMascara);

unsigned char* loadPixels(QString input, int &width, int &height);

bool exportImage(unsigned char* pixelData, int width,int height, QString archivoSalida);

unsigned int* loadSeedMasking(const char* nombreArchivo, int &seed, int &n_pixels);

void desplazaminetoDerecha(unsigned char *arrayImagen = nullptr, int semilla = 0, unsigned short int *arrayCopia = nullptr, int nBytes = 0, unsigned char numDesplazamiento = 0);

void desplazamientoIzquierda(unsigned char *arrayImagen = nullptr, int semilla = 0, unsigned short int *arrayCopia = nullptr, int nBytes = 0, unsigned char numDesplazamiento = 0);

void rotacionDerecha(unsigned char *arrayImagen = nullptr, int semilla = 0, unsigned short int *arrayCopia = nullptr, int nBytes = 0, unsigned char numRotacion = 0);

void rotacionIzquierda(unsigned char *arrayImagen = nullptr, int semilla = 0, unsigned short int *arrayCopia = nullptr, int nBytes = 0, unsigned char numRotacion = 0);

void xorEntreImagenes(unsigned char* arrayImagen = nullptr, unsigned short int *arrayCopia = nullptr, int semilla = 0, unsigned char *arrayI_M = nullptr, int nBytes = 0);

bool comparar(unsigned int *arrayTexto, unsigned short int *arrayCopia);

void sumarMascara(unsigned short int *arrayCopia, unsigned char *arrayMascara, int numBytesMascara);

#endif // HEADER_H
