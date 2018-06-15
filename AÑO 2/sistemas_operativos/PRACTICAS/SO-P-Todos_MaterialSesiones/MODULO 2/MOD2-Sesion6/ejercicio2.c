/*

Nombre: Juan Carlos Ruiz García
Grupo: C2
Año: 2017

Reescribir el programa que implemente un encauzamiento de dos órdenes pero
utilizando fcntl. Este programa admitirá tres argumentos. El primer argumento y el tercero
serán dos órdenes de Linux. El segundo argumento será el carácter “|”. El programa deberá
ahora hacer la redirección de la salida de la orden indicada por el primer argumento hacia el
cauce, y redireccionar la entrada estándar de la segunda orden desde el cauce. Por ejemplo,
para simular el encauzamiento ls|sort, ejecutaríamos nuestro programa como:

      $> ./mi_programa2 ls “|” sort

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
  printf("%d\n",STDIN_FILENO);
  int fd[2];
  pid_t pid;

  if (argc < 4) {
    printf("Numero de argumentos incorrecto\n");
    printf("Estructura:\t%s <orden-linux> | <orden-linux>\n",argv[0]);
    printf("Ejemplo:\t%s ls “|” sort\n",argv[0]);
    exit(EXIT_FAILURE);
  }

  // Compruebo que el segundo argumento sea |
  if (strcmp(argv[2],"|") == 0) {
    // Creo un cauce
    pipe(fd);
    // Creo un hijo
    if ((pid = fork()) < 0) {
      perror("Error en el fork");
      exit(EXIT_FAILURE);
    }
    if (pid == 0) {
      // Cierro mi descriptor de lectura
      close(fd[0]);
      // Cierro el descriptor de escritura del cauce
      close(STDOUT_FILENO);
      // Duplico mi descriptor de escritura al por defecto
      if (fcntl(fd[1], F_DUPFD, STDOUT_FILENO) == -1 ){
        perror ("Fallo en fcntl");
        exit(EXIT_FAILURE);
      }
      // Ejecuta el primer comando
      execlp(argv[1],argv[1],NULL);
      // Cierro mi descriptor de escritura
      close(fd[1]);
    }
    else{
      // Cierro mi descriptor de escritura
      close(fd[1]);
      // Cierro el descriptor de lectura del cauce
      close(STDIN_FILENO);
      // Duplico mi descriptor de lectura al por defecto
      if (fcntl(fd[0], F_DUPFD, STDIN_FILENO) == -1 ){
        perror ("Fallo en fcntl");
        exit(EXIT_FAILURE);
      }
      // Ejecuto el segundo comando
      execlp(argv[3],argv[3],NULL);
      // Cierro mi descriptor de lectura
      close(fd[0]);
    }
  }
  else{
    printf("El segundo argumento tiene que ser un |\n");
    exit(EXIT_FAILURE);
  }

  return 0;
}
