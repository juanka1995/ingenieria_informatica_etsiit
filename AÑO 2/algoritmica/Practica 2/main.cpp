#include <vector>
#include <set>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

template<class T>
ostream & operator<<(ostream & os, const vector<T> & v)
{
    typename vector<T>::const_iterator it = v.begin();
    os << '[' << *it;
    it++;
    for(; it!=v.end(); ++it)
        os <<", " <<  *it ;
    os << ']';

    return os;
}

// GUILLE

vector<int> vectorSinRepetidosConExito(int n)
{
    vector<int> v(n);
    set<int> s;

    int r = rand() % n;

    // cout << r << endl;

    v[r] = r;

    //Rellenamos a la izquierda
    for(int i=0; i<r; i++){
        int val = r - 1 -(rand() % (2*n));
        while(s.count(val) != 0)
            val = r - 1 - (rand() % (2*n));
        v[i] = val;
        s.insert(val);
    }
    sort(v.begin(),v.begin()+r);

    //cout << "DOS" << endl;

    //Rellenamos a la derecha
    s.clear();

    for(int i=r+1; i<n; i++){
        int val = (rand() % (2*n)) + r + 1;
        while(s.count(val) != 0)
            val = (rand() % (2*n)) + r + 1;
        v[i] = val;
        s.insert(val);
    }
    sort(v.begin()+(r+1),v.end());
    return v;
}

vector<int> vectorSinRepetidosIndeterminado(int n) {
    vector<int> v(n);
    set<int> s;
    for(int i=0; i<n; i++){
        int val = (rand() % (2*n))-n;
        while(s.count(val) != 0)
            val = (rand() % (2*n))-n;
        v[i] = val;
        s.insert(val);
    }
    sort(v.begin(),v.end());
    return v;
}

vector<int> vectorSinRepetidosSinExito(int n) {
    vector<int> v = vectorSinRepetidosIndeterminado(n);
    int lect, escr;
    for(escr = 0, lect = 0; lect < n; escr++, lect++){
        while(escr == v[lect])
            lect++;
        v[escr] = v[lect];
    }
    int m = v[max(escr-1,0)];
    for(;escr < n; escr++)
        v[escr] = m++;
    return v;
}

int encontrarOcurrenciaSR(const vector<int> & v, int ini, int fin){
    // cout << "##" << ini << ' '  << fin << ' '  <<(ini + fin)/2 << endl;
    if(ini == fin){
      return -1;
    }
    else{
        int medio = (ini + fin)/2;
        int res;
        if(v[medio] == medio){
            return medio;
        }
        else{
            if( v[medio] < medio){
                res = encontrarOcurrenciaSR(v,medio+1,fin);
                return res;
            }
            else{
                res = encontrarOcurrenciaSR(v,ini,medio);
                return res;
            }
        }
    }
}


// DANI
vector<int> vectorConRepetidosIndeterminado(int n)
{
    vector<int> v;
    v.resize(n);
    v[0]=1;
    for(int i=1; i<n; i++){
        v[i] = v[i-1]+rand()%3;
    }
    sort(v.begin(),v.end());
    return v;
}

int encontrarOcurrenciaCR(vector<int>&v, int ini, int fin)
{
    int pos = -1;

    if(ini==fin){
        if(v[ini]==ini)
            pos = ini;
    }
    else{
        int izq,dch,mitad;
        mitad=(ini+fin)/2;

        izq=encontrarOcurrenciaCR(v,ini,mitad);
        dch=encontrarOcurrenciaCR(v,mitad+1,fin);

        if(izq>=0)
            pos=izq;
        else if(dch>=0)
            pos=dch;
    }

    return pos;
}

// joaquin

int encontrarOcurrenciaBasico(vector<int>&v, int ini, int fin){
	bool encontrado = false;
    int pos3 = -1;
	for (int i = ini; i < fin && encontrado == false; i++)
    {
     if (v[i] == i)
     {
       encontrado = true;
       pos3 = i;
     }
    }
	return pos3;
}

int main(int argc, char * argv[]){

    if (argc != 2)
    {
      cerr << "Formato " << argv[0] << " <num_elem>" << endl;
      return -1;
    }

    /* Matriz de tiempos de tamaño 8x15
    Fila 0: vSinRepConExito-OcurrenciaSR
    Fila 1: vSinRepSinExito-OcurrenciaSR
    Fila 2: vSinRepConExito-OcurrenciaBasico
    Fila 3: vSinRepSinExito-OcurrenciaBasico
    Fila 4: vConRepIndeter-OcurrenciaBasico
    Fila 5: vSinRepConExito-OcurrenciaCR
    Fila 6: vSinRepSinExito-OcurrenciaCR
    Fila 7: vConRepIndeter-OcurrenciaCR

    */
	  vector<vector<duration<double> > > tiempos(8);
    high_resolution_clock::time_point tantes,tdespues;

    int TAM = atoi(argv[1]),pos;
    srand(time(NULL));

    vector<int> v1, v2, v3;

    // 15 iteraciones por cada tamaño del vector para hacer la media
    for (int i = 0; i < 15; i++) {
      v1 = vectorSinRepetidosConExito(TAM);
      v2 = vectorSinRepetidosSinExito(TAM);
      v3 = vectorConRepetidosIndeterminado(TAM);

      // Algoritmo EncontrarOcurrenciaSR (Guillermo)
      tantes = high_resolution_clock::now();
      pos = encontrarOcurrenciaSR(v1,0,TAM);
      tdespues = high_resolution_clock::now();
      tiempos[0].push_back(duration_cast<duration<double> >(tdespues - tantes));

      tantes = high_resolution_clock::now();
      pos = encontrarOcurrenciaSR(v2,0,TAM);
      tdespues = high_resolution_clock::now();
      tiempos[1].push_back(duration_cast<duration<double> >(tdespues - tantes));

      // Algoritmo encontrarOcurrenciaBasico (Joaquin)
      tantes = high_resolution_clock::now();
      pos = encontrarOcurrenciaBasico(v1,0,TAM);
      tdespues = high_resolution_clock::now();
      tiempos[2].push_back(duration_cast<duration<double> >(tdespues - tantes));

      tantes = high_resolution_clock::now();
      pos = encontrarOcurrenciaBasico(v2,0,TAM);
      tdespues = high_resolution_clock::now();
      tiempos[3].push_back(duration_cast<duration<double> >(tdespues - tantes));

      tantes = high_resolution_clock::now();
      pos = encontrarOcurrenciaBasico(v3,0,TAM);
      tdespues = high_resolution_clock::now();
      tiempos[4].push_back(duration_cast<duration<double> >(tdespues - tantes));

      // Algoritmo encontrarOcurrenciaCR (Dani)
      tantes = high_resolution_clock::now();
      pos = encontrarOcurrenciaCR(v1,0,TAM);
      tdespues = high_resolution_clock::now();
      tiempos[5].push_back(duration_cast<duration<double> >(tdespues - tantes));

      tantes = high_resolution_clock::now();
      pos = encontrarOcurrenciaCR(v2,0,TAM);
      tdespues = high_resolution_clock::now();
      tiempos[6].push_back(duration_cast<duration<double> >(tdespues - tantes));

      tantes = high_resolution_clock::now();
      pos = encontrarOcurrenciaCR(v3,0,TAM);
      tdespues = high_resolution_clock::now();
      tiempos[7].push_back(duration_cast<duration<double> >(tdespues - tantes));

    }

    // Mostrar por pantalla la media de las 15 iteraciones
    double media = 0.0;
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 15; j++) {
        media += tiempos[i][j].count();
      }
      media = media / 15;
      if(i == 7)
        cout << media << endl;
      else
        cout << media << ",";

      media = 0.0;
    }

    return 0;
}
