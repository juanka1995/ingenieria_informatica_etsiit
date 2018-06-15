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

using namespace std;

int main(){
	
	int cifra,min,max,contador=0,c,c1,aux;
	bool existe_cifra=false;
	
	cout << "Introduce un rango de dos numeros (Ej. 22 4568): ";
	cin >> min;
	cin >> max;
	
	cout << "Introduce la cifra a buscar: ";
	cin >> cifra;
	
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

	if(existe_cifra)
		cout << "El numero " << cifra << " aparace " << contador << " veces desde el " << min << " hasta el " << max;
	else
		cout << "El numero " << cifra << " no aparece ni una vez desde el " << min << " hasta el " << max;
	
}
