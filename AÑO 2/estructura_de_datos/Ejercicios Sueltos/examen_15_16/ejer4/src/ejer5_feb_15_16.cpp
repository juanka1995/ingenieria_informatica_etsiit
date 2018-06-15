/*
Implementa una funcion que compruebe si un arbol binario es simetrico de otro
*/

#include <iostream>
#include "bintree.h"
#include <cmath>

using namespace std;

template <class T>
bool simetricos(const bintree<T> &A, const bintree<T> &B){
  return auxSimetricos(A,A.root(),B,B.root());
}

template <class T>
bool auxSimetricos(const bintree<T> &A, const typename bintree<T>::node &na, const bintree<T> &B, const typename bintree<T>::node &nb){
  bool simetrico = false;
  if (!na.null() && !nb.null()) {
    simetrico = (*na == *nb);
    // cout << *na << " " << *nb << endl;
    if(simetrico)
      simetrico = auxSimetricos(A,na.right(),B,nb.left()) && auxSimetricos(A,na.left(),B,nb.right());
  }
  else if(na.null() && nb.null()){
    simetrico = true;
  }
  return simetrico;
}

template<typename T>
void mostrarNodosNivelNORecursivo(const bintree<T> &A){
  queue<pair<typename bintree<T>::node,int> > cola;
  typename bintree<T>::node n = A.root();
  typename bintree<T>::node aux;

  if( !n.null() ){
    cola.push(pair<typename bintree<T>::node,int>(n,1));
    while( !cola.empty() ){
      aux = cola.front().first;
        cout << *aux << " " << cola.front().second << endl;
      if( !aux.left().null() ){
        cola.push(pair<typename bintree<T>::node,int>(aux.left(),(cola.front().second)+1));
      }
      if( !aux.right().null() ){
        cola.push(pair<typename bintree<T>::node,int>(aux.right(),(cola.front().second)+1));
      }
      cola.pop();
    }
  }
}

int main(int argc, char const *argv[]) {

  bintree<int> A(5);
  bool resultado;

  A.insert_left(A.root(), 3);
  A.insert_right(A.root(), 8);
  // A.insert_left(A.root().left(), 1);
  A.insert_right(A.root().left(), 4);
  A.insert_right(A.root().right(),9);
  A.insert_left(A.root().right(),6);
  A.insert_right(A.root().right().left(),7);

  bintree<int> B(5);
  B.insert_left(B.root(), 8);
  B.insert_right(B.root(), 3);
  B.insert_left(B.root().left(), 9);
  B.insert_right(B.root().left(), 6);
  // B.insert_right(B.root().right(),1);
  B.insert_left(B.root().right(),4);
  // B.insert_left(B.root().left().right(),7);

  // Creamos los arboles:
  //
  //        A                    B
  //
  //        5                    5
  //      /   \                /   \
  //     3     8              8     3
  //    / \   / \     ==     / \   / \
  //   1   4 6   9          9   6 4   1
  //          \                /
  //           7              7
  //
  //

  // mostrarNodosNivelNORecursivo(A);
  // cout << endl;
  // mostrarNodosNivelNORecursivo(B);

  resultado = simetricos(A,B);

  if (resultado) {
    cout << "Los arboles A y B son simetricos" << endl;
  }
  else{
    cout << "Los arboles A y B NO son simetricos" << endl;
  }

  //cout << resultado << endl;

}
