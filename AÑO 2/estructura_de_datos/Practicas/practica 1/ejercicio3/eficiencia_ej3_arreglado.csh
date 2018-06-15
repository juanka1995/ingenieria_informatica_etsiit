#!/bin/csh
@ inicio = 50
@ fin = 30000
@ incremento = 100
@ i = $inicio
echo > tiempos_ordenacion_3.dat
while ( $i <= $fin )
echo Ejecución tam = $i
echo `./ejercicio_desc_arreglado $i` >> tiempos_ordenacion_3.dat
@ i += $incremento
end
