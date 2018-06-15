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

//Muestra los permisos de un struct stat como los muestra un ls -l para que sea mas legible
void showPermission(struct stat *atributos){
   printf( (atributos->st_mode & S_IRUSR) ? "r" : "-");
   printf( (atributos->st_mode & S_IWUSR) ? "w" : "-");
   printf( (atributos->st_mode & S_IXUSR) ? "x" : "-");
   printf( (atributos->st_mode & S_IRGRP) ? "r" : "-");
   printf( (atributos->st_mode & S_IWGRP) ? "w" : "-");
   printf( (atributos->st_mode & S_IXGRP) ? "x" : "-");
   printf( (atributos->st_mode & S_IROTH) ? "r" : "-");
   printf( (atributos->st_mode & S_IWOTH) ? "w" : "-");
   printf( (atributos->st_mode & S_IXOTH) ? "x" : "-");
}

int main(int argc, char const *argv[]) {
  struct stat atr_dir;
  unsigned int permis;
  DIR *dir;
  struct dirent *mi_dirent;

  //Compruebo que el numero de parametros sea el correcto
  if( argc != 3 ){
    printf("Numero de parametros incorrecto.\n");
    printf("\tSintaxis: %s <pathname> <permisos_en_octal_de_4_digitos>\n",argv[0]);
    printf("\tEjemplo: %s /home/juanka1995/ 0775\n",argv[0]);
    exit(EXIT_FAILURE);
  }

  // Almaceno los permisos del directorio pasado como primer parametro
  if(stat(argv[1],&atr_dir) < 0) {
  	printf("Error al intentar acceder a los atributos de %s, podria no ser un directorio\n",argv[1]);
  	perror("Error en lstat");
  	exit(EXIT_FAILURE);
  }

  //Compruebo que el primer parametro pasado sea realmente un directorio
  if( (atr_dir.st_mode & S_IFMT) != S_IFDIR){
    printf("\nError %s no es un directorio.",argv[1]);
    exit(EXIT_FAILURE);
  }

  //Compruebo que el numero pasado sea un numero valido para ser octal
  if( strlen(argv[2]) != 4 || argv[2][0] != '0'){
    printf("El numero %s no es exactamente de 4 digitos comenzando por 0\n",argv[2]);
    exit(EXIT_FAILURE);
  }

  //Paso el *char a integer para asignar permisos posteriormente.
  permis = strtol(argv[2],NULL,8);

  //Abrimos el directorio pasado por argumento
  dir = opendir(argv[1]);
  if(dir == NULL){
    printf("Error. No se puede abrir el directorio %s\n",argv[1]);
    exit(EXIT_FAILURE);
  }

  printf("Si todo va bien la 2ª columna mostrara <p_antiguos> y la 3ª mostrara <p_nuevos>\n");
  printf("Si falla la 2ª columna mostrara <error> y la 3ª mostrara <p_antiguos>\n\n");
  printf("<nombre_archivo>\t\t\t<p_antiguos/error>\t\t<p_nuevos/antiguos>\n\n");
  //Mientras existan ficheros/directorios en el directorio abierto vamos avanzando seleccionando uno distinto en cada iteracion
  while ((mi_dirent = readdir(dir)) != NULL){
    // Guardamos el nombre del fichero/directorio seleccionado
    char *dname = mi_dirent->d_name;
    // Evitamos localizar . y ..
    if(strcmp(dname,".") && strcmp(dname,"..")){
      //Creamos un vector de char que contenga el path completo del fichero/directorio seleccionado
      char dirp[strlen(argv[1]+strlen(dname))];
      strcpy(dirp,argv[1]);
      strcat(dirp,dname);
      //Guardamos los permisos de dicho fichero/directorio en atr_dir
      stat(dirp,&atr_dir);
      //Si es un fichero regular entramos en el if
      if((atr_dir.st_mode & S_IFMT) == S_IFREG){
        //Si al intentar dar permisos diera error mostrariamos lo siguiente
        //NOTA : el chmod en el if solo devuelve el resultado, es decir se pueden cambiar los permisos
        // o no se pueden pero no los llega a cambiar.
        if(chmod(dirp,permis) < 0){ //Muestra <nombre_archivo> <error> <p_antiguos>
          printf("%s\t\t%s\t\t",dirp,strerror(errno));
          showPermission(&atr_dir);
          printf("\n");
        }
        else{ //Muestra <nombre_archivo> <p_antiguos> <p_nuevos>
          printf("%s\t\t",dirp);
          showPermission(&atr_dir);
          printf("\t\t\t");
          //Cambiamos los permisos
          chmod(dirp,permis);
          stat(dirp,&atr_dir);
          showPermission(&atr_dir);
          printf("\n");
        }
      }
    }
  }

  //Cierra el directorio abierto
  closedir(dir);

  return 0;
}
