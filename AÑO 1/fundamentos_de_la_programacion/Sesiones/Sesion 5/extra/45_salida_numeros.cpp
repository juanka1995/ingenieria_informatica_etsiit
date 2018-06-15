/*

Cread un programa que ofrezca en pantalla la siguiente salida:
1 2 3 4 5 6
2 3 4 5 6
3 4 5 6
4 5 6
5 6
6

*/

#include <iostream>


using namespace std;

	void Salida(int inicio, int tope){
		
		int c1;
			
			for(c1=inicio;c1<=tope;c1++)
				cout << c1 << " ";					//Funcion que muestra el numero desde el inicio hasta el tope
		
	}

int main(){
	
	int tope,c;
	
	cout << "Introduce el numero tope: ";
	cin >> tope;
	
	for(c=1;c<=tope;c++){
		
		Salida(c,tope);				//Llamamos a la funcion Salida c veces
		cout << "\n";
	
	}
	
}
