#include <string>
#include <fstream>
#include "lista.h"

#include <iostream>

using namespace std;

Lista::Lista(){
  cabecera=NULL;
}

Lista::Lista(string valor){
  cabecera=new Celda();
  cabecera->datos=valor;
  cabecera->siguiente=NULL;
}

Lista::Lista(const Lista &l){
  cabecera=NULL;
  copia(l);
}

void Lista::copia(const Lista &l){
  int longitud_l=l.longitud();
  for(int i=0;i<longitud_l;i++)
    this->insertar(l.getCelda(i));
}

Lista& Lista::operator=(const Lista &l){
  if(&l!=this){
    destruir();
    copia(l);
  }
  return *this;
}

Lista Lista::operator+(const string &dato)const{
  Lista aux(*this);
  aux.insertar(dato);
  return aux;
}

void Lista::destruir(){
  if(cabecera!=NULL){
    Celda *p=cabecera;
    while(p->siguiente!=NULL){
      cabecera=p->siguiente;
      delete p;
      p=cabecera;
    }
    delete cabecera;
    cabecera=NULL;
  }
}

Lista::~Lista(){
  destruir();
}

void Lista::insertar(string valor){
  Celda *p=cabecera; //Creo un puntero a celda y a punta hacia donde apunta la cabecera(primera celda)
  if(cabecera!=NULL){
    while(p->siguiente!=NULL) //Recorro las celdas hasta llegar a la ultima
      p=p->siguiente;
    p->siguiente=new Celda();
    p->siguiente->datos=valor; //Asigno a la ultima celta el valor pasado
    p->siguiente->siguiente=NULL; //Pongo el ultimo puntero de la ultima celda que apunta a la siguiente a NULL
  }
  else{ //En caso contrario creo la nueva celda y vuelco el contenido de valor
    cabecera=new Celda();
    cabecera->datos=valor;
    cabecera->siguiente=NULL;
  }

}

string Lista::getCelda(int pos) const{
  string resultado="";
  if(cabecera!=NULL){
    Celda *p=cabecera;
    int aux=0;
    while(p->siguiente!=NULL && aux<pos){
      p=p->siguiente;
      aux++;
    }
    if(aux==pos)
      resultado=p->datos;
    }
  return resultado;
}

int Lista::longitud() const{
  int total_c=0;
  if(cabecera!=NULL){
    Celda *p=cabecera;
    total_c=1;
    while(p->siguiente!=NULL){
      total_c++;
      p=p->siguiente;
    }
  }
  return total_c;
}

/**
 * @brief Construye una lista de celdas enlazadas a partir de la informacion
 * contenida en un fichero.
 * @param nombreFichero ruta del fichero de texto con el contenido de las datoss
 * a insertar en la lista
 * @retval true si ha tenido éxito en la lectura y el formato es el correcto
 * @retval false si se ha producido algún error en la lectura
 *
 * Lee desde disco los elementos almacenados en @a nombreFichero y los guarda
 * en la lista. La función debe asegurarse de que la estructura sigue un patron
 * determinado, y se ha de crear la lista con el numero de elementos que contenga.
 */
bool Lista::leerLista(const char nombrefichero[]){
	ifstream fin;
	fin.open(nombrefichero);
	if(!fin){
		return false;
	}else{
		string grises;
		int lineas;
		getline(fin,grises); //la primera linea se ignora
		fin >> lineas; //leo el numero de datos de grises
		getline(fin,grises); //leer salto de linea
		if (!fin){
			return false;
		}else {
			int i = 0;
			getline(fin,grises); //leer cadena de caracteres
			while ((i < lineas)&&(fin)){
				if (grises != ""){
					insertar(grises);
					i++;
				}
				getline(fin,grises); //leer cadena de caracteres
			}
		}
		fin.close();
	}
	return true;
}
