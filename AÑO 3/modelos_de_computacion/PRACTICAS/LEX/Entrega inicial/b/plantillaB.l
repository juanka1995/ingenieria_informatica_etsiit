        /*------ Sección de Declaraciones ------*/

%{
#include <stdio.h>

int np, nc, nl;
void mostrarDatos();
%}

%%
        /*------ Sección de Reglas ------*/

[^ \t\n]+			{ np++; nc += yyleng; }
[ \t]+				{ nc += yyleng;}
\n					{ nl++; nc++; }

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
	
	np = nc = nl = 0;
    yylex();
    mostrarDatos();
    
    return 0;
}

void mostrarDatos(){
	printf("Numero de caracteres: %d\nNumero de palabras: %d\nNumero de lineas: %d\n",nc,np,nl);
}
