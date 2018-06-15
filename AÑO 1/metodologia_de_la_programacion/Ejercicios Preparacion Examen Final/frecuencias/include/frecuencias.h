#ifndef _FRECUENCIAS_H_
#define _FRECUENCIAS_H_

#include <iostream>

using namespace std;

struct Pareja{
  int dato;
  int nveces;
};

class Frecuencias{
private:
  Pareja *parejas;
  int npares;
  void destruir();
  void copiar(const Frecuencias &f);
public:
  Frecuencias();
  ~Frecuencias();
  Frecuencias(const Frecuencias &f);
  Frecuencias& operator=(const Frecuencias &f);
  void Add(const int k);
  int Getnpares()const;
  int getDato(const int pos);
  Frecuencias& operator+=(const int k);
  friend ostream& operator<<(ostream &flujo,const Frecuencias &f);
  int Repeticiones(int d);
};

#endif
