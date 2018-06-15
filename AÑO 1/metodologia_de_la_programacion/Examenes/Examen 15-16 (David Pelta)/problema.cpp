/**
**COMPLETAR**
NOMBRE Y APELLIDOS:
DNI:
Examen de laboratorio
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;


/**
@brief Imprime el contenido de un vector de string
@param v 	Vector de string
@param n	Numero de elementos que contiene @a v
*/
void imprimirVector(string v[], int n)  {
	cout << n << " elementos" << endl;
	for (int i=0; i<n; i++)
		cout << "["<<i<<"] = " << v[i] << endl;
}

int main()  {
	string *A, *B, *Resultado;
	int elemA, elemB, elemResultado=0;
	ifstream FichA, FichB;

	/// Examen: Leer fichero en vector A
	FichA.open("fA.txt");
	FichA >> elemA;
	A=new string[elemA];
	for(int i=0;i<elemA;i++)
		FichA >> A[i];
	FichA.close();
	imprimirVector(A, elemA);

	/// Examen: Leer fichero en vector B
	FichB.open("fB.txt");
	FichB >> elemB;
	B=new string[elemB];
	for(int i=0;i<elemB;i++)
		FichB >> B[i];
	FichB.close();
	imprimirVector(B, elemB);

	/// Examen: Calcular resultado
	for(int i=0;i<elemB;i++){
		for(int j=0;j<elemA;j++)
			if(B[i]==A[j])
				elemResultado++;
	}
	Resultado=new string[elemResultado];
	int k=0;
	bool existe;
	for(int i=0;i<elemB;i++){
		existe=false;
		for(int j=0;j<elemA && !existe;j++){
			if(B[i]==A[j]){
				existe=true;
				Resultado[k]=B[i];
				k++;
			}
		}
	}
	imprimirVector(Resultado, elemResultado);

	/// Examen: Terminacion del programa
	delete [] A;
	delete [] B;
	delete [] Resultado;
	A=B=Resultado=0;
	return 0;
}
