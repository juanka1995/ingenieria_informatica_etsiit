// tarea9.c

#include <stdio.h>
#include <signal.h>

int main()
{
  // Creo la estructura sigaction
  struct sigaction sa;
  // Le indico la accion que le voy a asociar
  sa.sa_handler = SIG_IGN; // ignora la se�al
  // Inicializo a vacío el conjunto de señales
  sigemptyset(&sa.sa_mask);

  //Reiniciar las funciones que hayan sido interrumpidas por un manejador
  sa.sa_flags = SA_RESTART;

  // Cambio la accion SIGINT (Ctrl + C) por la señal sa
  if (sigaction(SIGINT, &sa, NULL) == -1)
  { printf("error en el manejador");}
  while(1); // Bucle infinito
}
