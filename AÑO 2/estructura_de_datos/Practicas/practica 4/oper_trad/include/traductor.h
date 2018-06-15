/**
  * @file traductor.h
  * @brief Fichero cabecera del TDA Traductor
  */

#include <map>
#include "frase.h"

using namespace std;

/**
* @brief T.D.A. Traductor
*
* Una instancia de traductor es un mapa
* compuesto por una clave string (origen)
* y un valor que seria una frase con su
* su origen y sus correspondientes destinos
*
* Un ejemplo de su uso:
* @include traductor.h
*
* @author Juan Carlos Ruiz García
* @date Diciembre 2016
*/

#ifndef _TRADUCTOR_H_
#define _TRADUCTOR_H_

/**
* @brief Clase functor encargada de especificar el orden que llevara
* el mapa del Traductor gracias a la key_compare del mapa
*/
class comparador{
  public:
    /**
    * @brief Sobrecarga del operador (). Ordenaremos el mapa de Traductor
    * de forma alfabetica.
    */
    bool operator()(const string &origen1,const string &origen2){
      return origen1 < origen2;
    }
};

class Traductor{
  private:
    /**
    * @page repConjunto Rep del TDA Traductor
    *
    * @section invConjunto Invariante de la representacion
    *
    * Para representar esta clase utilizaremos un mapa del tipo:
    * map<string,Frase,comparador> frases;
    *
    */
    map<string,Frase,comparador> traducciones;
  public:
    /**
    * @brief Clase del iterador constante para iterar sobre un Traductor
    */
    class const_iterator{
      private:
        map<string,Frase,comparador>::const_iterator it;
      public:

        /**
        * @brief Constructor por defecto
        */
        const_iterator(){};

        /**
        * @brief Constructor copia
        */
        const_iterator(const map<string,Frase,comparador>::const_iterator i):it(i){};

        /**
        * @brief Operador ++ PRE-incremento
        * @return Devuelve un iterador a la siguiente posicion
        */
        const_iterator & operator++(){
          ++it;
          return *this;
        }

        /**
        * @brief Operador -- PRE-decremento
        * @return Devuelve un iterador a la anterior posicion
        */
        const_iterator & operator--(){
          --it;
          return *this;
        }

        /**
        * @brief Operador ==. Compara si dos iteradores son iguales
        * @return Devuelve true si son iguales y false en caso contrario
        */
        bool operator==(const const_iterator &orig)const{
          return it==orig.it;
        }

        /**
        * @brief Operador !=. Compara si dos iteradores no son iguales
        * @return Devuelve true si no son iguales y false en caso contrario
        */
        bool operator!=(const const_iterator &orig)const{
          return it!=orig.it;
        }

        /**
        * @brief Operador *. Devuelve el contenido de la posicion a la que apuntaba el iterador de Traductor
        * @return Devuelve un pair<string,Frase> con el contenido de la posicion a la que apuntaba el iterador
        * de traductor
        */
        const pair<const string,Frase> & operator*()const{
          return *it;
        }

        // Clase friend Traductor
        friend class Traductor;
    };

    /**
    * @brief Constructor por defecto.
    */
    Traductor(){};

    /**
    @brief Metodo encargado de devolver un iterador constante con la posicion de la primera entrada del mapa
    @return Devuelve un const_iterator apuntando a la primera entrada del map traducciones
    */
    const_iterator begin() const;

    /**
    @brief Metodo encargado de devolver un iterador constante con la posicion de la ultima entrada del mapa
    @return Devuelve un const_iterator apuntando a la ultima entrada del map traducciones
    */
    const_iterator end() const;

    /**
    * @brief Metodo encargado de buscar una clave concreta en el mapa traducciones
    * @param clave:string de la clave a buscar
    * @return Si encuentra la clave en el mapa devuelve un const_iterator con la posicion de dicha clave,
    * en caso contrario devuelve un const_iterator con la traducciones.end()
    */
    const_iterator find(const string & clave) const;

    /**
    * @brief Inserta una nueva frase al mapa de frases utilizando los []. Si no existe dicha clave la crea
    * e inserta la correspondiente frase al valor.
    */
    void InsertarFrase(const Frase &ff);

    /**
    * @brief Sobrecarga el operador >> para añadir al mapa de traducciones el contenido de un fichero
    * @param o:flujo de entrada
    * @param tr:traductor en el que guardaremos el contenido del fichero
    * @return Devuelve el flujo
    */
    friend istream& operator>>(istream &o,Traductor &tr);

    /**
    * @brief Devuelve los destinos de un origen especificado
    * @param ff:string que contiene el origen
    * @pre Asumimos que el string pasado por parametro es un origen existente dentro del conjunto de traducciones
    * @return Devuelve un vector<string> con los destinos del origen especificado
    */
    vector<string> GetTraducciones(const string &ff);

    /**
    * @brief Pasa un string a minusculas
    * @param ff:string que deseamos pasar a minusculas
    */
    void toLower(string &ff);

    /**
    * @brief Sobrecarga el operador << para mostrar el conjunto de frases y sus traducciones
    * @param os:flujo de salida
    * @param cf:conjunto de frases de las que queremos mostrar sus traduciones
    * @return Devuelve el flujo de salida
    */
    friend ostream& operator<< (ostream & os, const Traductor &tr);

};

#include "traductor.hxx"

#endif
