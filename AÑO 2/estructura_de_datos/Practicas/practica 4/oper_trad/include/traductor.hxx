
Traductor::const_iterator Traductor::begin() const{
  Traductor::const_iterator ite;
  ite.it = traducciones.begin();
  return ite;
}

Traductor::const_iterator Traductor::end() const{
  Traductor::const_iterator ite;
  ite.it = traducciones.end();
  return ite;
}

Traductor::const_iterator Traductor::find(const string & clave) const{
  Traductor::const_iterator ite;
  ite.it = traducciones.end();
  bool encontrado = false;
  map<string,Frase,comparador>::const_iterator it2;
  for (it2 = traducciones.begin(); it2 != traducciones.end() && !encontrado; ++it2) {
    if ((*it2).first == clave) {
      encontrado = true;
      ite.it = it2;
    }
  }
  return ite;
}

vector<string> Traductor::GetTraducciones(const string &ff){
  map<string,Frase>::const_iterator it = traducciones.find(ff);
  Frase::const_iterator it2;
  vector<string> resultado;
  for (it2 = (*it).second.begin(); it2 != (*it).second.end(); ++it2) {
    resultado.push_back((*it2));
  }
  return resultado;
}

istream& operator>>(istream &o,Traductor &tr){
  string aux;
  getline(o,aux);
  while(aux.size() != 0){
    tr.toLower(aux);
    Frase ff(aux);
    tr.InsertarFrase(ff);
    getline(o,aux);
  }
  return o;
}

void Traductor::toLower(string &ff){
  for (unsigned int i = 0; i < ff.size(); i++)
    ff[i] = tolower(ff[i]);
}

void Traductor::InsertarFrase(const Frase &ff){
    map<string,Frase>::iterator it = traducciones.find(ff.GetOrigen());
  if (it != traducciones.end()) {
    Frase::const_iterator itf1,itf2;
    bool ya_existe;
    for ( itf1 = ff.begin(); itf1 != ff.end(); ++itf1) {
      ya_existe = false;
      for (itf2 = (*it).second.begin(); itf2 != (*it).second.end() && !ya_existe; ++itf2) {
        if((*itf1) == (*itf2))
          ya_existe = true;
      }
      if(!ya_existe)
        (*it).second.InsertarDestino((*itf1));
    }
  }
  else{
    traducciones[ff.GetOrigen()] = ff;
  }
}

ostream& operator<< (ostream & os, const Traductor &tr){
  map<string,Frase>::const_iterator it;
  for (it = tr.traducciones.begin(); it != tr.traducciones.end() ; ++it) {
    os << (*it).second;
  }
  return os;
}
