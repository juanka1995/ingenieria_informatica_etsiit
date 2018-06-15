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

using namespace std;

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
		double Capital_N_Anios(){
			double simulacion;
			simulacion=capital+((capital*interes/100)*n_anios);
			return simulacion;
		}
		double N_Anios_Doble_Capital(){
			int total_anios=0;
			double cap=capital;
			while(cap<capital*2){
				total_anios++;
				cap=capital+((capital*interes/100)*total_anios);
			}
			return total_anios;
		}
};
