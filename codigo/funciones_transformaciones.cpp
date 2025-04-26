#include <iostream>

using namespace std;

//Funciones de transformaciones sobre la porcion del arreglo

void desplazamientoDerecha(unsigned char *arrayImagen, int semilla, unsigned short int *arrayCopia, int nBytes, unsigned char numDesplazamiento)
{
    /*
 * @brief Realiza un desplazamiento a la derecha de los bits de una porcion de un arreglo de imagen o de todo el arreglo.
 *
 * Esta funcion aplica un desplazamiento a la derecha (operador >>) por el numero de bits especificado en 'numDesplazamiento'.
 * Si 'semilla' es diferente de cero, la operacion se realiza sobre 'nBytes' bytes del 'arrayImagen', comenzando desde el
 * indice 'semilla', y los resultados se guardan en el 'arrayCopia'. Cada byte desplazado se expande a un 'unsigned short int'.
 * Si 'semilla' es cero, la operacion se realiza directamente sobre los primeros 'nBytes' del 'arrayImagen'.
 *
 * @param arrayImagen Puntero al arreglo de unsigned char que contiene los datos de la imagen.
 * @param semilla Indice de inicio en 'arrayImagen' para la lectura (si no es 0). Si es 0, se opera directamente sobre el inicio del arreglo.
 * @param arrayCopia Puntero al arreglo de unsigned short int donde se guardaran los resultados del desplazamiento (solo si semilla != 0).
 * @param nBytes Numero de bytes a procesar.
 * @param numDesplazamiento Numero de bits a desplazar hacia la derecha (tipo unsigned char).
 */
    if (semilla != 0){
        for (int i = 0; i < nBytes; semilla ++, i ++) {
            *(arrayCopia + i) = *(arrayImagen + semilla) >> numDesplazamiento;
        }
    } else {
        for (int i = 0; i < nBytes; i ++) {
            *(arrayImagen + i) = *(arrayImagen + i) >> numDesplazamiento;
        }
    }
}

void desplazamientoIzquierda(unsigned char *arrayImagen, int semilla, unsigned short int *arrayCopia, int nBytes, unsigned char numDesplazamiento)
{
    /*
 * @brief Realiza un desplazamiento a la derecha de los bits de una porcion de un arreglo de imagen o de todo el arreglo.
 *
 * Esta funcion aplica un desplazamiento a la izquierda (operador <<) por el numero de bits especificado en 'numDesplazamiento'.
 * Si 'semilla' es diferente de cero, la operacion se realiza sobre 'nBytes' bytes del 'arrayImagen', comenzando desde el
 * indice 'semilla', y los resultados se guardan en el 'arrayCopia'. Cada byte desplazado se expande a un 'unsigned short int'.
 * Si 'semilla' es cero, la operacion se realiza directamente sobre los primeros 'nBytes' del 'arrayImagen'.
 *
 * @param arrayImagen Puntero al arreglo de unsigned char que contiene los datos de la imagen.
 * @param semilla Indice de inicio en 'arrayImagen' para la lectura (si no es 0). Si es 0, se opera directamente sobre el inicio del arreglo.
 * @param arrayCopia Puntero al arreglo de unsigned short int donde se guardaran los resultados del desplazamiento (solo si semilla != 0).
 * @param nBytes Numero de bytes a procesar.
 * @param numDesplazamiento Numero de bits a desplazar hacia la derecha (tipo unsigned char).
 */
    if (semilla != 0){
        for (int i = 0; i < nBytes; semilla ++, i ++) {
            *(arrayCopia + i) = *(arrayImagen + semilla) << numDesplazamiento;
        }
    } else {
        for (int i = 0; i < nBytes; i ++) {
            *(arrayImagen + i) = *(arrayImagen + i) << numDesplazamiento;
        }
    }
}

void rotacionDerecha(unsigned char *arrayImagen, int semilla, unsigned short int *arrayCopia, int nBytes, unsigned char numRotacion)
{
    /*
 * @brief Realiza una rotacion a la derecha de los bits de una porcion de un arreglo de imagen o de todo el arreglo.
 *
 * Esta funcion efectua una rotacion circular a la derecha por 'numRotacion' bits.
 * Si 'semilla' es diferente de cero, se rotan 'nBytes' bytes de 'arrayImagen' a partir del indice 'semilla',
 * y los resultados se guardan en 'arrayCopia' como 'unsigned short int'.
 * Si 'semilla' es cero, la rotacion se aplica directamente a los primeros 'nBytes' de 'arrayImagen'.
 *
 * @param arrayImagen Puntero al arreglo de unsigned char que contiene los datos de la imagen.
 * @param semilla Indice de inicio en 'arrayImagen' para la lectura (si no es 0). Si es 0, se opera directamente sobre el inicio del arreglo.
 * @param arrayCopia Puntero al arreglo de unsigned short int donde se guardaran los resultados de la rotacion (solo si semilla != 0).
 * @param nBytes Numero de bytes a rotar.
 * @param numRotacion Numero de bits a rotar hacia la derecha (tipo unsigned char).
 **/
    if (semilla !=0){
        for (int i = 0; i < nBytes; semilla ++, i ++) {
            unsigned char byte = *(arrayImagen + semilla);
            unsigned char bitsDerecha = byte >> numRotacion;
            unsigned char bitsMovidoAIzquierda = byte << (8 - numRotacion);
            *(arrayCopia + i) = bitsDerecha | bitsMovidoAIzquierda;
        }
    } else {
        for (int i = 0; i < nBytes; i ++) {
            unsigned char byte = *(arrayImagen + i);
            unsigned char bitsDerecha = byte >> numRotacion;
            unsigned char bitsMovidoAIzquierda = byte << (8 - numRotacion);
            *(arrayImagen + i) = bitsDerecha | bitsMovidoAIzquierda;
        }
    }

}

void rotacionIzquierda(unsigned char *arrayImagen, int semilla, unsigned short int *arrayCopia, int nBytes, unsigned char numRotacion)
{
    /*
 * @brief Realiza una rotacion a la izquierda de los bits de una porcion de un arreglo de imagen o de todo el arreglo.
 *
 * Esta funcion efectua una rotacion circular a la derecha por 'numRotacion' bits.
 * Si 'semilla' es diferente de cero, se rotan 'nBytes' bytes de 'arrayImagen' a partir del indice 'semilla',
 * y los resultados se guardan en 'arrayCopia' como 'unsigned short int'.
 * Si 'semilla' es cero, la rotacion se aplica directamente a los primeros 'nBytes' de 'arrayImagen'.
 *
 * @param arrayImagen Puntero al arreglo de unsigned char que contiene los datos de la imagen.
 * @param semilla Indice de inicio en 'arrayImagen' para la lectura (si no es 0). Si es 0, se opera directamente sobre el inicio del arreglo.
 * @param arrayCopia Puntero al arreglo de unsigned short int donde se guardaran los resultados de la rotacion (solo si semilla != 0).
 * @param nBytes Numero de bytes a rotar.
 * @param numRotacion Numero de bits a rotar hacia la derecha (tipo unsigned char).
 **/
    if (semilla != 0){
        for (int i = 0; i < nBytes; semilla ++, i ++) {
            unsigned char byte = *(arrayImagen + semilla);
            unsigned char bitsIzquierda = byte << numRotacion;
            unsigned char bitsMovidoADerecha = byte >> (8 - numRotacion);
            *(arrayCopia + i) = bitsIzquierda | bitsMovidoADerecha;
        }
    }
    else {
        for (int i = 0; i < nBytes; i ++) {
            unsigned char byte = *(arrayImagen + i);
            unsigned char bitsIzquierda = byte << numRotacion;
            unsigned char bitsMovidoADerecha = byte >> (8 - numRotacion);
            *(arrayImagen + i) = bitsIzquierda | bitsMovidoADerecha;
        }
    }
}

void xorEntreImagenes(unsigned char* arrayImagen, unsigned short int *arrayCopia, int semilla, unsigned char *arrayI_M, int nBytes)
{
    /*
 * @brief Aplica una operacion XOR bit a bit entre una porcion de un arreglo de imagen y otra, o entre arreglos completos.
 *
 * Si 'semilla' no es cero, esta funcion realiza una operacion XOR (operador ^) entre 'nBytes' elementos del 'arrayCopia' (comenzando desde el indice 0)
 * y 'nBytes' elementos del 'arrayI_M' (comenzando desde el indice 'semilla'). Los resultados se guardan en 'arrayCopia'.
 * Si 'semilla' es cero, la operacion XOR se realiza entre los primeros 'nBytes' de 'arrayImagen' y los primeros 'nBytes' de 'arrayI_M',
 * y los resultados se guardan en 'arrayImagen'.
 *
 * @param arrayImagen Puntero al arreglo de unsigned char de la imagen (modificado si semilla es 0).
 * @param arrayCopia Puntero al arreglo de unsigned short int donde se guardaran los resultados del XOR (si semilla no es 0).
 * @param semilla Indice de inicio en 'arrayI_M' para la lectura (si no es 0). Si es 0, la operacion se realiza desde el inicio de los arreglos.
 * @param arrayI_M Puntero al arreglo de unsigned char con el que se realizara la operacion XOR.
 * @param nBytes Numero de elementos a procesar de ambos arreglos.
 */
    if (semilla != 0){
        for (int i = 0; i < nBytes; semilla++, i++) {
            *(arrayCopia + i) = *(arrayCopia + i) ^ *(arrayI_M + semilla);
        }
    } else {
        for (int i = 0; i < nBytes; i++) {
            *(arrayImagen + i) = *(arrayImagen + i) ^ *(arrayI_M + i);
        }
    }

}
