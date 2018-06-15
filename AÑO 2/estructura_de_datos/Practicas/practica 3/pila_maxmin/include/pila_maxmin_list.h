#ifndef __PILA_MAXMIN_LIST
#define __PILA_MAXMIN_LIST

#include <iostream>
#include "list.h"

using namespace std;

class Pila{
  private:
      Lista<elemento> datos;
  public:
    Pila(){};
    elemento tope()const;
    bool vacia() const;
    void poner(const int & v);
    void quitar();
    int size()const;
};

#include "pila_maxmin_list.cpp"

#endif
