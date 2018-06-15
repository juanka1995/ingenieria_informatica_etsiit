// tarea11.c

#include <stdio.h>
#include <signal.h>

/*
Escribe un programa que suspenda la ejecución del proceso actual hasta que se
reciba la señal SIGUSR1.
*/
int main()

{
sigset_t new_mask;

/* inicializar la nueva mascara de se�ales */
sigfillset(&new_mask);

sigdelset(&new_mask, SIGUSR1);

/*esperar a cualquier se�al excepto SIGUSR1 */
sigsuspend(&new_mask);

}
