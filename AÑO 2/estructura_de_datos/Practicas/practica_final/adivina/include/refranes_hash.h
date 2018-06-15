#ifndef __REFRANES__HASH_H
#define __REFRANES__HASH_H
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_set>
#include <functional>
using namespace std;

/**
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
  *     Si R es una instancia de Refranes:
  *       f(R) ->
            {[s0,0 ; s0,1 ; ... ; s0,n(0)],
              ...,
              [sm,0 ; ... ; sm,n(m)]}
        Donde si,j es un string que contiene un refrán
        i es el índice del cubo al que pertenece
        j es la posición de la lista.
        Cada string pertenece a un cubo por una función
        que calcula un hash en base a su estado y a una
        lista a su vez sin ningún orden garantizado.
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
    class my_hash{
     private:
        const unsigned N_LETRAS = 28;
        unsigned int len;
     public:
         my_hash(int l=3){
           set_len(l);
         }
         void set_len(int l){
           len = l;
         }
         size_t operator()(const string & clave) const{
           size_t val;
          int mult = 1;
          for(unsigned i=1; i<len; i++){
              mult *= N_LETRAS;
          }
          for(unsigned i=0; i<clave.size() && i<len; i++){
              val += (mult*clave[i]);
              mult /= N_LETRAS;
          }
          return val;
         }
    };

    unordered_set<string,my_hash> ab;
    int len_prefijo;//la longitud del prefijo para definir obtener el valor hash
    int n_ref;
    int caracteres_totales;//numero de caracteres totales


 public:
    /**@brief Constructor por defecto. Inicia len_prefijo a 3
     * */
    //Refranes();

    /**@brief Constructor por defecto. Inicia len_prefijo a  un valor
     **/

    Refranes(int lpre = 3);

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

    //typedef unordered_set<string,my_hash>::iterator iterator;
    //typedef unordered_set<string,my_hash>::const_iterator const_iterator; //declaracion adelantada de los iteradores de refranes
    class iterator;
    class const_iterator;

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


    /****************************************/
    class iterator{
    private:
      unordered_set<string,my_hash>::const_iterator it;
    public:
      string operator*()const{
        return *it;
      }
      bool operator==(const iterator &i)const{
        return it == i.it;
      }
      bool operator!=(const iterator &i)const{
        return it != i.it;
      }
      iterator & operator=(const iterator &i){
        it = i.it;
        return *this;
      }
      iterator & operator++(){
        ++it;
        return *this;
      }
      friend class Refranes;
      friend class const_iterator;
    };


    class const_iterator{
    private:
      Refranes::iterator it;
    public:
      const_iterator(){};
      const_iterator(const Refranes::iterator & i){
        it = i;
      }
      const_iterator & operator=(const const_iterator & cit){
        it = cit.it;
        return *this;
      }
      const string operator*()const{
        return *it;
      }
      bool operator==(const const_iterator &i)const{
        return it == i.it;
      }
      bool operator!=(const const_iterator &i)const{
        return it != i.it;
      }
      const_iterator & operator++(){
        ++it;
        return *this;
      }
      friend class Refranes;
    };
    /***************BEGIN y END*************/

    iterator begin();
    iterator end();

    const_iterator begin()const;
    const_iterator end()const;
};

#endif
