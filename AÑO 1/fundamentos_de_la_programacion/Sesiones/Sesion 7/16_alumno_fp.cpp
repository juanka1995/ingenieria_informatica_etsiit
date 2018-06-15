/*

Definir la clase AlumnoFP, que almacene el nombre, el primer apellido, el DNI del
alumno y cada una de las partes consideradas en la evaluación de la asignatura: teoría,
parcial_pract1, parcial_pract2, participación_clase. La escala utilizada para evaluar
cada parte es de 0 a 10.

- Construir los constructores necesarios para poder asignar valores a los miembros
de la clase.
- Construir un método que calcule la nota final del alumno. Para ello se debe de
tener en cuenta los porcentajes de las distintas partes consideradas: 70% teoría,
5% parcial 1, 15% parcial 2 y 10% participación.
- Construir un método que calcule la nota final del alumno.
- Construir un programa que lea los datos del alumno y en caso de haber obtenido
una nota inferior a 5 en alguna de las partes que indique la nota obtenida en dicha
parte.

*/

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class AlumnoFP{
	private:
		string nombre,apellido,dni;
		double parcial_1,parcial_2,teoria,participacion;
	public:
		AlumnoFP(string a1,string a2,string a3){
			nombre=a1;
			apellido=a2;
			dni=a3;			
		}
		void SetNotas(double parc_1, double parc_2, double teo, double particip){
			parcial_1=parc_1;
			parcial_2=parc_2;
			teoria=teo;
			participacion=particip;
		}
		double Nota_final(){
			double final;
			final=parcial_1*0.05+parcial_2*0.15+teoria*0.7+participacion*0.1;
			return final;
		}
		double GetParcial_1(){
			return parcial_1;
		}
		double GetParcial_2(){
			return parcial_2;
		}
		double GetTeoria(){
			return teoria;
		}
		double GetParticipacion(){
			return participacion;
		}
	
};

string Recoger_datos(string mnsj){
	
	string dato;
	
	cout << mnsj;
	cin >> dato;
	
	return dato;
	
}

double Recoger_notas(string mnsj){
	
	double nota;
	
	do{
		
		cout << mnsj;
		cin >> nota;
		
	}while(nota < 0 || nota > 10);
	
}

int main(){
	const string SMS1="Introduce el nombre del alumno: ", SMS2="Introduce el primer apellido: ", SMS3="Introduce el DNI: ",
	SMS4="Introduce la nota del primer parcial (0-10): ", SMS5="Introduce la nota del segundo parcial (0-10): ", SMS6="Introduce la nota de teoria (0-10): ",
	SMS7="Introduce la nota de participacion en clase (0-10): ";
	string nombre,apellido,dni;
	double parcial1,parcial2,teoria,participacion;
	
	nombre=Recoger_datos(SMS1);
	apellido=Recoger_datos(SMS2);
	dni=Recoger_datos(SMS3);
	
	AlumnoFP un_alumno(nombre,apellido,dni);
	
	parcial1=Recoger_notas(SMS4);
	parcial2=Recoger_notas(SMS5);
	teoria=Recoger_notas(SMS6);
	participacion=Recoger_notas(SMS7);
	
	un_alumno.SetNotas(parcial1,parcial2,teoria,participacion);
	
	if(un_alumno.GetParcial_1()<5)
		cout << "\nSuspendiste el primer parcial con: " << un_alumno.GetParcial_1();
	if(un_alumno.GetParcial_2()<5)
		cout << "\nSuspendiste el segundo parcial con: " << un_alumno.GetParcial_2();
	if(un_alumno.GetTeoria()<5)
		cout << "\nSuspendiste el examen teorico con: " << un_alumno.GetTeoria();
	if(un_alumno.GetParticipacion()<5)
		cout << "\nSuspendiste la participacion en clase con: " << un_alumno.GetParticipacion();
	
}
