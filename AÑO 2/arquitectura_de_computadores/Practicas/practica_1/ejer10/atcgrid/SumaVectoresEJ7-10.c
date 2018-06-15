/* SumaVectoresOpenMP.c
Suma de dos vectores: v3 = v1 + v2
Para compilar usar (-lrt: real time library):
gcc -O2 SumaVectoresOpenMP.c -o SumaVectoresOpenMP -lrt
gcc -O2 –S SumaVectoresOpenMP.c –lrt //para generar el código ensamblador
Para ejecutar use: SumaVectoresOpenMP longitud
*/
#include <stdlib.h> // biblioteca con funciones atoi(), malloc() y free()
#include <stdio.h> // biblioteca donde se encuentra la función printf()
#include <omp.h>

#define MAX 67108864 //=2^26
double v1[MAX], v2[MAX], v3[MAX];

int main(int argc, char** argv)
{
	int i;
	double cgt1,cgt2;
	double ncgt; //para tiempo de ejecución
	//Leer argumento de entrada (nº de componentes del vector)
	if (argc<2)
	{
		printf("Faltan nº componentes del vector\n");
		exit(-1);
	}

	unsigned int N = atoi(argv[1]); // Máximo N =2^32-1=4294967295 (sizeof(unsigned int) = 4 B)

	if (N>MAX) N=MAX;

	//Inicializar vectores
	#pragma omp parallel for
		for(i=0; i<N; i++){
		v1[i] = N*0.1+i*0.1; v2[i] = N*0.1-i*0.1; //los valores dependen de N
		}
	cgt1 = omp_get_wtime();
	//Calcular suma de vectores
	#pragma omp parallel for
		for(i=0; i<N; i++)
			v3[i] = v1[i] + v2[i];
	cgt2 = omp_get_wtime();
	ncgt = cgt2 - cgt1;
	//Imprimir resultado de la suma y el tiempo de ejecución
	printf("Tiempo(seg.):%11.9f\n",ncgt);

	return 0;
}
