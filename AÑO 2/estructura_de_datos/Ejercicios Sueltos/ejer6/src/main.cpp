#include <iostream>
#include "conjunto_enteros.h"

using namespace std;

int main(int argc, char const *argv[]) {
  ConjuntoEnteros conjunto,conjunto2;

  conjunto.insertar(1);
  conjunto.insertar(2);
  conjunto.insertar(3);
  conjunto.insertar(4);
  conjunto.insertar(5);

  conjunto2.insertar(2);
  conjunto2.insertar(9);

  cout << "Conjunto 1: " << conjunto << endl;
  cout << "Conjunto 2: " << conjunto2 << endl;

  if (conjunto.estaIncluido(conjunto2))
    cout << "El conjunto 2 esta incluido en el conjunto 1." << endl;
  else
    cout << "El conjunto 2 NO esta incluido en el conjunto 1." << endl;

  return 0;
}
