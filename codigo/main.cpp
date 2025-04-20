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
    int semilla = 0;
    int numPixels = 0;
    int numArchivos = 0;
    bool transformacionHallada = false;

    //Cargar informacion de la mascara
    QString rutaMascara = "C:/Users/DELL/Documents/universidad/segundo_semestre/informatica_II/prueba_desafio/Caso1/M.bmp";
    int widthMascara = 0;
    int heightMascara = 0;
    unsigned char *arrayMascara = loadPixels(rutaMascara, widthMascara, heightMascara);

    //Cargar informacion de I_D
    QString rutaI_D = "C:/Users/DELL/Documents/universidad/segundo_semestre/informatica_II/prueba_desafio/Caso1/I_D.bmp";
    int widthI_D = 0;
    int heightI_D = 0;
    unsigned char *arrayImagen = loadPixels(rutaI_D, widthI_D, heightI_D);

    //Cargar informacion de I_M
    QString rutaI_M = "C:/Users/DELL/Documents/universidad/segundo_semestre/informatica_II/prueba_desafio/Caso1/I_M.bmp";
    int widthI_M = 0;
    int heightI_M = 0;
    unsigned char *arrayI_M = loadPixels(rutaI_M, widthI_M, heightI_M);

    int numBytesImagenes = widthI_D * heightI_D * 3;

    cout << "Ingrese el numero de archivos de texto a comparar: " << endl;
    cin >> numArchivos;

    for (int i = 1; i <= numArchivos; i++) {
        //Seleccionar archivo de texto
        cout << "Ingrese la ruta del archivo: " << endl;
        cin >> nombreArchivo;

        const char *punteroArchivo = nombreArchivo.c_str(); //.c_str es para convertir el string a const char
        unsigned int *arrayTexto = loadSeedMasking(punteroArchivo, semilla, numPixels);

        int numBytesMascara = numPixels * 3;

        unsigned char *arrayCopia = crearArrayCopia(arrayImagen, semilla, numBytesMascara);

        while (not transformacionHallada) {
            //Proceso de prueba de posibles transformaciones

            //Desplazamientos
            for (int i = 1; i <= 8; i++) {
                //Primera posible trasnformacion: Desplazamiento a la derecha
                desplazamientoDerecha(arrayImagen, semilla, arrayCopia, numBytesMascara, i);
                transformacionHallada = comparar(arrayTexto,
                                                 numBytesMascara,
                                                 arrayCopia,
                                                 arrayMascara);
                if (transformacionHallada) {
                    cout << "La transformacion aplicada es: Desplazamiento a la derecha de " << i
                         << " pixeles" << endl;
                    desplazamientoDerechaImagen(arrayImagen, numBytesImagenes, i);
                    break;
                }

                if (i != 8) {
                    //Segunda posible transformacion: Desplazamiento a las izquierda
                    desplazamientoIzquierda(arrayImagen, semilla, arrayCopia, numBytesMascara, i);
                    transformacionHallada = comparar(arrayTexto,
                                                     numBytesMascara,
                                                     arrayCopia,
                                                     arrayMascara);
                    if (transformacionHallada) {
                        cout << "La transformacion aplicada es: Desplazamiento a la izquierda de "
                             << i << " pixeles" << endl;
                        desplazamientoIzquierdaImagen(arrayImagen, numBytesImagenes, i);
                        break;
                    }
                }
            }

            //Rotaciones
            if (not transformacionHallada) {
                for (int i = 1; i < 8; i++) {
                    //Primera posible trasnformacion: Rotacion a la derecha
                    rotacionDerecha(arrayImagen, semilla, arrayCopia, numBytesMascara, i);
                    transformacionHallada = comparar(arrayTexto,
                                                     numBytesMascara,
                                                     arrayCopia,
                                                     arrayMascara);
                    if (transformacionHallada) {
                        cout << "La transformacion aplicada es: Rotacion a la derecha de " << i
                             << " pixeles";
                        rotacionDerechaImagen(arrayImagen, numBytesImagenes, i);
                        break;
                    }

                    //Segunda posible transformacion: Rotacion a las izquierda
                    rotacionIzquierda(arrayImagen, semilla, arrayCopia, numBytesMascara, i);
                    transformacionHallada = comparar(arrayTexto,
                                                     numBytesMascara,
                                                     arrayCopia,
                                                     arrayMascara);
                    if (transformacionHallada) {
                        cout << "La transformacion aplicada es: Rotacion a la izquierda de " << i
                             << " pixeles";
                        rotacionIzquierdaImagen(arrayImagen, numBytesImagenes, i);
                        break;
                    }
                }
            }

            //XOR entre imagenes
            if (not transformacionHallada) {
                xorEntreImagenes(arrayImagen, arrayI_M, numBytesImagenes);
                transformacionHallada = comparar(arrayTexto,
                                                 numBytesMascara,
                                                 arrayImagen,
                                                 arrayMascara);
                if (transformacionHallada) {
                    cout << "La transformacion aplicada es: XOR entre imagenes";
                }
            }

            delete[] arrayTexto;
            arrayTexto = nullptr;

            delete[] arrayCopia;
            arrayCopia = nullptr;
        }
    }

    delete[] arrayI_M;
    arrayI_M = nullptr;

    delete[] arrayMascara;
    arrayMascara = nullptr;

    delete[] arrayImagen;
    arrayImagen = nullptr;

    return 0; // Fin del programa
}
