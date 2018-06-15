// *****************************************************************************
//
// Prácticas de SCD. Práctica 1.
// Plantilla de código para el ejercicio de los fumadores
//
// Alumno: Juan Carlos Ruiz García    Grupo: C2
//
// *****************************************************************************

#include <iostream>
#include <cassert>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>      // incluye "time(....)"
#include <unistd.h>    // incluye "usleep(...)"
#include <stdlib.h>    // incluye "rand(...)" y "srand"

using namespace std ;

int dato_mesa;
sem_t id_sem[4], mutex;
const string INGREDIENTES[3]={"PAPEL","TABACO","CERILLAS"};

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

// ----------------------------------------------------------------------------
// función que simula la acción de fumar, como un retardo aleatorio de la hebra.
// recibe como parámetro el numero de fumador
// el tiempo que tarda en fumar está entre dos y ocho décimas de segundo.

void fumar( int num_fumador )
{
  sem_wait(&mutex);
    cout << "Fumador número " << num_fumador << ": comienza a fumar." << endl << flush ;
  sem_post(&mutex);
  retraso_aleatorio( 0.2, 0.8 );
  sem_wait(&mutex);
    cout << "Fumador número " << num_fumador << ": termina de fumar." << endl << flush ;
  sem_post(&mutex);
}

void * funcion_estanquero(void *){
  while(true){
    sem_wait(&(id_sem[3]));
      dato_mesa = rand()%3;
      sem_wait(&mutex);
      cout << "                                          Suministro producido: " << INGREDIENTES[dato_mesa] << endl;
      sem_post(&mutex);
    sem_post(&(id_sem[dato_mesa]));
  }
}

void * funcion_fumador (void * num_fum_void){
  unsigned long num_fumador = (unsigned long) num_fum_void;
  while(true){
    sem_wait(&mutex);
    cout << "Fumador numero: " << num_fumador << " espera " << INGREDIENTES[num_fumador] << endl;
    sem_post(&mutex);

    sem_wait(&(id_sem[num_fumador]));
    sem_post(&(id_sem[3]));
      fumar( num_fumador );
  }
}

int main()
{
  srand( time(NULL) ); // inicializa semilla aleatoria para selección aleatoria de fumador

  cout << "ESTADO DE LOS FUMADORES: " << endl
       << "   Fumador 0 tiene : TABACO, CERILLAS" << endl
       << "   Fumador 1 tiene : PAPEL, CERILLAS" << endl
       << "   Fumador 2 tiene : TABACO, PAPEL" << endl << endl;

  sem_init(&(id_sem[0]),0,0); //Semaforo fumador 1 (necesita papel)
  sem_init(&(id_sem[1]),0,0); //Semaforo fumador 2 (necesita tabaco)
  sem_init(&(id_sem[2]),0,0); //Semaforo fumador 3 (necesita cerillas)
  sem_init(&(id_sem[3]),0,1); //Semaforo estanquero
  sem_init(&mutex,0,1); //Semaforo para comentarios

  pthread_t id_hebra[4];
  for (unsigned long i = 0; i < 3; i++) {
    void * ih_void = (void *) i;
    pthread_create(&(id_hebra[i]),NULL,funcion_fumador,ih_void);
  }
  pthread_create(&(id_hebra[3]),NULL,funcion_estanquero,NULL);

  pthread_exit(NULL); //Permite continuar al resto de hebras

  for (int i = 0; i < 4; i++) { //Destruir semaforos
    sem_destroy(&(id_sem[i]));
  }
  sem_destroy(&mutex);

  return 0 ;
}
