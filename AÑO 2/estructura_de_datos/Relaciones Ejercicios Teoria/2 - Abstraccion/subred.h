#include <iostream>
#include <string>

#include <servidor.h>

using namespace std;

/**
*
* @brief T.D.A. Subred
*
* @brief INVARIANTE DE REPRESENTACION
*
* Para cada instancia del T.D.A. Subred el mapa subr
* tiene que tener como key una ip valida con numeros
* entre 0 y 255.
*
*
* @brief FORMA DE USO
*
* #include 'subred.h'
*
*
* @autor Juan Carlos Ruiz García
* @date Diciembre 2016
*
*/

class Subred{
  private:
    /* OTRO TIPO REP
      set<unsigned char[4]>; //Ip que identifica a la subred
      vector<Servidor>; // Conjunto de servidores pertenecientes a una subred
      int n_servidores; // Numero de servidores de la subred
    */
    map<unsigned char[4],vector<Servidor>> subr;
    int n_servidores;
  public:
    /**
    * @brief Constructor por defecto. Se iniciaría la ip de la subred a 127.0.0.1
    * y el n_servidores a 0.
    */
    Subred();
    /**
    * @brief Constructor con parametros.
    * @param Recibe una nueva ip para crear la nueva subred.
    */
    Subred(unsigned char *ip);
    /**
    * @brief Devuelve un servidor especifico
    * @return Devuelve el servidor cuya ip es la pasada por parametros.
    * @param Recibe una ip buscar dentro del mapa de servidores
    * @pre Asumimos que la ip que buscamos pertenece a algun servidor
    */
    Servidor getServidor(unsigned char *i);
    /**
    * @brief Añade un nuevo servidor al mapa de subred
    * @param Recibe el nuevo servidor que quiere insertarse en la Subred.
    */
    void aniadirServidor(const Servidor &serv);
    /**
    * @brief Devuelve el numero de servidores que contiene la subred
    */
    int getNServidores();
}
