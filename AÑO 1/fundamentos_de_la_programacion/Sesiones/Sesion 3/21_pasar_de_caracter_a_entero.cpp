/*

Supongamos el siguiente c�digo:
	int entero;
	char caracter;
	caracter = '7';
	entero = caracter;
	
La variable entero almacenar� el valor 55 (el orden en la tabla ASCII del car�cter
'7'). Queremos construir una expresi�n que devuelva el entero 7, para asignarlo a la
variable entero. Formalmente:
Supongamos una variable car de tipo car�cter que contiene un valor entre '0' y '9'.
Construid un programa que obtenga el correspondiente valor entero, se lo asigne a
una variable de tipo int llamada entero y lo imprima en pantalla. Por ejemplo, si la
variable car contiene '7' queremos asignarle a entero el valor num�rico 7.
Nota. La comilla simple para representar un literal de car�cter es la que hay en el
teclado del ordenador debajo de la interrogaci�n ?.

*/

#include <iostream>
#include <cmath>

using namespace std;

int main(){
	
	const int NUM_ASCII=48;
	char car;
	int entero;
	
	cout << "Introduce un numero del 0 - 9: ";
	cin >> car;
	
	entero=car-NUM_ASCII;
	
	cout << "El valor de tipo caracter'" << car << "' en tipo entero es de: " << entero;	
	
}
