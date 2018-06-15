
elemento Pila::tope()const{
  return datos.getLast();
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
    tope = datos.getLast();
    if(tope.max > v)
      ele.max = tope.max;
    if(tope.min < v)
      ele.min = tope.min;
  }
  datos.addLast(ele);
}

void Pila::quitar(){
  datos.deleteLast();
}

int Pila::size()const{
  return datos.getSize();
}
