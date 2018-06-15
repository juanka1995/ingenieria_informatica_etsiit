#ifndef __PILA_MAXMIN_VD
#define __PILA_MAXMIN_VD

#include <iostream>
#include "vd.h"

using namespace std;

class Pila{
  private:
      VD<elemento> datos;
  public:
    Pila(){};
    elemento tope()const;
    bool vacia() const;
    void poner(const int & v);
    void quitar();
    int size()const;
};

#include "pila_maxmin_vd.cpp"

#endif
