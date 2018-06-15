#include <iostream>
#include <list>

using namespace std;

bool esPrimo(int x){
  int divisores = 0;
  bool es_primo = false;
  for (int i = x; i > 0; i--)
    if (x%i == 0)
      divisores++;
  if (divisores == 2 || x == 1)
    es_primo = true;
  return es_primo;
}

void invertirPrimos(list<int> &l){
  bool encontrado;
  list<int>::iterator it_ini = l.begin(),it_fin = --(l.end());
  int mitad_lista = l.size()/2, j = l.size()-1;
  for (int i = 0; i < mitad_lista; i++, ++it_ini) {
    if(esPrimo(*it_ini)){
      encontrado = false;
      for ( ; j >= mitad_lista && !encontrado; j--, --it_fin) {
        if (esPrimo(*it_fin)) {
          swap(*it_ini,*it_fin);
          encontrado = true;
        }
      }
    }
  }
}

void mostrarLista(const list<int> &l){
  list<int>::const_iterator it;
  for (it = l.begin(); it != l.end(); ++it)
    cout << *it << "-";
  cout << endl;
}

int main(int argc, char const *argv[]) {

  list<int> lista;
  list<int>::const_iterator it;

  lista.push_back(1);lista.push_back(4);lista.push_back(5);
  lista.push_back(6);lista.push_back(3);lista.push_back(12);
  lista.push_back(15);lista.push_back(17);

/*
  mostrarLista(lista);

  for (it = lista.begin(); it != lista.end(); ++it)
    if(esPrimo(*it))
      cout << *it << "-";

  cout << endl;*/

  mostrarLista(lista);

  invertirPrimos(lista);

  mostrarLista(lista);

  return 0;
}
