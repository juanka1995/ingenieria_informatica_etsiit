
elemento Pila::tope()const{
  return datos.pop_back();
}

bool Pila::vacia() const{
  return datos.isEmpty();
}

void Pila::poner(const int & v){
  elemento ele,tope;
  ele.dato = v;
  ele.max = v;
  ele.min = v;
  if(!datos.isEmpty()){
    tope = datos.pop_back();
    if(tope.max > v)
      ele.max = tope.max;
    if(tope.min < v)
      ele.min = tope.min;
  }
  datos.push_back(ele);
}

void Pila::quitar(){
  datos.deleteLast();
}

int Pila::size()const{
  return datos.getSize();
}
