/*
tarea1.c
Trabajo con llamadas al sistema del Sistema de Archivos ''POSIX 2.10 compliant''
Probad tras la ejecución del programa: $>cat archivo y $> od -c archivo
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char buf1[]="abcdefghij";
char buf2[]="ABCDEFGHIJ";

int main(int argc, char *argv[]){
  int fd;

  if( (fd=open("archivo",O_CREAT|O_WRONLY,S_IRUSR|S_IWUSR))<0) {
    printf("\nError %d en open",errno);
    perror("\nError en open");
    exit(-1);
  }

  if(write(fd,buf1,strlen(buf1)) != strlen(buf1)) {
    perror("\nError en primer write");
    exit(-1);
  }

  if(lseek(fd,strlen(buf1),SEEK_SET) < 0) {
    perror("\nError en lseek");
    exit(-1);
  }

  if(write(fd,buf2,strlen(buf2)) != strlen(buf2)) {
    perror("\nError en segundo write");
    exit(-1);
  }

  close(fd);
  return 0;
}
