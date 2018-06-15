/*
Nombre: Juan Carlos Ruiz García
Grupo: C2
Año: 2016

Enunciado: Implementa una modificación sobre el anterior programa en la que el proceso padre espera primero a
los hijos creados en orden impar (1o,3o,5o) y después a los hijos pares (2o y 4o).

*/

#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdio.h>
#include<errno.h>
#include <stdlib.h> //atoi

int main(int argc, char const *argv[]) {

  int nprocs = 5, estado, total_hijos = 5;
  pid_t pid[nprocs],aux;

  for (int i=0; i < nprocs; i++) {
    if( (pid[i] = fork()) < 0 ) {
        fprintf(stderr, "No se pudo crear el hijo %d: %s\n",i,strerror(errno));
        exit(EXIT_FAILURE);
    }
    if(pid[i] == 0){
        printf("%d. Soy el hijo %d\n",i,getpid());
        exit(EXIT_SUCCESS);
    }
  }
  for (int i = 0; i < nprocs; i = i + 2) {
    aux = waitpid(pid[i],&estado,0);
    printf("%d. Acaba de finalizar mi hijo con PID %d\n",i,aux);
    printf("Solo me quedan %d hijos vivos\n",--total_hijos);
  }

  for (int i = 1; i < nprocs; i = i + 2) {
    aux = waitpid(pid[i],&estado,0);
    printf("%d. Acaba de finalizar mi hijo con PID %d\n",i,aux);
    printf("Solo me quedan %d hijos vivos\n",--total_hijos);
  }

  exit(EXIT_SUCCESS);

}
