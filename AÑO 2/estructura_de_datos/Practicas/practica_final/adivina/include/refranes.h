#ifndef __REFRANES__H
#define __REFRANES__H
#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include "ArbolGeneral.h"
using namespace std;
   /** 
   * @file Refranes.h: TDA Refranes
   * @page repRefranes Rep del TDA Refranes
   *
   * @section invRefranes Invariante de la representación
   *
   *     Si R es una instancia de Refranes:
   *       R.len_prefijo !< 0
   *       R.r_ref !< 0
   *       R.caracteres_totales !< 0
   *
   * @section faRefranes Función de abstracción
   *
   *   Si R es una instancia de Refranes:
   *   f(R) ->     c-1,-1
                   / |  \
             [c0,0]  c0,1 .. c0,n(0)-1
             /  |  \
     [cm-1,0]  cm-1,1 .. cm-1,n(m-1)
         | \
     [sm,0] ...  sm,n(m)

     Donde en cada nivel del arbol hay almacenado un caracter que
     pertenece al string, habiendo R.len_prefijo niveles no hojas
     sin contar la raiz y las hojas en las que se almacena el
     resto de la cadena, no hay caracteres repetidos en un mismo nivel:

     Ej: [e][s][t][a es una frase] (*para len_prefijo 3)
       [e]: Nivel 0
       [s]: Nivel 1
       [t]: Nivel 2
       [a es una frase]: Nivel 3

   */


class Refranes{
/**
  * @page repRefranes Rep del TDA Refranes
  *
  * @section invRefranes Invariante de la representación
  *
  * Añadir el invariante de la representación
  *
  * @section faRefranes Función de abstracción
  *
  * Añadir la función de abstracción
  */

  private:
    ArbolGeneral<string> ab;//arbol para almacenar los refranes
    int len_prefijo;//la longitud del prefijo para construir el arbol
    int n_ref;//numero de refranes

    //caracteres totales a lo largo de todos los refranes
    int caracteres_totales;


 public:
    /**@brief Constructor por defecto. Inicia len_prefijo a 3
     * */
    Refranes();

    /**@brief Constructor por defecto. Inicia len_prefijo a  un valor
     **/

    Refranes(int lpre);

    /** @brief devuelve el numero de refranes alamacenados
     */

    int size()const;

    /** @brief Inserta un refran en el conjunto
     * @param r: refran a insertar
     * @note el numero de refranes se incrementa en uno mas
     */
    void Insertar(const string & refran);

    /** @brief Borra un refrán en el conjunto
     * @param r: refran a borrar
     * @note el numero de refranes se decrementa en uno mas
     */

    void BorrarRefran(const string &refran);

    class iterator;
    class const_iterator; //declaracion adelantada de los iteradores de refranes

    /** @brief Devuelve si un refran esta en el conjunto. Si esta devuelve un iterador a el
     * @param r: refran a buscar
     * @return una pareja que contiene si el refran esta y en caso afirmativo un iterador a el
    */
    pair<bool, iterator> Esta(const string &refran);

    /** @brief Elimina todos los refranes
     */

    void clear();

    /** @brief Lectura/Escritura de un conjunto de refranes
     */


    friend istream & operator>>(istream &is, Refranes &R);


    friend ostream & operator<<(ostream &is,const Refranes &R);

    /**@brief Devuelve el numero total de los caracteres en todos los refranes
     */

    int Caracteres_Refranes()const;

    /**@brief Devuelve el numero de caracteres usados
     * @note que no tiene que conincide con el numero de caracteres de todos los refranes almancenados

     */
    int Caracteres_Almacenados();

    /**@brief Numero de nodos necesarios para la configuración
     */
    int Numero_Nodos()const;

    /****************************************/
    class iterator{
    private:
      ArbolGeneral<string>::iter_preorden it;
      string cad;
    public:
      iterator(){
	 cad="";
      }
      string & operator *();
      bool operator==(const iterator &i)const;
      bool operator!=(const iterator &i)const;

      iterator &operator ++();

      friend class Refranes;
      friend class const_iterator;
    };


    class const_iterator{
    private:
      ArbolGeneral<string>::const_iter_preorden it;
      string cad;
    public:
      const_iterator(){
        cad = "";
      }
      const_iterator(const iterator  &i){
        it = i.it;
        cad = i.cad;
      };
      string & operator *();
      bool operator==(const const_iterator &i)const;
      bool operator!=(const const_iterator &i)const;

      const_iterator &operator ++();
     friend class Refranes;

    };

    /***************BEGIN y END*************/

    iterator begin();

    iterator end();

    const_iterator begin()const;

    const_iterator end()const;
};

#endif
