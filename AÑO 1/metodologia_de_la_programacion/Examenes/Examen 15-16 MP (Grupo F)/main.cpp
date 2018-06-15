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
	string *A=NULL, *B=NULL, *Resultado=NULL;
	bool existe;
	int elemA, elemB, elemResultado;
	ifstream FichA, FichB;

	/// Examen: Leer fichero en vector A
	FichA.open("ficheroa.txt");
	FichA >> elemA;
	A=new string[elemA];
	for(int i=0;i<elemA;i++){
		FichA >> A[i];
	}
	FichA.close();
	imprimirVector(A, elemA);

	/// Examen: Leer fichero en vector B
	FichB.open("ficherob.txt");
	FichB >> elemB;
	B=new string[elemB];
	for(int i=0;i<elemB;i++){
		FichB >> B[i];
	}
	FichB.close();
	imprimirVector(B, elemB);

	/// Examen: Calcular resultado
	elemResultado=elemB-elemA;
	Resultado=new string[elemResultado];
	int k=0;
	for(int i=0;i<elemB;i++){
		existe=false;
		for(int j=0;j<elemA && !existe;j++){
				if(B[i]==A[j])
					existe=true;
		}
		if(!existe){
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
	return 0;
}
