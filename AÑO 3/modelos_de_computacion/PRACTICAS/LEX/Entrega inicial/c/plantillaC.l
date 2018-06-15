        /*------ Sección de Declaraciones ------*/

%{
#include <stdio.h>
#include <stdlib.h>

int numPalabrasM;
int numPalabrasm;
int numPalabrasMm;
int numEnteros;
int numReales;
int sumaEnteros;
double sumaReales;

void mostrarDatos();
%}

letraM		[A-Z]
palabraM	{letraM}+
letram		[a-z]
palabram	{letram}+
letraMm		[a-zA-Z]
palabraMm	{letraMm}+
digito		[0-9]
entero		{digito}+
real		{entero}\.{entero}
real2		({entero}|{real})[eE][\+\-]?{entero}

%%
        /*------ Sección de Reglas ------*/

{palabraM}						{ numPalabrasM++; }
{palabram}						{ numPalabrasm++; }
{palabraMm}						{ numPalabrasMm++; }
{real}|{real2}					{ numReales++; sumaReales += atof(yytext); }
{entero}						{ numEnteros++; sumaEnteros += atoi(yytext); }
\n|\t|\b|.						{}

%%

        /*------ Sección de Procedimientos ------*/

int main(int argc, char *argv[]) {

    if(argc == 2) {
        yyin = fopen(argv[1], "rt");
        if(yyin == NULL) {
            printf("El fichero %s no se puede abrir\n",argv[1]);
            exit(-1);
        }
    }
    else
        yyin = stdin;
	
	numPalabrasM = numPalabrasm = numPalabrasMm = numEnteros = numReales = sumaEnteros = 0;
	sumaReales = 0.0;
    yylex();
    mostrarDatos();
    
    return 0;
}

void mostrarDatos(){
	printf("Numero de secuencias de caracteres escritas completamente en mayusculas: %d\n",numPalabrasM);
	printf("Numero de secuencias de caracteres escritas completamente en minuscula: %d\n",numPalabrasm);
	printf("Numero de secuencias de caracteres que mezclen mayusculas y minusculas: %d\n",numPalabrasMm);
	printf("Numero de enteros: %d\n",numEnteros);
	printf("Numero de reales: %d\n",numReales);
	printf("Suma de todos los numeros enteros encontrados: %d\n",sumaEnteros);
	printf("Suma de todos los numeros reales encontrados: %lf\n",sumaReales);
}
