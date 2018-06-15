#include <ArbolGeneral.h>
#include <string>
#include <iostream>

int main(int argc, char * argv[]){
    ArbolGeneral<int> a;
    int i = 1;
    ArbolGeneral<int> b(i);
    string s = "hola";
    ArbolGeneral<string> c(s);
    ArbolGeneral<string> d(s);
    ArbolGeneral<string> aux("adios1");
    ArbolGeneral<string> aux2("adios2");
    c.insertar_hijomasizquierda(c.raiz(),aux);
    c.insertar_hermanoderecha(c.hijomasizquierda(c.raiz()),aux2);
    cout << b << endl;
    cin >> a;
    cout << a << endl;
    cout << c << endl;
    cin >> d;
    cout << d << endl;

    ArbolGeneral<int>::const_iter_preorden it;
    for(it=a.begin(); it!=a.end(); ++it){
        
        cout << "["<< it.getlevel()<< "]"<< *it << endl;
    }

    return 0;
}