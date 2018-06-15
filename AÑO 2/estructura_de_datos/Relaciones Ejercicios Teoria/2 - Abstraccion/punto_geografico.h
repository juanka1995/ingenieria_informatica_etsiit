#include <iostream>
#include <string>

using namespace std;

/**
*
* @brief T.D.A. Punto Geografico
*
* @brief INVARIANTE DE REPRESENTACION
*
* Para cada instancia del T.D.A. Punto Geografico el float
* latitud tiene que tener un valor comprendido entre -90 y 90,
* y ademas el float longitud tiene que tener un valor comprendido
* entre -180 y 180. Si no las coordenadas del punto geografico
* serian erroneas.
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

class PuntoGeografico{
  private:
    /* OTRO TIPO REP
    pair<float,float>; // La key seria la latitud y el valor la longitud
    */
    float latitud;
    float longitud;
  public:
    /**
    * @brief Constructor por defecto. Se iniciaría la longitud a 0 y la latitud a 0.
    */
    PuntoGeografico();
    /**
    * @brief Constructor con parametros
    * @param Recibe una latitud y una longitud
    * @pre Asumimos que lat está entre -90 y 90, y ademas que lon esta entre -180 y 180
    */
    PuntoGeografico(float lat, float lon);
    /**
    * @brief Devuelve la latitud del punto geografico
    * @return Devuelve el float latitud
    */
    float getLatitud();
    /**
    * @brief Devuelve la latitud del punto geografico
    * @return Devuelve el float latitud
    */
    float getLongitud();
    /**
    * @brief Asigna una nueva longitud a un punto geografico
    * @param Recibe una nueva longitud.
    * @pre Asumimos que new_lon esta entre -180 y 180
    */
    void setLongitud(float new_lon);
    /**
    * @brief Asigna una nueva latitud a un punto geografico
    * @param Recibe una nueva latitud.
    * @pre Asumimos que new_lat esta entre -90 y 90
    */
    void setLatitud(float new_lat);
}
