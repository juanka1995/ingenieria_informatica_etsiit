#ifndef __PILA_H
#define __PILA_H

#include <iostream>

using namespace std;

template <typename T>
struct Celda{
  T dato;
  Celda *siguiente;
};

template <typename T>
class Lista{
  private:
    Celda<T> *cabecera;
    void destruir();
  public:
    Lista();
    ~Lista();
    T getLast()const;
    bool isEmpty()const;
    void addLast(T dato);
    void deleteLast();
    int getSize()const;
};

#include "list.cpp"

#endif
