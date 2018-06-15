// *****************************************************************************
//
// Prácticas de SCD. Práctica 1.
// Plantilla de código para el ejercicio del productor-consumidor con
// buffer intermedio.
//
// *****************************************************************************

#include <iostream>
#include <cassert>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h> // necesario para {\ttbf usleep()}
#include <stdlib.h> // necesario para {\ttbf random()}, {\ttbf srandom()}
#include <time.h>   // necesario para {\ttbf time()}

using namespace std ;

// ---------------------------------------------------------------------
// constantes configurables:

const unsigned
  num_items  = 40 ,    // numero total de items que se producen o consumen
  tam_vector = 10 ;    // tamaño del vector, debe ser menor que el número de items

int buffer[tam_vector]; //buffer de datos
int indice = 0;

sem_t
  puede_escribir,
  puede_leer,
  mutex;

// ---------------------------------------------------------------------
// introduce un retraso aleatorio de duración comprendida entre
// 'smin' y 'smax' (dados en segundos)

void retraso_aleatorio( const float smin, const float smax )
{
  static bool primera = true ;
  if ( primera )        // si es la primera vez:
  {  srand(time(NULL)); //   inicializar la semilla del generador
     primera = false ;  //   no repetir la inicialización
  }
  // calcular un número de segundos aleatorio, entre {\ttbf smin} y {\ttbf smax}
  const float tsec = smin+(smax-smin)*((float)random()/(float)RAND_MAX);
  // dormir la hebra (los segundos se pasan a microsegundos, multiplicándos por 1 millón)
  usleep( (useconds_t) (tsec*1000000.0)  );
}

// ---------------------------------------------------------------------
// función que simula la producción de un dato

unsigned producir_dato()
{
  static int contador = 0 ;
  contador = contador + 1 ;
  retraso_aleatorio( 0.1, 0.5 );

  cout << "Productor : dato producido: " << contador << endl << flush ;
  sem_post(&mutex);
  return contador ;
}
// ---------------------------------------------------------------------
// función que simula la consumición de un dato

void consumir_dato( int dato )
{
   retraso_aleatorio( 0.1, 1.5 );
   cout << "Consumidor :                        dato consumido: " << dato  << endl << flush ;
}
// ---------------------------------------------------------------------
// función que ejecuta la hebra del productor

void * funcion_productor( void * )
{
  for( unsigned i = 0 ; i < num_items ; i++ )
  {
    int dato = producir_dato() ;

    sem_wait(&puede_escribir);
    sem_wait(&mutex);
    buffer[indice]=dato;
    indice++;
    sem_post(&mutex);
    sem_post(&puede_leer);

    cout << "Productor : dato insertado: " << dato << endl << flush ;
  }
  return NULL ;
}
// ---------------------------------------------------------------------
// función que ejecuta la hebra del consumidor

void * funcion_consumidor( void * )
{
  for( unsigned i = 0 ; i < num_items ; i++ )
  {
    int dato ;

    sem_wait(&puede_leer);
    sem_wait(&mutex);
    indice--;
    dato=buffer[indice];
    sem_post(&mutex);
    sem_post(&puede_escribir);

    cout << "Consumidor :                           dato extraído: " << dato << endl << flush ;
    consumir_dato( dato ) ;
  }
  return NULL ;
}
//----------------------------------------------------------------------

int main()
{

  sem_init(&puede_escribir,0,10); // de primeras se puede escribir
  sem_init(&puede_leer,0,0);  // de primeras no se puede leer
  sem_init(&mutex,0,1); // de primeras se puede mostrar un mensaje

  pthread_t productor,consumidor;
  pthread_create(&productor,NULL,funcion_productor,NULL);
  pthread_create(&consumidor,NULL,funcion_consumidor,NULL);

  pthread_join(productor,NULL);
  pthread_join(consumidor,NULL);

  cout << "FIN" << endl;

  sem_destroy(&puede_escribir);
  sem_destroy(&puede_leer);
  sem_destroy(&mutex);

   return 0 ;
}
