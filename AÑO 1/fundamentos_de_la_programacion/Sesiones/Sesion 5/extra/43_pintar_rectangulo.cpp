/*

Implemente un programa que sea capaz de �dibujar� rect�ngulos utilizando un s�mbolo
(un car�cter) dado. El usuario ingresar� el s�mbolo simb, la altura M y el ancho N
del rect�ngulo. Por ejemplo, siendo simb =*, M = 3 y N = 5, el dibujo tendr�a la
siguiente forma:

		*****
		*****
		*****

*/

#include <iostream>
#include <cmath>

using namespace std;

int main(){
	
	char simbolo;
	int altura,ancho,c1,c2;
	
	cout << "Introduce la altura del cuadrado: ";
	cin >> altura;
	
	cout << "Introduce el ancho del cuadrado: ";
	cin >> ancho;
	
	cout << "Introduce un simbolo: ";
	cin >> simbolo;
	
	cout << "\n";
	
	for(c1=1;c1<=altura;c1++){
				
		cout << "\t";		
				
		for(c2=1;c2<=ancho;c2++){
			
			cout << simbolo;
			
		}
		
		cout << "\n";
		
	}
	
}
