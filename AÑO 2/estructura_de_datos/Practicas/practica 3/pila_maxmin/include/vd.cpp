
template <typename T>
VD<T>::VD(){
  utiles = 0;
  reservados = 10;
  datos = new T[reservados];
}

template <typename T>
VD<T>::VD(int tam){
  utiles = 0;
  reservados = tam;
  datos = new T[reservados];
}

template <typename T>
VD<T>::VD(const VD<T> &origen){
  reservados = origen.reservados;
  datos = new T[reservados];
  copia(origen);
}

template <typename T>
void VD<T>::copia(const VD<T> &origen){
  utiles = origen.utiles;
  for (int i = 0; i < origen.getSize(); i++) {
    datos[i] = origen.datos.getElem(i);
  }
}

template <typename T>
int VD<T>::getElem(int i)const{
  return datos[i];
}

template <typename T>
VD<T>::~VD(){
  destruir();
}

template <typename T>
void VD<T>::destruir(){
  delete[] datos;
  utiles = reservados = 0;
}

template <typename T>
T VD<T>::pop_back()const{
  return datos[utiles-1];
}

template <typename T>
bool VD<T>::isEmpty()const{
  return utiles == 0;
}

template <typename T>
void VD<T>::push_back(T dato){
  if(utiles >= reservados)
    resize();
  datos[utiles++] = dato;
}

template <typename T>
void VD<T>::resize(){
  int nuevo_tam = reservados*2;
  T *aux=new T [nuevo_tam];
  int minimo=(utiles<nuevo_tam) ? utiles:nuevo_tam;
  for(int i=0;i<minimo;i++)
  {
    aux[i]=datos[i];
  }
  reservados=nuevo_tam;
  utiles=minimo;
  delete [] datos;
  datos=aux;
}

template <typename T>
VD<T>& VD<T>::operator=(const VD<T> & origen){
  if(this!=&origen)
  {
    delete[] datos;
    datos = new T[origen.reservados];
    if(utiles>0)
    {
      copia(origen);
    }
  }
  return *this;
}

template <typename T>
void VD<T>::deleteLast(){
  if(utiles>0)
    utiles--;
}

template <typename T>
int VD<T>::getSize()const{
  return utiles;
}
