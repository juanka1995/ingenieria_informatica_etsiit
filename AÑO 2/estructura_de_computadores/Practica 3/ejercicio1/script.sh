#!/bin/bash
#$1 nombre fichero de entrada (ejecutable)
#$2 nombre fichero de salida (destino)
for i in $(seq 10)
do
	./$1 | cut -f3 | tr -d "^us" | tr -d " " >> $2
	printf "\n" >> $2
done
