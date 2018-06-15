template <class Tbase>
void ArbolGeneral<Tbase>::destruir(nodo * n){
    if(n){
        nodo * aux = n->izqda;
        while(aux){
            destruir(aux);
            aux = aux->drcha;
        }
        delete n;
    }
}

template <class Tbase>
void ArbolGeneral<Tbase>::copiar(nodo *& dest, nodo * orig){
    if(orig){
        dest = new nodo;
        dest->etiqueta = orig->etiqueta;
        dest->padre = NULL;
        dest->drcha = NULL;
        
        //opcion 1
        if(orig->izqda){
            copiar(dest->izqda, orig->izqda);
            dest->izqda->padre = dest;

            nodo * aux_l = orig->izqda;
            nodo * aux_e = dest->izqda;
            while(aux_l->drcha){
                copiar(aux_e->drcha,aux_l->drcha);
                aux_e->drcha->padre = dest;
                aux_e = aux_e->drcha;
                aux_l = aux_l->drcha;
            }
        }
        else{
            dest->izqda = NULL;
        }
        /*
        //opcion 2
        nodo ** aux_l = &(orig->izqda);
        nodo ** aux_e = &(dest->izqda);
        do{
            copiar(*aux_e,*aux_l);
            if(*aux_e){
                (*aux_e)->padre = dest;
                aux_l = &(aux_l->drcha);
                aux_e = &(aux_e->drcha);
            }
        }while(*aux_l)
        */
    }else
        dest = NULL;
}

template <class Tbase>
int ArbolGeneral<Tbase>::contar(const nodo * n) const{
    if(n){
        int i = 1;
        nodo * aux = n->izqda;
        while(aux){
            i += contar(aux);
            aux = aux->drcha;
        }
        return i;
    }
    else
        return 0;
}

template <class Tbase>
bool ArbolGeneral<Tbase>::soniguales(const nodo * n1, const nodo * n2) const{
    if((n1==0) && (n2==0))
        return true;
    else if((n1==0)||(n2==0))
        return false;
    else
        return (n1.etiqueta == n2.etiqueta) && soniguales(n1->izqda,n2->izqda) && soniguales(n1->drcha, n2->drcha);
}

template <class Tbase>
void ArbolGeneral<Tbase>::escribe_arbol(std::ostream& out, nodo * nod) const{
    if(nod){
        out << "n " << nod->etiqueta << " ";
        escribe_arbol(out,nod->izqda);
        escribe_arbol(out,nod->drcha);
    }else   
        out << "x ";
}

template <class Tbase>
void ArbolGeneral<Tbase>::lee_arbol(std::istream& in, nodo *& nod){
    if(in){
        char c;
        Tbase s;
        in >> c;
        if(c == 'x')
            nod = NULL;
        else{
            in >> s;
            nod = new nodo;
            nod->etiqueta = s;
            nod->padre = NULL;
            lee_arbol(in, nod->izqda);
            lee_arbol(in, nod->drcha);
            nodo * aux = nod->izqda;
            while(aux){
                aux->padre = nod;
                aux = aux->drcha;
            }
        }
    }
}

template <class Tbase>
ArbolGeneral<Tbase>::ArbolGeneral(){
    laraiz = new nodo;
    laraiz->izqda = laraiz->drcha = laraiz->padre = NULL;
}

template <class Tbase>
ArbolGeneral<Tbase>::ArbolGeneral(const Tbase& e){
    laraiz = new nodo;
    laraiz->etiqueta = e;
    laraiz->izqda = laraiz->drcha = laraiz->padre = NULL;
}

template <class Tbase>
ArbolGeneral<Tbase>::ArbolGeneral(const ArbolGeneral<Tbase>& v){
    copiar(laraiz,v.laraiz);
}

template <class Tbase>
ArbolGeneral<Tbase>::~ArbolGeneral(){
    destruir(laraiz);
}

template <class Tbase>
ArbolGeneral<Tbase>& ArbolGeneral<Tbase>::operator=(const ArbolGeneral<Tbase> &v){
    if(this!=&v){
        destruir(laraiz);
        copiar(laraiz,v.laraiz);
    }
    return *this;
}

template <class Tbase>
void ArbolGeneral<Tbase>::AsignaRaiz(const Tbase& e){
    destruir(laraiz);
    laraiz = new nodo;
    laraiz->etiqueta = e;
    laraiz->izqda = laraiz->drcha = laraiz->padre = NULL;
}

template <class Tbase>
typename ArbolGeneral<Tbase>::Nodo ArbolGeneral<Tbase>::raiz() const{
    return laraiz;
}

template <class Tbase>
typename ArbolGeneral<Tbase>::Nodo ArbolGeneral<Tbase>::hijomasizquierda(const Nodo n) const{
    return n->izqda;
}

template <class Tbase>
typename ArbolGeneral<Tbase>::Nodo ArbolGeneral<Tbase>::hermanoderecha(const Nodo n) const{
    return n->drcha;
}

template <class Tbase>
typename ArbolGeneral<Tbase>::Nodo ArbolGeneral<Tbase>::padre(const Nodo n) const{
    return n->padre;
}


template <class Tbase>
Tbase& ArbolGeneral<Tbase>::etiqueta(const Nodo n){
    return n->etiqueta;
}

template <class Tbase>
const Tbase& ArbolGeneral<Tbase>::etiqueta(const Nodo n) const{
    return n->etiqueta;
}

template <class Tbase>
void ArbolGeneral<Tbase>::asignar_subarbol(const ArbolGeneral<Tbase>& orig, const Nodo nod){
    if(this != &orig){
        destruir(laraiz);
        copiar(laraiz,nod);
    }else{
        Nodo * aux;
        copiar(aux,nod);
        destruir(laraiz);
        copiar(laraiz,aux);
    }
}

template <class Tbase>
void ArbolGeneral<Tbase>::podar_hijomasizquierda(Nodo n, ArbolGeneral<Tbase>& dest){
    destruir(dest.laraiz);
    dest.laraiz = n->izqda;
    if(dest.laraiz){
        n->izqda = n->izqda->drcha;
        dest.laraiz->padre = dest.laraiz->drcha = NULL;
    }
}

template <class Tbase>
void ArbolGeneral<Tbase>::podar_hermanoderecha(Nodo n, ArbolGeneral<Tbase>& dest){
    destruir(dest.laraiz);
    dest.laraiz = n->drcha;
    if(dest.laraiz){
        n->drcha = n->drcha->drcha;
        dest.laraiz->padre = dest.laraiz->drcha = NULL;
    }
}

template <class Tbase>
void ArbolGeneral<Tbase>::insertar_hijomasizquierda(Nodo n, ArbolGeneral<Tbase>& rama){
    if(rama.laraiz){
        if(n->izqda)
            rama.laraiz->drcha = n->izqda;
        n->izqda=rama.laraiz;
        n->izqda->padre = n;
        rama.laraiz = NULL;
    }
}

template <class Tbase>
void ArbolGeneral<Tbase>::insertar_hermanoderecha(Nodo n, ArbolGeneral<Tbase>& rama){
    if(rama.laraiz){
        if(n->drcha)
            rama.laraiz->drcha = n->drcha;
        n->drcha = rama.laraiz;
        n->drcha->padre = n->padre;
        rama.laraiz = NULL;
    }
}

template <class Tbase>
void ArbolGeneral<Tbase>::clear(){
    destruir(laraiz);
    laraiz = NULL;
}

template <class Tbase>
int ArbolGeneral<Tbase>::size() const{
    return contar(laraiz);
}

template <class Tbase>
bool ArbolGeneral<Tbase>::empty() const{
    return laraiz == NULL;
}

template <class Tbase>
bool ArbolGeneral<Tbase>::operator==(const ArbolGeneral<Tbase>& v) const{
    return soniguales(laraiz, v.laraiz);
}

template <class Tbase>
bool ArbolGeneral<Tbase>::operator!=(const ArbolGeneral<Tbase>& v) const{
    return !soniguales(laraiz, v.laraiz);
}

template <class T>
std::istream& operator>>(std::istream& in, ArbolGeneral<T>& v){
    v.destruir(v.laraiz);
    v.lee_arbol(in,v.laraiz);
    return in;
}

template <class T>
std::ostream& operator<<(std::ostream& out, const ArbolGeneral<T>& v){
    v.escribe_arbol(out,v.laraiz);
    return out;
}

inline std::ostream& operator<<(std::ostream& out, const string& s){
        out << '"' << s.c_str() << '"';
        return out;
    }

inline std::istream& operator>>(std::istream& in,string& s){
    char c;
    string aux;
    in.get(c);//Espacio
    while(c==' ')
        in.get(c);//'"'
    //Cadena entre " "
    if(c=='"'){
        in.get(c);//Primer char
        while(c != '"'){
            aux.push_back(c);
            in.get(c);
        }
    //Cadena normal
    }else{
        while(c != ' ' && c != '\n'){
            aux.push_back(c);
            in.get(c);
        }
    }
    s = aux;
    return in;
}