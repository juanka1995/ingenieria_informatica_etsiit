#include <iostream>
#include <stack>

using namespace std;

bool Comparar(stack<char> pila){
  bool mismo_numero = false;
  stack<char> aux;
  int izq = 0, drch = 0;
  if (pila.size()%2 == 0) {
    while (!pila.empty()) {
      if (pila.top() == '(')
        izq++;
      else
        drch++;
      pila.pop();
    }
    if (izq == drch)
      mismo_numero = true;
  }
  return mismo_numero;
}

int main(int argc, char const *argv[]) {
  stack<char> pila;

  pila.push('(');pila.push('(');pila.push('(');pila.push('(');
  pila.push(')');pila.push(')');pila.push(')');
  
  pila.push('(');

  if (Comparar(pila))
    cout << "La pila tiene el mismo numero de '(' que de ')'" << endl;
  else
    cout << "La pila NO tiene el mismo numero de '(' que de ')'" << endl;

  return 0;
}
