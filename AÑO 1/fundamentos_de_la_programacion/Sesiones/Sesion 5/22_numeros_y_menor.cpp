/*

Realizar un programa que lea enteros desde teclado y calcule cuántos se han introducido
y cual es el mínimo de dichos valores (pueden ser positivos o negativos). Se
dejará de leer datos cuando el usuario introduzca el valor 0. Realizad la lectura de
los enteros dentro de un bucle sobre una única variable llamada dato. Es importante
controlar los casos extremos, como por ejemplo, que el primer valor leído fuese ya el
terminador de entrada (en este caso, el cero).

*/

#include <iostream>
#include <cmath>

using namespace std;

int main(){
	
	int dato,menor,contador=0;
	
	cout << "Introduce un numero. (Pulsa 0 para terminar): ";
	cin >> dato;
	menor=dato;
	
	while(dato!=0){
		
		if(dato<menor)
			menor=dato;
			
		cout << "Introduce otro numero. (Pulsa 0 para terminar): ";
		cin >> dato;
		contador++;	
		
	}
	
	if(contador==0)
		cout << "No se ha introducido ningun numero.";
	else
		cout << "\nSe han introducido: " << contador << " numeros.\nEl minimo de los valores introducidos es: " << menor;
	
}
