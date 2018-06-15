#ifndef __VD_H
#define __VD_H

#include <iostream>

using namespace std;

template <typename T>
class VD{
  private:
    T *datos;
    int utiles,reservados;
    void destruir();
    void copia(const VD<T> &origen);
  public:
    VD();
    VD(int tam);
    VD(const VD<T> &origen);
    ~VD();
    void resize();
    VD<T>& operator=(const VD<T> & origen);
    int getElem(int i)const;
    T pop_back()const;
    bool isEmpty()const;
    void push_back(T dato);
    void deleteLast();
    int getSize()const;
};

#include "vd.cpp"

#endif
