#include <list>
#include <iostream>

using namespace std;

#ifndef _LISTA_H_
#define	_LISTA_H_

template <class T>
class Lista{
  private:
    list<T> lista;
  public:
    Lista<T>(){};
    void duplicar(const Lista<T> & inicial, Lista<T> &resultado);
    void insertar(const T &x);
    list<T> getLista()const;
};

template <class T>
ostream & operator<<(ostream& os, const Lista<T> &l);

#include "lista.hxx"

#endif
