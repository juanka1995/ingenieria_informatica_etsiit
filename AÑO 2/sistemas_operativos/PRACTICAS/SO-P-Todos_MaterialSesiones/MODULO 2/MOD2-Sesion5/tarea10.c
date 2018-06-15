// tarea10.c

#include <stdio.h>
#include <signal.h>

static int s_recibida=0;
static void handler (int signum){
  printf("\n Accion %d del manejador \n",s_recibida+1);
  s_recibida++;
}

int main()
{
  // Creo la estructura sigaction
  struct sigaction sa;
  // Le indico la accion que le voy a asociar
  // que en este caso es la ejecución de la funciones
  // handler
  sa.sa_handler = handler; // ignora la se�al
  // Inicializo a vacío el conjunto de señales
  sigemptyset(&sa.sa_mask);

  //Reiniciar las funciones que hayan sido interrumpidas por un manejador
  sa.sa_flags = SA_RESTART;

  // Cambio la accion SIGINT (Ctrl + C) por la señal sa
  if (sigaction(SIGINT, &sa, NULL) == -1)
  {
  printf("error en el manejador");}
  while(s_recibida<3); //Bucle 3 veces
}
