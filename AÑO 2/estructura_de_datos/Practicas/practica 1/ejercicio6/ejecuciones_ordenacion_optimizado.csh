#!/bin/csh
@ inicio = 100
@ fin = 30000
@ incremento = 500
@ i = $inicio
echo > tiempos_ordenacion_optimizado.dat
while ( $i <= $fin )
echo Ejecución tam = $i
echo `./ordenacion_optimizado $i 10000` >> tiempos_ordenacion_optimizado.dat
@ i += $incremento
end
