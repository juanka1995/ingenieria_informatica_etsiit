#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "pila_maxmin.h"


using namespace std;


int main(int argc, char * argv[]){
    if(argc!=3){
        printf("Uso incorrecto\n./datos <fichero_1> <fichero_2>\n");
        exit(EXIT_FAILURE);
    }

    ifstream arch1(argv[1],ios::in), arch2(argv[2],ios::in);

    if(!(arch1.is_open() && arch2.is_open())){
        printf("Se producio un error abriendo los ficheros\n");
        exit(EXIT_FAILURE);
    }

    Pila pila_01,pila_02;
    int n;

    while(!arch1.eof()){
        arch1 >> n;
        pila_01.poner(n);
    }

    while(!arch2.eof()){
        arch2 >> n;
        pila_02.poner(n);
    }

    if(pila_01.tope().min > pila_02.tope().max)
        printf("EL primero conjunto de elementos es mayor que el segundo\n");
    else if(pila_02.tope().min > pila_01.tope().max)
        printf("El segundo conjunto de elementos es mayor que el primero\n");
    else
        printf("Ambos conjuntos tienen el mismo tamaño\n");


    if( (pila_01.tope().min < pila_02.tope().min) && (pila_01.tope().max > pila_02.tope().max) )
          printf("El segundo conjunto de elementos esta contenido en el primero\n");
    else if((pila_02.tope().min < pila_01.tope().min) && (pila_02.tope().max > pila_01.tope().max))
          printf("El primer conjunto de elementos esta contenido en el segundo\n");
    else
        printf("Ninguno conjunto se encuentra contenido en el otro\n");


    exit(0);
}
