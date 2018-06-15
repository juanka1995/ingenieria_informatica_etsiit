/*******************************************************************************
*
*   ejecutivociclico.c: Planificacion con ejecutivo ciclico
*
* 	Autor: Juan Carlos Ruiz Garcia
*	Ultima modificacion: 17/01/2017
*	Plataforma: POSIX
*	Asignatura: Sistemas Concurrentes y Distribuido
*	Departamento: Lenguajes y Sistemas Informaticos
* 	Universidad de Granada
*
* 	compilacion: gcc ejecutivociclico.c utilRT.c -o ejecutivo
*
*   Nota: En linux es necesario enlazar la libreria POSIX al final a�adiendo -lrt
*
*******************************************************************************/


#include <time.h>		//para  clock_gettime()
#include <stdio.h>		//para printf()
#include <errno.h>		//para perror
#include "utilRT.h"


// Se define una variable global que marca la referencia de tiempo:
// es el instante de tiempo absoluto (tiempo desde 1 de enero de 1970)
// en el cual comienza la primera iteración del ciclo principal (inicio de la
// simulación)
struct timespec origenTiempo;

///////////////////////////////////////////////////////////////
//Definicion de tareas
// Nota: Si las tareas tuvieran el mismo comportamiento se pueden parametrizar
void TareaA(void);
void TareaB(void);
void TareaC(void);
void TareaD(void);


// *****************************************************************************
//
// Programa principal

int main(int argc, char **argv)
{
	//Parametros relacionados con el ejecutivo ciclico
	struct timespec activacionTiempo;  //define el nuevo instante de activacion
	struct timespec cicloMarco;  //define el intervalo de tiempo

	//Parametros relacionados con el ejecutivo ciclico
	int nciclos; //Numero de ciclos secundarios respecto al marco primario ---Modificar----
	int marco;   //especifica el ciclo secundario actual
	marco = 0;   //se inicializa el marco, que varia entre 0 y nCiclos-1


	//Establecer el numero de ciclos secundarios nciclos, asi como la inicializacion el marco
	nciclos = 4;
	/////////////////////////////////////////////////////////////////////////////////
	//Etapa 1: Inicializacion y Preparacion del Ejecutivo Ciclico
	//
	/////////////////////////////////////////////////////////////////////////////////

	//COMPLETAR: Establecer el Ciclo Secundario (--- usar getTimespec ---)
	cicloMarco = getTimespec(5);
	//COMPLETAR: Calcula la marca de tiempo para determinar el instante de referencia
	clock_gettime(CLOCK_REALTIME,&origenTiempo);
  //COMPLETAR: A partir de este instante, determina la siguiente activacion del ejecutivo ciclico ( --- usar sumaTiempos ---)
	activacionTiempo = sumaTiempos(&cicloMarco,&origenTiempo);
	/////////////////////////////////////////////////////////////////////////////////
	//Etapa 2: Implementacion del ejecutivo ciclico
	/////////////////////////////////////////////////////////////////////
	// Aqui esta el planificador ciclico
	while (1) {
	    switch(marco)
	    {
		       case 0:
					 	TareaA();TareaB();TareaC();
						break;
		       case 1:
					 	TareaA();TareaB();TareaD();
						break;
					 case 2:
					 	TareaA();TareaB();TareaC();
						break;
					 case 3:
					 	TareaA();TareaB();
						break;
	    }
	    marco = (marco +1)% nciclos;
			clock_nanosleep(CLOCK_REALTIME,TIMER_ABSTIME,&activacionTiempo,NULL);
			activacionTiempo = sumaTiempos(&activacionTiempo,&cicloMarco);
	    // suspender hasta nueva activacion utilizando retardos absolutos  (--- usar clock_nanosleep ---)
	    // y definir la activacion del siguiente ciclo
	}
	/////////////////////////////////////////////////////////////////////////////////

  return 0;
}

// *****************************************************************************
//
// TareaA

void TareaA(void)
{
	// Variables de tiempo
	struct timespec
		tInicio,     // tiempo de inicio de esta ejecución de la tarea (relativo a 'origenTiempo')
		tFinal,      // tiempo final de esta ejecución de la tarea (relativo a 'origenTiempo')
		tActivacion, // instante absoluto en el cual la tarea debe de despertarse:
		             //    (se debe calcular sumando el instante absoluto de inicio y la duración (tComputo))
		tComputo,    // duración del intervalo en el que se duerme la hebra, simulando hacer algún trabajo útil.
		             //    (se debe de construir usando el valor de C expresado en segundos)
		tiempo;      // variable temporal usada en los cálculos
	static int
	  i = 0 ;      // número de la activación actual de la tarea

	//COMPLETAR: Establece el tiempo de computo tComputo (--- usar getTimespec ---)
	tComputo = getTimespec(1);
	//Marca el tiempo de inicio
	clock_gettime(CLOCK_REALTIME,&tiempo);
	tInicio = restaTiempos(&tiempo,&origenTiempo);
	printf("Tarea A: activacion = %d, tiempo activacion = %.6f seg\n",
		i,getSeconds(&tInicio));

	//COMPLETAR: Simula el consumo con otro retardo absoluto o relativo  (--- usar clock_nanosleep ---)
	tActivacion = sumaTiempos(&tiempo,&tComputo);
	clock_nanosleep(CLOCK_REALTIME,TIMER_ABSTIME,&tActivacion,NULL);
	//Marca el tiempo de fin
	clock_gettime(CLOCK_REALTIME,&tiempo);
	tFinal = restaTiempos(&tiempo,&origenTiempo);
	printf("Tarea A: activacion = %d, tiempo finalizacion = %.6f seg\n",
		i,getSeconds(&tFinal));

	// incrementa contador de activaciones
	i++;
}

// *****************************************************************************
//
// TareaB

void TareaB(void)
{
	// Variables de tiempo
	struct timespec
		tInicio,     // tiempo de inicio de esta ejecución de la tarea (relativo a 'origenTiempo')
		tFinal,      // tiempo final de esta ejecución de la tarea (relativo a 'origenTiempo')
		tActivacion, // instante absoluto en el cual la tarea debe de despertarse:
								 //    (se debe calcular sumando el instante absoluto de inicio y la duración (tComputo))
		tComputo,    // duración del intervalo en el que se duerme la hebra, simulando hacer algún trabajo útil.
								 //    (se debe de construir usando el valor de C expresado en segundos)
		tiempo;      // variable temporal usada en los cálculos
	static int
		i = 0 ;      // número de la activación actual de la tarea

	//COMPLETAR: Establece el tiempo de computo tComputo
	tComputo = getTimespec(1.5);
	//Marca el tiempo de inicio
	clock_gettime(CLOCK_REALTIME,&tiempo);
	tInicio = restaTiempos(&tiempo,&origenTiempo);
	printf("Tarea B: activacion = %d, tiempo activacion = %.6f seg\n",
		i,getSeconds(&tInicio));

	//COMPLETAR: Simula el consumo con otro retardo absoluto o relativo
	tActivacion = sumaTiempos(&tiempo,&tComputo);
	clock_nanosleep(CLOCK_REALTIME,TIMER_ABSTIME,&tActivacion,NULL);
	//Marca el tiempo de fin
	clock_gettime(CLOCK_REALTIME,&tiempo);
	tFinal = restaTiempos(&tiempo,&origenTiempo);
	printf("Tarea B: activacion = %d, tiempo finalizacion = %.6f seg\n",
		i,getSeconds(&tFinal));

	// incrementa contador de activaciones
	i++;
}

// *****************************************************************************
//
// TareaC

void TareaC(void)
{
	// Variables de tiempo
	struct timespec
		tInicio,     // tiempo de inicio de esta ejecución de la tarea (relativo a 'origenTiempo')
		tFinal,      // tiempo final de esta ejecución de la tarea (relativo a 'origenTiempo')
		tActivacion, // instante absoluto en el cual la tarea debe de despertarse:
								 //    (se debe calcular sumando el instante absoluto de inicio y la duración (tComputo))
		tComputo,    // duración del intervalo en el que se duerme la hebra, simulando hacer algún trabajo útil.
								 //    (se debe de construir usando el valor de C expresado en segundos)
		tiempo;      // variable temporal usada en los cálculos
	static int
		i = 0 ;      // número de la activación actual de la tarea

	//COMPLETAR: Establece el tiempo de computo tComputo
	tComputo = getTimespec(2);
	//Marca el tiempo de inicio
	clock_gettime(CLOCK_REALTIME,&tiempo);
	tInicio = restaTiempos(&tiempo,&origenTiempo);
	printf("Tarea C: activacion = %d, tiempo activacion = %.6f seg\n",
		i,getSeconds(&tInicio));

	//COMPLETAR: Simula el consumo con otro retardo absoluto o relativo
	tActivacion = sumaTiempos(&tiempo,&tComputo);
	clock_nanosleep(CLOCK_REALTIME,TIMER_ABSTIME,&tActivacion,NULL);
	//Marca el tiempo de fin
	clock_gettime(CLOCK_REALTIME,&tiempo);
	tFinal = restaTiempos(&tiempo,&origenTiempo);
	printf("Tarea C: activacion = %d, tiempo finalizacion = %.6f seg\n",
		i,getSeconds(&tFinal));

	// incrementa contador de activaciones
	i++;
}

// *****************************************************************************
//
// TareaD

void TareaD(void)
{
	// Variables de tiempo
	struct timespec
		tInicio,     // tiempo de inicio de esta ejecución de la tarea (relativo a 'origenTiempo')
		tFinal,      // tiempo final de esta ejecución de la tarea (relativo a 'origenTiempo')
		tActivacion, // instante absoluto en el cual la tarea debe de despertarse:
								 //    (se debe calcular sumando el instante absoluto de inicio y la duración (tComputo))
		tComputo,    // duración del intervalo en el que se duerme la hebra, simulando hacer algún trabajo útil.
								 //    (se debe de construir usando el valor de C expresado en segundos)
		tiempo;      // variable temporal usada en los cálculos
	static int
		i = 0 ;      // número de la activación actual de la tarea

	//COMPLETAR: Establece el tiempo de computo tComputo
	tComputo = getTimespec(2.4);
	//Marca el tiempo de inicio
	clock_gettime(CLOCK_REALTIME,&tiempo);
	tInicio = restaTiempos(&tiempo,&origenTiempo);
	printf("Tarea D: activacion = %d, tiempo activacion = %.6f seg\n",
		i,getSeconds(&tInicio));

	//COMPLETAR: Simula el consumo con otro retardo absoluto o relativo
	tActivacion = sumaTiempos(&tiempo,&tComputo);
	clock_nanosleep(CLOCK_REALTIME,TIMER_ABSTIME,&tActivacion,NULL);
	//Marca el tiempo de fin
	clock_gettime(CLOCK_REALTIME,&tiempo);
	tFinal = restaTiempos(&tiempo,&origenTiempo);
	printf("Tarea D: activacion = %d, tiempo finalizacion = %.6f seg\n",
		i,getSeconds(&tFinal));

	// incrementa contador de activaciones
	i++;
}

/*
	SALIDA DE EJEMPLO

Tarea A: activacion = 0, tiempo activacion = 0.000001 seg
Tarea A: activacion = 0, tiempo finalizacion = 1.000126 seg
Tarea B: activacion = 0, tiempo activacion = 1.000148 seg
Tarea B: activacion = 0, tiempo finalizacion = 2.500296 seg
Tarea C: activacion = 0, tiempo activacion = 2.500328 seg
Tarea C: activacion = 0, tiempo finalizacion = 4.500471 seg
Tarea A: activacion = 1, tiempo activacion = 5.000134 seg
Tarea A: activacion = 1, tiempo finalizacion = 6.000273 seg
Tarea B: activacion = 1, tiempo activacion = 6.000303 seg
Tarea B: activacion = 1, tiempo finalizacion = 7.500448 seg
Tarea D: activacion = 0, tiempo activacion = 7.500484 seg
Tarea D: activacion = 0, tiempo finalizacion = 9.900625 seg
Tarea A: activacion = 2, tiempo activacion = 10.000133 seg
Tarea A: activacion = 2, tiempo finalizacion = 11.000224 seg
Tarea B: activacion = 2, tiempo activacion = 11.000242 seg
Tarea B: activacion = 2, tiempo finalizacion = 12.500388 seg
Tarea C: activacion = 1, tiempo activacion = 12.500427 seg
Tarea C: activacion = 1, tiempo finalizacion = 14.500566 seg
Tarea A: activacion = 3, tiempo activacion = 15.000138 seg
Tarea A: activacion = 3, tiempo finalizacion = 16.000274 seg
Tarea B: activacion = 3, tiempo activacion = 16.000301 seg
Tarea B: activacion = 3, tiempo finalizacion = 17.500433 seg
Tarea A: activacion = 4, tiempo activacion = 20.000127 seg
Tarea A: activacion = 4, tiempo finalizacion = 21.000267 seg
Tarea B: activacion = 4, tiempo activacion = 21.000298 seg
Tarea B: activacion = 4, tiempo finalizacion = 22.500440 seg


**********CASO EN EL QUE D FUERA DE 2500*************

Lo que pasaría es que el en el caso en el que el D durara 2500 en
vez de 2400, la ejecución del tercer ciclo se retrasaría pero no
pasaría nada porque dicho ciclo tiene un poco de margen y el 4º ciclo
de reloj se empezaría a ejecutar correctamente.
*/
