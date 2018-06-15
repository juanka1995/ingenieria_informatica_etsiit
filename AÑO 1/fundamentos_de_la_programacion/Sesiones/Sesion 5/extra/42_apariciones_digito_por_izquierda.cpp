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
	
	int cifra,min,max,num_cifras,aux1,aux2,aux3,divisor,comparar,contador;
	bool existe_cifra=false;
	
	cout << "Introduce un rango de dos numeros (Ej. 22 4568): ";
	cin >> min;
	cin >> max;
	
	cout << "Introduce la cifra a buscar: ";
	cin >> cifra;
	
	aux1=min;
	
	while(aux1<=max){
		
		num_cifras=1;
		aux2=aux1;
		while(aux2/10>0){
			
			aux2=aux2/10;
			num_cifras++;
			
		}
		
		aux3=aux1;
		
		while(num_cifras>=1){
			
			divisor=pow(10,num_cifras-1);
			num_cifras--;
			aux2=aux3;
			comparar=aux2/divisor;
			if(comparar==cifra){
				
				existe_cifra=true;
				contador++;
				
			}
			aux3=aux3%divisor;
			
		}
		
		aux1++;
		
	}
	
	if(existe_cifra)
		cout << "El numero " << cifra << " aparace " << contador << " veces desde el " << min << " hasta el " << max;
	else
		cout << "El numero " << cifra << " no aparece ni una vez desde el " << min << " hasta el " << max;
	
}
