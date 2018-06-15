
template <class T>
bool Lista<T>::yaExiste(const T &t)const{
  typename list<T>::const_iterator it;
  bool yaexiste = false;
  for (it = lista.begin(); it != lista.end() && !yaexiste; ++it) {
    if(*it == t)
      yaexiste = true;
  }
  return yaexiste;
}

template <class T>
Lista<T> Lista<T>::mezclarListas(const Lista<T> &l)const{
  Lista<T> resultado;
  typename list<T>::const_iterator it,it2;
  it = lista.begin();
  it2 = l.lista.begin();
  while(it != lista.end() && it2 != l.lista.end()){
    if (*it < *it2) {
      resultado.insertar(*it);
      ++it;
    }
    else if(*it > *it2){
      resultado.insertar(*it2);
      ++it2;
    }
    else if(*it == *it2){
      resultado.insertar(*it2);
      ++it2;
      ++it;
    }
  }
  if (it == lista.end() || it2 == l.lista.end()) {
    if (it == lista.end()) {
      for (; it2 != l.lista.end(); ++it2) {
        resultado.insertar(*it2);
      }
    }
    else{
      for (; it != lista.end(); ++it) {
        resultado.insertar(*it);
      }
    }
  }
  return resultado;
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
