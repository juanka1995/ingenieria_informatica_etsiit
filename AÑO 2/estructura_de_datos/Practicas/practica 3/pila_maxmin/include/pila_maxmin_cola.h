#ifndef __PILA_MAXMIN_COLA
#define __PILA_MAXMIN_COLA

#include <iostream>
#include "cola.h"

using namespace std;

class Pila{
  private:
      Cola<elemento> datos;
  public:
    Pila(){};
    elemento tope()const;
    bool vacia() const;
    void poner(const int & v);
    void quitar();
    int size()const;
};

#include "pila_maxmin_cola.cpp"

#endif
