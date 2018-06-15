/**
  * @file pila_maxmin.h
  * @brief Fichero cabecera del TDA Pila
  *
  * Gestiona una secuencia de elementos con facilidades para la inserci�n y
  * borrado de elementos en un extremo
  */

/**
 *  @brief T.D.A. PILA
 *
 *
 * Una instancia @e c del tipo de dato abstracto PILA sobre un dominio @e T es
 * una sucesi�n finita de elementos del mismo con un funcionamiento @e LIFO
 * (First In, Last Out}). En una PILA, las operaciones de inserci�n tienen
 * lugar siempre en la ultima posicion, denominado @e final de la pila, mientras que
 * el borrado y consulta se lleva tambien  a cabo al final, denominado
 * @e final de la pila. Una pila de longitud @e n la denotamos

 * - <a1,a2,a3,..,an<

 * En esta pila, tendremos acceso �nicamente al elemento del @e Final,
 * es decir, a @e a1. El borrado o consulta de un elemento ser� sobre @e a1,
 * mientras que la inserci�n de un nuevo elemento se har� despu�s de
 * @e an (final de la cola).
 *
 * Si n=0 diremos que la cola est� vac�a.
 *
 * El espacio requerido para el almacenamiento es O(n), donde n es el n�mero
 * de elementos de la cola.
 *
 * @author
 * @date
*/
#include<iostream>
using namespace std;
struct elemento
{
  int dato;
  int max;
  int min;

};

/**
* @brief Operator << devuelve los componentes de un elemento.
* @param os flujo de salida
* @param s  la estructura elemento a mostrar
* @return os El flujo de salida
*/

ostream & operator <<(ostream & os, const elemento & s)
{
  os << "Dato: "<< s.dato << ", Maximo: "<< s.max << ", Minimo: "<< s.min;
  return os;
}

#define IMPLEMENTACION 2

#if IMPLEMENTACION == 1
#include <pila_maxmin_list.h>
#elif IMPLEMENTACION == 2
#include <pila_maxmin_vd.h>
#else
#include <pila_maxmin_cola.h>
#endif
