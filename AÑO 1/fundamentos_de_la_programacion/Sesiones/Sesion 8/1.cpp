/*


*/

#include <iostream>
#include <string>

using namespace std;

//Funcion encargada de contar el numero de mayusculas de un vector
int CuentaMayusculas(char vector[],int utilizados){
	int num_may=0;
	for(int c=0;c<=utilizados;c++){
		if(vector[c] >= 'A' && vector[c] <= 'Z')
			num_may++;
	}
	return num_may;
}

//Funcion encargada de invertir un vector
char Invertir(char vector[],int posicion){
	
	/*char aux;
	int pos=posicion;
	
	for(int c=0;c<=posicion;c++){
		aux=vector[pos];
		vector[pos]=vector[c];
		vector[c]=aux;
		pos--;
	}*/
	
	return vector[posicion];
}

//Funcion encargada de comprobar si un vector es palindromo
bool Palindromo(int utilizados,char vector[]){
	bool igual;
	for(int c=0;c<utilizados && igual==true;utilizados--){
		if(vector[c]==vector[utilizados])
			c++;
		else
			igual=false;
	}
	return igual;
}

//Funcion encargada de preguntar al usuario por el contenido del vector
char RecogerCaracter(string sms){
	char caracter;
	do{
		cout << sms;
		cin >> caracter;
	}while((caracter < 'A' || caracter > 'Z') && (caracter < 'a' || caracter > 'z') && caracter!='#');
	return caracter;
}

int main(){
	const char TERMINADOR='#';
	const int TAMANIO=100;
	const string MENSAJE="Introduce un caracter: ";
	char vector[TAMANIO],inverso[TAMANIO];
	int total_utilizados=0,posicion_final,num_mayusculas=0;
	bool es_palindromo;
	
	vector[total_utilizados]=RecogerCaracter(MENSAJE);
	
	while(vector[total_utilizados] != '#' && total_utilizados < 99){
		total_utilizados++;
		vector[total_utilizados]=RecogerCaracter(MENSAJE);
	}
	
	//Restamos uno al total para quitar cuando el usuario introduzca el terminador
	total_utilizados--;
	
	es_palindromo=Palindromo(total_utilizados,vector);
	
	//Guardamos la inversa del vector en otro vector utilizando la funcion Inversa
	posicion_final=total_utilizados;
	for(int c=0;c<=total_utilizados;c++){
		inverso[c]=Invertir(vector,posicion_final);
		posicion_final--;
	}
	
	num_mayusculas=CuentaMayusculas(vector,total_utilizados);
	
	if(es_palindromo)
		cout << "La secuencia de caracteres introducida SI es un palindromo";
	else
		cout << "La secuencia de caracteres introducida NO es un palindromo";
	
	cout << "\nEl vector invertido es:  ";
	for(int c=0;c<=total_utilizados;c++){
		cout << inverso[c] << "  ";
	}
	
	if(num_mayusculas!=0)
		cout << "\nEl numero de mayusculas en el vector es de " << num_mayusculas;
	else
		cout << "\nNo existen mayusculas en el vector.";
}
