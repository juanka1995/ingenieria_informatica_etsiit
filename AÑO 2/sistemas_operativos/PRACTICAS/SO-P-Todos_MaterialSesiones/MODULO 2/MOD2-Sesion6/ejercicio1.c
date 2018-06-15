/*

Nombre: Juan Carlos Ruiz García
Grupo: C2
Año: 2017

Ejercicio 1. Implementa un programa que admita t argumentos. El primer argumento será una
orden de Linux; el segundo, uno de los siguientes caracteres “<” o “>”, y el tercero el nombre de
un archivo (que puede existir o no). El programa ejecutará la orden que se especifica como
argumento primero e implementará la redirección especificada por el segundo argumento hacia
el archivo indicado en el tercer argumento. Por ejemplo, si deseamos redireccionar la entrada
estándar de sort desde un archivo temporal, ejecutaríamos:

      $> ./mi_programa sort “<” temporal

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

  int fd;

  if (argc < 4) {
    printf("Numero de argumentos incorrecto\n");
    printf("Estructura:\t%s <orden-linux> {'<'-'>'} <nombre-fichero>\n",argv[0]);
    printf("Ejemplo:\t%s sort “<” temporal\n",argv[0]);
    exit(EXIT_FAILURE);
  }

  // Comparo si el segundo argumento es < o >
  if (strcmp(argv[2],"<") || strcmp(argv[2],">")) {
    // Abro el archivo pasado como tercer argumento y si no existe lo creo
    if ((fd = open(argv[3],O_CREAT|O_RDWR,S_IRWXU|S_IRWXG|S_IRWXO)) < 0) {
      printf("Error al abrir el fichero %s\n",argv[3]);
      exit(EXIT_FAILURE);
    }
    // Si es < ...
    if (strcmp(argv[2],"<") == 0) {
      // Cierro la entrada estandar
      close(STDIN_FILENO);
      // Duplico el descriptor del fichero como entrada estandar
      if (fcntl(fd, F_DUPFD, STDIN_FILENO) == -1 ){
        perror ("Fallo en fcntl");
        exit(EXIT_FAILURE);
      }
      // Lanzo el comando pasado como primer argumento sobre el contenido del
      // fichero pasado como tercer argumento
      execlp(argv[1],argv[1],NULL);
    }
    // Si es > ...
    else{
      // Cierro la salida estandar
      close(STDOUT_FILENO);
      // Duplico el descriptor del fichero como salida estandar
      if (fcntl(fd, F_DUPFD, STDOUT_FILENO) == -1 ){
        perror ("Fallo en fcntl");
        exit(EXIT_FAILURE);
      }
      // Lanzo el comando pasado como primer argumento sobre del
      // descriptor del fichero que ahora es la salida estandar
      execlp(argv[1],argv[1],NULL);
    }
  }
  else{
    printf("El tercer argumento tiene que ser un < o un >\n");
    exit(EXIT_FAILURE);
  }

  return 0;
}
