/*

En este ejercicio no hay que definir ninguna clase. Todas las operaciones se realizan
directamente en el main.
Construya un programa que vaya leyendo caracteres hasta que se encuentre un punto
'.' y cuente el número de veces que aparece cada una de las letras mayúsculas.
Imprimir el resultado.
Una posibilidad sería declarar un vector contador_mayusculas con tantas componentes
como letras mayúsculas hay ('Z'-'A'+1) y conforme se va leyendo cada
carácter, ejecutar lo siguiente:
cin >> letra;
if (letra == 'A')
contador_mayusculas[0] = contador_mayusculas[0] + 1;
else if (letra == 'B')
contador_mayusculas[1] = contador_mayusculas[1] + 1;
else if (letra == 'C')
contador_mayusculas[2] = contador_mayusculas[2] + 1;
else ....
Sin embargo, este código es muy redundante. Como solución se propone calcular de
forma directa el índice entero que le corresponde a cada mayúscula, de forma que
todos los if-else anteriores los podamos resumir en una única sentencia del tipo:
contador_mayusculas[indice] = contador_mayusculas[indice] + 1;
Hacedlo, declarando el vector directamente dentro del main.

*/
#include <iostream>
#include <cmath>
#include <cctype>

using namespace std;

int main(){
	
	const int MAX_MAY='Z'-'A'+1;
	const string MENSAJE="Introduce un caracter: ";
	char vector[50],caracter;
	int contador_mayusculas[MAX_MAY],total_utilizados=0;
	
	cout << MENSAJE;
	caracter=cin.get();
	
	while(caracter!='.'){
		if(caracter!='\n'){
			vector[total_utilizados]=caracter;
			total_utilizados++;
		}	
		cout << MENSAJE;
		caracter=cin.get();
	}
	
	// Inicializamos el vector auxiliar entero a 0
	for(int c=0;c<MAX_MAY;c++){
		contador_mayusculas[c]=0;
	}
	
	for(int j=0;j<total_utilizados;j++)
		if(isupper(vector[j]))
			contador_mayusculas[vector[j]-'A']++;
	
	for(int c=0;c<MAX_MAY;c++){
		if(contador_mayusculas[c]!=0){
			caracter=c+'A';
			cout << "\nLa letra " << caracter << " se ha repetido " << contador_mayusculas[c] << " veces.";	
		}	
	}
	
}
