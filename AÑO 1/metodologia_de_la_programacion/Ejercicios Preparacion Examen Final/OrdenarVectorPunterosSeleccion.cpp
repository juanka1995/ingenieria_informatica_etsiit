#include <iostream>
#include <cstring>

using namespace std;

void OrdenarPorSeleccion(const int *v[],int utiles){
  int posmin;
  const int *aux;

  for (int i = 0; i < utiles-1; i++) {
    posmin=i;
    for (int j = i+1; j < utiles; j++)
      if(*v[j]<*v[posmin])
        posmin=j;

      aux=v[i];
      v[i]=v[posmin];
      v[posmin]=aux;
  }
}

int main(){
  const int TAM_ARRAY=5;
  const int *arrayPunt[TAM_ARRAY];
  const int arrayInt[TAM_ARRAY]={5,7,3,4,4};
  int utiles=5;

  for (int i = 0; i < utiles; i++) {
    arrayPunt[i]=&arrayInt[i];
  }

  //Muestra del array de punteros sin ordenar
  for (int i = 0; i < utiles; i++) {
    cout << *arrayPunt[i] << " ";
  }
  cout << endl;

  //Ordenamos por seleccion el vector de punteros
  OrdenarPorSeleccion(arrayPunt,utiles);

  //Muestra del array de punteros ordenado
  for (int i = 0; i < utiles; i++) {
    cout << *arrayPunt[i] << " ";
  }
  cout << endl;

  //Muestra del array de enteros
  //Como podemos apreciar no se ha modificado el orden ya que solo modificamos el orden del de punteros
  for (int i = 0; i < utiles; i++) {
    cout << arrayInt[i] << " ";
  }
  cout << endl;
}
