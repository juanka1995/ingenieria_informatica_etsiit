#!/bin/csh
@ inicio = 100
@ fin = 30000
@ incremento = 500
@ i = $inicio
echo > tiempos_ordenacion_mejor_caso.dat
while ( $i <= $fin )
echo Ejecución tam = $i
echo `./burbuja_mejor_caso $i` >> tiempos_ordenacion_mejor_caso.dat
@ i += $incremento
end
