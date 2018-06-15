#include <cstring>
#include <string>
#include<fstream>
#include "imagen.h"
#include "pgm.h"
#include "byte.h"
#include "lista.h"

using namespace std;
Imagen::Imagen(){
  nfilas=ncolumnas=0;
  datos=NULL;
}

Imagen::Imagen(int filas, int columnas){
  datos=NULL;
  crear(filas,columnas);
}

void Imagen::destruir(){
  if(datos!=NULL){
    delete [] datos;
    datos=NULL;
  }
  nfilas=ncolumnas=0;
}

void Imagen::crear(int filas, int columnas){
  if(datos!=0)
    destruir();
  nfilas=filas;
  ncolumnas=columnas;
  datos=new byte[nfilas*ncolumnas];
  for(int i=0;i<nfilas*ncolumnas;i++){
      datos[i]=0x0;
  }
}

int Imagen::filas(){
  return nfilas;
}

int Imagen::columnas(){
  return ncolumnas;
}

void Imagen::set(int y, int x, byte v){
  datos[y*ncolumnas+x]=v;
}

byte Imagen::get(int y, int x){
  return datos[y*ncolumnas+x];
}

void Imagen::setPos(int i, byte v){
  datos[i]=v;
}

byte Imagen::getPos(int i){
  return datos[i];
}

bool Imagen::leerImagen(const char nombreFichero[]){
  bool exito=false;
  TipoImagen tipo=infoPGM(nombreFichero,nfilas,ncolumnas);
  if(datos==0)
    crear(nfilas,ncolumnas);
  if(tipo!=IMG_DESCONOCIDO){
    if(tipo==IMG_PGM_BINARIO)
      exito=leerPGMBinario(nombreFichero,datos,nfilas,ncolumnas);
    else
      exito=leerPGMTexto(nombreFichero,datos,nfilas,ncolumnas);
  }
  return exito;
}

bool Imagen::escribirImagen(const char nombreFichero[], bool esBinario){
  bool exito=false;
  if(esBinario)
    exito=escribirPGMBinario(nombreFichero,datos,nfilas,ncolumnas);
  else
    exito=escribirPGMTexto(nombreFichero,datos,nfilas,ncolumnas);
  return exito;
}

Imagen Imagen::plano(int k){
  Imagen devolver(nfilas,ncolumnas);
  for(int i=0;i<nfilas*ncolumnas;i++){
    if(getbit(datos[i],k))
      devolver.datos[i]=0x80;//asigna el valor 1000 0000 al unsigned char
    else
      devolver.datos[i]=0x0; //asigna el valor 0000 0000 al unsigned char
  }
  return devolver;
}

bool Imagen::aArteASCII(const char grises[], char arteASCII[], int maxlong){
  int cardinal=strlen(grises),pos=0;
  if((nfilas*ncolumnas)+nfilas+1<=maxlong){ //nfilas * ncolumnas + nfilas(uno por cada \n) + 1 (por \0)
    for(int i=0;i<nfilas;i++){
      for(int j=0;j<ncolumnas;j++){
        arteASCII[pos++]=grises[datos[i*ncolumnas+j]*cardinal/256];
      }
      arteASCII[pos++]='\n';
    }
    arteASCII[pos]='\0';
    return true;
  }
  else
    return false;
}

bool Imagen::listaAArteASCII(const Lista celdas){
  const int MAX_ASCII=(nfilas*ncolumnas)+nfilas+1; //nfilas * ncolumnas + nfilas(uno por cada \n) + 1 (por \0)
  char *p=new char[MAX_ASCII];
  string salida="ascii0.txt"; //Nombre generico salida
  char n_salida[salida.length()];
  strcpy(n_salida,salida.c_str()); //Introduczco en nombre de salida en un vector de char
  ofstream fsalida; //Creo el fichero de salida

  for(int i=0;i<celdas.longitud();i++){
    string cadena=celdas.getCelda(i); //Guardo el contenido de la celda(i) en un string
    char c_cadena[cadena.length()]; //Creo un vector de char de tamaño cadena.length()
    strcpy(c_cadena,cadena.c_str()); //Paso el contenido de cadena a el vector de char c_cadena
    if(aArteASCII(c_cadena,p,MAX_ASCII)){
      n_salida[strlen(n_salida)-5]='1'+i; //Cambio el nombre de salida del fichero
      fsalida.open(n_salida);
      fsalida << p;
      fsalida.close();
    }
    else
      return false;
  }
  delete [] p;
  return true;
}
