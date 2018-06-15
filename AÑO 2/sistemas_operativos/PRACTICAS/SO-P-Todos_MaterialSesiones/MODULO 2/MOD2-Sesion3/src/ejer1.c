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

int main(int argc, char *argv[])
{
pid_t pid;
int num;

if(argc != 2){
  printf("Numero de argumentos incorrecto\nSintaxis:\t\t\tEjemplo:\n");
  printf("%s <numero_entero>\t\t%s 5\n",argv[0],argv[0]);
  exit(EXIT_FAILURE);
}

num = atoi(argv[1]);

if( (pid=fork())<0) {
	perror("\nError en el fork");
	exit(EXIT_FAILURE);
}
else if(pid==0) {  //proceso hijo comprobando si el numero es par o impar
  if( num%2 == 0 )
    printf("El numero %d es un numero par.\n",num);
  else
    printf("El numero %d es un numero impar\n",num);
  exit(1);
}

if( num%4 == 0 )
  printf("El numero %d es divisible por 4.\n",num);
else
  printf("El numero %d no es divisible por 4.\n",num);

printf("PID Padre: %d\nPID Hijo: %d\n",getpid(),pid);

exit(EXIT_SUCCESS);

}
