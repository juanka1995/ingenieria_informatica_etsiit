//consumidorFIFO.c
//Consumidor que usa mecanismo de comunicacion FIFO.

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#define ARCHIVO_FIFO "ComunicacionFIFO"

int main(void)
{
int fd;
char buffer[80];// Almacenamiento del mensaje del cliente.
int leidos;

//Crear el cauce con nombre (FIFO) si no existe
umask(0);
mknod(ARCHIVO_FIFO,S_IFIFO|0666,0);
//tambi�n vale: mkfifo(ARCHIVO_FIFO,0666);

//Abrir el cauce para lectura-escritura
if ( (fd=open(ARCHIVO_FIFO,O_RDWR)) <0) {
perror("open");
exit(EXIT_FAILURE);
}

//Aceptar datos a consumir hasta que se env�e la cadena fin
while(1) {
  leidos=read(fd,buffer,80);
  if(strcmp(buffer,"fin")==0) {
    close(fd);
    break;
  }
  printf("\nMensaje recibido: %s\n", buffer);
}

// Elimina el archivo FIFO si todo va bien
if (unlink(ARCHIVO_FIFO) == 0) {
  printf("\nFichero %s cerrado correctamente\n",ARCHIVO_FIFO);
}
else{
  perror("Error al cerrar el fichero FIFO");
}

return EXIT_SUCCESS;
}
