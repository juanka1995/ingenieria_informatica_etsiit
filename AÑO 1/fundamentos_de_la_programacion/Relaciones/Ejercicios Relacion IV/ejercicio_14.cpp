/*

La sucesión de Fibonacci de orden n es una secuencia de números en la que los
dos primeros son el 0 y el 1. A partir del tercero, los elementos se calculan como la
suma de los n anteriores, si ya hay n elementos disponibles, o la suma de todos los
anteriores si hay menos de n elementos disponibles.
Por ejemplo, la sucesión de Fibonacci de orden 4 sería la siguiente:
0; 1; 1; 2; 4; 8; 15; 29; : : :
Definid una clase llamada Fibonacci. Para almacenar los enteros, se usará un vector
de enteros. Al constructor se le pasará como parámetro el valor de n. Definid los
siguientes métodos:
 int GetBase() para obtener el valor de n.
 void CalculaPrimeros(int tope) para que calcule los tope primeros
elementos de la sucesión.
 int TotalCalculados() que devuelva cuántos elementos hay actualmente
almacenados (el valor tope del método anterior)
 int k_esimo(int k) para que devuelva el elemento k-ésimo de la sucesión.
Escribid un programa que lea los valores de dos enteros, n y k y calcule, almacene y
muestre por pantalla los k primeros términos de la sucesión de Fibonacci de orden n:
......
Fibonacci fibonacci(n);
fibonacci.CalculaPrimeros(k);
tope = fibonacci.TotalCalculados(); // tope = k
for (int i=0; i<tope; i++)
cout << fibonacci.k_esimo(i) << " ";

*/
#include <iostream>
#include <cmath>

using namespace std;

class Fibonacci{
	private:
		static const int MAX=50;
		int base,vector[MAX],total_utilizados;
	public:
		Fibonacci(int n){
				base=n;
				total_utilizados=2;
				InicializarVector();
		}
		int GetBase(){
			return base;
		}
	// Se encarga de inicializar todo el vector a 0, excepto la posiciones 0 y 1.
		void InicializarVector(){
			vector[0]=0;
			vector[1]=1;
			for(int c=total_utilizados;c<MAX;c++)
				vector[c]=0;
		}
	// Se encarga de calcular la suma de tope elementos con respecto al tamaño de la base.
		void CalcularPrimeros(int tope){
			while(total_utilizados<tope+2){
				if(total_utilizados<base){
					for(int c=total_utilizados;c<base;c++){
						for(int i=0;i<c;i++)
								vector[c]=vector[i]+vector[c];
					total_utilizados++;
					}			
				}	
				else{
					for(int k=total_utilizados;k<tope+2;k++){
						for(int j=k-base;j<k;j++)
								vector[k]=vector[j]+vector[k];
					total_utilizados++;	
					}		
				}	
			}
		}
	// Devuelve el numero de numeros calculados (tope del metodo CalcularPrimeros)
		int TotalCalculados(){
			int contador=0;
			for(int c=2;c<total_utilizados;c++)
				contador++;
			return contador;
		}
	// Devuelve el valor de una posicion concreta del vector.
		int k_esimo(int k){
			return vector[k];
		}
};

int main(){
	
	int base,tope;
	
	cout << "Introduce la base: ";
	cin >> base;
	
	cout << "Introduce el tope: ";
	cin >> tope;
	
	Fibonacci prueba(base);
	
	prueba.CalcularPrimeros(tope);
	
	for(int c=0;c<tope+2;c++)
		cout << prueba.k_esimo(c) << " ";
	
}
