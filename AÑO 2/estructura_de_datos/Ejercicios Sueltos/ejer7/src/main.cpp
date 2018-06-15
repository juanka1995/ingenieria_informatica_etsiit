#include <iostream>
#include "lista.h"

using namespace std;

int main(int argc, char const *argv[]) {
  Lista<int> lista1,lista2,resultado;

  lista1.insertar(1);
  lista1.insertar(2);
  lista1.insertar(3);
  lista1.insertar(4);
  lista1.insertar(5);

  lista2.insertar(2);
  lista2.insertar(7);
  lista2.insertar(9);

  cout << "Lista 1: " << lista1 << endl;
  cout << "Lista 2: " << lista2 << endl;

  resultado = lista1.mezclarListas(lista2);

  cout << endl << "Resultado: " << resultado << endl;

  return 0;
}
