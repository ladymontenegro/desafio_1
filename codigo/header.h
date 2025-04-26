#ifndef HEADER_H
#define HEADER_H

#include <QCoreApplication>

//Funciones archivos
unsigned short int *crearArrayCopia(unsigned char *arrayOriginal, int semilla, int numBytesMascara);

unsigned char* loadPixels(QString input, int &width, int &height);

bool exportImage(unsigned char* pixelData, int width,int height, QString archivoSalida);

unsigned int* loadSeedMasking(const char* nombreArchivo, int &seed, int &n_pixels);


//Funciones transformaciones
void desplazaminetoDerecha(unsigned char *arrayImagen, int semilla, unsigned short int *arrayCopia, int nBytes, unsigned char numDesplazamiento);

void desplazamientoIzquierda(unsigned char *arrayImagen, int semilla, unsigned short int *arrayCopia, int nBytes, unsigned char numDesplazamiento);

void rotacionDerecha(unsigned char *arrayImagen, int semilla, unsigned short int *arrayCopia, int nBytes, unsigned char numRotacion);

void rotacionIzquierda(unsigned char *arrayImagen, int semilla, unsigned short int *arrayCopia, int nBytes, unsigned char numRotacion);

void xorEntreImagenes(unsigned char* arrayImagen, unsigned short int *arrayCopia, int semilla, unsigned char *arrayI_M, int nBytes);


//Funciones comparar
bool comparar(unsigned int *arrayTexto, unsigned short int *arrayCopia);

void sumarMascara(unsigned short int *arrayCopia, unsigned char *arrayMascara, int numBytesMascara);

#endif // HEADER_H
