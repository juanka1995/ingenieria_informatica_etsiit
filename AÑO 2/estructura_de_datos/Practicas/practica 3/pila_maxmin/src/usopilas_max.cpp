#include <iostream>
#include "pila_maxmin.h"

using namespace std;

int main(){

  Pila p;
  int i;
  for ( i=10; i>=0 ; i--)
    p.poner(i);


  while(!p.vacia()) {
    elemento x = p.tope();
    cout << x <<endl;
    p.quitar();
  }

  return 0;
}
