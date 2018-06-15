/*
Nombre: Juan Carlos Ruiz García
Grupo: C2
Año: 2016
*/

#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdio.h>
#include<errno.h>
#include <stdlib.h> //atoi

int main(int argc, char const *argv[]) {

  pid_t pid;
  int nprocs = 5, estado;

  for (int i=0; i < nprocs; i++) {
    if( (pid = fork()) < 0 ) {
        fprintf(stderr, "No se pudo crear el hijo %d: %s\n",i,strerror(errno));
        exit(EXIT_FAILURE);
    }
    if(pid == 0){
        printf("Soy el hijo %d\n",getpid());
        exit(EXIT_SUCCESS);
    }
  }
  for (int i = 0; i < nprocs; i++) {
    pid = wait(&estado);
    printf("Acaba de finalizar mi hijo con PID %d\n",pid);
    printf("Solo me quedan %d hijos vivos\n",nprocs-i-1);
  }

  exit(EXIT_SUCCESS);

}
