        /*------ Sección de Declaraciones ------*/

%{
#include <iostream>
#include <vector>
#include <cstdio>
#include <iterator>
#include <string>
#include <cstdlib>
#include <list>
#include <utility>

#define NUM_LETRAS 26

using namespace std;

vector<double> variables;
vector<bool> variablesU;
list<double> valores;
list<pair<char,int> > simbolos;

int posVarAsig, numParentesis;
int prioSumRes, prioMulDiv;
string entrada;
bool lineaValida;

void inicializarVariables();
void mostrarValorVariables();
double calcularResultado();
void mostrarAyuda();

%}

	/*------ Contextos ------*/

%start ASIGNAR

	/*------ Simbolos ------*/

operador		["+"\-"*""/"]
igual			"="
parentesisA		"("
parentesisC		")"
endl			"\n"
caracter		[a-z]
digito			[0-9]
entero			{digito}+
real			{entero}\.{entero}

%%

        /*------ Sección de Reglas INITIAL ------*/

<INITIAL>{caracter}{igual}		{
									posVarAsig = yytext[0]%97;  											
									BEGIN ASIGNAR;
								}

<INITIAL>{caracter}" ?"$		{
							if(variablesU[yytext[0]%97])											
								cout << "'" << yytext[0] << "' = " << variables[yytext[0]%97] << endl;
							else
								cout << "<ERROR> - " << yytext[0] << " no tiene un valor asignado" << endl;
						}

<INITIAL>" ?"$			{
							if(lineaValida){
								if(numParentesis == 0){
									cout << "Resultado: " << calcularResultado() << endl;
								}
								else{
									cout << "<ERROR> - faltan parentesis por cerrar" << endl;	
								}											
							}
							lineaValida=true;
							valores.clear();
							simbolos.clear();
						}

        /*------ Sección de Reglas Generales ------*/

.*{operador}{operador}.*|" "|\t|{operador}" "|" "{operador}|{parentesisA}{parentesisC}|{operador}{parentesisC}|{parentesisA}{operador}|({entero}|{real}){endl}({entero}{real})|({entero}|{real}){parentesisA}|{parentesisC}({entero}|{real})		{ 
																																																														if(lineaValida){
																																																															cout << "<ERROR> - Comprueba que no haya espacios, que no haya operadores seguidos, " << endl;
																																																															cout << " que no falten operadores, etc... " << endl;
																																																															lineaValida = false;
																																																															valores.clear();
																																																															simbolos.clear();
																																																														}
																																																													}

{parentesisA}		{ numParentesis++; }

{parentesisC}		{ 
						if(numParentesis > 0)
							numParentesis--;
						else{
							cout << "<ERROR> - No se puede cerrar un parentesis sin abrirlo previamente" << endl;
							lineaValida = false;
							valores.clear();
							simbolos.clear();
						}
					}

({caracter}{2,})|({caracter}+{digito}+)|({digito}+{caracter}+)		{}

({entero}|{real})	{
								if(lineaValida){
									entrada = yytext;
									valores.push_back(stof(entrada) * 1.0);
								}
							}

{parentesisA}"-"({entero}|{real}){parentesisC}		{
																if(lineaValida){
																	entrada = yytext;
																	entrada = entrada.substr(1,2);
																	valores.push_back(stof(entrada) * 1.0);
																}
															}

{caracter}			{
								if(lineaValida){
									if(variablesU[yytext[0]%97]){
										valores.push_back(variables[yytext[0]%97]);
									}
									else{
										lineaValida = false;
										cout << "<ERROR> - " << yytext << " no tiene un valor asignado" << endl;
										valores.clear();
										simbolos.clear();
									}	
								}
							}

{operador}({entero}|{real})		{
												if(lineaValida){												
													entrada = yytext;
													char simbolo = entrada[0];
													if(numParentesis > 0){
														if(simbolo == '+' || simbolo == '-')
															simbolos.push_back(make_pair(simbolo,numParentesis*3));
														else
															simbolos.push_back(make_pair(simbolo,numParentesis*4));
													}
													else{
														if(simbolo == '+' || simbolo == '-')
															simbolos.push_back(make_pair(simbolo,prioSumRes));
														else
															simbolos.push_back(make_pair(simbolo,prioMulDiv));
													}
													entrada = entrada.substr(1,entrada.size());
													valores.push_back(stof(entrada)*1.0);
												}
											}

{operador}{parentesisA}+"-"?({entero}|{real})	{
													if(lineaValida){												
														entrada = yytext;
														char simbolo = entrada[0];
														if(numParentesis > 0){
															if(simbolo == '+' || simbolo == '-')	
																simbolos.push_back(make_pair(simbolo,numParentesis*3));
															else
																simbolos.push_back(make_pair(simbolo,numParentesis*4));
														}
														else{
															if(simbolo == '+' || simbolo == '-')
																simbolos.push_back(make_pair(simbolo,prioSumRes));
															else
																simbolos.push_back(make_pair(simbolo,prioMulDiv));
														}

														int firstParentesis, lastParentesis;
														firstParentesis = entrada.find_first_of('(');
														lastParentesis = entrada.find_last_of('(');
														numParentesis += lastParentesis - firstParentesis + 1;

														entrada = entrada.substr(lastParentesis+1,entrada.size());
														valores.push_back(stof(entrada)*1.0);
													}
												}

{parentesisC}{operador}({entero}|{real})		{
													if(lineaValida){
														if(numParentesis > 0){											
															numParentesis--;												
															entrada = yytext;
															char simbolo = entrada[1];
															if(numParentesis > 0){
																if(simbolo == '+' || simbolo == '-')
																	simbolos.push_back(make_pair(simbolo,prioSumRes+numParentesis*2));
																else
																	simbolos.push_back(make_pair(simbolo,prioMulDiv+numParentesis*2));
															}
															else{
																if(simbolo == '+' || simbolo == '-')	
																	simbolos.push_back(make_pair(simbolo,prioSumRes));
																else
																	simbolos.push_back(make_pair(simbolo,prioMulDiv));
															}
															entrada = entrada.substr(2,entrada.size());
															valores.push_back(stof(entrada)*1.0);
														}
														else{
															cout << "<ERROR> - No se puede cerrar un parentesis sin abrirlo previamente" << endl;
															lineaValida = false;
															valores.clear();
															simbolos.clear();
														}										
													}
												}

{operador}{caracter}		{
								if(lineaValida){
									entrada = yytext;
									char simbolo = entrada[0];
									if(numParentesis > 0){
										if(simbolo == '+' || simbolo == '-')	
											simbolos.push_back(make_pair(simbolo,prioSumRes+numParentesis));
										else
											simbolos.push_back(make_pair(simbolo,prioMulDiv+numParentesis));
									}
									else{
										if(simbolo == '+' || simbolo == '-')	
											simbolos.push_back(make_pair(simbolo,prioSumRes));
										else
											simbolos.push_back(make_pair(simbolo,prioMulDiv));
									}

									entrada = entrada.substr(1,entrada.size());
									if(variablesU[entrada[0]%97]){
										valores.push_back(variables[entrada[0]%97]);
									}
									else{
										lineaValida = false;
										cout << "<ERROR> - " << entrada << " no tiene un valor asignado" << endl;
										valores.clear();
										simbolos.clear();
									}
									
								}
							}

{operador}{parentesisA}+"-"?({caracter})	{
													if(lineaValida){												
														entrada = yytext;
														char simbolo = entrada[0];
														if(numParentesis > 0){
															if(simbolo == '+' || simbolo == '-')	
																simbolos.push_back(make_pair(simbolo,numParentesis*3));
															else
																simbolos.push_back(make_pair(simbolo,numParentesis*4));
														}
														else{
															if(simbolo == '+' || simbolo == '-')
																simbolos.push_back(make_pair(simbolo,prioSumRes));
															else
																simbolos.push_back(make_pair(simbolo,prioMulDiv));
														}

														int firstParentesis, lastParentesis;
														firstParentesis = entrada.find_first_of('(');
														lastParentesis = entrada.find_last_of('(');
														numParentesis += lastParentesis - firstParentesis + 1;

														entrada = entrada.substr(lastParentesis+1,entrada.size());

														if(entrada.size() == 2){
																if(variablesU[entrada[1]%97]){
																	valores.push_back(variables[entrada[1]%97]*(-1.0));
																}
																else{
																	lineaValida = false;
																	cout << "<ERROR> - " << entrada << " no tiene un valor asignado" << endl;
																	valores.clear();
																	simbolos.clear();
																}
														}
														else{
																if(variablesU[entrada[0]%97]){
																	valores.push_back(variables[entrada[0]%97]);
																}
																else{
																	lineaValida = false;
																	cout << "<ERROR> - " << entrada << " no tiene un valor asignado" << endl;
																	valores.clear();
																	simbolos.clear();
																}
														}
													}
												}

{parentesisC}{operador}({caracter})		{
											if(lineaValida){
												if(numParentesis > 0){											
													numParentesis--;												
													entrada = yytext;
													char simbolo = entrada[1];
													if(numParentesis > 0){
														if(simbolo == '+' || simbolo == '-')
															simbolos.push_back(make_pair(simbolo,prioSumRes+numParentesis*2));
														else
															simbolos.push_back(make_pair(simbolo,prioMulDiv+numParentesis*2));
													}
													else{
														if(simbolo == '+' || simbolo == '-')	
															simbolos.push_back(make_pair(simbolo,prioSumRes));
														else
															simbolos.push_back(make_pair(simbolo,prioMulDiv));
													}
													entrada = entrada.substr(2,entrada.size());

													if(variablesU[entrada[0]%97]){
														valores.push_back(variables[entrada[0]%97]);
													}
													else{
														lineaValida = false;
														cout << "<ERROR> - " << entrada << " no tiene un valor asignado" << endl;
														valores.clear();
														simbolos.clear();
													}
												}
												else{
													cout << "<ERROR> - No se puede cerrar un parentesis sin abrirlo previamente" << endl;
													lineaValida = false;
													valores.clear();
													simbolos.clear();
												}										
											}
										}

        /*------ Sección de Reglas ASIGNAR ------*/

<ASIGNAR>" ?"$		{
							if(lineaValida){
								if(numParentesis == 0){
									variables[posVarAsig] = calcularResultado();
									variablesU[posVarAsig] = true;
									char var = posVarAsig+97;												
									cout << "'" << var << "' = " << variables[posVarAsig] << endl;
								}
								else{
									cout << "<ERROR> - faltan parentesis por cerrar" << endl;	
								}											
							}
							lineaValida=true;
							valores.clear();
							simbolos.clear();	
							BEGIN INITIAL;
						}

%%

        /*------ Sección de Procedimientos ------*/

int main(int argc, char *argv[]) {

	if(argc == 2) {
		yyin = fopen(argv[1], "rt");
		if(yyin == NULL) {
			cout << "El fichero " << argv[1] << " no se puede abrir" << endl;
			return 0;
		}
	}
    	else{
        	yyin = stdin;
			mostrarAyuda();		
		}

	inicializarVariables();
	numParentesis = 0;
	lineaValida = true;

	prioMulDiv = 2;
	prioSumRes = 1;

	yylex();
	
	mostrarValorVariables();
    
	return 0;
}



void inicializarVariables(){
	for(int i = 0; i < NUM_LETRAS; i++){
		variables.push_back(0.0);
		variablesU.push_back(false);
	}
}

void mostrarValorVariables(){
	cout << endl << "Valores de las variables usadas: " << endl;
	for(int i = 0; i < variables.size(); i++){
		if(variablesU[i]){
			char var = 97+i;
			cout << "\t'" << var << "' = " << variables[i] << endl;
		}
	}
}

double calcularResultado(){
	double resultado = 0.0;
	int prioridad = 0;

	while(!simbolos.empty()){
		double aux;
		auto it = simbolos.begin();
		auto it2 = valores.begin();
		auto itAux1 = it;
		auto itAux2 = it2;
		for( ; it != simbolos.end(); ++it, ++it2){
			if(it->second > prioridad){
				prioridad = it->second;
				itAux1 = it;
				itAux2 = it2;
			}
		}

		it = itAux1;
		it2 = itAux2;		

		switch(it->first){
			case '+':
				aux = (*it2) + (*(++it2));
				simbolos.erase(it);
				valores.erase(it2);
				--it2;
				*it2 = aux;
			break;
			case '-':
				aux = (*it2) - (*(++it2));
				simbolos.erase(it);
				valores.erase(it2);
				--it2;
				*it2 = aux;
			break;
			case '*':
				aux = (*it2) * (*(++it2));
				simbolos.erase(it);
				valores.erase(it2);
				--it2;
				*it2 = aux;
			break;
			case '/':
				aux = (*it2) / (*(++it2));
				simbolos.erase(it);
				valores.erase(it2);
				--it2;
				*it2 = aux;
			break;
		}
		prioridad = 0;
	}

	resultado = valores.front();

	return resultado;
}

void mostrarAyuda(){
	system("clear");
	cout << endl << "\t####  RESTRICCIONES DE LA CALCULADORA PARA UN BUEN FUNCIONAMIENTO  ####" << endl << endl;

	cout << "Para todas las restricciones detalladas a continuacion, he intentado crear reglas que las " << endl;
	cout << "solventen, pero es posible que no las haya abarcado todas, por lo que no me hago responsable " << endl;
	cout << "del resultado de las operaciones o de la ejecucición del programa, si no se cumplen TODAS Y " << endl;
	cout << "CADA UNA de las restricciones siguientes:" << endl << endl;
	
	cout << "\t(1)-Para realizar cualquier operacion la sintaxis debe ser [OPERACION] ?." << endl;
	cout << "\t\tEjemplos:" << endl;
	cout << "\t\t\tMAL:  (-5)*(3+4)\tBIEN:  (-5)*(3+4) ?" << endl;
	cout << "\t\t\tMAL:  (-55)\t\tBIEN:  (-55) ?" << endl;
	cout << "\t\t\tMAL:  a=a*b\t\tBIEN:  a=a*b ?" << endl << endl;

	cout << "\t(2)-Los NUMEROS NEGATIVOS deben ir SIEMPRE ENTRE PARENTESIS." << endl;
	cout << "\t\tEjemplos:" << endl;
	cout << "\t\t\tMAL:  -5*3 ?\t\tBIEN:  (-5)*3 ?" << endl;
	cout << "\t\t\tMAL:  -10 ?\t\tBIEN:  (-10) ?" << endl;
	cout << "\t\t\tMAL:  a=-5*3 ?\t\tBIEN:  a=(-5)*3 ?" << endl << endl;

	cout << "\t(3)-No debe existir NINGUN ESPACIO en las operaciones." << endl;
	cout << "\t\tEjemplos:" << endl;
	cout << "\t\t\tMAL:  (-5) * 3 ?\tBIEN:  (-5)*3 ?" << endl;
	cout << "\t\t\tMAL:  a = (-5) * 3 ?\tBIEN:  a=(-5)*3 ?" << endl << endl;

	cout << "\t(4)-Escribir CUALQUIER COSA que no sea una operacion, una variable o una asignacion " << endl;
	cout << "\t    a una variable puede generar un RESULTADO INESPERADO." << endl << endl;

	cout << "\t(5)-Puede utilizar un número ILIMITADO DE PARENTESIS, siempre " << endl;
	cout << "\t    y cuando no falte ninguno y respete las restricciones" << endl;
	cout << "\t    anteriores." << endl << endl; 

	cout << "\t(6)-No debe DIVIDIR POR CERO." << endl << endl; 
	
	cout << "Eso es todo, ¡ya puedes empezar a usar la calculadora! :)" << endl << endl << endl;
}

