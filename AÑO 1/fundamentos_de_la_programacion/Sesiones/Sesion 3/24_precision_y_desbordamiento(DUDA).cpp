/*



Indicar si se produce un problema de precisión o de desbordamiento en los siguientes ejemplos indicando cuál sería el resultado final de las operaciones.

Nota. Si se desea ver el contenido de una variable real con cout, es necesario que antes de hacerlo, se establezca el número de decimales
que se quieren mostrar en pantalla. Hacedlo escribiendo la sentencia cout.precision(numero_digitos); en cualquier sitio del programa antes
de la ejecución de cout << real1 << "," << real2;. Hay que destacar que al trabajar con reales siempre debemos asumir representaciones aproximadas por lo
que no podemos pensar que el anterior valor numero_digitos esté indicando un número de decimales con representación exacta.


a) int chico, chico1, chico2;
chico1 = 123456789;
chico2 = 123456780;
chico = chico1 * chico2;



b) long grande;
int chico1, chico2;
chico1 = 123456789;
chico2 = 123456780;
grande = chico1 * chico2;



c) double resultado, real1, real2;
real1 = 123.1;
real2 = 124.2;
resultado = real1 * real2;



d) double resultado, real1, real2;
real1 = 123456789.1;
real2 = 123456789.2;
resultado = real1 * real2;



e) double real, otro_real;
real = 2e34;
otro_real = real + 1;
otro_real = otro_real - real;



f ) double real, otro_real;
real = 1e+300;
otro_real = 1e+200;
otro_real = otro_real * real;



float chico;
double grande;
grande = 2e+150;
chico = grande;




*/

#include <iostream>
#include <cmath>

using namespace std;

int main(){
	
	int chico, chico1, chico2;
	chico1 = 123456789;
	chico2 = 123456780;
	chico = chico1 * chico2;
	
	cout << cout.precision(chico);
	
	cout << "\n" << chico;
	
	
}

