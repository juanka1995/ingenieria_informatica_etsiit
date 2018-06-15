/*


Queremos modificar el ejercicio 7 para leer un car�cter letra_original desde teclado
y hacer lo siguiente:
	- Si es una letra may�scula, almacenaremos en la variable letra_convertida
la correspondiente letra min�scula.
	- Si es una letra min�scula, almacenaremos en la variable letra_convertida
la correspondiente letra may�scula.
	- Si es un car�cter no alfab�tico, almacenaremos el mismo car�cter en la variable
letra_convertida
El programa debe imprimir en pantalla el valor de letra_convertida e indicar si la
letra introducida era una min�scula, may�scula o no era una car�cter alfab�tico. No
pueden usarse las funciones tolower ni toupper de la biblioteca cctype.


*/

#include <iostream>
#include <cmath>

using namespace std;

int main(){
	
	char letra_original,letra_convertida;
	int numero_letra,diferencia='a'-'A'; 			//Calcula la diferencia de posicion entre una letra mayuscula y su minuscula segun la tabla ASCII
	
	cout << "Introduce la letra original: ";
	cin >> letra_original;
	numero_letra=letra_original;
	
	if(letra_original>='A' && letra_original<='z'){		//limita al usuario para que introduzca un valor alfetico
		if(numero_letra>'Z'){
		
		letra_convertida=numero_letra-diferencia;
		cout << "La letra original era la "<< letra_original << " minuscula y su mayuscula es la: " << letra_convertida;
		
		}
		else if (numero_letra<'a'){
			
			letra_convertida=numero_letra+diferencia;
			cout << "La letra original era la " << letra_original << " mayuscula y su minuscula es la: " << letra_convertida;
			
		}
	}
	else{
		
		letra_convertida=letra_original;
		cout << letra_convertida << " no es un caracter alfabetico.";
		
	}
	
}
