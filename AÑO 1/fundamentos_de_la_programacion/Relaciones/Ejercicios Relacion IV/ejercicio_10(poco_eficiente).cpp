/*

En este ejercicio no hay que definir ninguna clase. Todas las operaciones se realizan
directamente en el main.
Construya un programa que vaya leyendo caracteres hasta que se encuentre un punto
'.' y cuente el n�mero de veces que aparece cada una de las letras may�sculas.
Imprimir el resultado.
Una posibilidad ser�a declarar un vector contador_mayusculas con tantas componentes
como letras may�sculas hay ('Z'-'A'+1) y conforme se va leyendo cada
car�cter, ejecutar lo siguiente:
cin >> letra;
if (letra == 'A')
contador_mayusculas[0] = contador_mayusculas[0] + 1;
else if (letra == 'B')
contador_mayusculas[1] = contador_mayusculas[1] + 1;
else if (letra == 'C')
contador_mayusculas[2] = contador_mayusculas[2] + 1;
else ....
Sin embargo, este c�digo es muy redundante. Como soluci�n se propone calcular de
forma directa el �ndice entero que le corresponde a cada may�scula, de forma que
todos los if-else anteriores los podamos resumir en una �nica sentencia del tipo:
contador_mayusculas[indice] = contador_mayusculas[indice] + 1;
Hacedlo, declarando el vector directamente dentro del main.

*/
#include <iostream>
#include <cmath>

using namespace std;

int main(){
	
	const string MENSAJE="Introduce un caracter: ";
	char vector[50],caracter;
	int total_utilizados=0,contador=1;
	
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
	
	for(int c=0;c<total_utilizados;c++){
		if(isupper(vector[c])){
			for(int i=c+1;i<total_utilizados;i++)
				if(vector[i]==vector[c]){
					contador++;
					for(int j=i;j<total_utilizados;j++)
						vector[j]=vector[j+1];
					total_utilizados--;
				}
					
			cout << "\nLa letra " << vector[c] << " esta repetida " << contador << " veces.";
			contador=1;
		}
	}
	
}
