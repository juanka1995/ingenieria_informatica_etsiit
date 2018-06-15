//productorFIFO.c
//Productor que usa mecanismo de comunicacion FIFO

#include <fcntl.h> //open
#include <sys/types.h> //open,lseek,stat,umask,chmod,directorios,procesos,fifo
#include <sys/stat.h> //open,stat,umask,chmod,fifo
#include <unistd.h> //close,write,read,lseek,stat,procesos,exec,pipe,dup2
#include <dirent.h> //directories
#include <ftw.h> //nftw
#include <stdio.h> //setvbuf,printf
#include <sys/wait.h> //wait,waitpid
#include <stdlib.h> //exit,strtol,atoi
#include <signal.h> //señales
#include <fcntl.h> //fcntl
#include <errno.h>
#include <string.h> //strcmp,str...,memset
#include <stdbool.h> //Cabeceras para poder usar el tipo booleano
#include <math.h>

// Calcula si un numero es primo o no
bool es_primo(int n){
  bool esprimo = true;
  for(int i = 2 ; i <= sqrt(n) && esprimo ; i++)
   if(n%i == 0)
     esprimo = false;
  return esprimo;
}

int main(int argc, char *argv[]){
  int inicio, final;

  //Comprobar el uso correcto del programa
  if (argc != 3) {
    printf("Error en el numero de argumentos\n");
    printf("Ejemplo:\t%s 1000 2000\n",argv[0]);
    exit(EXIT_FAILURE);
  }

  inicio = atoi(argv[1]);
  final = atoi(argv[2]);

  for (int i = inicio; i < final; i++) {
    if (es_primo(i)) {
      printf("\tValor --> %d\n",i);
    }
  }

  return(EXIT_SUCCESS);
}
