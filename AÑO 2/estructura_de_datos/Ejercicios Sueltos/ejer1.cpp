#include <iostream>
#include <stack>

using namespace std;

void eliminaRep(stack<int> &pila){
  stack<int> aux;
  while(!pila.empty()){
    aux.push(pila.top());
    pila.pop();
    while(!pila.empty() && pila.top() == aux.top())
      pila.pop();
  }
  while (!aux.empty()) {
    pila.push(aux.top());
    aux.pop();
  }
}

void invertirPila(stack<int>&pila){
  stack<int> aux1,aux2;
  while(!pila.empty()){
    aux1.push(pila.top());
    pila.pop();
  }
  while(!aux1.empty()){
    aux2.push(aux1.top());
    aux1.pop();
  }
  while(!aux2.empty()){
    pila.push(aux2.top());
    aux2.pop();
  }
}

void mostrarPila(stack<int> pila){
  while (!pila.empty()){
    cout << pila.top() << "";
    pila.pop();
  }
  cout << endl;
}

int main(int argc, char const *argv[]) {
  stack<int> pila;

  pila.push(3);pila.push(7);pila.push(7);
  pila.push(8);pila.push(9);pila.push(1);
  pila.push(1);pila.push(5);pila.push(5);
  pila.push(4);pila.push(3);pila.push(3);
  pila.push(2);pila.push(1);pila.push(1);

  cout << "Pila antes: ";
  mostrarPila(pila);

  eliminaRep(pila);
  invertirPila(pila);

  cout << endl << "Pila despues: ";
  mostrarPila(pila);

  return 0;
}
