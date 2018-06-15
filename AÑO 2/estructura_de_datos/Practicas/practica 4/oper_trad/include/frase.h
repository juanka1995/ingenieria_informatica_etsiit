/**
  * @file frase.h
  * @brief Fichero cabecera del TDA Frase
  */

#include <vector>
#include <iostream>
#include <string>

using namespace std;

/**
  * @brief T.D.A. Frase
  *
  * Una instancia de una frase es un objeto que contiene
  * un dato de tipo string el cual contiene la frase en el idioma origen,
  * y un dato de tipo vector<string> que contiene las correspondientes
  * traducciones de la frase en el idioma destino.
  *
  * Un ejemplo de su uso:
  * @include frase.h
  *
  * @author Juan Carlos Ruiz García
  * @date Diciembre 2016
  */

#ifndef _FRASE_H_
#define _FRASE_H_

class Frase{
  private:
    /**
    * @page repFrase Rep del TDA Frases
    *
    * @section invFrase Invariante de la representacion
    *
    * Para representar esta clase utilizaremos un string y un vector del tipo:
    * \e vector<string>
    *
    * En dicho string guardaremos la frase de origen y en el vector destino
    * sus correspondientes traducciones.
    *
    */
    string origen;
    vector<string> destino;
  public:
    /**
    * @brief Clase del iterador constante para iterar sobre un Frase
    */
    class const_iterator{
      private:
        vector<string>::const_iterator it;
      public:
        /**
        * @brief Constructor por defecto
        */
        const_iterator(){};
        /**
        * @brief Constructor copia
        */
        const_iterator(const vector<string>::iterator &i){
          it = i;
        }
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
        const string &operator*()const{
          return *it;
        }
        // Clase friend Frase
        friend class Frase;
    };
    /**
    @brief Metodo encargado de devolver un iterador constante con la posicion de la primera entrada del vector
    @return Devuelve un const_iterator apuntando a la primera entrada del vector de destinos
    */
    const_iterator begin() const;
    /**
    @brief Metodo encargado de devolver un iterador constante con la posicion de la ultima entrada del vector
    @return Devuelve un const_iterator apuntando a la ultima entrada del vector de destinos
    */
    const_iterator end() const;
    /**
    * @brief Constructor por defecto
    */
    Frase(){};
    /**
    * @brief Construye una frase a partir de un string con sus traducciones
    * @param ff:string que contiene la frase y sus traducciones
    */
    Frase(string ff);
    /**
    * @brief Sobrecarga el operador << para mostrar cada frase con sus correspondientes traducciones
    * @param os:flujo de salida
    * @param f:frase que vamos a mostrar con sus traducciones
    * @return Devuelve el flujo de salida
    */
    friend ostream& operator<< (ostream & os, const Frase &f);
    /**
    * @brief Devuelve el vector destino que contiene las traducciones de la frases
    * @return Devuelve el vector destino
    */
    vector<string> GetDestino() const;
    /**
    * @brief Devuelve la frase
    * @return Devuelve el string que contiene la frase
    */
    string GetOrigen() const;
    /**
    * @brief Inserta un nuevo destino al final del vector de destinos
    */
    void InsertarDestino(const string &nuevo_dest);
};

#include "frase.hxx"

#endif
