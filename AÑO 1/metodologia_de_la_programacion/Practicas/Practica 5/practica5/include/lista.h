/**
  * @file
  * @brief Clase para la estructura de datos de lista de strings
  *
  * Permite el manejo de cadenas (strings) en una lista enlazada
  *
  */

#ifndef _LISTA_H_
#define _LISTA_H_

#include <string>

using namespace std;

struct Celda{
	string datos;		///valor de la celda actual
	Celda * siguiente;  ///puntero al siguiente elemento de la lista
};

class Lista{

private:
   Celda * cabecera;
public:

/// Construye una lista vacia (0 elementos)
   Lista();


/**
* @brief Construye una lista a partir de un elemento
* @param cadena el elemento a insertar en la lista
*
* Construye una lista de tamaño 1 e inserta la cadena @a cadena
*/
   Lista(string cadena);

/**
* @brief Libera la memoria reservada en la lista de cadenas
*
* Libera la memoria reservada en el vetor de imagen y actualiza el numero
* de elementos de la misma a 0.
*/
   void destruir();

/**
 * @brief inserta una nueva cadena al final de la lista
 * @param cad elemento a insertar en la lista
 *
 * Añade un nuevo elemento ( @a cadena ) a la lista
 */
void insertar(string cadena);

/**
 * @brief devuelve la cadena de la posicion i-esima de la lista o una cadena
 * vacia en caso de que el valor de i sea erroneo.
* @param i indice del elemento dentro de la lista
* @return la cadena que se encuentra en la celda con indice @a i
* siempre que este valor se encuentre en los margenes de la lista,
* o una cadena vacia en caso contrario
*/
string getCelda(int i) const;

/**
 * @brief devuelve el numero de celdas que contiene la lista
 * @return el tamaño de la lista
 *
 */
int longitud() const;

/**
 * @brief Construye una lista de celdas enlazadas a partir de la informacion
 * contenida en un fichero.
 * @param nombreFichero ruta del fichero de texto con el contenido de las cadenas
 * a insertar en la lista
 * @retval true si ha tenido éxito en la lectura y el formato es el correcto
 * @retval false si se ha producido algún error en la lectura
 *
 * Lee desde disco los elementos almacenados en @a nombreFichero y los guarda
 * en la lista. La función debe asegurarse de que la estructura sigue un patron
 * determinado, y se ha de crear la lista con el numero de elementos que contenga.
 */
bool leerLista(const char nombrefichero[]);

};

#endif
