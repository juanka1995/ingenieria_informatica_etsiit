/*
Nombre: Juan Carlos Ruiz García
Grupo: C2
Año: 2016

NOTA: Compilar con la opcion -w para evitar todos los incomodos warnings

              gcc -w ejer4.c -o ejer4 

*/
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <dirent.h> //opendir
#include <stdio.h> //strlen y strtol
#include <string.h> //strcmp
#include <ftw.h> //nftw

off_t full_size = 0; //Almacenara el tamaño total en bytes de todos los archivos regulares encontrados
int n_files = 0; //Almacenara el numero de archivos encontrados
const unsigned int D_PERMISOS = 0011; // Permisos de ejecucion para grupo y otros

// Busca de forma recursiva dentro de un directorio y sus subdirectorios, archivos regulares
// con permisos de ejecucion en el grupo y en otros.
int buscar(const char *pathname, const struct stat *stat, int flags, struct FTW *ftw){
  // Compruebo que el pathname no sea . ni ..
  if( pathname != '.' && pathname != '..' ){
    // Si es un archivo regular...
    if ( (stat->st_mode & S_IFMT) == S_IFREG){
      // Si tiene permisos de ejecucion para grupos y otros muestro el pathname y el numero de inodo.
      // Incremento en 1 el contador de ficheros y sumo el tamaño de dicho archivo al contenedor.
      if ((stat->st_mode & D_PERMISOS) == D_PERMISOS){
        printf("\t%s %lu\n",pathname,stat->st_ino);
        n_files++;
        full_size += stat->st_size;
      }
    }
  }
  return 0;
}


int main(int argc, char const *argv[]) {
  struct stat atr_dir;
  int fd_limit = 5;
  int flags = 10;
  char *pathname = malloc(sizeof(char) * 254); // assuming the max length of a string is not more than 253 characters

  if(argc <= 2){
    if(argc == 2)
      strcpy(pathname,argv[1]);
    else
      pathname = "./";

    // Almaceno los permisos del directorio pasado como primer parametro
    if(stat(pathname,&atr_dir) < 0) {
      printf("Error al intentar acceder a los atributos de %s, podria no ser un directorio\n",argv[1]);
      perror("Error en stat");
      exit(EXIT_FAILURE);
    }

    //Compruebo que el primer parametro pasado sea realmente un directorio
    if( (atr_dir.st_mode & S_IFMT) != S_IFDIR){
      printf("Error %s no es un directorio.\n",argv[1]);
      exit(EXIT_FAILURE);
    }

    printf("Los inodos son: \n\n");
    // nftw recorre todo el arbol de directorios de pathname y para cada directorio/archivo llama a la funcion buscar
    // con un maximo de 5 files descriptor y con los flags a 10
    if( nftw(pathname,buscar,fd_limit,flags) != 0 ){
      perror("nftw");
      exit(EXIT_FAILURE);
    }
    printf("\nExisten %d archivos regulares con permisos x para grupo y otros en el directorio %s\n",n_files,pathname);
    printf("El tamaño total ocupado por dichos archivos es %ld Bytes = %ld MB aprox.\n", full_size,full_size/(1024*1024));
  }
  else{
    printf("Numero de parametros incorrecto\n");
    printf("\tFormato: %s <directorio_a_buscar>\n",argv[0]);
    printf("NOTA : Si no se especifica <directorio_a_buscar> se utilizar ./ por defecto\n");
  }
  return 0;
}
