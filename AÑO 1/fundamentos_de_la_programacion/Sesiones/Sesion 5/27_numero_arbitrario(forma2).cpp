/*

En el ejercicio 14 de la Relaci�n de Problemas I se ped�a escribir un programa que leyese
un valor entero de tres d�gitos e imprimiese los d�gitos separados por un espacio
en blanco. Haced lo mismo pero para un n�mero entero arbitrario. Por ejemplo, si el
n�mero es 3519, la salida ser�a:
3 5 1 9

*/

#include <iostream>
#include <cmath>

using namespace std;

int main(){

	int dato,contador=1,aux,divisor,resto,mostrar;

	cout << "Introduce un numero: ";
	cin >> dato;
	aux=dato;
	
	while(aux/10>0){
		
		aux=aux/10;
		contador++;
		
	}
	
	while(contador>=1){
		
		divisor=pow(10,contador-1);		// Calculo la potencia de 10 por la que debemos dividir nuestro dato
		contador--;
		aux=dato;
		mostrar=aux/divisor;			// Calculamos el digito que debemos de mostrar dividiendolo
		cout << mostrar << "\t";
		dato=dato%divisor;				// Sacamos el resto de digitos de izquierda a derecha
		
	}
	
}
