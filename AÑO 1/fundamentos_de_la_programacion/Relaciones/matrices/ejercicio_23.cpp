/*

(Examen Septiembre 2011) La posición de aquel elemento que sea el mayor de
entre los mínimos de cada fila. Por ejemplo, dada la matrizM (3  4),
9 7 4 5
2 18 2 12
7 9 1 5
el máximo entre 4, 2 y 1 (los mínimos de cada fila) es 4 y se encuentra en la
posición (0; 2).

*/
#include <iostream>
#include <cmath>

using namespace std;

int main(){
	
	const int MAX_FIL=3,MAX_COL=4;
	int matriz[MAX_FIL][MAX_COL],matriz_aux[2][MAX_FIL],max=0,valor;
	
	for(int c=0;c<MAX_FIL;c++)
		for(int i=0;i<MAX_COL;i++){
			cout << "Introduce el valor para la posicion " << c << " " << i << ": ";
			cin >> valor;
			while(valor<0){
				cout << "Introduce el valor para la posicion " << c << " " << i << ": ";
				cin >> valor;
			}
			matriz[c][i]=valor;
		}	
		
	for(int i=0;i<MAX_FIL;i++)
		for(int j=0;j<MAX_COL;j++)
			if(matriz[i][j]>max){
				max=matriz[i][j];
				matriz_aux[0][c]=i;
				matriz_aux[1][c]=j;
			}
		max=0;//por qeui
		
	cout << "\n";
	
	for(int c=0;c<MAX_FIL;c++){
		for(int i=0;i<MAX_COL;i++)
			cout << matriz[c][i] << " ";
		cout << "\n";
	}
		
}
