/*

La sonda Mars Climate Orbiter fue lanzada por la NASA en 1998 y llegó a Marte
el 23 de septiembre de 1999. Lamentablemente se estrelló contra el planeta ya que
se acercó demasiado. El error principal fue que los equipos que desarrollaron los
distintos módulos de la sonda usaron sistemas de medida distintos (el anglosajón y el
métrico). Cuando un componente software mandaba unos datos en millas (o libras),
otro componente software los interpretaba como si fuesen kilómetros (o Newtons). El
problema se habría arreglado si todos hubiesen acordado usar el mismo sistema. En
cualquier caso, cada equipo se encuentra más a gusto trabajando en su propio sistema
de medida. Por tanto, la solución podría haber pasado por que todos utilizasen una
misma clase para representar distancias (idem para fuerzas, presión, etc), utilizando
los métodos que les resultasen más cómodos.

Para ello, se pide construir la clase Distancia que contendrá métodos como
SetKilometros, SetMillas, etc. Internamente se usará un único dato miembro
privado llamado kilometros al que se le asignará un valor a través de los métodos
anteriores, realizando la conversión oportuna (una milla es 1;609344 kilómetros). La
clase también proporcionará métodos como GetKilometros y GetMillas para lo
que tendrá que realizar la conversión oportuna (un kilómetro es 0;621371192 millas).

*/

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class Distancia{
	private:
		const double CAMBIO_A_KM=1.609344, CAMBIO_A_MILLAS=0.621371192;
		double kilometros;
	public:
		void SetKilometros(double km){
			kilometros=km;
		}
		void SetMillas(double millas){
			kilometros=millas*CAMBIO_A_KM;
		}
		double GetKilometros(){
			return kilometros;
		}
		double GetMillas(){
			double millas;
			millas=kilometros*CAMBIO_A_MILLAS;
			return millas;
		}
};

char RecogerTipo(string sms){
	char tipo;
	do{
		cout << sms;
		cin >> tipo;
	}while(tipo != 'K' && tipo != 'M' && tipo != 'k' && tipo != 'm');
	return tipo;
}

double Recoger_KM_Millas(string sms){
	double dato;
	do{
		cout << sms;
		cin >> dato;
	}while(dato < 0);
	return dato;
}

int main(){
	const string SMS1="Que deseas introducir Kilometros o Millas?: (K/M): ",SMS2="Introduce el numero de Km: ",SMS3="Introduce el numero de millas: ";
	char tipo,sn;
	double km,millas;
	bool seguir=true;
	
	Distancia una_distancia;
	
	while(seguir){
		tipo=RecogerTipo(SMS1);
		if(tipo == 'K' || tipo == 'k'){
			km=Recoger_KM_Millas(SMS2);
			una_distancia.SetKilometros(km);
			cout << km << " km equivalen a " << una_distancia.GetMillas() << " millas.";
		}
		else{
			millas=Recoger_KM_Millas(SMS3);
			una_distancia.SetMillas(millas);
			cout << millas << " millas equivalen a " << una_distancia.GetKilometros() << " km.";
		}
		do{
			cout << "\n\nDeseas convertir algun otro valor? (S/N): ";
			cin >> sn;
		}while(sn != 'S' && sn != 's' && sn != 'N' && sn != 'n');
		switch(sn){
			case 'S':
			case 's':
				seguir=true;
			break;
			case 'N':
			case 'n':
				seguir=false;
			break;
		}
	}
}
