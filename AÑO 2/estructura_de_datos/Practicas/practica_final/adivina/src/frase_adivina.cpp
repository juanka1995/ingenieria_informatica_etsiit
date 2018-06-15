#include "frase_adivina.h"

#include <iostream>


FraseAdivina::FraseAdivina(const std::string & s){
    original = s;
    n_visible = 0;
    n_total = 0;
    setCadena(s);
    mapa = stringToMap(s);
}

std::vector<int> FraseAdivina::posLetras(const std::string & s, char c){
    std::vector<int> v;
    for(unsigned i=0; i<s.size(); i++){
        if(s[i]==c)
            v.push_back(i);
    }
    return v;
}

std::unordered_map<char,std::vector<int> > FraseAdivina::stringToMap(const std::string & s){
    std::unordered_map<char,std::vector<int> > m;
    for(char i='a'; i<='z'; i++){
        std::vector<int> v = posLetras(s,i);
        if(v.size()>0)
            m[i] = v;
    }
    
    return m;
}

void FraseAdivina::setCadena(const std::string & s){
    for(unsigned i=0; i<s.size(); i++){
        Letra l(s[i],true);
        if(s[i]>='a' && s[i]<='z'){
            l.visible = false;
            n_total++;
        }

        cadena.push_back(l);
    }
}

void FraseAdivina::setVisible(int perc){
    const int abc_n = 'z' - 'a';
    srand(time(NULL));
    while(n_visible<(n_total*perc/100)){
        char c = 'a' + (rand()%abc_n);
        estaYActualiza(c);
    }
}

int FraseAdivina::estaYActualiza(char c){
    bool esta = (mapa.count(c)>0);
    int tam = 0;
    if(esta){
        std::vector<int> v = mapa[c];
        for(std::vector<int>::const_iterator it=v.begin(); it!=v.end(); ++it){
            if(!cadena[*it].visible){
                cadena[*it].visible = true;
                tam++;
            }
        }
        n_visible += tam;
    }
    return tam;
}

bool FraseAdivina::esIgual(const std::string & s){
    if(original == s){
        for(unsigned i=0; i<cadena.size(); i++)
            cadena[i].visible = true;
        n_visible = n_total;
        return true;
    }
    else
        return false;
}

bool FraseAdivina::adivinada(){
    return n_total == n_visible;
}

std::ostream & operator<<(std::ostream & os, FraseAdivina & f){
    for(unsigned i=0; i<f.cadena.size(); i++){
        if(f.cadena[i].visible)
            os << f.cadena[i].c;
        else
            os << '_';
        os << ' ';
    }
        //os << (f.cadena[i].visible)?f.cadena[i].c:'_' << ' ';
    return os;
}
