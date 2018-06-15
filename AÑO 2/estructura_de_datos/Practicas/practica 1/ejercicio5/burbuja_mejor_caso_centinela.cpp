#include <iostream>
#include <ctime> // Recursos para medir tiempos
#include <cstdlib> // Para generación de números pseudoaleatorios

using namespace std;

void ordenar(int *v, int n) {
  for (int i=0; i<n-1; i++)
    for (int j=0; j<n-i-1; j++)
      if (v[j]>v[j+1]) {
        int aux = v[j];
        v[j] = v[j+1];
        v[j+1] = aux;
      }
}

void sintaxis() {
  cerr << "Sintaxis:" << endl;
  cerr << " TAM: Tamaño del vector (>0)" << endl;
  cerr << "Genera un vector de TAM números ordenado en [0,TAM]" << endl;
  exit(EXIT_FAILURE);
  }

int main(int argc, char * argv[]) {
  if (argc!=2) // Lectura de parámetros
    sintaxis();
  int tam=atoi(argv[1]); // Tamaño del vector
  if (tam<=0)
    sintaxis(); // Generación del vector aleatorio
  int *v=new int[tam]; // Reserva de memoria

  // ESTE ES EL MEJOR CASO EN EL QUE LOS ELEMENTOS DEL VECTOR YA ESTAN
  // ORDENADOS ANTES DE LLAMAR AL METODO BURBUJA

  for (int i=0; i<tam; i++) // Recorrer vector
    v[i] = i; // Añade elementos al vector desde 0 a tam-1

  clock_t tini; // Anotamos el tiempo de inicio
  tini=clock();

  ordenar(v,tam); // Ordenamos el vector mediante el metodo burbuja

  clock_t tfin; // Anotamos el tiempo de finalización
  tfin=clock();

  // Mostramos resultados (Tamaño del vector y tiempo de ejecución en seg.)
  cout << endl << tam << "\t" << (tfin-tini)/(double)CLOCKS_PER_SEC << endl;

  delete [] v; // Liberamos memoria dinámica
}
