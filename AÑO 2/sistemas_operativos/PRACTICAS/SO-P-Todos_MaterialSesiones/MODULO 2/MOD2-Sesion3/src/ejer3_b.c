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

  pid_t childpid;
  int nprocs = 20;

  /*
  Jerarquía de procesos tipo 1

  Este tipo de jerarquia generaria nprocs hermanos del mismo padre

  */
  for (int i=1; i < nprocs; i++) {
    if( (childpid= fork()) == -1 ) {
        fprintf(stderr, "Could not create child %d: %s\n",i,strerror(errno));
        exit(-1);
    }
    if (!childpid)
      break;
    printf("%d.Mi PID: %d\t\tPID padre: %d\n",i,childpid,getppid());
  }

  exit(EXIT_SUCCESS);

}
