/*

	Este programa recogera un valor de tipo entero de 3 digitos y
	mostrará dichos digitos de manera separada.
	Es decir, si introducimos el 352, mostrara el 3, el 5 y el 2
	por separado.

*/

#include <iostream>
#include <cmath>

using namespace std;

int main(){
	
	int numero,n_1,n_2,n_3;
	const int N_DIEZ=10;
	
	cout << "Introduce un numero de 3 digitos: ";
	cin >> numero;
	
	n_3=numero%N_DIEZ;				// Calcula el tercer digito
	n_2=(numero/N_DIEZ)%N_DIEZ;		// Calcula el segundo digito
	n_1=(numero/N_DIEZ)/N_DIEZ;		// Calcula el primer digito
	
	cout << "El numero " << numero << " esta formado por:   " << n_1 << "   " << n_2 << "   " << n_3;
	
	
}
