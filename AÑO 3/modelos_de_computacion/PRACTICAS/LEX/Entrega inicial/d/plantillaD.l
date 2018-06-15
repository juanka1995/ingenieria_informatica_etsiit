        /*------ Sección de Declaraciones ------*/

%{
#include <stdio.h>
#include <string.h>

FILE * pFileOut;
void invertirYEscribir(int yyleng, char * yytext);
%}

%%
        /*------ Sección de Reglas ------*/

[^ \t\n]+			{ invertirYEscribir(yyleng,yytext); }
[ \t\n]+			{ fputs(yytext,pFileOut); }

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

	// Abrimos el fichero de salida
	pFileOut = fopen("inverseFile.out", "w");
	if(pFileOut == NULL){
		printf("El fichero inverseFile.out no se puede crear\n");
        exit(-1);
	}
	
    yylex();
	
	printf("Se ha generado el fichero inverseFile.out con las palabras inversas\n");

	fclose(pFileOut);
    
    return 0;
}

void invertirYEscribir(int yyleng, char * yytext){
	for(int i=yyleng-1; i>=0; i--){
		fputc(yytext[i],pFileOut);
	}
}
