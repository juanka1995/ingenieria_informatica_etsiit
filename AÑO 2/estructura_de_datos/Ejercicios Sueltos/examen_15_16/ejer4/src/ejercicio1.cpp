/**
Escribe una funcion que determine cual es la hoja mas profunda de un pruebaol binario.
*/
#include <iostream>
#include "bintree.h"

using namespace std;

template<typename T>
typename bintree<T>::node recorridoporNiveles(const bintree<T> &A, const typename bintree<T>::node &n){
  typename bintree<T>::const_level_iterator it;
  int i = 0;

  for( it = A.begin_level(); it != A.end_level(); ++it,i++){
    if( i == A.size()-1 )
      return *it;
  }
  //recorrido por niveles con cola
}

int main(){
  bintree<int> prueba(7);
  typename bintree<int>::node resultado;

  prueba.insert_left(prueba.root(), 1);
  prueba.insert_right(prueba.root(), 9);
  prueba.insert_left(prueba.root().left(), 6);
  prueba.insert_right(prueba.root().left(), 8);
  prueba.insert_right(prueba.root().left().right(), 4);
  prueba.insert_left(prueba.root().right(), 5);

  // Creamos el árbol:
  //        7
  //     /    \
  //    1      9
  //  /  \    /
  // 6    8  5
  //       \
  //       4

resultado = recorridoporNiveles(prueba,prueba.root());

cout << *resultado << endl;

}
