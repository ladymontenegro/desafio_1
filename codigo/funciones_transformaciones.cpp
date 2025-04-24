#include <iostream>

using namespace std;

//Funciones de transformaciones sobre la porcion del arreglo

void desplazamientoDerecha(unsigned char *array, int semilla, unsigned short int *arrayCopia, int bytesMascara, unsigned char numDesplazamiento)
{
    /*
 * @brief Realiza un desplazamiento a la derecha de los bits de una porcion de un arreglo.
 *
 * Esta funcion itera a traves de una porcion del arreglo 'array' de entrada, comenzando
 * en la posicion indicada por `semilla` y procesando 'bytesMascara' bytes. Para cada byte
 * leido, aplica un desplazamiento a la derecha (operador >>) por el numero de bits
 * especificado en 'numDesplazamiento', y guarda el resultado en el arreglo 'arrayCopia'.
 *
 * @param array Puntero al arreglo de unsigned char de origen.
 * @param semilla Indice de inicio en el arreglo 'array' para la lectura de bytes.
 * @param arrayCopia Puntero al arreglo de unsigned short int donde se guardaran los resultados del desplazamiento.
 * @param bytesMascara Numero de bytes a procesar desde el arreglo 'array'.
 * @param numDesplazamiento Numero de bits a desplazar hacia la derecha (tipo unsigned char).
 */
    for (int i = 0; i < bytesMascara; semilla ++, i ++) {
        *(arrayCopia + i) = *(array + semilla) >> numDesplazamiento;
    }
}

void desplazamientoIzquierda(unsigned char *array, int semilla, unsigned short int *arrayCopia, int bytesMascara, unsigned char numDesplazamiento)
{
    /*
 * @brief Realiza un desplazamiento a la izquierda de los bits de una porcion de un arreglo.
 *
 * Esta funcion recorre una seccion del arreglo 'array' de entrada, empezando
 * en el indice 'semilla' y trabajando con 'bytesMascara' bytes. Por cada byte
 * extraido, efectua un desplazamiento a la izquierda (operador <<) por la cantidad de bits
 * indicada en 'numDesplazamiento', y almacena el valor resultante en el arreglo 'arrayCopia'.
 *
 * @param array Puntero al arreglo de unsigned char de donde se leen los datos.
 * @param semilla Indice inicial en el arreglo 'array' para la lectura de los bytes.
 * @param arrayCopia Puntero al arreglo de unsigned short int donde se escriben los bytes desplazados.
 * @param bytesMascara Cantidad de bytes a procesar del arreglo 'array'.
 * @param numDesplazamiento Numero de bits a desplazar hacia la izquierda (tipo unsigned char).
 */
    for (int i = 0; i < bytesMascara; semilla ++, i ++) {
        *(arrayCopia + i) = *(array + semilla) << numDesplazamiento;
    }
}

void rotacionDerecha(unsigned char *array, int semilla, unsigned short int *arrayCopia, int bytesMascara, unsigned char numRotacion)
{
    /*
 * @brief Realiza una rotacion a la derecha de los bits de una porcion de un arreglo.
 *
 * Esta funcion procesa 'bytesMascara' bytes del arreglo 'array' comenzando desde el indice 'semilla'.
 * Para cada byte, realiza una rotacion circular a la derecha por 'numRotacion' bits.
 * Los bits que salen por la derecha vuelven a entrar por la izquierda.
 * El resultado de cada rotacion se guarda en el arreglo 'arrayCopia'.
 *
 * @param array Puntero al arreglo de unsigned char de entrada.
 * @param semilla Indice de inicio en el arreglo 'array'.
 * @param arrayCopia Puntero al arreglo de unsigned short int donde se almacenan los resultados de la rotacion.
 * @param bytesMascara Numero de bytes a rotar.
 * @param numRotacion Numero de bits a rotar hacia la derecha (tipo unsigned char).
 */
    for (int i = 0; i < bytesMascara; semilla ++, i ++) {
        unsigned char byte = *(array + semilla);
        unsigned char bitsDerecha = byte >> numRotacion;
        unsigned char bitsMovidoAIzquierda = byte << (8 - numRotacion);
        *(arrayCopia + i) = bitsDerecha | bitsMovidoAIzquierda;
    }
}

void rotacionIzquierda(unsigned char *array, int semilla, unsigned short int *arrayCopia, int bytesMascara, unsigned char numRotacion)
{
    /*
 * @brief Realiza una rotacion a la izquierda de los bits de una porcion de un arreglo.
 *
 * Esta funcion itera a traves de 'bytesMascara' bytes del arreglo 'array', empezando en 'semilla'.
 * Para cada byte, efectua una rotacion circular a la izquierda por 'numRotacion' bits.
 * Los bits que se desplazan fuera de la izquierda reaparecen por la derecha.
 * El byte rotado se guarda en el arreglo 'arrayCopia'.
 *
 * @param array Puntero al arreglo de unsigned char de origen.
 * @param semilla Indice de inicio para la lectura en 'array'.
 * @param arrayCopia Puntero al arreglo de unsigned short int donde se escriben los bytes rotados.
 * @param bytesMascara Cantidad de bytes a rotar.
 * @param numRotacion Numero de bits a rotar hacia la izquierda (tipo unsigned char).
 */
    for (int i = 0; i < bytesMascara; semilla ++, i ++) {
        unsigned char byte = *(array + semilla);
        unsigned char bitsIzquierda = byte << numRotacion;
        unsigned char bitsMovidoADerecha = byte >> (8 - numRotacion);
        *(arrayCopia + i) = bitsIzquierda | bitsMovidoADerecha;
    }
}

void xorEntreImagenes(unsigned short int *arrayCopia, int semilla, unsigned char *arrayI_M, int bytesMascara)
{
    /*
 * @brief Aplica una operacion XOR bit a bit entre una porcion de un arreglo y otra.
 *
 * Esta funcion compara 'bytesMascara' elementos del 'arrayCopia', comenzando desde el indice 0,
 * con elementos del 'arrayI_M' empezando desde el indice 'semilla'. Realiza una operacion XOR
 * (operador ^) entre los elementos correspondientes y guarda el resultado en la posicion
 * del 'arrayCopia'.
 *
 * @param arrayCopia Puntero al arreglo de unsigned short int que se modificara con el resultado del XOR.
 * @param semilla Indice de inicio en el arreglo 'arrayI_M' para la lectura de los bytes.
 * @param arrayI_M Puntero al arreglo de unsigned char con el que se realizara la operacion XOR.
 * @param bytesMascara Numero de elementos a procesar de ambos arreglos.
 */
    for (int i = 0; i < bytesMascara; semilla++, i++) {
        *(arrayCopia + i) = *(arrayCopia + i) ^ *(arrayI_M + semilla);
    }
}
