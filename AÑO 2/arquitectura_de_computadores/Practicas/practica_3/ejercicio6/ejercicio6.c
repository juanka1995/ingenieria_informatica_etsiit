#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[]) {

  int **matriz;
  int *vector, *resultado;
  int tam, suma_aux;
  time_t t;

  // Inicializamos la semilla del rand
  srand((unsigned) time(&t));

  if(argc < 2){
      fprintf(stderr, "\nFalta tamaño de filas/columnas\n");
      exit(-1);
  }

  tam = atoi(argv[1]);

  // Reservo memoria
  vector = (int *) malloc(tam*sizeof(int));
  resultado = (int *) malloc(tam*sizeof(int));
  matriz = (int **) malloc(tam*sizeof(int*));

  // Inicializar vector y reservar memoria para matriz
  for (int i = 0; i < tam; i++) {
    matriz[i] = (int *) malloc(tam*sizeof(int));
  }

  // Inicializar matriz a 0
  for (int i = 0; i < tam; i++) {
    for (int j = 0; j < tam; j++) {
      matriz[i][j] = 0;
    }
  }

  // Inicializar valores por encima de diagonal principal de la matriz
  // e inicializar valores del vector
  for (int i = 0; i < tam; i++) {
    vector[i] = rand() % 20;
    for (int j = 0 + i; j < tam; j++) {
      matriz[i][j] = rand() % 20;
    }
  }

  // Realizar calculo
  for (int i = 0; i < tam; i++) {
    suma_aux = 0;
    for (int j = 0 + i; j < tam; j++) {
      suma_aux += vector[j] * matriz[i][j];
    }
    resultado[i] = suma_aux;
  }

  // Mostrar resultado
  printf("Primer elemento resultado: %d\n",resultado[0]);
  printf("Ultimo elemento resultado: %d\n",resultado[tam-1]);

  //Liberar memoria
  for (int i = 0; i < tam; i++) {
    free(matriz[i]);
  }

  free(matriz);
  free(vector);
  free(resultado);

  return 0;
}
