/*
Nombre: Juan Carlos Ruiz García
Grupo: C2
Año: 2016
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

off_t full_size = 0; //Almacenara el tamaño total en bytes de todos los archivos regulares encontrados
int n_files = 0; //Almacenara el numero de archivos encontrados
const unsigned int D_PERMISOS = 0011; // Permisos de ejecucion para grupo y otros

// Busca de forma recursiva dentro de un directorio y sus subdirectorios, archivos regulares
// con permisos de ejecucion en el grupo y en otros.
void buscar(char * pathname){
  DIR *dir;
  struct dirent *mi_dirent;
  char * next_path;
  struct stat atr_dir;
  //Abrimos el directorio pasado como parametro de la funcion buscar
  dir = opendir(pathname);
  if(dir == NULL){
    printf("\t\tError. No se puede abrir el directorio %s\n",pathname);
  }
  else{
    //Mientras existan ficheros/directorios en el directorio abierto vamos avanzando seleccionando uno distinto en cada iteracion
    while ((mi_dirent = readdir(dir)) != NULL){
      // Guardamos el nombre del fichero/directorio seleccionado
      char *dname = mi_dirent->d_name;
      // Evitamos localizar . y ..
      if(strcmp(dname,".") && strcmp(dname,"..")){
        //Creamos un vector de char que contenga el path completo del fichero/directorio seleccionado
        char dirp[strlen(pathname)+strlen(dname)];
        strcpy(dirp,pathname);
        //Si el pathname no acaba en / se la añadimos
        if(pathname[strlen(pathname)-1] != '/')
          strcat(dirp,"/");
        strcat(dirp,dname);
        //Guardamos los permisos de dicho fichero/directorio en atr_dir
        stat(dirp,&atr_dir);
        /*
        Si es un directorio llamamos recursivamente a la misma funcion buscar para
        que busque dentro de dicho directorio archivos regulares con permisos de
        ejecucion para grupo y otros.

        NOTA : Para evitar problemas he ignorado todos los directorios ocultos,
        es decir los que empiezan por .<nombre_directorio>
        */
        if( ((atr_dir.st_mode & S_IFMT) == S_IFDIR) && dname[0] !='.' ){
          buscar(dirp);
        }
        // Si no es un directorio y es un archivo regular...
        else if ( (atr_dir.st_mode & S_IFMT) == S_IFREG){
          // Si es un archivo regular y tiene al menos los permisos 011 = -----x--x,
          // muestro la ruta absoluta del archivo, su numero de inodo, incremento el contador
          // y sumo el tamaño de dicho archivo regular a la variable full_size
          if ((atr_dir.st_mode & D_PERMISOS) == D_PERMISOS){
            printf("\t%s %lu\n",dirp,atr_dir.st_ino);
            n_files++;
            full_size += atr_dir.st_size;
          }
        }
      }
    }
  }
}


int main(int argc, char const *argv[]) {
  struct stat atr_dir;
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
    buscar(pathname);
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
