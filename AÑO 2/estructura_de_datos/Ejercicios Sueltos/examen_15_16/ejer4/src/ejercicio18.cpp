/**
Crear una funcion que muestre los nodos de un nivel concreto de forma no recursiva.
Implente tambien los demas recorridos
Implementa una funcion que calcule el numero de nodos
*/
#include <iostream>
#include <queue>
#include "bintree.h"

using namespace std;

template<typename T>
void mostrarNodosNivelNORecursivo(const bintree<T> &A, int l){
  queue<pair<typename bintree<T>::node,int> > cola;
  typename bintree<T>::node n = A.root();
  typename bintree<T>::node aux;

  if( !n.null() ){
    cola.push(pair<typename bintree<T>::node,int>(n,1));
    while( !cola.empty() ){
      aux = cola.front().first;
      if( cola.front().second == l ){
        cout << *aux << endl;
      }
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

template<typename T>
void RecorridoPreordenRecursivo(const bintree<T> &A, typename bintree<T>::node n){
  if( !n.null() ){
    cout << *n << endl;
    RecorridoPreordenRecursivo(A,n.left());
    RecorridoPreordenRecursivo(A,n.right());
  }
}

template<typename T>
void RecorridoPostodenRecursivo(const bintree<T> &A, typename bintree<T>::node n){
  if( !n.null() ){
    RecorridoPostodenRecursivo(A,n.left());
    RecorridoPostodenRecursivo(A,n.right());
    cout << *n << endl;
  }
}

template<typename T>
void RecorridoInodenRecursivo(const bintree<T> &A, typename bintree<T>::node n){
  if( !n.null() ){
    RecorridoInodenRecursivo(A,n.left());
    cout << *n << endl;
    RecorridoInodenRecursivo(A,n.right());
  }
}

template<typename T>
int nNodos(const bintree<T> &A , typename bintree<T>::node n){
  if( !n.null() ){
    return 1+(nNodos(A,n.left())+nNodos(A,n.right()));
  }
  else return 0;
}

int main(){
  bintree<int> prueba(7);

  prueba.insert_left(prueba.root(), 1);
  prueba.insert_right(prueba.root(), 9);
  prueba.insert_left(prueba.root().left(), 6);
  prueba.insert_right(prueba.root().left(), 8);
  prueba.insert_right(prueba.root().left().right(), 4);
  prueba.insert_left(prueba.root().right(), 5);

  //      Arbol:
  //        7
  //     /    \
  //    1      9
  //  /  \    /
  // 6    8  5
  //       \
  //       4

  int nivel = 3;
  cout << "Mostrar nodos del nivel " << nivel << ":" << endl;
  mostrarNodosNivelNORecursivo(prueba,nivel);

  cout << endl << "Mostrar en arbol en Preorden:" << endl;
  RecorridoPreordenRecursivo(prueba,prueba.root());

  cout << endl << "Mostrar el arbol en Postorden:" << endl;
  RecorridoPostodenRecursivo(prueba,prueba.root());

  cout << endl << "Mostrar el arbol en Inorden:" << endl;
  RecorridoInodenRecursivo(prueba,prueba.root());

  cout << endl << "Mostrar el numero de nodos:" << endl;
  cout << nNodos(prueba,prueba.root()) << endl;
}
