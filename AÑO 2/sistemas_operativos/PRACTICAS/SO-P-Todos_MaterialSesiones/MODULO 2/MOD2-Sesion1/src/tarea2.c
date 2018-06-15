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

int main(int argc, char *argv[]){
  char caracter[1],texto_bloque[20],num_bloques[30];
  int contador = 1, fentrada, fsalida, end_file, current_pos;

  if(argc == 2){ //Si hay dos argumentos coje el segundo como el fichero con la informacion
    fentrada = open(argv[1],O_RDONLY);
  }
  else{  // Si no coje la entrada estandar
    printf("Escriba el texto deseado: \n");
    fentrada = STDIN_FILENO;
  }

  if(fentrada < 0){ //En caso de que no se abra bien el fichero dará error
    printf("Error al abrir el fichero de entrada.\n");
    exit(-1);
  }

  if( (fsalida = open("salida.txt",O_CREAT|O_TRUNC|O_WRONLY,S_IRUSR|S_IWUSR)) < 0) { //Crea el fichero salida.txt o lo abre si no existe
    printf("Error al abrir el fichero de salida.\n");
    exit(-1);
  }

  while( (end_file = read(fentrada,caracter,1)) != 0 ){ //Read devolvera 0 cuando llegue al final del fichero
    current_pos = lseek(fentrada,0,SEEK_CUR); // Calculo la posicion actual del puntero
    if(current_pos == 1 || current_pos%80 == 0){
      if(current_pos==1){ //Escribo el total de bloques MAL, que posteriormente se cambiara
        sprintf(num_bloques,"El numero de bloques es <%d>\n",contador);
        if(write(fsalida,num_bloques,strlen(num_bloques)) != strlen(num_bloques)){
          printf("Error escribir nº de bloques en el fichero de salida.\n");
          exit(-1);
        }
      }
      sprintf(texto_bloque, "\nBloque %d\n", contador); //Escribo el numero de bloque
      if(write(fsalida,texto_bloque,strlen(texto_bloque)) != strlen(texto_bloque)){
        printf("Error escribir bloque en el fichero de salida.\n");
        exit(-1);
      }
      contador++;
    }
    if(write(fsalida,caracter,1) != 1){ //Escribo caracter a caracter hasta llegar a modulo 80
      printf("Error escribir caracter en el fichero de salida.\n");
      exit(-1);
    }
  }

  sprintf(num_bloques,"El numero de bloques es <%d>\n",--contador); //Calculo el num_bloques correcto
  lseek(fsalida,0,SEEK_SET); //Vuelvo al inicio del fichero de salida
  if(write(fsalida,num_bloques,strlen(num_bloques)) != strlen(num_bloques)){ //Escribo el total de bloques correcto
    printf("Error escribir nº de bloques en el fichero de salida.\n");
    exit(-1);
  }

  close(fentrada); //Cierro ambos ficheros
  close(fsalida);
  return 0;
}
