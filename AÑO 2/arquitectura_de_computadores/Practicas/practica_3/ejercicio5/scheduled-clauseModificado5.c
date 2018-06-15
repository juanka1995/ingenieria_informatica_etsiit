#include <stdio.h>
#include <stdlib.h>
#ifdef _OPENMP
  #include <omp.h>
#else
   #define omp_get_thread_num() 0
#endif

int main(int argc, char **argv) {
  int i, n=200,chunk,a[n],suma=0;
  omp_sched_t kind;
  int modifier;
   if(argc < 3)     {
      fprintf(stderr,"\nFalta iteraciones o chunk \n");
      exit(-1);
     }
   n = atoi(argv[1]); if (n>200) n=200; chunk = atoi(argv[2]);

   for (i=0; i<n; i++)       a[i] = i;

   // Antes de modificar
   omp_get_schedule(&kind, &modifier);
   printf("Antes de modificar:\n\tdyn-var: %d\n\tnthreads-var: %d\n\trun-sched-var:\n\tkind: %d\n\tmodifier: %d\n",omp_get_dynamic(),omp_get_max_threads(),kind,modifier);

   // static = 1 ; dynmic = 2 ; guided = 3 ; auto = 4

   // Realizamos los cambios
   omp_set_dynamic(3);
   omp_set_num_threads(8);
   omp_set_schedule(3,2);

   // Despues de modificar
   omp_get_schedule(&kind, &modifier);
   printf("\nDespues de modificar:\n\tdyn-var: %d\n\tnthreads-var: %d\n\trun-sched-var:\n\tkind: %d\n\tmodifier: %d\n\n",omp_get_dynamic(),omp_get_max_threads(),kind,modifier);

   #pragma omp parallel for firstprivate(suma) \
            lastprivate(suma) schedule(dynamic,chunk)
   for (i=0; i<n; i++)
   {   suma = suma + a[i];
       printf(" thread %d suma a[%d]=%d suma=%d \n",
             omp_get_thread_num(),i,a[i],suma);
   }

   printf("Fuera de 'parallel for' suma=%d\n",suma);

   return(0);
}
