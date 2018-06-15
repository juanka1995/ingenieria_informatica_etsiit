/* pmv-OpenMP-a.c
Producto de una matriz cuadrada por un vector
Para compilar usar (-lrt: real time library):
gcc -O2 pmv-OpenMP-a.c -o pmv-OpenMP-a -lrt -fopenmp
gcc -O2 -S pmv-OpenMP-a.c -lrt -fopenmp //para generar el código ensamblador
Para ejecutar use: pmv-OpenMP-a.c n_filas n_columnas
*/
#include <stdlib.h> // biblioteca con funciones atoi(), malloc() y free()
#include <stdio.h> // biblioteca donde se encuentra la función printf()
#include <time.h> // biblioteca donde se encuentra la función clock_gettime()
#ifdef _OPENMP
  #include <omp.h>
#else
   #define omp_get_thread_num() 0
#endif
#define PRINTF_ALL// comentar para quitar el printf ...
 									// que imprime todos los componentes
//Sólo puede estar definida una de las tres constantes VARIABLES_ (sólo uno de los ...
//tres defines siguientes puede estar descomentado):
// #define VARIABLES_LOCALES		 // descomentar para que las variables sean locales ...
				 								// locales (si se supera el tamaño de la pila se ...
 												// generará el error "Violación de Segmento")
// #define VARIABLES_GLOBALES // descomentar para que las variables sean globales ...
 											 // globales (su longitud no estará limitada por el ...
 										 	 // tamaño de la pila del programa)
#define VARIABLES_DINAMICAS // descomentar para que las variables sean dinamicas ...
 // dinámicas (memoria reutilizable durante la ejecución)
#ifdef VARIABLES_GLOBALES
#define MAX 8192 //=2^13
double M[MAX][MAX], v1[MAX], v2[MAX];
#endif

int main(int argc, char** argv)
{
	int i;
	struct timespec cgt1,cgt2;
	double ncgt; //para tiempo de ejecución
	//Leer argumento de entrada (nº de componentes del vector)
	if (argc<2)
	{
		printf("Faltan filas y columnas\n");
		exit(-1);
	}

	unsigned int filas_columnas = atoi(argv[1]);
#ifdef VARIABLES_LOCALES
	double M[filas_columnas][filas_columnas], v1[filas_columnas], v2[filas_columnas]; // Tamaño variable local en tiempo de ejecución ...
	// disponible en C a partir de actualización C99
#endif
#ifdef VARIABLES_GLOBALES
	if (filas_columnas>MAX) filas_columnas=MAX;
#endif
#ifdef VARIABLES_DINAMICAS
	double **M, *v1, *v2;
	M = (double **) malloc(filas_columnas*sizeof(double*));
	v1 = (double*) malloc(filas_columnas*sizeof(double));// malloc necesita el tamaño en bytes
	v2 = (double*) malloc(filas_columnas*sizeof(double)); //si no hay espacio suficiente malloc devuelve NULL
	if ( (v1==NULL) || (v2==NULL) || (M==NULL)){
	printf("Error en la reserva de espacio para los vectores\n");
	exit(-2);
	}
#endif
#ifndef _OPENMP
	//Inicialiar v1 y M
	for(i=0; i<filas_columnas; i++){
		v1[i] = filas_columnas*0.1-i*0.1;//los valores dependen de filas_columnas
		v2[i] = 0.0;
		M[i] = (double*) malloc(filas_columnas*sizeof(double));
		for (int j = 0; j < filas_columnas; j++) {
			M[i][j] = filas_columnas*0.1+i*0.1;
		}
	}
	clock_gettime(CLOCK_REALTIME,&cgt1);
	//Calcular producto de v1 por M, en v2
	for (int i = 0; i < filas_columnas; i++) {
		for (int j = 0; j < filas_columnas; j++) {
			v2[i] += M[i][j] * v1[j];
		}
	}
	clock_gettime(CLOCK_REALTIME,&cgt2);
#else
  #pragma omp parallel
	{
		// Inicializar v1 y M
		#pragma omp for
		for(i=0; i<filas_columnas; i++){
			v1[i] = filas_columnas*0.1-i*0.1;//los valores dependen de filas_columnas
			v2[i] = 0.0;
			M[i] = (double*) malloc(filas_columnas*sizeof(double));
			for (int j = 0; j < filas_columnas; j++) {
				M[i][j] = filas_columnas*0.1+i*0.1;
			}
		}
		clock_gettime(CLOCK_REALTIME,&cgt1);
		#pragma omp for
		for (int i = 0; i < filas_columnas; i++) {
			for (int j = 0; j < filas_columnas; j++) {
				v2[i] += M[i][j] * v1[j];
			}
		}
		clock_gettime(CLOCK_REALTIME,&cgt2);
	}
#endif


	ncgt=(double) (cgt2.tv_sec-cgt1.tv_sec)+ (double) ((cgt2.tv_nsec-cgt1.tv_nsec)/(1.e+9));
	//Imprimir resultado de la suma y el tiempo de ejecución
#ifdef PRINTF_ALL
	printf("Tiempo(seg.):%11.9f\t Tamaño vectores y matriz:%u\n",ncgt,filas_columnas);
	for(i=0; i<filas_columnas; i++)
		printf("V2[%d]=(%8.6f) \n", i,v2[i]);
#else
	printf("Tiempo(seg.):%11.9f\t Tamaño vectores y matriz:%u\t V2[0]=(%8.6f) V2[%d]=(%8.6f) \n", ncgt,filas_columnas,v2[0],filas_columnas-1,v2[filas_columnas-1]);
#endif
#ifdef VECTOR_DYNAMIC
	free(v1); // libera el espacio reservado para v1
	free(v2); // libera el espacio reservado para v2
	free(*M); // libera el espacio reservado para v3
#endif
	return 0;
}
