#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 1000

int matrizA[TAM][TAM], matrizB[TAM][TAM], resultado[TAM][TAM];

int main(int argc, char const *argv[]) {

  struct timespec cgt1,cgt2;
  double ncgt;

  // Inicializar matrices
  for (int i = 0; i < TAM; i++) {
    for (int j = 0; j < TAM; j++) {
      matrizA[i][j] = (i+j) * 2;
      matrizB[i][j] = (i+j) * 4;
    }
  }

  clock_gettime(CLOCK_REALTIME,&cgt1);

  // Realizar calculo matrizA x matrizB
  for (int i = 0; i < TAM; i++) {
    for (int j = 0; j < TAM; j++) {
      for (int k = 0; k < TAM; k++) {
        resultado[i][j] += matrizA[i][k] * matrizB[k][j];
      }
    }
  }

  clock_gettime(CLOCK_REALTIME,&cgt2);

  // Mostrar resultado
  printf("Primer elemento resultado: %u\n",resultado[0][0]);
  printf("Ultimo elemento resultado: %u\n",resultado[TAM-1][TAM-1]);

  ncgt=(double) (cgt2.tv_sec-cgt1.tv_sec) + (double) ((cgt2.tv_nsec-cgt1.tv_nsec)/(1.e+9));

  printf("Tiempo:\t%8.6f\n",ncgt);

  return 0;
}
