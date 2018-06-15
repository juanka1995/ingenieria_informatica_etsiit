#include "refranes_hash.h"

Refranes::Refranes(int lpre):
        ab(0,my_hash(lpre)),
        len_prefijo(lpre),
        n_ref(0),
        caracteres_totales(0){
};

int Refranes::size() const{
    return ab.size();
}

void Refranes::Insertar(const string & refran){
    if(ab.count(refran)==0){
        ab.insert(refran);
        caracteres_totales+=refran.size();
        n_ref++;
    }
}

void Refranes::BorrarRefran(const string & refran){
    if(ab.count(refran)>0){
        ab.erase(refran);
        caracteres_totales-=refran.size();
        n_ref--;
    }
}

pair<bool, Refranes::iterator> Refranes::Esta(const string & refran){
    pair<bool, iterator> p;
    if((p.first=ab.count(refran))){
        Refranes::iterator it;
        it.it = ab.find(refran);
        p.second = it;
    }
    return p; 
}

void Refranes::clear(){
    ab.clear();
}

int Refranes::Caracteres_Refranes()const{
    return caracteres_totales;
}

int Refranes::Caracteres_Almacenados(){
    return caracteres_totales;
}

Refranes::iterator Refranes::begin(){
    Refranes::iterator it;
    it.it = ab.begin();
    return it;
}

Refranes::iterator Refranes::end(){
    Refranes::iterator it;
    it.it = ab.end();
    return it;
}

Refranes::const_iterator Refranes::begin()const{
    Refranes::iterator it;
    it.it = ab.begin();
    Refranes::const_iterator cit(it);
    return cit;
}

Refranes::const_iterator Refranes::end()const{
    Refranes::iterator it;
    it.it = ab.end();
    Refranes::const_iterator cit(it);
    return cit;
}

istream & operator>>(istream &is, Refranes &R){
    string s;
    while(getline(is,s)){
        string caux;
        for(unsigned i=0; i<s.size(); i++)
            caux.push_back(tolower(s[i]));
        R.Insertar(caux);
    }
    return is;
}

ostream & operator<<(ostream & is, const Refranes &R){
    Refranes::const_iterator it;
    for(it=R.begin();it!=R.end();++it){
        is << (*it).c_str() << endl;
    }
    return is;
}