/*
  Fichero: maestro.c
  Autor: Juan Carlos Ruiz García
  Grupo: C2
  Año: 2017
*/

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

int main(int argc, char const *argv[]) {
  int n_esclavos = 2,fd1[2],fd2[2];
  int mitad_intervalo,numBytes;
  pid_t pid[n_esclavos];
  char buffer[80];
  char mitad[strlen(argv[2])]; // char[] que contendra la mitad del intervalo

  // Controlo el numero de argumentos
  if (argc != 3) {
    printf("Error en el numero de argumentos\n");
    printf("Ejemplo:\t%s 1000 2000\n",argv[0]);
    exit(EXIT_FAILURE);
  }

  //Calculo la mitad del intervalo
  mitad_intervalo = (atoi(argv[1]) + atoi(argv[2])) / 2;
  // Paso el decimal a char[] y lo guardo en mitad
  sprintf(mitad,"%d",mitad_intervalo);

  // Lanzo 2 cauces
  pipe(fd1);
  pipe(fd2);

  for (int i = 0; i < n_esclavos; i++) {
    if( (pid[i] = fork()) < 0 ) {
        printf("No se pudo crear el esclavo %d\n",i+1);
        perror("Error: ");
        exit(EXIT_FAILURE);
    }
    if(pid[i] == 0){
      if (i == 0) {
        // Cierra descriptor de lectura y escritura fd2 porque ese lo utilizara solo el
        // segundo esclavo
        close(fd2[0]);
        close(fd2[1]);
        // Cierro el descriptor de lectura ya que usare el de escritura
        close(fd1[0]);
        // Duplico la salida estandar al descriptor de escritura y
        // cierro la salida estandar
        dup2(fd1[1],STDOUT_FILENO);
        execlp("./esclavo","esclavo",argv[1],mitad,NULL);
      }
      else{
        // Cierra descriptor de lectura y escritura fd1 porque ese lo utilizara solo el
        // primer esclavo
        close(fd1[0]);
        close(fd1[1]);
        // Cierro el descriptor de lectura ya que usare el de escritura
        close(fd2[0]);
        // Duplico la salida estandar al descriptor de escritura y
        // cierro la salida estandar
        dup2(fd2[1],STDOUT_FILENO);
        execlp("./esclavo","esclavo",mitad,argv[2],NULL);
      }
    }
  }

  // Cierro el descriptor de escritura del primer esclavo, ya que solo
  // usare el de lectura para recibir los datos
  close(fd1[1]);
  // Duplico la entrada estandar al descriptor de lectura y
  // cierro la entrada estandar
  dup2(fd1[0],STDIN_FILENO);
  printf("Valores primos recibidos de esclavo 1 [%s - %d]:\n",argv[1],mitad_intervalo-1);
  while ((numBytes = read(fd1[0],&buffer,sizeof(buffer))) > 0) {
    write(STDOUT_FILENO,&buffer,numBytes);
  }

  // Cierro el descriptor de escritura del segundo esclavo, ya que solo
  // usare el de lectura para recibir los datos
  close(fd2[1]);
  // Duplico la entrada estandar al descriptor de lectura y
  // cierro la entrada estandar
  dup2(fd2[0],STDIN_FILENO);
  printf("Valores primos recibidos de esclavo 2 [%d - %s]:\n",mitad_intervalo,argv[2]);
  while ((numBytes = read(fd2[0],&buffer,sizeof(buffer))) > 0) {
    write(STDOUT_FILENO,&buffer,numBytes);
  }

  return(EXIT_SUCCESS);
}
