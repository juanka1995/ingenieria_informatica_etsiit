#include <list>
#include <iostream>

using namespace std;

#ifndef _LISTA_H_
#define	_LISTA_H_

template <class T>
class Lista{
  private:
    list<T> lista;
    bool yaExiste(const T &t)const;
  public:
    Lista<T>(){};
    Lista<T> mezclarListas(const Lista<T> &l) const;
    void insertar(const T &x);
    list<T> getLista()const;
    void mostrarLista()const {
      typename list<T>::const_iterator it;
      for (it = lista.begin(); it != lista.end(); ++it) {
        cout << *it << " ";
      }
    }
};

template <class T>
ostream & operator<<(ostream& os, const Lista<T> &l);

#include "lista.hxx"

#endif
