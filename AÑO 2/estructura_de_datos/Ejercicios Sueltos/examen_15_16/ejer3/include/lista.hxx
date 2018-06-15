
template <class T>
void Lista<T>::duplicar(const Lista<T> & inicial, Lista<T> & resultado){
  typename list<T>::const_iterator it,it2;
  it = inicial.lista.begin();
  it2 = --(inicial.lista.end());
  resultado.lista.clear();
  while (it != inicial.lista.end()) {
    resultado.insertar(*it);
    resultado.insertar(*it2);
    ++it;
    --it2;
  }
}

template <class T>
list<T> Lista<T>::getLista()const{
  return lista;
}

template <class T>
void Lista<T>::insertar(const T &x){
  lista.push_back(x);
}

template <class T>
ostream & operator<<(ostream& os, const Lista<T> &l){
  typename list<T>::const_iterator it;
  list<T> mylist = l.getLista();
  for (it = mylist.begin(); it != mylist.end(); ++it) {
    os << *it << " ";
  }
  return os;
}
