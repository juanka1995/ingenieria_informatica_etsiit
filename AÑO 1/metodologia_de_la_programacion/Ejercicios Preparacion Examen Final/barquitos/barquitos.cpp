#include <iostream>
#include "barquitos.h"

using namespace std;

Barquitos::Barquitos(){
  nfilas=0;
  ncolumnas=0;
  tablero=NULL;
}

Barquitos::Barquitos(int filas,int columnas){
  nfilas=filas;
  ncolumnas=columnas;
  tablero=new int *[nfilas];
  for(int i=0;i<nfilas;i++)
    tablero[i]=new int[ncolumnas];
  for(int i=0;i<nfilas;i++)
    for(int j=0;j<ncolumnas;j++)
      tablero[i][j]=9;
}

void Barquitos::destruir(){
  if(tablero!=NULL){
    for(int i=0;i<nfilas;i++)
      delete [] tablero[i];
    delete [] tablero;
    tablero=NULL;
  }
  nfilas=0;
  ncolumnas=0;
}

void Barquitos::copia(const Barquitos &b){
  nfilas=b.nfilas;
  ncolumnas=b.ncolumnas;
  tablero=new int *[nfilas];
  for(int i=0;i<nfilas;i++)
    tablero[i]=new int [ncolumnas];
  for(int i=0;i<nfilas;i++)
    for(int j=0;j<ncolumnas;j++)
      tablero[i][j]=b.tablero[i][j];
}

Barquitos::Barquitos(const Barquitos &b){
  nfilas=0;
  ncolumnas=0;
  tablero=NULL;
  if(b.tablero!=NULL)
    copia(b);
}

Barquitos& Barquitos::operator=(const Barquitos &b){
  if(&b!=this){
    destruir();
    copia(b);
  }
  return *this;
}

bool Barquitos::esPosible(char fila,int columna,int tam,char direc){
  bool posible=false;
  int fil=fila-'A';
  if(fil>=0 && fil<nfilas && columna>=0 && columna<ncolumnas && tam>=0 && tam<nfilas && tam<ncolumnas && direc=='H' || direc=='V'){
    if(direc=='H'){
      if(tablero[fil][columna]==9 && columna+tam-1<ncolumnas){
        bool coge=true;
        for(int i=0;i<tam;i++)
          if(tablero[fil][columna+i]!=9)
            coge=false;

        if(coge && columna-1>=0){
          if(tablero[fil][columna-1]!=9)
            coge=false;
          if(coge && fila-1>=0){

            for(int i=)
          }
          if(fila+1<nfilas){

          }
          if(tablero[fil][columna-1]!=9)
        }
        else{

        }


        if(coge && columna-1>=0 && tablero[fil][columna-1]==9)
        if(coge && fil-1>=0){
          if(columna-1>=0 && tablero[fil-1][columna-1]==9 && tablero[fil-1][columna+tam]==9){
            for(int i=0;i<tam;i++)
              if(tablero[fil-1][columna+i]!=9)
                coge=false;
          }
        }
        if(coge && fil+1<nfilas){
          if(columna-1>=0 && tablero[fil+1][columna-1]==9 && tablero[fil+1][columna+tam]==9){
            for(int i=0;i<tam;i++)
              if(tablero[fil+1][columna+i]!=9)
                coge=false;
          }
        }
        posible=true;
      }
    }
  }
  return posible;
}
