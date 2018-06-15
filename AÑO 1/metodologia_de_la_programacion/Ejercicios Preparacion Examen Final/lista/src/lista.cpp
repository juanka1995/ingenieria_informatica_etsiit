#include <iostream>
#include "lista.h"
#include "assert.h"

using namespace std;

Lista::Lista(){
  cabecera=NULL;
}

Lista::Lista(int k){
  cabecera=new Celda;
  cabecera->dato=k;
  cabecera->siguiente=NULL;
}

void Lista::destruir(){
  if(cabecera!=NULL){
    Celda *p;
    while(cabecera!=NULL){
      p=cabecera->siguiente;
      delete cabecera;
      cabecera=p;
    }
  }
}

Lista::~Lista(){
  destruir();
}

Lista::Lista(const Lista &l){
  cabecera=NULL;
  if(l.cabecera!=NULL)
    copia(l);
}

void Lista::copia(const Lista &l){
  int longitud=l.getLongitud();
  for(int i=0;i<longitud;i++)
    this->insertarFin(l.getCelda(i));
}

Lista& Lista::operator=(const Lista &l){
  if(&l!=this){
    this->destruir();
    copia(l);
  }
  return *this;
}

Lista Lista::operator+(int k)const{
  Lista nueva;
  for(int i=0;i<this->getLongitud();i++)
    nueva.insertarFin(this->getCelda(i));
  nueva.insertarFin(k);
  return nueva;
}

Lista Lista::operator+(const Lista &l)const{
  Lista nueva;
  nueva.copia(*this);
  for(int i=0;i<l.getLongitud();i++)
    nueva.insertarFin(l.getCelda(i));
  return nueva;
}

ostream& operator<<(ostream &flujo,const Lista &l){
  if(l.cabecera!=NULL){
    for(int i=0;i<l.getLongitud();i++)
      flujo << "[" << i << "]: " << l.getCelda(i) << endl;
  }
  else
    flujo << "Vacia..." << endl;
  return flujo;
}

istream& operator>>(istream &flujo,Lista &l){
  if(l.cabecera!=NULL)
    l.destruir();
  int dato;
  flujo >> dato;
  while(!flujo.eof()){
    l.insertarFin(dato);
    flujo >> dato;
  }
  return flujo;
}

Lista* Lista::dividir(int t){
  Lista *l=NULL;
  int lon=getLongitud()/t;
  if(!getLongitud()%t==0)
    lon++;
  l=new Lista [lon];
  l[0].cabecera=cabecera;
  int aux=0,cont=1;
  Celda *p=cabecera,*p2;
  while(p->siguiente!=NULL){
    p2=p;
    p=p->siguiente;
    aux++;
    if(aux==t){
      l[cont++].cabecera=p;
      p2->siguiente=NULL;
      aux=0;
    }
  }
  cabecera=NULL;
  return l;
}


bool Lista::operator<(const Lista &l)const{
  return this->getLongitud()<l.getLongitud();
}

bool Lista::operator>(const Lista &l)const{
  return this->getLongitud()>l.getLongitud();
}

bool Lista::operator==(const Lista &l)const{
  bool iguales=false;
  if(this->getLongitud()==l.getLongitud()){
    iguales=true;
    for(int i=0;i<getLongitud();i++)
      if(getCelda(i)!=l.getCelda(i))
        iguales=false;
  }
  return iguales;
};


int Lista::getCelda(int k)const{
  assert(k>=0 && k<this->getLongitud());
  int aux=0;
  Celda *p=cabecera;
  while(p->siguiente!=NULL && aux<k){
    p=p->siguiente;
    aux++;
  }
  return p->dato;
};

void Lista::setCelda(int pos,int k){
  if(pos>=0 && pos<this->getLongitud()){
    Celda *p=cabecera;
    int aux=0;
    while(p->siguiente!=NULL && aux<pos){
      p=p->siguiente;
      aux++;
    }
    p->dato=k;
  }
}

int Lista::getLongitud()const{
  int k=0;
  if(cabecera!=NULL){
    Celda *p=cabecera;
    k++;
    while(p->siguiente!=NULL){
      p=p->siguiente;
      k++;
    }
  }
  return k;
}

void Lista::insertarFin(int k){
  if(cabecera!=NULL){
    Celda *p=cabecera;
    while(p->siguiente!=NULL)
      p=p->siguiente;
    p->siguiente=new Celda;
    p=p->siguiente;
    p->dato=k;
    p->siguiente=NULL;
  }
  else{
    cabecera=new Celda;
    cabecera->dato=k;
    cabecera->siguiente=NULL;
  }
}

void Lista::insertarIni(int k){
  if(cabecera!=NULL){
    Celda *p=new Celda;
    p->dato=k;
    p->siguiente=cabecera;
    cabecera=p;
  }
  else{
    this->insertarFin(k);
  }
}

void Lista::eliminarIni(){
  if(cabecera!=NULL){
    if(this->getLongitud()>1){
      Celda *p=cabecera->siguiente;
      delete cabecera;
      cabecera=p;
    }
    else{
      delete cabecera;
      cabecera=NULL;
    }
  }
}

void Lista::eliminarFin(){
  if(cabecera!=NULL){
    if(this->getLongitud()>1){
        Celda *p=cabecera,*p2;
        while(p->siguiente!=NULL){
          p2=p;
          p=p->siguiente;
        }
        delete p;
        p2->siguiente=NULL;
    }
    else{
      delete cabecera;
      cabecera=NULL;
    }
  }
}

void Lista::eliminarPos(int pos){
  if(pos>=0 && pos<this->getLongitud()){
    int aux=0;
    Celda *p=cabecera,*p2=p;
    while(p->siguiente!=NULL && aux<pos){
      p2=p;
      p=p->siguiente;
      aux++;
    }
    if(aux==0){
      eliminarIni();
    }
    else{
      p2->siguiente=p->siguiente;
      delete p;
    }
  }
}

void Lista::eliminar(){
  if(cabecera!=NULL){
    while(cabecera!=NULL)
      eliminarIni();
  }
}
