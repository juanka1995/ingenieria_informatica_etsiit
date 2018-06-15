#ifndef _LISTA_H_
#define _LISTA_H_

#include <iostream>

using namespace std;

struct Celda{
  int dato;
  Celda *siguiente;
};

class Lista{
  private:
    Celda *cabecera;
    void destruir();
    void copia(const Lista &l);
  public:
    Lista();
    Lista(int k);
    ~Lista();
    Lista(const Lista &l);
    Lista& operator=(const Lista &l);
    Lista operator+(int k)const;
    Lista operator+(const Lista &l)const;
    friend ostream& operator<<(ostream &flujo,const Lista &l);
    friend istream& operator>>(istream &flujo,Lista &l);
    Lista* dividir(int t);
    bool operator<(const Lista &l)const;
    bool operator>(const Lista &l)const;
    bool operator==(const Lista &l)const;
    int getCelda(int k)const;
    void setCelda(int pos,int k);
    int getLongitud()const;
    void insertarIni(int k);
    void insertarFin(int k);
    void eliminarIni();
    void eliminarFin();
    void eliminarPos(int pos);
    void eliminar();
};

#endif
