#ifndef _LISTA_H_
#define _LISTA_H_

#include <iostream>

using namespace std;

class Barquitos{
private:
  int nfilas;
  int ncolumnas;
  int **tablero;
  void copia(const Barquitos &b);
  void destruir();
private:
  Barquitos();
  Barquitos(int filas,int columnas);
  ~Barquitos();
  Barquitos(const Barquitos &b);
  Barquitos& operator=(const Barquitos &b);
  bool esPosible(char fila,int columna,int tam,char direc);
}
