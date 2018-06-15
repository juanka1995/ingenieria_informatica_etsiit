/*
Diseña una funcion para calcular la potencia externa PE de un ABB definida como:

      PE = SUMATORIA(2^profundidad(n))
Siendo n cada nodo hoja del arbol
*/

#include <iostream>
#include "bintree.h"
#include <cmath>

using namespace std;

template <class T>
int profundidad(const bintree<T> &A,const typename bintree<T>::node & n){
  int contador = -1;
  if(!n.null())
    contador = profundidad(A,n.parent()) + 1;
  return contador;
}

template <class T>
int auxCalcularPotExt(const bintree<T> &A, const typename bintree<T>::node &n){
  int resultado = 0;
  if (!n.null()) {
    if (n.left().null() && n.right().null()) {
      resultado += pow(2,profundidad(A,n));
    }
    else{
      resultado += auxCalcularPotExt(A,n.left());
      resultado += auxCalcularPotExt(A,n.right());
    }
  }
  return resultado;
}

template <class T>
int calcularPotExt(const bintree<T> &A){
  return auxCalcularPotExt(A,A.root());
}


int main(int argc, char const *argv[]) {

  bintree<int> prueba(50);
  int resultado;

  prueba.insert_left(prueba.root(), 30);
  prueba.insert_right(prueba.root(), 65);
  prueba.insert_left(prueba.root().left(), 10);
  prueba.insert_right(prueba.root().left(), 40);
  prueba.insert_left(prueba.root().left().right(), 34);
  prueba.insert_right(prueba.root().left().right(), 43);
  prueba.insert_left(prueba.root().left().left(), 5);
  prueba.insert_right(prueba.root().left().left(), 20);
  prueba.insert_left(prueba.root().left().left().right(), 12);
  prueba.insert_right(prueba.root().left().left().right(), 23);

  // Creamos el árbol:
  //         50
  //       /    \
  //     30      65         PE = a+b+c+d+e+f =
  //    /   \     a               2^1+2^3+2^3+2^3+2^4+2^4 = 58
  //   10    40
  //  /  \   / \
  // 5   20 34 43
  // b   / \ c  d
  //    12 23
  //     e  f

  resultado = calcularPotExt(prueba);

  cout << resultado << endl;

}
