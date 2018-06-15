#include <iostream>
#include <time.h>      // incluye "time"
#include <unistd.h>    // incluye "usleep"
#include <stdlib.h>    // incluye "rand" y "srand"
#include <mpi.h>

using namespace std;

int RANK_CAMARERO = 10;
int ETQ_SENTARSE = 11;
int ETQ_LEVANTARSE = 12;

void Filosofo( int id, int nprocesos);
void Tenedor ( int id, int nprocesos);
void Camarero();

// ---------------------------------------------------------------------

int main( int argc, char** argv )
{
   int rank, size;

   srand(time(0));
   MPI_Init( &argc, &argv );
   MPI_Comm_rank( MPI_COMM_WORLD, &rank );
   MPI_Comm_size( MPI_COMM_WORLD, &size );

   if( size!=11)
   {
      if( rank == 0)
         cout<<"El numero de procesos debe ser 11" << endl << flush ;
      MPI_Finalize( );
      return 0;
   }

   if (rank == RANK_CAMARERO)
    Camarero();
   else if((rank%2) == 0)
    Filosofo(rank,size-1); // Los pares son Filosofos
   else
    Tenedor(rank,size-1);  // Los impares son Tenedores

   MPI_Finalize( );
   return 0;
}
// ---------------------------------------------------------------------

void Camarero(){
  int asientos_libres = 4;
  int buf;
  MPI_Status status;

  while (true) {
    if (asientos_libres == 0) {
      MPI_Recv(&buf,1,MPI_INT,MPI_ANY_SOURCE,ETQ_LEVANTARSE,MPI_COMM_WORLD,&status);
      cout << "Filosofo " << status.MPI_SOURCE << " se levanta de la mesa." << endl << flush;
      asientos_libres++;
    }
    else{
      MPI_Recv(&buf,1,MPI_INT,MPI_ANY_SOURCE,MPI_ANY_TAG,MPI_COMM_WORLD,&status);
      if (status.MPI_TAG == ETQ_LEVANTARSE){
        cout << "Filosofo " << status.MPI_SOURCE << " se levanta de la mesa." << endl << flush;
        asientos_libres++;
      }else{
        cout << "Filosofo " << status.MPI_SOURCE << " se sienta en la mesa." << endl << flush;
        asientos_libres--;
      }
    }
    cout << "Hay " << asientos_libres << " asientos libres en la mesa." << endl << flush;
  }
}

void Filosofo( int id, int nprocesos )
{
   int buf;
   int izq = (id+1) % nprocesos;
   int der = ((id+nprocesos)-1) % nprocesos;

   while(1)
   {
      // Solicita sentarse en la mensaje
      cout << "Filosofo "<<id<< " solicita sentarse al camarero..." << endl << flush;
      // ...
      MPI_Ssend(&buf,1,MPI_INT,RANK_CAMARERO,ETQ_SENTARSE,MPI_COMM_WORLD);

      // Solicita tenedor izquierdo
      cout << "Filosofo "<<id<< " solicita tenedor izq ..." << izq << endl << flush;
      // ...
      MPI_Ssend(&buf,1,MPI_INT,izq,0,MPI_COMM_WORLD);

      // Solicita tenedor derecho
      cout <<"Filosofo "<<id<< " solicita tenedor der ..." << der << endl << flush;
      // ...
      MPI_Ssend(&buf,1,MPI_INT,der,0,MPI_COMM_WORLD);

      cout<<"Filosofo "<<id<< " COMIENDO"<<endl<<flush;
      sleep((rand() % 3)+1);  //comiendo

      // Suelta el tenedor izquierdo
      cout <<"Filosofo "<<id<< " suelta tenedor izq ..." << izq << endl << flush;
      // ...
      MPI_Ssend(&buf,1,MPI_INT,izq,1,MPI_COMM_WORLD);

      // Suelta el tenedor derecho
      cout <<"Filosofo "<<id<< " suelta tenedor der ..." << der << endl << flush;
      // ...
      MPI_Ssend(&buf,1,MPI_INT,der,1,MPI_COMM_WORLD);

      // Solicita levantarse de la mesa al Camarero
      cout <<"Filosofo "<<id<< " solicita levantarse al camarero ..." << endl << flush;
      // ...
      MPI_Ssend(&buf,1,MPI_INT,RANK_CAMARERO,ETQ_LEVANTARSE,MPI_COMM_WORLD);

      // Piensa (espera bloqueada aleatorio del proceso)
      cout << "Filosofo " << id << " PENSANDO" << endl << flush;

      // espera bloqueado durante un intervalo de tiempo aleatorio
      // (entre una décima de segundo y un segundo)
      usleep( 1000U * (100U+(rand()%900U)) );
 }
}
// ---------------------------------------------------------------------

void Tenedor(int id, int nprocesos)
{
  int buf;
  MPI_Status status;
  int Filo;

  while( true )
  {
    // Espera un peticion desde cualquier filosofo vecino ...
    // ...
    MPI_Recv(&buf,1,MPI_INT,MPI_ANY_SOURCE,0,MPI_COMM_WORLD,&status);

    // Recibe la peticion del filosofo ...
    // ...
    Filo = status.MPI_SOURCE;
    cout << "Ten. " << id << " recibe petic. de " << Filo << endl << flush;

    // Espera a que el filosofo suelte el tenedor...
    // ...
    MPI_Recv(&buf,1,MPI_INT,Filo,1,MPI_COMM_WORLD,&status);

    cout << "Ten. " << id << " recibe liberac. de " << Filo << endl << flush;
  }
}
// ---------------------------------------------------------------------
