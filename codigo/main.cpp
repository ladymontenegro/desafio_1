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

#include <fstream>
#include <iostream>
#include <QCoreApplication>
#include <QImage>
#include <string>
#include "header.h"

using namespace std;

int main()
{
    //Definicion de variables
    string nombreArchivo = "";
    int semilla = 0;
    int numPixels = 0;
    int numBytesMascara = 0;
    int numBytesImagenes = 0;
    int numArchivos = 0;
    unsigned char* arrayCopia = nullptr;
    unsigned char* arrayPosibleTransformacion = nullptr;
    unsigned char* arrayImagen = nullptr;
    unsigned int* arrayTexto = nullptr;
    bool resultadoComparacion;
    bool tranformacionHallada = false;

    //Cargar informacion de la mascara
    QString rutaMascara = "C:/Users/DELL/Documents/universidad/segundo_semestre/informatica_II/prueba_desafio/Caso 1/M.bmp";
    int widthMascara = 0;
    int heightMascara = 0;
    unsigned char* arrayMascaraPixels = loadPixels(rutaMascara, widthMascara, heightMascara);

    //Cargar informacion de I_D
    QString rutaI_D = "C:/Users/DELL/Documents/universidad/segundo_semestre/informatica_II/prueba_desafio/Caso 1/I_D.bmp";
    int widthI_D = 0;
    int heightI_D = 0;
    unsigned char* arrayI_DPixels = loadPixels(rutaI_D, widthI_D, heightI_D);

    //Cargar informacion de I_M
    QString rutaI_M = "C:/Users/DELL/Documents/universidad/segundo_semestre/informatica_II/prueba_desafio/Caso 1/I_M.bmp";
    int widthI_M = 0;
    int heightI_M = 0;
    unsigned char* arrayI_MPixels = loadPixels(rutaI_M, widthI_M, heightI_M);

    cout << "Ingrese el numero de archivos de texto a comparar: " << endl;
    cin >> numArchivos;

    for(int i = 1; i <= numArchivos; i++){

        //Seleccionar archivo de texto
        cout << "Ingresar nombre del archivo: " << endl;
        cin >> nombreArchivo;

        const char* punteroArchivo = nombreArchivo.c_str(); //.c_str es para convertir el string a const char
        unsigned int* arrayTexto = loadSeedMasking(punteroArchivo, semilla, numPixels);

        while (not tranformacionHallada){

            //Proceso de prueba de posibles transformaciones

            //Desplazamientos
            for (int i = 1; i <= 8; i++){
                //Primera posible trasnformacion: Desplazamiento a la derecha
                arrayPosibleTransformacion = desplazamientoDerecha(arrayI_DPixels, arrayCopia, i, semilla, numBytesMascara);
                resultadoComparacion = comparar(arrayTexto, numBytesMascara, arrayPosibleTransformacion, arrayMascaraPixels);
                if (resultadoComparacion){
                    cout << "La transformacion desplazamiento a la derecha de "<< i << "pixeles es correcta";
                    break;
                }

                //Segunda posible transformacion: Desplazamiento a las izquierda
                arrayPosibleTransformacion = desplazamientoIzquierda(arrayI_DPixels, arrayCopia, i, semilla, numBytesMascara);
                resultadoComparacion = comparar(arrayTexto, numBytesMascara, arrayPosibleTransformacion, arrayMascaraPixels);
                if (resultadoComparacion){
                    cout << "La transformacion desplazamiento a la izquierda de "<< i << "pixeles es correcta";
                    break;
                }
            }

            //Rotaciones
            for (int i = 1; i < 8; i++){
                //Primera posible trasnformacion: Rotacion a la derecha
                arrayPosibleTransformacion = rotacionDerecha(arrayI_DPixels, arrayCopia, i, semilla, numBytesMascara);
                resultadoComparacion = comparar(arrayTexto, numBytesMascara, arrayPosibleTransformacion, arrayMascaraPixels);
                if (resultadoComparacion){
                    cout << "La transformacion rotacion a la derecha de "<< i << "pixeles es correcta";
                    break;
                }

                //Segunda posible transformacion: Rotacion a las izquierda
                arrayPosibleTransformacion = rotacionIzquierda(arrayI_DPixels, arrayCopia, i, semilla, numBytesMascara);
                resultadoComparacion = comparar(arrayTexto, numBytesMascara, arrayPosibleTransformacion, arrayMascaraPixels);
                if (resultadoComparacion){
                    cout << "La transformacion rotacion a la izquierda de "<< i << "pixeles es correcta";
                    break;
                }
            }

            //XOR entre imagenes
            arrayImagen = xorEntreImagenes(arrayImagen, arrayI_MPixels, numBytesImagenes);

            if(resultadoComparacion){
                tranformacionHallada = true;
            }
        }

        delete[] arrayTexto;
        arrayTexto = nullptr;
    }

    delete[] arrayI_MPixels;
    arrayI_MPixels = nullptr;

    delete[] arrayMascaraPixels;
    arrayMascaraPixels = nullptr;

    delete[] arrayI_DPixels;
    arrayI_DPixels = nullptr;

    return 0; // Fin del programa
}
