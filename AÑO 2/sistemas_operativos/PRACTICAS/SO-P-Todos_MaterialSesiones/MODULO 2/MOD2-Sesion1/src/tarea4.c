/*
tarea4.c
Trabajo con llamadas al sistema del Sistema de Archivos ''POSIX 2.10 compliant''
*/
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<stdio.h>
#include<errno.h>
#include<string.h>

#define S_ISREG2(mode) ((mode & S_IFMT) == S_IFREG)

int main(int argc, char *argv[]){
  int i;
  struct stat atributos;
  char tipoArchivo[30];
  if(argc<2) {
    printf("\nSintaxis de ejecucion: tarea4 [<nombre_archivo>]+\n\n");
    exit(-1);
  }
  if(lstat(argv[1],&atributos) < 0) {
    printf("\nError al intentar acceder a los atributos de %s",argv[1]);
    perror("\nError en lstat");
    exit(-1);
  }
  if(S_ISREG2(atributos.st_mode))
    strcpy(tipoArchivo,"Regular");
  else
    strcpy(tipoArchivo,"No Regular");

  printf("El archivo %s es de tipo: %s\n",argv[1],tipoArchivo);

  return 0;
}
