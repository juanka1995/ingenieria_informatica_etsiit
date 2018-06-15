#include <iostream>
#include <list>

using namespace std;

// Asumimos que ninguna de las listas está vacia
void peinarListas(list<char> &destino, list<char> &origen){
  list<char>::iterator it,it2;
  bool turno = true;

  it = destino.begin();
  it2 = origen.begin();

  while(it != destino.end() && it2 != origen.end()){
    if (turno){
      ++it;
      turno = false;
    }
    else{
      destino.insert(it,*it2);
      it2 = origen.erase(it2);
      turno = true;
    }
  }

  if(it == destino.end())
    for (; it2 != origen.end(); it2 = destino.erase(it2))
      destino.push_back(*it2);
}

void mostrarLista(const list<char> &l){
  list<char>::const_iterator it;
  for (it = l.begin(); it != l.end(); ++it)
    cout << *it << " ";
  cout << endl;
}

int main(int argc, char const *argv[]) {
  list<char> origen, destino;

  destino.push_back('H');destino.push_back('o');destino.push_back('l');destino.push_back('a');

  origen.push_back('m');origen.push_back('u');origen.push_back('n');
  origen.push_back('d');origen.push_back('o');

  cout << "Lista origen antes: ";
  mostrarLista(origen);

  cout << "Lista destino antes: ";
  mostrarLista(destino);

    peinarListas(destino,origen);

  cout << endl << "Lista origen despues: ";
  mostrarLista(origen);

  cout << "Lista destino despues: ";
  mostrarLista(destino);

  return 0;
}
