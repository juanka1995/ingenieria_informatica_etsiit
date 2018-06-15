	/**
@file
@author DP
@date Marzo 2016
@brief Funciones de manejo de bloqueLeds

*/

#ifndef _BLOQUELED_H_
#define	_BLOQUELED_H_

#include <string>
using namespace std;

typedef unsigned char bloqueLed; ///< Un @c bloqueLed contiene el estado de 8 LEDs

/**
@brief enciende el LED @p pos del @c bloqueLed @p b
@param b 	el @c bloqueLed cuyo LED se quiere activar
@param pos 	el LED dentro de @p b que se quiere activar (0 m�s a la derecha)
*/
void on(bloqueLed &b, int pos);

/**
@brief apaga el LED @p pos del  @c bloqueLed @p b
@param b 	el @c bloqueLed cuyo LED se quiere desactivar
@param pos 	el LED dentro de @p b que se quiere desactivar (0 m�s a la derecha)
*/
void off(bloqueLed &b, int pos);

/**
@brief devuelve el estado del LED (encendido = true, apagado = false) en la posici�n @p pos
@param b 	el @c bloqueLed que se quiere consultar
@param pos 	el LED dentro de @ b que se quiere consultar (0 m�s a la derecha)
@retval true 	si el LED en la posici�n @p pos est� encendido
@retval false	si el LED en la posici�n @p pos est� apagado
*/
bool get(bloqueLed b, int pos);


/**
@brief devuelve un string conteniendo una secuencia de '0's y '1's correspondiente  al estado de cada LED
@param b el @c bloqueLed que se quiere imprimir

Por ejemplo, si en el @c bloqueLed @c b est�n encendidos los LEDs en posiciones 1 y 3 (0 m�s a la derecha), @c bloqueLedToString(b); devolver� el string @c "00001010"

*/

string bloqueLedToString(bloqueLed b);

/**
@brief enciende todos los LEDs
@param b el @c bloqueLed que se quiere encender completamente.
*/
void encender(bloqueLed &b);

/**
@brief apaga todos los LEDs
@param b el @c bloqueLed que se quiere apagar completamente.
*/
void apagar(bloqueLed &b);

/**
@brief enciende los LEDs seg�n la configuraci�n de @p v
@param b el @c bloqueLed sobre el que se quiere actuar
@param v vector de 8 elementos que contiene la secuencia de LEDS que se quieren asignar

Asigna a @p b la configuraci�n de LEDs contenida en @p v. @p v es un vector de 8 booleanos donde @c true significa encendido y @c false significa apagado.
*/
void asignar(bloqueLed &b, const bool v[]);

/**
@brief recupera la configuraci�n de todos los LED
@param b el @c bloqueLed que se quiere consultar
@param v vector de 8 elementos que contendr� el estado de cada uno de los LEDs de @ b

Vuelca en @p v la configuraci�n de LEDs contenida en @p b. @c true significa encendido y @c false significa apagado. El tama�o de @p v debe ser 8.
*/
void volcar(bloqueLed b, bool v[]);

/**
@brief devuelve las posiciones de los LEDs encendidos
@param b el @c bloqueLed que se quiere consultar
@param posic vector de enteros (valores entre 0 a 7) que indican la posici�n de los LEDs de @p b que est�n encendidos
@param cuantos n�mero de LEDs encendidos en @p b (n�mero de elementos usados en el vector @p posic)
*/
void encendidos(bloqueLed b, int posic[], int &cuantos);

#endif
