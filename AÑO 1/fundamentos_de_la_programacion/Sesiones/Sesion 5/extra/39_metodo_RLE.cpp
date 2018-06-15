/*

El método RLE (Run Length Encoding) codifica una secuencia de datos formada por
series de valores idénticos consecutivos como una secuencia de parejas de números
(valor de la secuencia y número de veces que se repite). Esta codificación es un
mecanismo de compresión de datos (zip) sin pérdidas. Se aplica, por ejemplo, para
comprimir los ficheros de imágenes en las que hay zonas con los mismos datos (fondo
blanco, por ejemplo). Realizar un programa que lea una secuencia de números
naturales terminada con un número negativo y la codifique mediante el método RLE.

Entrada: 1 1 1 2 2 2 2 2 3 3 3 3 3 3 5 -1
(tres veces 1, cinco veces 2, seis veces 3, una vez 5)
Salida: 3 1 5 2 6 3 1 5

*/

#include <iostream>
#include <string>

using namespace std;

int main(){
	
	const string MENSAJE=" Introduce un numero natural (termina con un numero negativo): ";
	int num,n_int=0,contador=0;
	string resultado,veces,numero;
	
	cout << MENSAJE;
	cin >> num;
			
	n_int=num; 
	
	while(num>0){		//Pregunta al usuario que introduzca un numero hasta que sea 0 o negativo
		
		if(num==n_int)
			contador++;		//Aumento el contador mientras el numero introducido sea igual que el anterior
		else{
											//Cuanto el numero introducido no sea igual que el anterior, guardo el valor de contador y del numero
			veces=to_string(contador);		//buscado, reinicio el contador y cambio el numero a buscar ahora.	
			numero=to_string(n_int);
			contador=1;
			n_int=num;
			resultado=resultado+" "+veces+" "+numero;
			
		}
		
		cout << MENSAJE;
		cin >> num;
		
	}
	
	if(contador!=0){
										//Almaceno de nuevo el ultimo numero introducido y las veces que se a repetido, para finalmente mostrar
		veces=to_string(contador);		//mostrar el resultado.	
		numero=to_string(n_int);
		resultado=resultado+" "+veces+" "+numero;
		
		cout << resultado;
	
	}
	else
		cout << "No has introducido una secuencia de numeros enteros";

}
