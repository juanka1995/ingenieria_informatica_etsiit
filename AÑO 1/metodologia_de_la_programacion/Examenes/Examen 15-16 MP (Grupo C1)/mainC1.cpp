/**
@file main.cpp
@brief
Universidad de Granada
Metodología de la Programación I
Examen de laboratorio

Por favor, rellene las funciones que se indican
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/**
@brief Imprime el contenido de un vector de string
@param v 	Vector de string
@param n	Número de elementos que contiene @a v
*/
void imprimirVector(string *v, int n)  {
	cout << n << " elementos" << endl;
	for (int i=0; i<n; i++)
		cout << "["<<i<<"] = " << v[i] << endl;
}


int main()  {
	string *A=0, *B=0, *Resultado=0;
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
	for(int i=0;i<elemA;i++)
		if(A[i].length()<6)
			elemResultado++;
	for(int i=0;i<elemB;i++)
		if(B[i].length()<6)
			elemResultado++;

	Resultado=new string[elemResultado];

	int k=0;
	for(int i=0;i<elemA;i++){
		if(A[i].length()<6){
			Resultado[k]=A[i];
			k++;
		}
	}
	for(int i=0;i<elemB;i++){
		if(B[i].length()<6){
			Resultado[k]=B[i];
			k++;
		}
	}
	/// Examen: Mostrar resultado

	imprimirVector(Resultado, elemResultado);

	/// Examen: Terminación del programa
	delete [] A;
	delete [] B;
	delete [] Resultado;
	A=B=Resultado=0;

	return 0;
}
