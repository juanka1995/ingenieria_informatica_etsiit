
int ConjuntoFrases::GetPosicion(const string &ff){
  //Busqueda binaria
  int primero = 0,
      ultimo = vm.size()-1,
      medio;
  while (primero <= ultimo) {
    medio = (primero + ultimo) / 2;
    if(vm[medio].GetOrigen() == ff)
      return medio;
    else if (ff < vm[medio].GetOrigen())
      ultimo = medio - 1;
    else
      primero = medio + 1;
  }
  return -1;
}

bool ConjuntoFrases::Esta(string &ff){
  toLower(ff);
  return GetPosicion(ff) >= 0;
}

void ConjuntoFrases::Insertar(const Frase &ff){
    if (vm.empty()) {
      vm.push_back(ff);
    }
    else if(vm[vm.size()-1].GetOrigen() < ff.GetOrigen()){
      vm.push_back(ff);
    }
    else{
      vector<Frase>::iterator it;
      bool insertado = false;
      for(it = vm.begin(); it != vm.end() && !insertado; ++it){
        if(ff.GetOrigen().compare((*it).GetOrigen()) != 0 ){
          if(ff.GetOrigen().compare((*it).GetOrigen()) < 0 ){
            insertado = true;
            vm.insert(it,ff);
          }
        }
        else{
          bool existe_dest;
          for (unsigned int i = 0; i < ff.GetDestino().size(); i++) {
            existe_dest = false;
            for (unsigned int j = 0; j < (*it).GetDestino().size() && !existe_dest; j++) {
              if(ff.GetDestino().at(i) == (*it).GetDestino().at(j))
                existe_dest = true;
            }
            if(!existe_dest)
              (*it).InsertarDestino(ff.GetDestino().at(i));
          }
          insertado = true;
        }
      }
    }
}

Frase ConjuntoFrases::GetTraducciones(const string &ff){
  return vm[GetPosicion(ff)];
}

int ConjuntoFrases::Size()const{
  return vm.size();
}

ConjuntoFrases ConjuntoFrases::Contenga(string &c){
  ConjuntoFrases contenido;
  toLower(c);
  for (unsigned int i = 0; i < vm.size(); i++) {
    if(vm[i].GetOrigen().find(c) < vm[i].GetOrigen().size() && vm[i].GetOrigen().find(c) >= 0)
      contenido.Insertar(vm[i]);
  }
  return contenido;
}

void ConjuntoFrases::toLower(string &ff){
  for (unsigned int i = 0; i < ff.size(); i++)
    ff[i] = tolower(ff[i]);
}

istream& operator>>(istream &o,ConjuntoFrases &cf){
  string aux;
  getline(o,aux);
  while(aux.size() != 0){
    cf.toLower(aux);
    Frase ff(aux);
    cf.Insertar(ff);
    getline(o,aux);
  }
  return o;
}

ostream& operator<< (ostream & os, const ConjuntoFrases &cf){
  for (unsigned int i = 0; i < cf.vm.size() ; i++) {
    os << cf.vm[i];
  }
  return os;
}
