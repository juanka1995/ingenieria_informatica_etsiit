#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include "refranes.h"

using namespace std;
#define MIN_PRE 2
#define MAX_PRE 14

int main(int argc, char * argv[]){
    
    if(argc != 3){
        printf("Uso:\n\t %s <archivo_refranes> <archivo_destino>\n",argv[0]);
        exit(EXIT_FAILURE);
    }


    //Abrimos archivo de entrada
    ifstream ifs(argv[1]);
    if(!ifs.is_open()){
        ifs.close();
        printf("No se puede abrir archivo %s\n",argv[1]);
        exit(EXIT_FAILURE);
    }

    //Abrimos archivo de salida
    ofstream ofs(argv[2]);
    if(!ofs.is_open()){
        ifs.close();
        ofs.close();
        printf("No se puede abrir archivo %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    //Escribimos etiquetas
    ofs << 
        "Prefijo, " <<
        "Car. Total, " <<
        "Car. Arbol, " <<
        "%Red, " <<
        "#Nodos, " <<
        "%Red/#Nodos\n";


    for(int i=MIN_PRE; i<=MAX_PRE; i++){
        Refranes ref(i);
        int car_total, car_arbol, nodos;
        double red, rel_red_nodos;
        
        //Reiniciamos stream
        ifs.clear();
        ifs.seekg(0,ios_base::beg);

        //Volcamos en ref
        ifs >> ref;

        //Calculamos valores
        car_total = ref.Caracteres_Refranes();
        car_arbol = ref.Caracteres_Almacenados();
        nodos = ref.Numero_Nodos();

        red = 100.0*(car_total-car_arbol)/car_total;
        rel_red_nodos = red/nodos;
        
        //Escribimos a archivo
        ofs << 
            i << ',' <<
            car_total << ',' <<
            car_arbol << ',' <<
            red << ',' <<
            nodos << ',' <<
            rel_red_nodos << '\n';
    }

    ifs.close();
    ofs.close();

    exit(EXIT_SUCCESS);

}
