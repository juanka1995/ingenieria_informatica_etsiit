#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#ifdef _OPENMP
  #include <omp.h>
#else
   #define omp_get_thread_num() 0
#endif

int main(int argc, char const *argv[]) {

  int **matrizA, **matrizB, **resultado;
  int tam,j,k;
  time_t t;
  double inicio, tiempo;

  // Inicializamos la semilla del rand
  srand((unsigned) time(&t));

  if(argc < 2){
      fprintf(stderr, "\nFalta tamaño de filas/columnas\n");
      exit(-1);
  }

  tam = atoi(argv[1]);

  // Reservo memoria
  matrizA = (int **) malloc(tam*sizeof(int*));
  matrizB = (int **) malloc(tam*sizeof(int*));
  resultado = (int **) malloc(tam*sizeof(int*));

  // Reservo memoria para matriz
  for (int i = 0; i < tam; i++) {
    matrizA[i] = (int *) malloc(tam*sizeof(int));
    matrizB[i] = (int *) malloc(tam*sizeof(int));
    resultado[i] = (int *) malloc(tam*sizeof(int));
  }

  // Inicializar matrices
  for (int i = 0; i < tam; i++) {
    for (int j = 0; j < tam; j++) {
      matrizA[i][j] = rand() % 10;
      matrizB[i][j] = rand() % 10;
    }
  }

  inicio = omp_get_wtime();
  // Realizar calculo matrizA x matrizB
  #pragma omp parallel for private(j,k) schedule(runtime)
  for (int i = 0; i < tam; i++) {
    for (j = 0; j < tam; j++) {
      for (k = 0; k < tam; k++) {
        resultado[i][j] += matrizA[i][k] * matrizB[k][j];
      }
    }
  }
  tiempo = omp_get_wtime() - inicio;

  // Mostrar resultado
  printf("Tiempo empleado: %11.9f\n",tiempo);
  printf("Primer elemento resultado: %d\n",resultado[0][0]);
  printf("Ultimo elemento resultado: %d\n",resultado[tam-1][tam-1]);

  // Liberar memoria
  for (int i = 0; i < tam; i++) {
    free(matrizA[i]);
    free(matrizB[i]);
    free(resultado[i]);
  }

  free(matrizA);
  free(matrizB);
  free(resultado);

  return 0;
}
