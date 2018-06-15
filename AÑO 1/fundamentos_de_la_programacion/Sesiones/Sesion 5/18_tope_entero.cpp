/*

Realizar un programa que lea desde teclado un entero tope e imprima en pantalla todos
sus divisores propios. Para obtener los divisores, basta recorrer todos los enteros
menores que el valor introducido y comprobar si lo dividen. A continuación, mejorar el
ejercicio obligando al usuario a introducir un entero positivo, usando un filtro con un
bucle post test (do while).

*/

#include <iostream>
#include <cmath>

using namespace std;

int main(){
	
	int tope,divisor=1,c=1;
	
	cout << "DIVISORES DE UN NUMERO\n\n";
	
	do{
	
		cout << "Introduce un numero entero positivo: ";			//Valida que el numero introducido sea un numero entero positivo
		cin >> tope;
		
	}while(tope<=0);
	
	while (c<=tope){
		
		if(tope%divisor==0)
			cout << "El numero " << divisor << " es divisor de " << tope << "\n";		// Muestra los divisores del numero introducido antes
		c++;
		divisor++;
		
	}
}
