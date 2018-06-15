/*

Cread un programa que lea los datos fiscales de una persona, reajuste su renta bruta según el criterio que se indica posteriormente 
e imprima su renta neta final.
	- La renta bruta es la cantidad de dinero íntegra que el trabajador gana.
	- La retención fiscal es el tanto por ciento que el gobierno se queda.
	- La renta neta es la cantidad que le queda al trabajador después de quitarle el porcentaje de retención fiscal, es decir:
		Renta_neta = Renta_bruta - Renta_bruta * Retención final / 100

Los datos a leer son:
	- Si la persona es un trabajador autónomo o no
	- Si es pensionista o no
	- Estado civil
	- Renta bruta (total de ingresos obtenidos)
	- Retención inicial a aplicar.

La retención inicial se va a modificar ahora atendiendo al siguiente criterio:
	-Se baja 3 puntos la retención fiscal a los autónomos, es decir, si la retención inicial era de un 15 %, por ejemplo, la retención
	 final a aplicar será de un 12% (por lo que la renta neta final será mayor)
	 
Para los no autónomos:
	– Se sube un punto la retención fiscal a todos los pensionistas, es decir, si la retención inicial era de un 13 %, por ejemplo, la 
	retención final a aplicar será de un 14% (por lo que la renta neta final será menor)
	– Al resto de trabajadores (no autónomo y no pensionista) se le aplica a todos una primera subida lineal de dos puntos en la retención inicial.

Una vez hecha esta subida, se le aplica (sobre el resultado anterior) las siguientes subidas adicionales, dependiendo de su estado 
civil y niveles de ingresos:
	- Se sube otros dos puntos la retención fiscal si la renta bruta es menor de 20.000 euros
	- Se sube otros 2.5 puntos la retención fiscal a los casados con renta bruta superior a 20.000 euros
	- Se sube otros tres puntos la retención fiscal a los solteros con renta bruta superior a 20.000 euros

Una vez calculada la retención final, habrá que aplicarla sobre la renta bruta para así obtener la renta final del trabajador.


*/

#include <iostream>
#include <cmath>

using namespace std;

int main(){
	
	char autonomo,pensionista,estado_civil;
	double renta_bruta,renta_neta,retencion;
	
	cout << "CALCULAR TU RENTA: \n\n";
	
	cout << "Actualmente eres autonomo? (S/N): ";
	cin >> autonomo;
	
	if(autonomo=='N' || autonomo=='n'){
		cout << "\nActualmente eres pensionista? (S/N): ";
		cin >> pensionista;
	}
	
	cout << "\nEstado civil: \n   a)Casado/a\n   b)Soltero/a\n";
	cout << "Cual es su estado civil? (a/b): ";
	cin >> estado_civil;
	
	cout << "\nIntroduzca la renta bruta obtenida: ";
	cin >> renta_bruta;
	
	cout << "\nIntroduzca el porcentaje su retencion inicial: ";
	cin >> retencion;
	
	if(autonomo=='S' || autonomo=='s')
		retencion=retencion-3;
	
	else if(pensionista=='S' || pensionista=='s')
		retencion++;
		
	else{
		
		retencion=retencion+2;
		
		if(renta_bruta<20000)
			retencion=retencion+2;
			
		else if(estado_civil=='a' || estado_civil=='A')
			retencion=retencion+2.5;
			
		else
			retencion=retencion+3;
			
	}
	
	renta_neta=renta_bruta-(renta_bruta*retencion/100);
	
	cout << "\nSu renta neta es de: " << renta_neta << " euros.";
	
} 
