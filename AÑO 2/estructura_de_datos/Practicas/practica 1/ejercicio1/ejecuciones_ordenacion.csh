#!/bin/csh
@ inicio = 100
@ fin = 30000
@ incremento = 500
@ i = $inicio
echo > tiempos_ordenacion.dat
while ( $i <= $fin )
echo Ejecución tam = $i
echo `./ordenacion $i 10000` >> tiempos_ordenacion.dat
@ i += $incremento
end
