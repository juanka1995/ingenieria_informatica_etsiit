#include <iostream>
#include <string>

using namespace std;

/**
*
* @brief T.D.A. Servidor
*
* @brief INVARIANTE DE REPRESENTACION
*
* Para cada instancia del T.D.A. Servidor el dato miembro
* ip debe contener unicamente numeros comprendidos entre 0
* y 255. Si no resultaría una ip inválida.
*
*
* @brief FORMA DE USO
*
* #include 'servidor.h'
*
*
* @autor Juan Carlos Ruiz García
* @date Diciembre 2016
*
*/

class Servidor{
  private:
    /* OTRO TIPO REP
      unsigned int ip[4];
    */
    unsigned char ip[4];
  public:
    /**
    * @brief Constructor por defecto. Se iniciaría el vector de char ip como 127.0.0.1
    */
    Servidor();
    /**
    * @brief Constructor con parametros.
    * @param Recibe un vector de char y se encarga de asignar cada valor al vector de char ip
    * @pre Asumimos que el vector recibido contiene numeros y que es de tamaño 4
    */
    Servidor(unsigned char *ip2);
    /**
    * @brief Devuelve la ip del Servidor
    * @return Devuelve un string que contiene la ip actual del Servidor.
    */
    string getIp();
    /**
    * @brief Cambia la antigua ip del servidor por una nueva.
    * @param Vector de char que contiene la nueva ip
    */
    void setNewIp(unsigned char *new_ip);
}
