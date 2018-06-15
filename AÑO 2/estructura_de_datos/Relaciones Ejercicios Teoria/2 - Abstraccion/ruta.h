#include <iostream>
#include <string>

#include "punto_geografico.h"

using namespace std;

/**
*
* @brief T.D.A. Ruta
*
* @brief INVARIANTE DE REPRESENTACION
*
* Para cada instancia del T.D.A. Ruta todos
* los puntos geograficos que forma la ruta
* deben ser correctos. Si no obtendriamos una
* ruta incoherente.
*
*
* @brief FORMA DE USO
*
* #include 'punto_geografico.h'
*
*
* @autor Juan Carlos Ruiz García
* @date Diciembre 2016
*
*/

//BASADO EN LA FORMULA DE HAVERSINE
const float RADIO_TIERRA = 6378.0F;

class Ruta{
  private:
    /* OTRO TIPO REP
    PuntoGeografico partida; // PuntoGeografico de partida
    list<PuntoGeografico>; // Lista que contiene todos los puntos geograficos de la ruta
    int nPuntos; // Numero de puntos de la ruta
    float distanciaKmRuta; // Distancia total en km de la ruta
    */
    map<PuntoGeografico,vector<PuntoGeografico>> ruta;
    int nPuntos;
    float distanciaKmRuta;
    /**
    * @brief Se encarga de calcular la distantica total de la ruta en Km utilizando
    * la formula de Haversine. Asigna dicho computo a la variable float distanciaKmRuta.
    */
    void calcularKmRuta();
  public:
    /**
    * @brief Constructor por defecto. Se iniciaría nPuntos a 0 y distanciaKmRuta a 0.
    * Se llamara al metodo
    */
    Ruta();
    /**
    * @brief Constructor con parametros. Inicializa el nPuntos a 1, la distanciaKmRuta a 0
    * y asignara al mapa ruta la clave partida.
    * @param Recibe un punto geografico que es el partida.
    */
    Ruta(const PuntoGeografico *partida);
    /**
    * @brief Constructor con parametros. Inicializa el nPuntos a n_puntos, añade al mapa la
    * clave partida y a los datos el vector de PuntoGeograficos v y calcula la distancia en km mediante
    * la funcion calcularKmRuta().
    * @param Recibe un PuntoGeografico que es el partida, un vector de puntos geograficos y el numero de puntos;
    */
    Ruta(const PuntoGeografico *partida,const vector<PuntoGeografico> &v, int n_puntos);
    /**
    * @brief Devuelve el numero de puntos geograficos que tiene la ruta
    * @return Devuelve el int nPuntos
    */
    int getNPuntos()const;
    /**
    * @brief Devuelve el punto de inicio de la ruta, es decir el punto de partida.
    * @ret Devuelve la clave del mapa ruta.
    */
    PuntoGeografico getPuntoPartida();
    /**
    * @brief Devuelve la distancia en KM de la ruta
    * @return Devuelve el float distanciaKmRuta
    */
    int getDistanciaKm()const;
    /**
    * @brief Añade un nuevo punto al final del vector de puntos y vuelve a calcular la distancia en km de la ruta
    * mediante la funcion calcularKmRuta().
    * @param Recibe un nuevo punto geografico
    */
    void aniadePunto(const PuntoGeografico &p);
}
