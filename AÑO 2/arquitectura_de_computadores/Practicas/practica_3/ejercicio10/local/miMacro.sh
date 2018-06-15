#!/bin/bash

tamanio1=350
tamanio2=950

salida1="tamaño350.dat"
salida2="tamaño950.dat"

rm -f salida1 salida2

echo -e "TAMAÑO $tamanio1:" >> $salida1
for ((N=1;N<5;N=N+1))
do
  export OMP_NUM_THREADS=$N
  echo -e "\nNº hebras: $N\n" >> $salida1
  ./ejercicio10 $tamanio1 >> $salida1
done

echo -e "TAMAÑO $tamanio2:" >> $salida2
for ((N=1;N<5;N=N+1))
do
  export OMP_NUM_THREADS=$N
  echo -e "\nNº hebras: $N\n" >> $salida2
  ./ejercicio10 $tamanio2 >> $salida2
done
