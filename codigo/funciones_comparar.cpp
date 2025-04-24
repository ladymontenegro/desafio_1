#include <iostream>

using namespace std;

//Funciones para proceso de comparacion
void sumarMascara(unsigned short int *arrayCopia, unsigned char *arrayMascara, int numBytesMascara)
{
    /*
 * @brief Suma los elementos de un arreglo de unsigned char a un arreglo de unsigned short int.
 *
 * Esta funcion itera a traves de los elementos del arreglo 'arrayMascara' y suma cada uno
 * al elemento correspondiente en el arreglo 'arrayCopia'. Se asume que ambos arreglos
 * tienen al menos 'numBytesMascara' elementos.
 *
 * @param arrayCopia Puntero al arreglo de unsigned short int que sera modificado con la suma.
 * @param arrayMascara Puntero al arreglo de unsigned char cuyos elementos seran sumados.
 * @param numBytesMascara Numero de elementos a sumar de ambos arreglos.
 *
 * @note Esta operacion modifica directamente el contenido del arreglo 'arrayCopia'.
 */
    for (int i = 0; i < numBytesMascara; i++) {
        *(arrayCopia + i) = *(arrayCopia + i) + *(arrayMascara + i);
    }
}

bool comparar(unsigned int *arrayTexto, unsigned short int *arrayCopia)
{
    /*
 * @brief Compara el primer elemento de un arreglo de unsigned short int con un elemento de un arreglo de unsigned int.
 *
 * Esta funcion compara el primer elemento del arreglo 'arrayCopia', casteado a 'unsigned short int',
 * con el primer elemento del arreglo 'arrayTexto'.
 *
 * @param arrayTexto Puntero al arreglo de unsigned int cuyo primer elemento se comparara.
 * @param arrayCopia Puntero al arreglo de unsigned short int cuyo primer elemento se comparara.
 * @return true si los primeros elementos (despues del casteo) son iguales, false en caso contrario.
 */
    if (static_cast<unsigned short int>(*(arrayCopia)) != *(arrayTexto)) {
        return false;
    } else {
        return true;
    }
}
