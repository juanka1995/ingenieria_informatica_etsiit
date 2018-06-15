
elemento Pila::tope()const{
  return datos.frente();
}

bool Pila::vacia() const{
  return datos.vacia();
}

void Pila::poner(const int & v){
  elemento ele,tope;
  ele.dato = v;
  ele.max = v;
  ele.min = v;
  if(!datos.vacia()){
    tope = datos.frente();
    if(tope.max > v)
      ele.max = tope.max;
    if(tope.min < v)
      ele.min = tope.min;
  }
  datos.poner(ele);
}

void Pila::quitar(){
  datos.quitar();
}

int Pila::size()const{
  return datos.num_elementos();
}
