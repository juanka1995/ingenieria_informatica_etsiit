#include <iostream>
#include "frecuencias.h"

using namespace std;

Frecuencias::Frecuencias(){
  parejas=NULL;
  npares=0;
}

void Frecuencias::destruir(){
  delete [] parejas;
  parejas=NULL;
  npares=0;
}

Frecuencias::~Frecuencias(){
  destruir();
}

void Frecuencias::copiar(const Frecuencias &f){
  npares=f.npares;
  parejas=new Pareja [npares];
  for(int i=0;i<npares;i++)
    parejas[i]=f.parejas[i];
}

int Frecuencias::Getnpares()const{
  return npares;
}

int Frecuencias::getDato(const int pos){
  return parejas[pos].dato;
}


Frecuencias::Frecuencias(const Frecuencias &f){
  parejas=NULL;
  npares=0;
  copiar(f);
}

Frecuencias& Frecuencias::operator=(const Frecuencias &f){
  if(&f!=this){
    if(parejas!=NULL)
      destruir();
    copiar(f);
  }
  return *this;
}

void Frecuencias::Add(const int k){
  if(parejas!=NULL){
    bool existe=false;
    for(int i=0;i<npares && !existe;i++)
      if(parejas[i].dato==k)
        existe=true;
    if(existe){
      for(int i=0;i<npares;i++)
        if(parejas[i].dato==k)
          parejas[i].nveces++;
    }
    else{
      int npares_aux=npares+1;
      Pareja *aux=new Pareja[npares_aux];
      int i=0;
      while(parejas[i].dato<k && i<npares){
        aux[i].dato=parejas[i].dato;
        aux[i].nveces=parejas[i].nveces;
        i++;
      }
      aux[i].dato=k;
      aux[i].nveces=1;
      for(int j=i;j<npares;j++){
        aux[j+1].dato=parejas[j].dato;
        aux[j+1].nveces=parejas[j].nveces;
      }
      delete [] parejas;
      parejas=aux;
      npares=npares_aux;
      aux=NULL;
    }
  }
  else{
    npares=1;
    parejas=new Pareja[npares];
    parejas[0].dato=k;
    parejas[0].nveces=1;
  }
}

Frecuencias& Frecuencias::operator+=(const int k){
  Add(k);
  return *this;
}


ostream& operator<<(ostream &flujo,const Frecuencias &f){
  if(f.parejas!=NULL){
    for(int i=0;i<f.npares;i++)
      flujo << "Pareja ["<< i << "]: " << f.parejas[i].dato << endl;
  }
  else
    flujo << "Vacio..." << endl;
}

int Frecuencias::Repeticiones(int d){
  int k=0;
  if(parejas!=NULL){
    bool encontrado=false;
    for(int i=0;i<npares && !encontrado;i++){
      if(parejas[i].dato==d){
        k=parejas[i].nveces;
        encontrado=true;
      }
    }
  }
  return k;
}
