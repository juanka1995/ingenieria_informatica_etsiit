#include <iostream>
#include "lista.h"

using namespace std;

int main(int argc, char const *argv[]) {
  Lista<int> lista1,resultado;

  lista1.insertar(1);
  lista1.insertar(2);
  lista1.insertar(3);
  lista1.insertar(4);
  lista1.insertar(5);

  cout << "Lista 1: " << lista1 << endl;

  lista1.duplicar(lista1,resultado);

  cout << endl << "Resultado: " << resultado << endl;

  return 0;
}
