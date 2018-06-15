/*

Se está diseñando un sistema web que recolecta datos
personales de un usuario y, en un momento dado, debe sugerirle un nombre de
usuario (login). Dicho login estará basado en el nombre y los apellidos; en concreto
estará formado por los N primeros caracteres de cada nombre y apellido
(en minúsculas, unidos y sin espacios en blanco). Por ejemplo, si el nombre es
"Antonio Francisco Molina Ortega" y N=2, el nombre de usuario sugerido
será "anfrmoor".
Debe tener en cuenta que el número de palabras que forman el nombre y los apellidos
puede ser cualquiera. Además, si N es mayor que alguna de las palabras que
aparecen en el nombre, se incluirá la palabra completa. Por ejemplo, si el nombre
es "Ana CAMPOS de la Blanca" y N=4, entonces la sugerencia será
"anacampdelablan" (observe que se pueden utilizar varios espacios en blanco
para separar palabras).
Implemente la clase Login que tendrá como único dato miembro el tamaño N. Hay
que definir el método Codifica que recibirá una cadena de caracteres (tipo string)
formada por el nombre y apellidos (separados por uno o más espacios en blanco) y
devuelva otra cadena con la sugerencia de login.
class Login{
private:
int num_caracteres_a_coger;
public:
Login (int numero_caracteres_a_coger)
:num_caracteres_a_coger(numero_caracteres_a_coger)
{ }
string Codifica(string nombre_completo){
......
}
};
Los únicos métodos que necesita usar de la clase string son size y
push_back. Para probar el programa o bien lea una cadena de caracteres con
getline(cin, cadena); o bien use directamente literales string en el main.

*/

#include <string>
#include <iostream>

using namespace std;

/*
Login
	- int num_caracteres
   	- int Siguiente_palabra(string nombre,int pos)
   	+ Login(int num)
  	+ string Codifica(string nombre)
*/

class Login{
	private:
		int num_caracteres;
	//Esta funcion se encarga de indicar el comienzo de la siguiente palabra de la frase contenida en el string nombre
		int Siguiente_palabra(string nombre,int pos){
			while(nombre[pos-1]!=' '){
				if(nombre.length()-1 == pos){
					pos=-1;
					break;
				}
				pos++;
			}
			return pos;
		}
	public:
		Login(int num)
			:num_caracteres(num)
		{}
	//Esta funcion se encargga de recibir un nombre completo y devolver una sugerencia de nick al usuario utilizando las num_caracteres letras
	//de dicho nombre completo en minuscula.
		string Codifica(string nombre){
			int c=0;
			string sugerencia;
			char letra;
			while(c != -1){
				int i=0;
				while(i<num_caracteres && nombre[c] != ' '){
					letra=tolower(nombre[c]);
					sugerencia=sugerencia+letra;
					c++;
					i++;
				}
				c=Siguiente_palabra(nombre,c);
			}
			return sugerencia;
		}
};

int main () {
  
  	string nombre="Juan Carlos Ruiz Garcia",sugerencia;
	int num;
	
	cout << "Introduce el numero de caracteres por palabra: ";
	cin >> num;
	
	// Creamo el objeto login de la clase Login
	Login login(num);
	
	sugerencia=login.Codifica(nombre);
	
	cout << "La sugerencia de nombre de usuario es: " << sugerencia;
	
}


