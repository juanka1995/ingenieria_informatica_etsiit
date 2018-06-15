#include "ArbolGeneral.h"
#include "refranes.h"

Refranes::Refranes(){
  len_prefijo = 3;
  n_ref = 0;
  caracteres_totales = 0;
}

Refranes::Refranes(int lpre){
  len_prefijo = lpre;
  n_ref = 0;
  caracteres_totales = 0;
}

int Refranes::size()const{
  return n_ref;
}

void Refranes::Insertar(const string & refran){
    bool esta, primero;
    int i;
    ArbolGeneral<string>::Nodo p_ant = ab.raiz();
    ArbolGeneral<string>::Nodo p_pos = ab.hijomasizquierda(p_ant); 
    //Buscamos en los n niveles del prefijo
    for(i=0;i<len_prefijo+1;i++){
        primero = true;
        string s_refran, s_etiqueta;
        if(i==len_prefijo){
            s_refran = refran.substr(len_prefijo);
        }else{
            s_refran = refran.substr(i,1);
        }
        //cout << 2 << endl;
        //Buscamos el nodo con la etiqueta
        esta = false;
        while(p_pos){
            s_etiqueta = ab.etiqueta(p_pos);
            //cout << 4 << endl;
            if(s_etiqueta == s_refran){
                esta = true;
                break;
            }
            else if(s_etiqueta > s_refran){
                break;
            }

            primero = false;
            p_ant = p_pos;
            p_pos = ab.hermanoderecha(p_pos);
        }

        //Si no está lo creamos
        if(!esta){
            ArbolGeneral<string> ab_n(s_refran);               
            //Si hay que insertarlo en la primera posición, 
            //es el hijo a la izquierda de su padre
            if(primero){
                ab.insertar_hijomasizquierda(p_ant,ab_n);
                p_ant = ab.hijomasizquierda(p_ant);
            }
            //Si hay que insertarlo en cualquier otra, es el 
            //hermano a la derecha de otro
            else{
                ab.insertar_hermanoderecha(p_ant,ab_n);
                p_ant = ab.hermanoderecha(p_ant);
            }            
            //Incrementamos si no estaba
            if(i==len_prefijo){
                n_ref++;
                caracteres_totales+=refran.length();
            }
        }
        else{
            p_ant = p_pos;
        }

        p_pos = ab.hijomasizquierda(p_ant);
    }
}

void Refranes::BorrarRefran(const string &refran){
    bool esta, primero;
    int i;
    pair<bool,ArbolGeneral<string>::Nodo> padres[len_prefijo+1];
    ArbolGeneral<string>::Nodo p_ant;
    ArbolGeneral<string>::Nodo p_pos = ab.raiz(); 
    //Buscamos en los n niveles del prefijo
    for(i=0;i<len_prefijo+1;i++){
        primero = true;
        string s_refran, s_etiqueta;

        p_ant = p_pos;
        p_pos = ab.hijomasizquierda(p_ant);

        if(i==len_prefijo){
            s_refran = refran.substr(len_prefijo);
        }else{
            s_refran = refran.substr(i,1);
        }

        //Buscamos el nodo con la etiqueta
        esta = false;
        while(!esta){
            s_etiqueta = ab.etiqueta(p_pos);
            
            if(s_etiqueta == s_refran){
                esta = true;
                padres[i]=pair<bool,ArbolGeneral<string>::Nodo>(primero,p_ant);
            }else{
                primero = false;
                p_ant = p_pos;
                p_pos = ab.hermanoderecha(p_pos);
            }
        }
    }

    bool hermder, borrado=false;
    ArbolGeneral<string> ab_aux;
    for(i=len_prefijo; !borrado && i>=0;i--){
        hermder = !ab.Nulo(ab.hermanoderecha(p_pos));
        primero = padres[i].first;
        if(primero && hermder)
            ab.podar_hijomasizquierda(padres[i].second,ab_aux);
        else if(hermder)
            ab.podar_hermanoderecha(padres[i].second,ab_aux);
        else if(i==0)
            ab.podar_hijomasizquierda(padres[i].second, ab_aux);
        else
            p_pos = ab.padre(p_pos);
    }

    n_ref--;
    caracteres_totales-=refran.length();
}

pair<bool,Refranes::iterator> Refranes::Esta(const string &refran){
  bool existe_frase = false;
  Refranes::iterator it = begin();
  while(!existe_frase && it != end() && *it <= refran){
    if (refran == *it) {
      existe_frase = true;
    }
    else{
      ++it;
    }
  }
  return pair<bool,Refranes::iterator>(existe_frase,it);
}

void Refranes::clear(){
  ab.clear();
}

istream & operator>>(istream &is, Refranes &R){
  string refran;
  while (getline(is,refran)) {
    string caux; 
    for (unsigned i=0;i<refran.size();++i)
        caux.push_back(tolower(refran[i]));
    R.Insertar(caux);
  }
  return is;
}

ostream & operator<<(ostream &is,const Refranes &R){
  Refranes::const_iterator it_c;
  for (it_c = R.begin() ; it_c != R.end(); ++it_c) {
    is << (*it_c).c_str() << endl;
  }
  //is << R.ab << endl;
  return is;
}

int Refranes::Caracteres_Refranes()const{
  return caracteres_totales;
}

int Refranes::Caracteres_Almacenados(){
  return caracteres_totales - (n_ref*len_prefijo) + (Numero_Nodos()-n_ref);
}

int Refranes::Numero_Nodos()const{
  int n_nodos = 0;
  ArbolGeneral<string>::const_iter_preorden it_c = ab.begin();
  for ( ; it_c != ab.end(); ++it_c)
      n_nodos++;
  return n_nodos;
}

// Class iterator

string & Refranes::iterator::operator *(){
  return cad;
}

bool Refranes::iterator::operator==(const Refranes::iterator &i)const{
  return (it == i.it);
}

bool Refranes::iterator::operator!=(const Refranes::iterator &i)const{
  return !(it == i.it);
}

Refranes::iterator & Refranes::iterator::operator++(){
  ArbolGeneral<string>::iter_preorden it_ant;
  do{
    it_ant = it;
    ++it;
    if(it.getlevel() == -1){
      cad = "";
      break;
    }
    if (it_ant.getlevel() >= it.getlevel()) {
      cad = cad.substr(0,it.getlevel());
      cad += *it;
    }
    else{
      cad += *it;
    }
  }while (!it.Hoja()) ;
  return *this;
}

Refranes::iterator Refranes::begin(){
  Refranes::iterator it_ref;
    it_ref.it = ab.begin();
  if (it_ref.it != ab.end()) {
    do{
      ++(it_ref.it);
      it_ref.cad += *(it_ref.it);
    }while(!it_ref.it.Hoja());
    return it_ref;
  }
  else{
    return end();
  }
}

Refranes::iterator Refranes::end(){
  Refranes::iterator it_ref;
  it_ref.it = ab.end();
  return it_ref;
}

// Class const_iterator

string & Refranes::const_iterator::operator *(){
  return cad;
}

bool Refranes::const_iterator::operator==(const Refranes::const_iterator &i)const{
  return (it == i.it);
}

bool Refranes::const_iterator::operator!=(const Refranes::const_iterator &i)const{
  return !(it == i.it);
}

Refranes::const_iterator & Refranes::const_iterator::operator++(){
    ArbolGeneral<string>::const_iter_preorden it_ant;
  do{
    it_ant = it;
    ++it;
    if(it.getlevel() == -1){
      cad = "";
      break;
    }
    if (it_ant.getlevel() >= it.getlevel()) {
      cad = cad.substr(0,it.getlevel());
      cad += *it;
    }
    else{
      cad += *it;
    }
  }while (!it.Hoja()) ;
  return *this;
}

Refranes::const_iterator Refranes::begin() const{
  Refranes::const_iterator it_ref_c;
    it_ref_c.it = ab.begin();
  if (it_ref_c.it != ab.end()) {
    do{
      ++(it_ref_c.it);
      it_ref_c.cad += *(it_ref_c.it);
    }while(!it_ref_c.it.Hoja());
    return it_ref_c;
  }
  else{
    return end();
  }
}

Refranes::const_iterator Refranes::end() const{
  Refranes::const_iterator it_ref_c;
  it_ref_c.it = ab.end();
  return it_ref_c;
}