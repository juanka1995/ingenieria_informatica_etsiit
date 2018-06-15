/*

Se quiere construir una clase DepositoSimulacion para simular préstamos, ofreciendo
la funcionalidad descrita en los ejercicios 19 (reinvierte capital e interés un
número de años) y 20 (reinvierte capital e interés hasta obtener el doble de la cantidad
inicial) de la relación de problemas II (página RP-II.7). Por tanto, la clase debe
proporcionar, para un capital y unos intereses dados, métodos para:

a) Calcular el capital que se obtendrá al cabo de un número de años,
b) Calcular el número de años que deben pasar hasta obtener el doble de la cantidad
inicial.

A la hora de diseñar la clase, tendremos que analizar cuestiones como:
- ¿Cuáles son sus datos miembro? Parece claro que el capital y el interés sí lo
serán ya que cualquier operación que se nos ocurra hacer con un objeto de la
clase DepositoSimulacion involucra a ambas cantidades. ¿Pero y el número
de años?
- ¿Qué constructor definimos?
- ¿Queremos modificar el capital y el interés una vez creado el objeto?
- ¿Queremos poder modificarlos de forma independiente?
- ¿Hay alguna restricción a la hora de asignar un valor al capital e interés?
- ¿Es mejor un método para calcular el número de años hasta obtener el doble de
la cantidad inicial, o por el contrario es mejor un método para calcular el número
de años hasta obtener una cantidad específica?

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
