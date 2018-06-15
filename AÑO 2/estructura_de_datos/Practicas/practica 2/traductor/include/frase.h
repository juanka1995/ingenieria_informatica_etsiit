/**
  * @file frase.h
  * @brief Fichero cabecera del TDA Frase
  *
  */

#include <vector>
#include <iostream>
#include <string>

using namespace std;

/**
  *  * @brief T.D.A. Frase
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
  * @date Noviembre 2016
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

    void InsertarDestino(const string &nuevo_dest);
};

#include "frase.hxx"

#endif
