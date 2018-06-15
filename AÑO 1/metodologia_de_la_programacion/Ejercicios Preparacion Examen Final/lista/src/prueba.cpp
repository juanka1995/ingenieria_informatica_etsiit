#include <iostream>
#include "lista.h"

using namespace std;

int main(int argc, char const *argv[]) {
  // Constructor por defecto
  Lista l1;
  // InsertarFin
  for(int i=0;i<5;i++)
    l1.insertarFin(i);
  // Sobrecarga del operador <<
  cout << l1 << endl;

  //Constructor pasandole un entero
  Lista l2(5);
  cout << l2 << endl;
  //Constructor copia
  Lista l3(l2);
  cout << l3 << endl;

  //Sobrecarga del operador de asignacion
  l2=l1;
  cout << l2 << endl;

  //Sobrecarga del operador + (lista+lista+entero)
  l2=l3+l1+69;
  cout << l2 << endl;

  //Sobrecarga del operador >>
  cout << "Introduce los numeros de la lista separados por espacios (Ctrl+D para salir): ";
  cin >> l3;
  cout << l3 << endl;

  //Dividir una lista en lon listas de tamaño t
  int t=2;
  int lon=l1.getLongitud()/t;
  if(!l1.getLongitud()%t==0)
    lon++;
  Lista *l=l1.dividir(t);
  cout << "Lista dividida en " << lon << " listas de tamaño " << t << endl;
  for(int i=0;i<lon;i++){
    cout << l[i] << endl;
  }

  // Sobrecarga del operador ==
  if(l2==l1)
    cout << "SON IGUALES" << endl;
  else
    cout << "NO SON IGUALES" << endl;

  //Sobrecarga del operador > y <
  if(l2>l3)
    cout << "L2 es mayor que L3" << endl;
  if(l2<l3)
    cout << "L2 es menor que L3" << endl;
  cout << endl;

  //Insertar una celda en una posicion concreta de la lista
  l3.setCelda(3,47);
  cout << l3 << endl;
  //Insertar un numero al inicio de una lista
  l3.insertarIni(88);
  cout << l3 << endl;
  //Insertar un dato al final de una lista
  l3.insertarFin(22);
  cout << l3 << endl;
  //Eliminar la primera celda de una lista
  l3.eliminarIni();
  cout << l3 << endl;
  //Eliminar la ultima celda de una lista
  l3.eliminarFin();
  cout << l3 << endl;
  //Eliminar una lista completamente
  l3.eliminar();
  cout << l3 << endl;

  return 0;
}
