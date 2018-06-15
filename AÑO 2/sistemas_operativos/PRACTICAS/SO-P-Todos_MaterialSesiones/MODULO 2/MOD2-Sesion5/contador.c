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

static int contador_seniales[64];
static void handler (int signum){
  contador_seniales[signum-1]++;
  printf("La señal %d se ha recibido %d veces\n",signum,contador_seniales[signum-1]);
}

int main(int argc, char const *argv[]) {
  struct sigaction sig;
  // Limpiar el buffer de salida
  if(setvbuf(stdout,NULL,_IONBF,0)){
    perror("\nError en setvbuf");
  }

  //Lleno el vector de contador_seniales con todo a 0
  // ya que inicialmente no se ha realizado ninguna llamada
  for (int i = 0; i < 64; i++) {
    contador_seniales[i] = 0;
  }

	//Asociamos la funcion definida como manejador
  sig.sa_handler = handler;

  //'sigemptyset' inicia el conjunto de señales dada al conjunto vacio.
  sigemptyset (&sig.sa_mask);

  sig.sa_flags = 0;

  //Ejecuto el manejador de señales con todas las señales
  for (int i = 1; i <= 64; i++) {
    if (sigaction(i,&sig,NULL) == -1) {
      printf("La señal %d no se puede manejar\n",i);
    }
  }
  while(1){}; // Bucle infinito

  return 0;
}
