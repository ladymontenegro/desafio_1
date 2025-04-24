#include <iostream>

using namespace std;

//Funciones de transformaciones sobre el arreglo completo
void desplazamientoDerechaImagen(unsigned char *arrayImagen, int numBytesImagen, unsigned char numDesplazamiento)
{
    /*
 * @brief Realiza un desplazamiento a la derecha de los bits de cada byte en un arreglo de imagen.
 *
 * Esta funcion itera a traves de cada byte del arreglo que representa los datos de una imagen
 * y aplica un desplazamiento a la derecha (operador >>) por el numero de bits especificado.
 * Los bits que se desplazan fuera del byte se pierden.
 *
 * @param arrayImagen Puntero al arreglo de unsigned char que contiene los datos de la imagen.
 * @param numBytesImagen Número total de bytes en el arreglo de la imagen.
 * @param numDesplazamiento Número de bits a desplazar hacia la derecha (tipo unsigned char).
 *
 * @note Esta operación modifica directamente el contenido del arreglo 'arrayImagen'.
 */
    for (int i = 0; i < numBytesImagen; i++) {
        *(arrayImagen + i) = *(arrayImagen + i) >> numDesplazamiento;
    }
}

void desplazamientoIzquierdaImagen(unsigned char *arrayImagen, int numBytesImagen, unsigned char numDesplazamiento)
{
    /*
 * @brief Realiza un desplazamiento a la izquierda de los bits de cada byte en un arreglo de imagen.
 *
 * Esta funcion recorre cada byte del arreglo que contiene los datos de una imagen
 * y efectua un desplazamiento a la izquierda (operador <<) por la cantidad de bits indicada.
 * Los bits que se desplazan fuera del byte se pierden, y los espacios vacíos a la derecha se rellenan con ceros.
 *
 * @param arrayImagen Puntero al arreglo de unsigned char que almacena los datos de la imagen.
 * @param numBytesImagen Cantidad total de bytes en el arreglo de la imagen.
 * @param numDesplazamiento Número de bits a desplazar hacia la izquierda (tipo unsigned char).
 *
 * @note Esta operación altera directamente el contenido del arreglo 'arrayImagen'.
 */
    for (int i = 0; i < numBytesImagen; i++) {
        *(arrayImagen + i) = *(arrayImagen + i) << numDesplazamiento;
    }
}

void rotacionDerechaImagen(unsigned char *arrayImagen, int numBytesImagen, unsigned char numRotacion)
{
    /*
 * @brief Realiza una rotacion a la derecha de los bits de cada byte en un arreglo de imagen.
 *
 * Esta funcion procesa cada byte del arreglo de datos de una imagen, efectuando una rotacion
 * circular a la derecha por el numero de bits especificado. Los bits que se desplazan fuera
 * del extremo derecho del byte reaparecen en el extremo izquierdo.
 *
 * @param arrayImagen Puntero al arreglo de unsigned char que contiene los datos de la imagen.
 * @param numBytesImagen Numero total de bytes en el arreglo de la imagen.
 * @param numRotacion Numero de bits a rotar hacia la derecha (tipo unsigned char).
 *
 * @note Esta operacion modifica directamente el contenido del arreglo 'arrayImagen'.
 */
    for (int i = 0; i < numBytesImagen; i++) {
        unsigned char byte = *(arrayImagen + i);
        unsigned char bitsDerecha = byte >> numRotacion;
        unsigned char bitsMovidoAIzquierda = byte << (8 - numRotacion);
        *(arrayImagen + i) = bitsDerecha | bitsMovidoAIzquierda;
    }
}

void rotacionIzquierdaImagen(unsigned char *arrayImagen, int numBytesImagen, unsigned char numRotacion)
{
    /*
 * @brief Realiza una rotacion a la izquierda de los bits de cada byte en un arreglo de imagen.
 *
 * Esta funcion itera sobre cada byte del arreglo que representa los datos de una imagen,
 * llevando a cabo una rotacion circular a la izquierda por el numero de bits indicado.
 * Los bits que se desplazan fuera del extremo izquierdo del byte vuelven a aparecer en el extremo derecho.
 *
 * @param arrayImagen Puntero al arreglo de unsigned char que almacena los datos de la imagen.
 * @param numBytesImagen Cantidad total de bytes en el arreglo de la imagen.
 * @param numRotacion Numero de bits a rotar hacia la izquierda (tipo unsigned char).
 *
 * @note Esta operación altera directamente el contenido del arreglo 'arrayImagen'.
 */
    for (int i = 0; i < numBytesImagen; i++) {
        unsigned char byte = *(arrayImagen + i);
        unsigned char bitsDerecha = byte << numRotacion;
        unsigned char bitsMovidoAIzquierda = byte >> (8 - numRotacion);
        *(arrayImagen + i) = bitsDerecha | bitsMovidoAIzquierda;
    }
}

void xorImagenCompleta(unsigned char *arrayImagen, int numBytesImagen, unsigned char *arrayI_M)
{
    /*
 * @brief Aplica una operación XOR bit a bit entre los bytes de un arreglo de imagen y otro arreglo.
 *
 * Esta funcion compara cada byte del 'arrayImagen' con el byte correspondiente en el 'arrayI_M'
 * y realiza una operación XOR (operador ^). El resultado de esta operacion se guarda de nuevo
 * en la posicion correspondiente del 'arrayImagen'. Se asume que ambos arreglos tienen el mismo tamaño.
 *
 * @param arrayImagen Puntero al arreglo de unsigned char que contiene los datos de la imagen (y donde se guardara el resultado).
 * @param numBytesImagen Numero total de bytes en ambos arreglos.
 * @param arrayI_M Puntero al arreglo de unsigned char con el que se realizara la operacion XOR.
 *
 * @note Esta operación modifica directamente el contenido del arreglo 'arrayImagen'.
 */
    for (int i = 0; i < numBytesImagen; i++) {
        *(arrayImagen + i) = *(arrayImagen + i) ^ *(arrayI_M + i);
    }
}
