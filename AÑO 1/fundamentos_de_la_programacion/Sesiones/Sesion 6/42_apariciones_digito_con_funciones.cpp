/*

¿Cuántas veces aparece el dígito 9 en todos los números
que hay entre el 1 y el 100? Por ejemplo, el 9 aparece una vez en los números 19 y
92 mientras que aparece dos veces en el 99. Pretendemos diseñar un algoritmo que
responda a esta sencilla pregunta, pero de forma suficientemente generalizada. Para
ello, se pide construir un programa que lea una cifra (entre 1 y 9), dos enteros min
y max y calcule el número de apariciones del dígito cifra en los números contenidos
en el intervalo cerrado [min, max].

*/

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

// Funcion que calcula las veces que aparece una cifra en un rango de numeros

int Buscar_cifra(int min,int max,int cifra){
	
	/*	Esta funcion recibe un rango de numeros [min,max] y comproba cuantas n veces aparece una
		cifra mediante el uso de dos bucles anidados. Finalmente devuelve el numero de veces.	
	*/
	
	int c,c1,aux,contador=0;
	bool existe_cifra=false;
	
	c=min;
	if(c==0 && c==cifra){		// Si el minimo es 0 y la cifra a buscar es 0 se aumenta en 1 el contador
		
		contador++;	
		c++;
		
	}
		
	while(c<=max){
		
		c1=c;
		while(c1>0){			//Bucle para descomponer el numero y comprobar si es igual a la cifra a buscar
			
			aux=c1%10;
			if(aux==cifra){
				
				contador++;
				existe_cifra=true;
				
			}
			c1=c1/10;
		}
		c++;
	}
	
	return contador;
	
}

// Funcion encargada de mostrar al usuario los datos que debe de introducir

int Leer_datos(string mensaje){
	
	int dato;
	
	cout << mensaje;
	cin >> dato;
	
	return dato;
		
}

int main(){
	
	const string MAXIMO="Introduce el numero mayor: ",MINIMO="Introduce el numero menor: ",CIFRA="Introduce la cifra a buscar: ";
	int cifra,min,max,contador;
	
	min=Leer_datos(MINIMO);
	max=Leer_datos(MAXIMO);
	cifra=Leer_datos(CIFRA);
	
	contador=Buscar_cifra(min,max,cifra);

	if(contador!=0)
		cout << "El numero " << cifra << " aparace " << contador << " veces desde el " << min << " hasta el " << max;
	else
		cout << "El numero " << cifra << " no aparece ni una vez desde el " << min << " hasta el " << max;
	
}
