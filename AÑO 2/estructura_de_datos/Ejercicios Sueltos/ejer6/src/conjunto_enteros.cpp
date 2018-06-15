#include "conjunto_enteros.h"

bool ConjuntoEnteros::estaIncluido(const ConjuntoEnteros &c) const{
  bool esta_incluido = false;
  if (!c.conjunto.empty()) {
    set<int>::const_iterator it,it2;
    bool encontrado;
    esta_incluido = true;
    for (it2= c.conjunto.begin(); it2!= c.conjunto.end() && esta_incluido; ++it2) {
      encontrado = false;
      for (it = conjunto.begin(); it != conjunto.end() && !encontrado; ++it) {
        if(*it2 == *it)
          encontrado = true;
      }
      if(!encontrado)
        esta_incluido = false;
    }
  }
  return esta_incluido;
}

void ConjuntoEnteros::insertar(int x){
  conjunto.insert(x);
}

ostream& operator<<(ostream& os, const ConjuntoEnteros &c){
  set<int>::const_iterator it;
  for (it = c.conjunto.begin(); it != c.conjunto.end(); ++it) {
    os << *it << "";
  }
  return os;
}
