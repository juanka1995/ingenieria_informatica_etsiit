/**
  * @file conjuntofrases.h
  * @brief Fichero cabecera del TDA ConjuntoFrases
  *
  */

#include "frase.h"

using namespace std;

/**
  * @brief T.D.A. ConjuntoFrases
  *
  * Una instancia de conjunto de frases es un objeto es un vector
  * compuesto por varias frases.
  *
  * Un ejemplo de su uso:
  * @include conjuntofrases.h
  *
  * @author Juan Carlos Ruiz García
  * @date Noviembre 2016
  */

#ifndef _CONJUNTOFRASES_H_
#define _CONJUNTOFRASES_H_

class ConjuntoFrases{
  private:
    /**
    * @page repConjunto Rep del TDA ConjuntoFrases
    *
    * @section invConjunto Invariante de la representacion
    *
    * Para representar esta clase utilizarem#include <string>os un vector del tipo:
    * \e vector<string> Frase
    *
    */
    vector<Frase> vm;
  public:
    /**
    * @brief Busca la posicion de un frase en el vector vm.
    * @param ff:string que contiene la frase a buscar en vm
    * @return Devuelve la posicion de la frase en el vector y en caso de no existir devuelve -1.
    */
    int GetPosicion(const string &ff);
    /**
    * @brief Comprueba si existe una frase en el conjunto de frases
    * @param ff:string que contiene la frase que se desea buscar en el conjunto de frases
    * @return Devuelve true si existe la frase y false si no
    */
    bool Esta(string &ff);
    /**
    * @brief Pasa un string a minusculas
    * @param ff:string que deseamos pasar a minusculas
    */
    void toLower(string &ff);
    /**
    * @brief Devuelve el numero de frases contenidas en un conjunto de frases
    * @return Devuelve un entero con el numero de frases del conjunto de frases
    */
    int Size()const;
    /**
    * @brief Insertar al final de vm una nueva frase
    * @param ff:frase a insertar en vm
    */
    void Insertar(const Frase &ff);
    /**
    * @brief Devuelve la frase con sus respectivas traducciones de la frase que se le indica
    * @param ff:string que contiene la frase indicada
    * @pre Asumimos que el string pasado por parametro es una frase existente dentro del conjunto de frases
    * @return Devuelve la frase con las traducciones
    */
    Frase GetTraducciones(const string &ff);
    /**
    * @brief Devuelve un conjunto de frases que contengan la cadena indicada
    * @param c:string con la cadena a indicar
    * @return Devuelve el conjunto de frases que contienen la cadena indicada
    */
    ConjuntoFrases Contenga(string &c);
    /**
    * @brief Sobrecarga el operador >> para añadir al conjunto de frases el contenido de un fichero
    * @param o:flujo de entrada
    * @param cf:conjunto de frases en el que guardaremos el contenido del fichero
    * @return Devuelve el flujo
    */
    friend istream& operator>>(istream &o,ConjuntoFrases &cf);
    /**
    * @brief Sobrecarga el operador << para mostrar el conjunto de frases y sus traducciones
    * @param os:flujo de salida
    * @param cf:conjunto de frases de las que queremos mostrar sus traduciones
    * @return Devuelve el flujo de salida
    */
    friend ostream& operator<< (ostream & os, const ConjuntoFrases &cf);
};

#include "conjuntofrases.hxx"

#endif
