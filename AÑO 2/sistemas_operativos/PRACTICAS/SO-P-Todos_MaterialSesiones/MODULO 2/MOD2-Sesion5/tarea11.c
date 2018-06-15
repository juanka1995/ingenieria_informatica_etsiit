// tarea11.c

#include <stdio.h>
#include <signal.h>

/*
En el siguiente ejemplo se suspende la ejecución del proceso actual hasta que
reciba una señal distinta de SIGUSR1
*/

int main()

{
sigset_t new_mask;

/* inicializar la nueva mascara de se�ales */
sigemptyset(&new_mask);

sigaddset(&new_mask, SIGUSR1);

/*esperar a cualquier se�al excepto SIGUSR1 */
sigsuspend(&new_mask);

}
