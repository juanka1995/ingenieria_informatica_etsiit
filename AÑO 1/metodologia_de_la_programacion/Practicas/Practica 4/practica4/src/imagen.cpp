#include <iostream>
#include <cstring>
#include "imagen.h"
#include "pgm.h"
#include "byte.h"

using namespace std;
Imagen::Imagen(){
  nfilas=ncolumnas=0;
}

Imagen::Imagen(int filas, int columnas){
  nfilas=filas;
  ncolumnas=columnas;
  for(int i=0;i<nfilas;i++){
    for(int j=0;j<ncolumnas;j++){
      datos[i*ncolumnas+j]=0x0;
    }
  }
}

void Imagen::crear(int filas, int columnas){
  nfilas=filas;
  ncolumnas=columnas;
  for(int i=0;i<nfilas;i++){
    for(int j=0;j<ncolumnas;j++){
      datos[i*ncolumnas+j]=0x0;
    }
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
  if(tipo!=IMG_DESCONOCIDO && nfilas*ncolumnas<MAXPIXELS){
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
  if((nfilas*ncolumnas+nfilas+1)<maxlong){ //nfilas * ncolumnas + nfilas(uno por cada \n) + 1 (por \0)
    for(int i=0;i<nfilas;i++){
      for(int j=0;j<ncolumnas;j++){
        arteASCII[pos++]=grises[datos[i*ncolumnas+j]*cardinal/256];
      }
      arteASCII[pos++]='\n';
    }
    return 1;
  }
  else
    return 0;
}
