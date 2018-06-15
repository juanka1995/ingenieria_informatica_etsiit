/*

Se quiere construir una clase DepositoSimulacion para simular pr�stamos, ofreciendo
la funcionalidad descrita en los ejercicios 19 (reinvierte capital e inter�s un
n�mero de a�os) y 20 (reinvierte capital e inter�s hasta obtener el doble de la cantidad
inicial) de la relaci�n de problemas II (p�gina RP-II.7). Por tanto, la clase debe
proporcionar, para un capital y unos intereses dados, m�todos para:

a) Calcular el capital que se obtendr� al cabo de un n�mero de a�os,
b) Calcular el n�mero de a�os que deben pasar hasta obtener el doble de la cantidad
inicial.

A la hora de dise�ar la clase, tendremos que analizar cuestiones como:
- �Cu�les son sus datos miembro? Parece claro que el capital y el inter�s s� lo
ser�n ya que cualquier operaci�n que se nos ocurra hacer con un objeto de la
clase DepositoSimulacion involucra a ambas cantidades. �Pero y el n�mero
de a�os?
- �Qu� constructor definimos?
- �Queremos modificar el capital y el inter�s una vez creado el objeto?
- �Queremos poder modificarlos de forma independiente?
- �Hay alguna restricci�n a la hora de asignar un valor al capital e inter�s?
- �Es mejor un m�todo para calcular el n�mero de a�os hasta obtener el doble de
la cantidad inicial, o por el contrario es mejor un m�todo para calcular el n�mero
de a�os hasta obtener una cantidad espec�fica?

*/

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

/*
		Clase DepositoSimulacion
*/
class DepositoSimulacion{
	private:
		double capital,interes;
		int n_anios=1;
	public:
		DepositoSimulacion(double cap,double inter,int anios){
			SetCapital(cap);
			SetInteres(inter);
			SetAnios(anios);
		}
		DepositoSimulacion(double cap,double inter){
			SetCapital(cap);
			SetInteres(inter);
		}
		void SetCapital(double cap){
			capital=cap;
		}
		void SetInteres(double inter){
			interes=inter;
		}
		void SetAnios(int anios){
			n_anios=anios;
		}
		// Funcion encargada de calcular el capital total despues de N a�os a un % de interes
		double Capital_N_Anios(){
			double total;
			total=capital+((capital*interes/100)*n_anios);
			return total;
		}
		// Fucion encargada de calcular el numero de a�os a pasar para lograr un capital deseado
		double N_Anios_Capital_Deseado(double deseado){
			int total_anios=0;
			double cap=capital;
			while(cap<deseado){
				total_anios++;
				cap=capital+((capital*interes/100)*total_anios);
			}
			return total_anios;
		}
};

//	Funcion encargada de recojer el capital ingresado por el usuario

double RecogerCapital(string SMS){
	double capital;
	do{
		cout << SMS;
		cin >> capital;
	}while(capital<0);
	return capital;
}

//	Funcion encargada de recojer el interes ingresado por el usuario

double RecogerInteres(string SMS){
	double interes;
	do{
		cout << SMS;
		cin >> interes;
	}while(interes<0 || interes >100);
	return interes;
}

//	Funcion encargada de recojer el capital a lograr por el usuario

double RecogerCapitalDeseado(string SMS, double capital){
	double deseado;
	do{
		cout << SMS;
		cin >> deseado;	
	}while(deseado<0 || deseado<capital);
	return deseado;
}

//	Funcion encargada de recojer el numero de a�os que han de pasar

int RecogerAnios(string SMS){
	int anios;
	do{
		cout << SMS;
		cin >> anios;
	}while(anios<0);
	return anios;
}

int main(){
	const string SMS1="Introduce el capital actual: ",SMS2="Introduce el interes para aplicar: ",SMS3="Introduce el numero de anios a pasar: ",
	SMS4="Introduce el capital a conseguir: ";
	int opcion,anios;
	double capital,interes,capital_deseado;
	
	// Menu para las dos opciones posibles del programa
	cout << "1.- Calcular capital en X anios.\n";
	cout << "2.- Calcular numero de anios para alcanzar el capital deseado.\n\n";

	do{
	 	cout << "Elige una opcion (1-2): ";	
		cin >> opcion;
	}while(opcion !=1 && opcion !=2);
	
	if(opcion==1){
		capital=RecogerCapital(SMS1);
		interes=RecogerInteres(SMS2);
		anios=RecogerAnios(SMS3);
		DepositoSimulacion un_deposito(capital,interes,anios);			
		cout << "El capital despues de " << anios << " anios sera de " << un_deposito.Capital_N_Anios() << " euros.";
	}
	else{
		capital=RecogerCapital(SMS1);
		interes=RecogerInteres(SMS2);
		capital_deseado=RecogerCapitalDeseado(SMS4,capital);
		DepositoSimulacion un_deposito(capital,interes);
		cout << "El numero de anios para alcanzar el capital de " << capital_deseado << " euros es de " << un_deposito.N_Anios_Capital_Deseado(capital_deseado) << " anios.";
	}	
}
