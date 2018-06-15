        /*------ Sección de Declaraciones ------*/

%{
#include <stdio.h>

int numCorreos, numTelefonos, numMatriculas, numCP, numNIF;
void mostrarNumCorreos();
%}

digito					[0-9]
real					{digito}*
letra					[a-zA-Z]
letraM					[A-Z]
palabra					{letra}+
alfaN					({palabra}|{real})*
dominio					(\.com|\.es|\.org)
caracEsp				[\.\-_]
espacio					[ ]
guion					\-
digitoSinCero			[1-9]
digito1a4				[1-4]

%%
        /*------ Sección de Reglas ------*/

	/* Correos */
({letra}|_){alfaN}({caracEsp}{alfaN})*@{alfaN}(\.{alfaN})*{dominio}								{ printf("He encontrado el correo: %s\n", yytext); numCorreos++; }
	/* Numeros de telefono */
([9678]{digito}{2})({digito}{6}|({espacio}{digito}{3}){2}|({espacio}{digito}{2}){3})			{ printf("He encontrado el numero de telefono: %s\n", yytext); numTelefonos++; }
	/* Matriculas */
({letraM}{1,2}){espacio}({digito}{4}){espacio}({letraM}{1,2})									{ printf("He encontrado la matricula antigua: %s\n", yytext); numMatriculas++; }
({letraM}{1,2}){guion}({digito}{4}){guion}({letraM}{1,2})										{ printf("He encontrado la matricula antigua: %s\n", yytext); numMatriculas++; }
({digito}{4}){espacio}({letraM}{3})																{ printf("He encontrado la matricula moderna: %s\n", yytext); numMatriculas++; }
	/* Codigos postales */
((0{digitoSinCero})|({digito1a4}{digito})|(50)|(51)|(51))({digito}{3})[^0-9]					{ printf("He encontrado el codigo postal: %s\n", yytext); numCP++; }
	/* NIF */
({digito}{8})({guion}?){letraM}																	{ printf("He encontrado el NIF: %s\n", yytext); numNIF++; }
.|\n																							{}

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
	
	numCorreos = numTelefonos = numMatriculas = numCP = numNIF = 0;
    yylex();
    mostrarNumCorreos();
    
    return 0;
}

void mostrarNumCorreos(){
	printf("\nEl numero de correos encontrados es de: %d\n",numCorreos);
	printf("\nEl numero de telefonos encontrados es de: %d\n",numTelefonos);
	printf("\nEl numero de matriculas encontradas es de: %d\n",numMatriculas);
	printf("\nEl numero de codigos postales es de: %d\n",numCP);
	printf("\nEl numero de NIFs es de: %d\n",numNIF);
}

