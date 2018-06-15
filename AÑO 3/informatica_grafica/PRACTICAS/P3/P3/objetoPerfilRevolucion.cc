/*
Juan Carlos Ruiz Garcia - Grupo C1
*/

#include "objetoPerfilRevolucion.h"

ObjetoPerfilRevolucion::ObjetoPerfilRevolucion( int nSegmentos){   

    if(nSegmentos < 3)
        nSegmentos = 3;

    ejeRevolucion = "Y";

    // Perfil introducido a mano (FIGURA: PEON DE AJEDREZ)
    verticesPerfil = {
        Vertice(1.0, -1.4, 0.0),
        Vertice(1.0, -1.1, 0.0),
        Vertice(0.5, -0.7, 0.0),
        Vertice(0.4, -0.4, 0.0),
        Vertice(0.4, 0.5, 0.0),
        Vertice(0.5, 0.6, 0.0),
        Vertice(0.3, 0.6, 0.0),
        Vertice(0.5, 0.8, 0.0),
        Vertice(0.55, 1.0, 0.0),
        Vertice(0.5, 1.2, 0.0),
        Vertice(0.3, 1.4, 0.0)
    };

    generarRevolucion(nSegmentos);

}

ObjetoPerfilRevolucion::ObjetoPerfilRevolucion(const string &ficheroPLY, int nSegmentos, string eje) : ObjetoPLY(ficheroPLY){

    if(nSegmentos < 3)
    nSegmentos = 3;

    ejeRevolucion = eje;

    if(numVertices > 0 && numCaras == 0 && getIsFileReaded()){
        verticesPerfil = vertices;
        generarRevolucion(nSegmentos);
    }
    else
        setIsFileReaded(false);

}

void ObjetoPerfilRevolucion::generarRevolucion(const int &nSegmentos){
    // Asignamos el nSegmentos
    this->nSegmentos = nSegmentos;

    // Asignamos que tapa/s puede/n pintarse o despintarse
    setQueTapaPuedoPintarODespintar();

    // Inicialmente las caras que se pueden pintar/despintar vienen despintadas
    estanTapasPintadas = false;

    //Insertamos las tapas que no estubieran aunque solo pintaremos/despintaremos las que se pueda
    if(!tienePerfilTapaSuperior())
        insertarTapaSuperiorAlPerfil();
    if(!tienePerfilTapaInferior())
        insertarTapaInferiorAlPerfil();

    // Asignamos el numero de vertices del perfil original
    numVerticesPerfil = verticesPerfil.size();

    // Actualizamos los vectores de vertices, caras y color en funcion de nSegmentos
    updateVerticesCarasColor(nSegmentos);

    // Añadimos las tapas que traia el perfil originalmente al vector de caras (dentro actualiza numCaras)
    switch(queTapaPuedoPintarODespintar){
        case 0: // No tenia tapa inferior, pinto la superior
            addTapasCorrespondientes(1);
        break;
        case 1: // No tenia tapa superior, pinta la inferior
            addTapasCorrespondientes(0);
        break;
        case 2: // No tenia ninguna tapa, no las pinto...
            // ... solo actualizamos el numero de caras
            this->numCaras = (unsigned int) caras.size();
        break;
        case 3: // Tenia las dos tapas, pues las pinto
            addTapasCorrespondientes(2);
        break;
    }
}

void ObjetoPerfilRevolucion::updateVerticesCarasColor(const int nSegmentos){

    // Igualamos el vector de vertices del objeto al perfil para que tenga esos
    // vertices inicialmente
    vertices = verticesPerfil;
    
    // Añadimos los vertices por revolucion dependiendo del eje de revolucion
    insertarVerticesSegunEjeRevolucion(nSegmentos);

    // Actualizamos numVertices
    this->numVertices = (unsigned int) vertices.size();
    
    // Borramos el contenido del vector de caras
    caras.clear();

    // Lados para triangulo par e impar de cada cuadrado
    vector<unsigned int> ladosParesImpares;

    // Creamos las CARAS del medio (sin las tapas) con triangulos
    unsigned int vertice = 1;
    for(unsigned int i = 0; i < (numVerticesPerfil-3)*nSegmentos; i++){
        if(vertice%(numVerticesPerfil-2) == 0)
            vertice++;
        
        ladosParesImpares = {
            // Triangulo par
            vertice, vertice+numVerticesPerfil-2, vertice+1,
            // Triangulo impar
            vertice+1, vertice+1+numVerticesPerfil-2, vertice+1+numVerticesPerfil-3
        };

        // Aplicamos el modulo numVertices-2 a todos los lados excepto a los de valor numVertices-2
        for(int i = 0; i < ladosParesImpares.size(); i++){
            if(ladosParesImpares[i] != (numVertices-2))
                ladosParesImpares[i] = ladosParesImpares[i] % (numVertices-2);
        }

        // Añadimos las nuevas caras al vector de caras
        caras.push_back(Triangulo(ladosParesImpares[0],ladosParesImpares[1],ladosParesImpares[2]));
        caras.push_back(Triangulo(ladosParesImpares[3],ladosParesImpares[4],ladosParesImpares[5]));
        vertice++;
    }

    // Borramos el vector de color
    color.clear();

    // Creamos el vector de COLOR
    for(unsigned int i = 0 ; i < numVertices ; i++){
        this->color.push_back(Color(defaultColor.r, defaultColor.g, defaultColor.b));
    }

}

void ObjetoPerfilRevolucion::insertarVerticesSegunEjeRevolucion(const int nSegmentos){
    float anguloRad = degreesToRadians(360.0/nSegmentos);
    if(ejeRevolucion == "X"){     
        // Añadimos los VERTICES aplicando la rotación sobre el eje de la Y
        // numSegmentos-1 para que no genere de nuevo el perfil original
        for(unsigned int i = 0; i < nSegmentos-1; i++){
            // j desde 1 a numVerticesPerfil-1 para no repetir las tapas en la revolucion
            for(unsigned int j = 1; j < numVerticesPerfil-1; j++){
                float x = vertices[j].x;
                float y = cos((i+1)*anguloRad)*vertices[j].y - sin((i+1)*anguloRad)*vertices[j].z;
                float z = sin((i+1)*anguloRad)*vertices[j].y + cos((i+1)*anguloRad)*vertices[j].z;
                vertices.insert(--vertices.end(),Vertice(x,y,z));
            }
        }
    }
    else if (ejeRevolucion == "Y"){
        // Añadimos los VERTICES aplicando la rotación sobre el eje de la Y
        // numSegmentos-1 para que no genere de nuevo el perfil original
        for(unsigned int i = 0; i < nSegmentos-1; i++){
            // j desde 1 a numVerticesPerfil-1 para no repetir las tapas en la revolucion
            for(unsigned int j = 1; j < numVerticesPerfil-1; j++){
                float x = cos((i+1)*anguloRad)*vertices[j].x + sin((i+1)*anguloRad)*vertices[j].z;
                float y = vertices[j].y;
                float z = -(sin((i+1)*anguloRad))*vertices[j].x + cos((i+1)*anguloRad)*vertices[j].z;
                vertices.insert(--vertices.end(),Vertice(x,y,z));
            }
        }
    }
    else{
        // Añadimos los VERTICES aplicando la rotación sobre el eje de la Y
        // numSegmentos-1 para que no genere de nuevo el perfil original
        for(unsigned int i = 0; i < nSegmentos-1; i++){
            // j desde 1 a numVerticesPerfil-1 para no repetir las tapas en la revolucion
            for(unsigned int j = 1; j < numVerticesPerfil-1; j++){
                float x = cos((i+1)*anguloRad)*vertices[j].x - sin((i+1)*anguloRad)*vertices[j].y;
                float y = sin((i+1)*anguloRad)*vertices[j].x + cos((i+1)*anguloRad)*vertices[j].y;
                float z = vertices[j].z;
                vertices.insert(--vertices.end(),Vertice(x,y,z));
            }
        }
    }
}

float ObjetoPerfilRevolucion::degreesToRadians(float degrees){
    // grados = 180/π · radianes
    // radianes = (grados · π)/180
    return ((degrees*M_PI)/180);
}

void ObjetoPerfilRevolucion::incrementarNSegmentos(){
    updateVerticesCarasColor(++nSegmentos);
    if(estanTapasPintadas){
        addTapasCorrespondientes(2);
    }
    else{
        switch(queTapaPuedoPintarODespintar){
            case 0: // No tenia tapa inferior, pinto la superior
                addTapasCorrespondientes(1);
            break;
            case 1: // No tenia tapa superior, pinta la inferior
                addTapasCorrespondientes(0);
            break;
            case 2: // No tenia ninguna tapa, no las pinto...
                // ... solo actualizamos el numero de caras
                this->numCaras = (unsigned int) caras.size();
            break;
            case 3: // Tenia las dos tapas, pues las pinto
                addTapasCorrespondientes(2);
            break;
        }
    }
}

void ObjetoPerfilRevolucion::decrementarNSegmentos(){
    // nSegmentos debe ser OBLIGATORIAMENTE >= 3
    if(nSegmentos > 3){
        updateVerticesCarasColor(--nSegmentos);
        if(estanTapasPintadas){
            addTapasCorrespondientes(2);
        }
        else{
            switch(queTapaPuedoPintarODespintar){
                case 0: // No tenia tapa inferior, pinto la superior
                    addTapasCorrespondientes(1);
                break;
                case 1: // No tenia tapa superior, pinta la inferior
                    addTapasCorrespondientes(0);
                break;
                case 2: // No tenia ninguna tapa, no las pinto...
                    // ... solo actualizamos el numero de caras
                    this->numCaras = (unsigned int) caras.size();
                break;
                case 3: // Tenia las dos tapas, pues las pinto
                    addTapasCorrespondientes(2);
                break;
            }
        }
    }   
}

bool ObjetoPerfilRevolucion::tienePerfilTapaSuperior() const{
    if(ejeRevolucion == "X")
        return ((verticesPerfil[verticesPerfil.size()-1].y == 0.0) && (verticesPerfil[verticesPerfil.size()-1].z == 0.0));
    else if(ejeRevolucion == "Y")
        return ((verticesPerfil[verticesPerfil.size()-1].x == 0.0) && (verticesPerfil[verticesPerfil.size()-1].z == 0.0));
    else
        return ((verticesPerfil[verticesPerfil.size()-1].x == 0.0) && (verticesPerfil[verticesPerfil.size()-1].y == 0.0));
}

bool ObjetoPerfilRevolucion::tienePerfilTapaInferior() const{
    if(ejeRevolucion == "X")
        return ((verticesPerfil[0].y == 0.0) && (verticesPerfil[0].z == 0.0));
    else if(ejeRevolucion == "Y")
        return ((verticesPerfil[0].x == 0.0) && (verticesPerfil[0].z == 0.0));
    else
        return ((verticesPerfil[0].x == 0.0) && (verticesPerfil[0].y == 0.0));
}

int ObjetoPerfilRevolucion::getQueTapaPuedoPintarODespintar() const{
    return queTapaPuedoPintarODespintar;
}

void ObjetoPerfilRevolucion::insertarTapaSuperiorAlPerfil(){
    if(ejeRevolucion == "X")
        verticesPerfil.push_back(Vertice(verticesPerfil[verticesPerfil.size()-1].x,0.0,0.0));
    else if(ejeRevolucion == "Y")
        verticesPerfil.push_back(Vertice(0.0,verticesPerfil[verticesPerfil.size()-1].y,0.0));
    else
        verticesPerfil.push_back(Vertice(0.0,0.0,verticesPerfil[verticesPerfil.size()-1].z));
}

void ObjetoPerfilRevolucion::insertarTapaInferiorAlPerfil(){
    if(ejeRevolucion == "X")
        verticesPerfil.insert(verticesPerfil.begin(),Vertice(verticesPerfil[0].x,0.0,0.0));
    else if(ejeRevolucion == "Y")
        verticesPerfil.insert(verticesPerfil.begin(),Vertice(0.0,verticesPerfil[0].y,0.0));
    else
        verticesPerfil.insert(verticesPerfil.begin(),Vertice(0.0,0.0,verticesPerfil[0].z));
}

void ObjetoPerfilRevolucion::setQueTapaPuedoPintarODespintar(){
    if(tienePerfilTapaSuperior() && !tienePerfilTapaInferior())
        queTapaPuedoPintarODespintar = 0;
    else if(!tienePerfilTapaSuperior() && tienePerfilTapaInferior())
        queTapaPuedoPintarODespintar = 1;
    else if(!tienePerfilTapaSuperior() && !tienePerfilTapaInferior())
        queTapaPuedoPintarODespintar = 2;
    else
        queTapaPuedoPintarODespintar = 3;
}

bool ObjetoPerfilRevolucion::getEstanTapasPintadas() const{
    return estanTapasPintadas;
}

void ObjetoPerfilRevolucion::setEstanTapasPintadas(){
    estanTapasPintadas = !estanTapasPintadas;
}

void ObjetoPerfilRevolucion::addTapasCorrespondientes(const int tapaAPintar){   
    unsigned int aux;
    switch(tapaAPintar){
        case 0: // Añadir tapa inferior
            aux = 1;
            for(unsigned int i = 0; i < nSegmentos-1; i++){
                caras.push_back(Triangulo(aux, aux+numVerticesPerfil-2, 0));
                aux += numVerticesPerfil - 2;
            }
            caras.push_back(Triangulo(aux, 1, 0));
        break;
        case 1: // Añadir tapa superior
            aux = numVerticesPerfil - 2;
            for(unsigned int i = 0; i < nSegmentos-1; i++){
                caras.push_back(Triangulo(aux, aux+numVerticesPerfil-2, numVertices-1));
                aux += numVerticesPerfil - 2;
            }
            caras.push_back(Triangulo(numVerticesPerfil-2, numVertices-2,  numVertices-1)); 
        break;
        case 2: // Añadir ambas tapas
            addTapasCorrespondientes(0);
            addTapasCorrespondientes(1);
        break;
    }
    // Actualizamos el numero de caras
    this->numCaras = (unsigned int) caras.size();
}

void ObjetoPerfilRevolucion::deleteTapasCorrespondientes(const int tapaADespintar){
    switch(tapaADespintar){
        case 0: // Eliminar tapa inferior
        {
            auto it = caras.begin();
            for(; it != caras.end(); it++){
                if(it->l3 == 0){
                    caras.erase(it);
                    it--;
                } 
            }
            break;
        }
        case 1: // Eliminar tapa superior
        {    
            auto it2 = caras.begin();
            for(; it2 != caras.end(); it2++){
                if(it2->l3 == numVertices-1){
                    caras.erase(it2);
                    it2--;
                } 
            }  
            break;
        }
        case 2: // Eliminar ambas tapas
            deleteTapasCorrespondientes(0);
            deleteTapasCorrespondientes(1);
        break;
    }
    // Actualizamos el numero de caras
    this->numCaras = (unsigned int) caras.size();
}