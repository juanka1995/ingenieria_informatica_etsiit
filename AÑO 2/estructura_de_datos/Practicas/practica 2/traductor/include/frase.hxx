
Frase::Frase(string ff){
  unsigned int pc=ff.find(";");
  for (unsigned int i = 0; i < pc; i++) {
    origen.push_back(ff[i]);
  }
  string aux;
  while( pc < ff.length()){
    if(ff[pc] == ';'){
      destino.push_back(aux);
      aux.clear();
    }
    else{
      aux.push_back(ff[pc]);
    }
    pc++;
  }
  destino.push_back(aux);
}

vector<string> Frase::GetDestino() const{
  return destino;
}

string Frase::GetOrigen() const{
  return origen;
}

void Frase::InsertarDestino(const string &nuevo_dest){
  destino.push_back(nuevo_dest);
}

ostream& operator<< (ostream & os, const Frase &f){
  os << "Frase original: " << "\t" << f.origen << endl;
  os << "Traducciones: ";
  for (unsigned int i = 0; i < f.destino.size(); i++) {
    os << "\t\t" << f.destino[i] << endl << "\t";
  }
  os << endl << endl;
  return os;
}
