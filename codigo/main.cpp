/*
 * Programa demostrativo de manipulaciónprocesamiento de imágenes BMP en C++ usando Qt.
 *
 * Descripción:
 * Este programa realiza las siguientes tareas:
 * 1. Carga una imagen BMP desde un archivo (formato RGB sin usar estructuras ni STL).
 * 2. Modifica los valores RGB de los píxeles asignando un degradado artificial basado en su posición.
 * 3. Exporta la imagen modificada a un nuevo archivo BMP.
 * 4. Carga un archivo de texto que contiene una semilla (offset) y los resultados del enmascaramiento
 *    aplicados a una versión transformada de la imagen, en forma de tripletas RGB.
 * 5. Muestra en consola los valores cargados desde el archivo de enmascaramiento.
 * 6. Gestiona la memoria dinámicamente, liberando los recursos utilizados.
 *
 * Entradas:
 * - Archivo de imagen BMP de entrada ("I_O.bmp").
 * - Archivo de salida para guardar la imagen modificada ("I_D.bmp").
 * - Archivo de texto ("M1.txt") que contiene:
 *     • Una línea con la semilla inicial (offset).
 *     • Varias líneas con tripletas RGB resultantes del enmascaramiento.
 *
 * Salidas:
 * - Imagen BMP modificada ("I_D.bmp").
 * - Datos RGB leídos desde el archivo de enmascaramiento impresos por consola.
 *
 * Requiere:
 * - Librerías Qt para manejo de imágenes (QImage, QString).
 * - No utiliza estructuras ni STL. Solo arreglos dinámicos y memoria básica de C++.
 *
 * Autores: Augusto Salazar Y Aníbal Guerra
 * Fecha: 06/04/2025
 * Asistencia de ChatGPT para mejorar la forma y presentación del código fuente
 */

#include <QCoreApplication>
#include <QImage>
#include "header.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    //Definicion de variables
    string nombreArchivo = "";
    string rutaI_D = "";
    string rutaMascara = "";
    string rutaI_M = "";
    string rutaSalida = "";
    int semilla = 0;
    int numPixels = 0;
    int numArchivos = 0;

    //Cargar informacion de I_D
    cout << "Ingrese la ruta de la imagen encriptada: ";
    cin >> rutaI_D;
    QString qRutaI_D = QString(rutaI_D.c_str());
    int widthI_D = 0;
    int heightI_D = 0;
    unsigned char *arrayImagen = loadPixels(qRutaI_D, widthI_D, heightI_D);

    //Cargar informacion de la mascara
    cout << "Ingrese la ruta de la mascara: ";
    cin >> rutaMascara;
    QString qRutaMascara = QString(rutaMascara.c_str());
    int widthMascara = 0;
    int heightMascara = 0;
    unsigned char *arrayMascara = loadPixels(qRutaMascara, widthMascara, heightMascara);

    //Cargar informacion de I_M
    cout << "Ingrese la ruta de la imagen aleatoria (I_M): ";
    cin >> rutaI_M;
    QString qRutaI_M = QString(rutaI_M.c_str());
    int widthI_M = 0;
    int heightI_M = 0;
    unsigned char *arrayI_M = loadPixels(qRutaI_M, widthI_M, heightI_M);

    int numBytesImagenes = widthI_D * heightI_D * 3;

    cout << "Ingrese el numero de archivos de texto a comparar: ";
    cin >> numArchivos;

    for (int i = 1; i <= numArchivos; i++) {
        //Seleccionar archivo de texto
        cout << "Ingrese la ruta del archivo a comparar: ";
        cin >> nombreArchivo;

        const char *punteroArchivo = nombreArchivo
                                         .c_str(); //.c_str es para convertir el string a const char
        unsigned int *arrayTexto = loadSeedMasking(punteroArchivo, semilla, numPixels);

        int numBytesMascara = numPixels * 3;

        unsigned short int *arrayCopia = crearArrayCopia(arrayImagen, semilla, numBytesMascara);

        bool transformacionHallada = false;

        while (not transformacionHallada) {
            //Proceso de prueba de posibles transformaciones

            //XOR entre imagenes
            if (not transformacionHallada) {
                xorEntreImagenes(arrayCopia, semilla, arrayI_M, numBytesMascara);
                sumarMascara(arrayCopia, arrayMascara, numBytesMascara);
                transformacionHallada = comparar(arrayTexto, arrayCopia);

                if (transformacionHallada) {
                    xorImagenCompleta(arrayImagen, numBytesImagenes, arrayI_M);
                    cout << "La transformacion aplicada es: XOR entre imagenes" << endl;
                }
            }

            //Rotaciones
            if (not transformacionHallada) {
                for (int i = 1; i < 8; i++) {
                    //Primera posible trasnformacion: Rotacion a la derecha
                    rotacionDerecha(arrayImagen, semilla, arrayCopia, numBytesMascara, i);
                    sumarMascara(arrayCopia, arrayMascara, numBytesMascara);
                    transformacionHallada = comparar(arrayTexto, arrayCopia);

                    if (transformacionHallada) {
                        cout << "La transformacion aplicada es: Rotacion a la izquierda de " << i
                             << " pixeles" << endl;
                        rotacionDerechaImagen(arrayImagen, numBytesImagenes, i);
                        break;
                    }

                    //Segunda posible transformacion: Rotacion a las izquierda
                    rotacionIzquierda(arrayImagen, semilla, arrayCopia, numBytesMascara, i);
                    sumarMascara(arrayCopia, arrayMascara, numBytesMascara);
                    transformacionHallada = comparar(arrayTexto, arrayCopia);

                    if (transformacionHallada) {
                        cout << "La transformacion aplicada es: Rotacion a la derecha de " << i
                             << " pixeles" << endl;
                        rotacionIzquierdaImagen(arrayImagen, numBytesImagenes, i);
                        break;
                    }
                }
            }
        }

        numPixels = 0;

        delete[] arrayTexto;
        arrayTexto = nullptr;

        delete[] arrayCopia;
        arrayCopia = nullptr;
    }

    cout << endl << "!! IMAGEN DESENCRIPTADA !!" << endl;
    cout << "Ingrese la ruta para guardar la imagen: ";
    cin >> rutaSalida;
    QString qRutaSalida = QString(rutaSalida.c_str());

    exportImage(arrayImagen, widthI_D, heightI_D, qRutaSalida);

    delete[] arrayI_M;
    arrayI_M = nullptr;

    delete[] arrayMascara;
    arrayMascara = nullptr;

    delete[] arrayImagen;
    arrayImagen = nullptr;

    return 0; // Fin del programa
}
