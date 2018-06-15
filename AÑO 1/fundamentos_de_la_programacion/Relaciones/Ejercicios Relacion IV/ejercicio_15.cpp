/*

(Examen Septiembre 2012) La criba de Eratóstenes (Cirene, 276 a. C. Alejandría,
194 a. C.) es un algoritmo que permite hallar todos los números primos menores que
un número natural dado n.
El procedimiento consiste en escribir todos los números naturales comprendidos entre
2 y n y tachar los números que no son primos de la siguiente manera: el primero (el 2)
se declara primo y se tachan todos sus múltiplos; se busca el siguiente número entero
que no ha sido tachado, se declara primo y se procede a tachar todos sus múltiplos, y
así sucesivamente. El proceso para cuando el cuadrado del número entero es mayor
o igual que el valor de n.
El programa debe definir una clase llamada Eratostenes que tendrá tres métodos:
 void CalculaHasta(int n) para que calcule los primos menores que n.
Este es el método que implementa el algoritmo de Eratóstenes. Cuando se ejecute
el método, se almacenarán en un vector interno del objeto todos los primos
menores que n. Debe implementarse tal y como se ha indicado anteriormente,
por lo que tendrá que decidir, por ejemplo, cómo gestiona el tachado de los números.
 int TotalCalculados() que devuelva cuántos primos hay actualmente almacenados.
 int k_esimo(int k) para que devuelva el k-ésimo primo.
El programa principal quedaría de la forma:
Eratostenes primos;
int n = 100; int num_primos;
primos.CalculaHasta(n);
num_primos = primos.TotalCalculados();
for (int i=0; i<num_primos; i++)
cout << primos.k_esimo(i) << " ";

*/
#include <iostream>
#include <cmath>

using namespace std;

class Eratostenes{
	private:
		static const int MAX=1000;
		int vector[MAX],total_utilizados,vector_aux[MAX];
	public:
		Eratostenes(){
			total_utilizados=0;
		}
	// Este metodo se encarga de inicializar el vector principal desde 2 a limite, y de inicializar el vector auxiliar todo a 1.
		void RellenarVectores(int limite){
			int num=2;
			for(int c=0;c<limite-1;c++){
				vector[c]=num;
				vector_aux[c]=1;
				num++;
				total_utilizados++;
			}
		}
		void CalculaHasta(int n){
		// Llamo al metodo RellenarVectores para inicializar el vector principal y el auxiliar
			RellenarVectores(n);
		// Recorremos el vector_principal en busca de los multiplos del numero c, y vamos tachando (poniendo a 0 en el segundo vector)
		// dichos multiplos hasta que recorramos el vector completamente.
			for(int c=0;c<total_utilizados;c++)
				if(vector_aux[c]==1)
					for(int i=c+1;i<total_utilizados;i++)
						if(vector[i]%vector[c]==0)
							vector_aux[i]=0;
		}
	// Este metodo se encarga de devolver el numero de numeros primos que existen entre 2 y n.
		int Total_Calculados(){
			int n_primos=0;
			for(int c=0;c<total_utilizados;c++)
				if(vector_aux[c]==1)
					n_primos++;
			return n_primos++;
		}
	// Este metodo devuelve el valor k-esimo de los numeros primos.
		int k_esimo(int k){
			int contador=0;
			for(int c=0;c<total_utilizados;c++)
				if(vector_aux[c]==1){
					if(contador==k){
						return vector[c];
						break;	
					}
					contador++;	
				}
		}
		void MostrarVectores(){
			for(int c=0;c<total_utilizados;c++)
				cout << vector[c] << " ";
			cout << "\n";
			for(int i=0;i<total_utilizados;i++)
				cout << vector_aux[i] << " ";
		}
};

int main(){
		
	Eratostenes primos;
	int n=100,num_primos;
	
	primos.CalculaHasta(n);

	num_primos=primos.Total_Calculados();
	
	for (int i=0; i<num_primos; i++)
		cout << primos.k_esimo(i) << " ";
	
}
