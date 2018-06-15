#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include "refranes.h"
#include "frase_adivina.h"

using namespace std;

int main(int argc, char *argv[]){
    
    if(argc!=2 && argc!=3){
        printf("Uso:\n\t%s <archivo_refranes> [porcentaje_descubierto]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    ifstream ifs(argv[1]);
    if(!ifs.is_open()){
        ifs.close();
        printf("No se puede abrir archivo %s\n",argv[1]);
        exit(EXIT_FAILURE);
    }

    //Lógica del juego
    Refranes ref;
    int porc_vistas = (argc==3)?atoi(argv[2]):50;
    bool volver_a_jugar = true;
    ifs >> ref;
    assert(ref.size()>0);

    Refranes::const_iterator it = ref.begin();
    srand(time(NULL));
    cout << "***************Comienza el juego***************" << endl;

    while(volver_a_jugar){
        bool adivinada = false;
        string inp;
        //Elegir posicion del refran (aleatorio)
        int n = (rand() % ref.size());
        for(int i=0; i<n; i++){
            ++it;
            if(it==ref.end())
                it = ref.begin();
        }
        //Creamos la FraseAdivina
        FraseAdivina fr(*it);
        //Hacemos el porc_vistas porciento vistas
        fr.setVisible(porc_vistas);
        //Entra en el bucle de juego
        while(!adivinada){
            cout << '\n' << fr <<'\n' << endl;
            cout << "Pulsa 0 para obtener ayuda\n"
                    "Dime un caracter (o el refran para resolver):\n";
            getline(cin,inp);

            if(inp.size()==1){
                int n;
                switch(inp[0]){
                    case '0':
                        do{
                            n=fr.estaYActualiza((char)('a' + (rand()%('a'-'z'))));
                        }while(n==0);
                        break;
                    default:
                        n = fr.estaYActualiza(inp[0]);
                        break;
                }
                cout << "Descubiertas: " << n << endl;
            }else{
                if(!fr.esIgual(inp))
                    cout << "Sigue intentandolo\n";
            }

            adivinada = fr.adivinada();
            if(adivinada){
                string c;
                cout << "La has adivinado: " << fr << "\n¿Quieres seguir jugando?[S/N]: ";
                getline(cin,c);
                volver_a_jugar = (c == "S");
            }
        }
        
    }
}