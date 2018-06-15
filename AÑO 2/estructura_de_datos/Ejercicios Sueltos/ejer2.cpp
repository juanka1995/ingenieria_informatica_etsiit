#include <iostream>
#include <stack>

using namespace std;

void Reemplazar(stack<int> &pila, int nuevo, int viejo){
  stack<int> aux;
  while (!pila.empty()) {
    if (pila.top() == viejo) {
      pila.pop();
      pila.push(nuevo);
    }
    aux.push(pila.top());
    pila.pop();
  }
  while (!aux.empty()) {
    pila.push(aux.top());
    aux.pop();
  }
}

void mostrarPila(stack<int> pila){
  while (!pila.empty()){
    cout << pila.top() << "-";
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

  Reemplazar(pila,28,1);

  cout << endl << "Pila despues: ";
  mostrarPila(pila);

  return 0;
}
