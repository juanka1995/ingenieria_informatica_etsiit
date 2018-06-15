// *********************************************************************
// SCD. Ejemplos del seminario 1.
//
// Plantilla para el ejercicio de cálculo de PI
//
// Alumno : Juan Carlos Ruiz Garcia     Grupo : C2
// *********************************************************************

#include <iostream>
#include <pthread.h>
#include <assert.h>
#include <stdlib.h> //strtol
#include "fun_tiempo.h"
#include <iomanip> // setprecision
#include <cmath> //numero PI

using namespace std ;

// ---------------------------------------------------------------------
// constante y variables globales (compartidas entre hebras)

unsigned long n;
unsigned long m;
long double * resultado_parcial; // tabla de sumas parciales (una por hebra)

// ---------------------------------------------------------------------
// implementa función $f$

long double f( long double x )
{
   return 4.0/(1+x*x) ;     // $~~~~f(x)\,=\,4/(1+x^2)$
}
// ---------------------------------------------------------------------
// cálculo secuencial

double calcular_integral_secuencial()
{
   double suma = 0.0 ;                        // inicializar suma
   for( unsigned long i = 0 ; i < m ; i++ ){  // para cada $i$ entre $0$ y $m-1$
     suma += f( (i+0.5)/m );                  // $~~~~~$ añadir $f(x_i)$ a la suma actual
     //cout << "Secuencial [" << i << "]: " << suma << endl;
   }
   return suma/m ;                            // devolver valor promedio de $f$
}
// ---------------------------------------------------------------------
// función que ejecuta cada hebra

void * funcion_hebra( void * ih_void)
{
   unsigned long ih = (unsigned long) ih_void ; // número o índice de esta hebra
   long double sumap = 0.0 ;
   for (unsigned long i = ih*(m/n); i < (ih+1)*m/n ; i++) {
     sumap += f( (i+0.5)/m );
     //cout << "Concurrente [" << i << "]: " << sumap << endl;
   }
   resultado_parcial[ih] = sumap/m ; // guardar suma parcial en vector.
   return NULL ;
}
// ---------------------------------------------------------------------
// cálculo concurrente

long double calcular_integral_concurrente(/*int n_hebras, int n_muestras*/)
{
  // crear y lanzar $n hebras, cada una ejecuta "funcion hebra"
  pthread_t id_hebra[n];
  for (unsigned long i = 0; i < n; i++) {
    void * ih_void = (void *) i;
    pthread_create( &(id_hebra[i]), NULL, funcion_hebra, ih_void);
  }
  // esperar (join) a que termine cada hebra
  for (int i = 0; i < n; i++)
    pthread_join(id_hebra[i],NULL);
  // sumar su resultado
  long double suma_total=0;
  for (int i = 0; i < n; i++) {
    suma_total += resultado_parcial[i];
  }
  // devolver resultado completo
  return suma_total;
}

// ---------------------------------------------------------------------

// Parametro 1: n_hebras || Parametro 2: n_muestras
// Precondicion de argurmentos: es necesario introducir el numero de hebras seguido del numero de muestras
// Ejemplo : calculopi 4 1000000 (4 hebras y 1000000 muestras)
int main(int argc, char const *argv[]) {

  assert(argc == 3);
  n = strtol(argv[1], NULL, 10);
  m = strtol(argv[2], NULL, 10);
  assert(m%n == 0); //Obliga a que n_muestras sea multiplo de n_hebras
  resultado_parcial = new long double [n];

  cout << "Ejemplo 4 (cálculo de PI)" << endl << endl ;
  double pi_sec = 0.0, pi_conc = 0.0 ;

  struct timespec ini_secu = ahora();
  pi_sec  = calcular_integral_secuencial() ;
  struct timespec fin_secu = ahora();

  struct timespec ini_concu = ahora();
  pi_conc = calcular_integral_concurrente();
  struct timespec fin_concu = ahora();

  cout << "Numero PI original: " << setprecision(20) << M_PI << endl << endl;
  cout << "valor de PI (calculado secuencialmente)  == " << pi_sec << ", en un tiempo de: " << duracion(&ini_secu,&fin_secu) << endl
        << "valor de PI (calculado concurrentemente) == " << pi_conc << ", en un tiempo de: " << duracion(&ini_concu,&fin_concu) << endl ;

  delete [] resultado_parcial;
  resultado_parcial = NULL;
  return 0 ;
}
