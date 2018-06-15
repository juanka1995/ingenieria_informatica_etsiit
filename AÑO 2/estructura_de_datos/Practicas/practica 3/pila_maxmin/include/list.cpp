
template <typename T>
Lista<T>::Lista(){
  cabecera = NULL;
}

template <typename T>
Lista<T>::~Lista(){
  destruir();
}

template <typename T>
void Lista<T>::destruir(){
  if(cabecera!=NULL){
  Celda<T> *p = cabecera;
  while(p->siguiente!=NULL){
    cabecera=p->siguiente;
    delete p;
    p=cabecera;
  }
  delete cabecera;
  cabecera=NULL;
  }
}

template <typename T>
T Lista<T>::getLast()const{
  Celda<T> *aux = cabecera;
  while(aux->siguiente!=NULL){
    aux = aux->siguiente;
  }
  return aux->dato;
}

template <typename T>
bool Lista<T>::isEmpty()const{
  return cabecera == NULL;
}

template <typename T>
void Lista<T>::addLast(T dato){
  Celda<T> *nueva = new Celda <T>;
  nueva->dato = dato;
  nueva->siguiente = NULL;
  if(isEmpty()){
    cabecera=nueva;
  }else{
      Celda<T> *aux = new Celda <T>;
      aux = cabecera;
      while(aux->siguiente != NULL){
        aux = aux->siguiente;
      }
      aux->siguiente = nueva;
  }
}

template <typename T>
void Lista<T>::deleteLast(){
  if(!isEmpty()){
    Celda<T> *aux = cabecera;
    Celda<T> *aux2 = aux;
    while(aux->siguiente != NULL){
      aux2 = aux;
      aux = aux->siguiente;
    }
    if(aux2 == cabecera && aux2->siguiente == NULL)
      cabecera = NULL;
    else
      aux2->siguiente=NULL;
    delete aux;
    aux = NULL;
  }
}

template <typename T>
int Lista<T>::getSize()const{
  int size = 0;
  if(!isEmpty()){
    size++;
    Celda<T> *aux = cabecera;
    while(aux->siguiente != NULL){
      aux = aux->siguiente;
      size++;
    }
  }
  return size;
}
