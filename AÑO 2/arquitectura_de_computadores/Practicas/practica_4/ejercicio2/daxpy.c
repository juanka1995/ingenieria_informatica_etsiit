#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 100000000

int vectorA[TAM], vectorB[TAM];

int main(int argc, char const *argv[]) {

  int a = 5;
  struct timespec cgt1,cgt2;
  double ncgt;

  // Inicializar vectores
  for (int i = 0; i < TAM; i++) {
    vectorA[i] = (i+1) * 2;
    vectorB[i] = (i+2) * 4;
  }

  clock_gettime(CLOCK_REALTIME,&cgt1);

  // Benchmark
  for (int i = 0; i < TAM; i++) {
    vectorA[i] = vectorB[i] * a + vectorA[i];
  }

  clock_gettime(CLOCK_REALTIME,&cgt2);

  // Mostrar resultado
  printf("Primer elemento resultado: %u\n",vectorA[0]);
  printf("Ultimo elemento resultado: %u\n",vectorA[TAM-1]);

  ncgt=(double) (cgt2.tv_sec-cgt1.tv_sec) + (double) ((cgt2.tv_nsec-cgt1.tv_nsec)/(1.e+9));

  printf("Tiempo:\t%8.6f\n",ncgt);

  return 0;
}
