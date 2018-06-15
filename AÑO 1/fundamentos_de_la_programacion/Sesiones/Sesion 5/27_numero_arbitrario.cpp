/*

En el ejercicio 14 de la Relaci�n de Problemas I se ped�a escribir un programa que leyese
un valor entero de tres d�gitos e imprimiese los d�gitos separados por un espacio
en blanco. Haced lo mismo pero para un n�mero entero arbitrario. Por ejemplo, si el
n�mero es 3519, la salida ser�a:
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
