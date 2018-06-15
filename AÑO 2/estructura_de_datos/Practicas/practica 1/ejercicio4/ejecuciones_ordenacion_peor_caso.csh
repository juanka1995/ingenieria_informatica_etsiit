#!/bin/csh
@ inicio = 100
@ fin = 30000
@ incremento = 500
@ i = $inicio
echo > tiempos_ordenacion_peor_caso.dat
while ( $i <= $fin )
echo Ejecución tam = $i
echo `./burbuja_peor_caso $i` >> tiempos_ordenacion_peor_caso.dat
@ i += $incremento
end
