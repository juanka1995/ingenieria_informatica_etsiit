/*
tarea3.c
Trabajo con llamadas al sistema del Sistema de Archivos ''POSIX 2.10 compliant''
Este programa fuente est� pensado para que se cree primero un programa con la parte
 de CREACION DE ARCHIVOS y se haga un ls -l para fijarnos en los permisos y entender
 la llamada umask.
En segundo lugar (una vez creados los archivos) hay que crear un segundo programa
 con la parte de CAMBIO DE PERMISOS para comprender el cambio de permisos relativo
 a los permisos que actualmente tiene un archivo frente a un establecimiento de permisos
 absoluto.
*/

#include<sys/types.h>	//Primitive system data types for abstraction of implementation-dependent data types.
						//POSIX Standard: 2.6 Primitive System Data Types <sys/types.h>
#include<unistd.h>		//POSIX Standard: 2.10 Symbolic Constants         <unistd.h>
#include<sys/stat.h>
#include<fcntl.h>		//Needed for open
#include<stdio.h>
#include<errno.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
int fd1,fd2;
struct stat atributos;

//CREACION DE ARCHIVOS

//Crea el fichero archivo1 si no existe con los permisos 070 & ~022 = 050 = ---r-x---
if( (fd1=open("archivo1",O_CREAT|O_TRUNC|O_WRONLY,S_IRGRP|S_IWGRP|S_IXGRP))<0) {
	printf("\nError %d en open(archivo1,...)",errno);
	perror("\nError en open");
	exit(EXIT_FAILURE);
}

//Crea el fichero archivo2 si no existe con los permisos 070 & ~000 = 070 = ---rwx---
umask(0);
if( (fd2=open("archivo2",O_CREAT|O_TRUNC|O_WRONLY,S_IRGRP|S_IWGRP|S_IXGRP))<0) {
	printf("\nError %d en open(archivo2,...)",errno);
	perror("\nError en open");
	exit(EXIT_FAILURE);
}

//CAMBIO DE PERMISOS
//stat guarda en atributos los permisos del archivo1, en caso de error termina el programa
if(stat("archivo1",&atributos) < 0) {
	printf("\nError al intentar acceder a los atributos de archivo1");
	perror("\nError en lstat");
	exit(EXIT_FAILURE);
}


//Mostrar los permisos del archivo 1 antes de realizar su modificacion.
printf("File Permissions of archivo 1: \t");
 printf( (S_ISDIR(atributos.st_mode)) ? "d" : "-");
 printf( (atributos.st_mode & S_IRUSR) ? "r" : "-");
 printf( (atributos.st_mode & S_IWUSR) ? "w" : "-");
 printf( (atributos.st_mode & S_IXUSR) ? "x" : "-");
 printf( (atributos.st_mode & S_IRGRP) ? "r" : "-");
 printf( (atributos.st_mode & S_IWGRP) ? "w" : "-");
 printf( (atributos.st_mode & S_IXGRP) ? "x" : "-");
 printf( (atributos.st_mode & S_IROTH) ? "r" : "-");
 printf( (atributos.st_mode & S_IWOTH) ? "w" : "-");
 printf( (atributos.st_mode & S_IXOTH) ? "x" : "-");
 printf("\n\n");

// Cambia los permisos de archivo1 de  a (050 - 010) + 2000 = 2040 = ---r-s---
if(chmod("archivo1", (atributos.st_mode & ~S_IXGRP) | S_ISGID) < 0) {
	perror("\nError en chmod para archivo1");
	exit(EXIT_FAILURE);
}

//Cambia los permisos del archivo2 de 070 a (700 + 040 + 020 + 004) = 764 ) rwxrw-r--
if(chmod("archivo2",S_IRWXU | S_IRGRP | S_IWGRP | S_IROTH) < 0) {
	perror("\nError en chmod para archivo2");
	exit(EXIT_FAILURE);
}

return EXIT_SUCCESS;
}
