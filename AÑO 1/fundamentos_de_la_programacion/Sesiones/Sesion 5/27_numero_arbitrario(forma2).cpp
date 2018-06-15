/*

En el ejercicio 14 de la Relación de Problemas I se pedía escribir un programa que leyese
un valor entero de tres dígitos e imprimiese los dígitos separados por un espacio
en blanco. Haced lo mismo pero para un número entero arbitrario. Por ejemplo, si el
número es 3519, la salida sería:
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
