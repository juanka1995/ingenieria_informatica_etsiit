#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM_VECTOR 5000
#define NUM_ITER 40000

struct{
  int a;
  int b;
} s[TAM_VECTOR];

int R[NUM_ITER];

int main(int argc, char const *argv[]) {

  int X1, X2, ii;
  struct timespec cgt1,cgt2;
  double ncgt;

  for (int i = 0; i < TAM_VECTOR; i++) {
    s[i].a = i*2;
    s[i].b = i*4;
  }

  clock_gettime(CLOCK_REALTIME,&cgt1);

  for (ii = 0; ii < NUM_ITER; ii++) {
    X1 = 0; X2 = 0;
    for (int i = 0; i < TAM_VECTOR; i++) {
      X1 += 2*s[i].a+ii;
    }
    for (int i = 0; i < TAM_VECTOR; i++) {
      X2 += 3*s[i].b-ii;
    }
    R[ii] = (X1 < X2) ? X1 : X2;
  }

  clock_gettime(CLOCK_REALTIME,&cgt2);

  ncgt=(double) (cgt2.tv_sec-cgt1.tv_sec) + (double) ((cgt2.tv_nsec-cgt1.tv_nsec)/(1.e+9));

  printf("R[0]: %u\nR[39999]: %u\n\nTiempo:\t%8.6f\n",R[0],R[39999],ncgt);

  return 0;
}
