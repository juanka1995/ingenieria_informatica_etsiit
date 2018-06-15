/*

Escriba un programa que rellene una matriz de dimension MAX_FIL x MAX_COL con
números pares, lea del usuario una posición (i,j) y muestre por pantalla el valor
de dicha posición. Nótese que es necesario controlar la posición introducida por el
usuario.

*/
#include <iostream>
#include <cmath>

using namespace std;

int main(){
	
	const int MAX_FIL=2,MAX_COL=3;
	int matriz[MAX_FIL][MAX_COL],valor,pos_i,pos_j;
	
	for(int c=0;c<MAX_FIL;c++)
		for(int i=0;i<MAX_COL;i++){
			cout << "Introduce el valor para la posicion " << c << " " << i << ": ";
			cin >> valor;
			while(valor%2!=0){
				cout << "Introduce el valor para la posicion " << c << " " << i << ": ";
				cin >> valor;
			}
			matriz[c][i]=valor;
		}	
		
	cout << "\nIntroduce la posicion a buscar (i j): ";
	cin >> pos_i;
	cin >> pos_j;
	while((pos_i < 0 || pos_i >= MAX_FIL) || (pos_j < 0 || pos_j >= MAX_COL)){
		cout << "\nIntroduce la posicion a buscar (i j): ";
		cin >> pos_i;
		cin >> pos_j;
	}
	
	cout << "El valor de la posicion " << pos_i << " " << pos_j << " es: " << matriz[pos_i][pos_j];
		
	cout << "\n";
	
	for(int c=0;c<MAX_FIL;c++){
		for(int i=0;i<MAX_COL;i++)
			cout << matriz[c][i] << " ";
		cout << "\n";
	}
		
}
