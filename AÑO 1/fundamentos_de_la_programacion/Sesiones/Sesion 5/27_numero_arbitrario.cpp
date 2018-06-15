/*

En el ejercicio 14 de la Relación de Problemas I se pedía escribir un programa que leyese
un valor entero de tres dígitos e imprimiese los dígitos separados por un espacio
en blanco. Haced lo mismo pero para un número entero arbitrario. Por ejemplo, si el
número es 3519, la salida sería:
3 5 1 9

*/

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main(){

	string num,num_final;
	int dato,aux;
	
	cout << "Introduce un numero: ";
	cin >> dato;
	
	while(dato/10>0){
		
		aux=dato%10;
		num=to_string(aux);					//Paso el resto a tipo string y lo almaceno en una variable
		num_final=num+"\t"+num_final;		//Guardo los restos anteriores en otra variable de tipo string y los voy separando con una tabulacion
		dato=dato/10;
		
	}
	
		cout << dato << "\t" << num_final;		//Muestro el primer digito seguido de la variable string creada anteriormente con el resto de digitos separados por tabulacion
	
}
