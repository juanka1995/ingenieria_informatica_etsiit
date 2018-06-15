/*
Juan Carlos Ruiz Garcia - Grupo C1
*/

#include "objetoPerfilBarrido.h"

ObjetoPerfilBarrido::ObjetoPerfilBarrido(int nSegmentos, float longitud){

    if(nSegmentos < 2)
        nSegmentos = 2;
    if(longitud < 0.0)
        longitud = 4.0;

    verticesPerfil = {
        Vertice(1.0, 0.0, 1.0),
        Vertice(0.5, 0.0, 0.0),
        Vertice(1.0, 0.0, -1.0),
        Vertice(0.0, 0.0, -0.5),
        Vertice(-1.0, 0.0, -1.0),
        Vertice(-0.5, 0.0, 0.0),
        Vertice(-1.0, 0.0, 1.0),
        Vertice(0.0, 0.0, 0.5)
    };

    generarBarrido(nSegmentos, longitud);

}

ObjetoPerfilBarrido::ObjetoPerfilBarrido(const string &ficheroPLY, int nSegmentos, float longitud) : ObjetoPLY(ficheroPLY){
    if(nSegmentos < 2)
        nSegmentos = 2;
    if(longitud < 0.0)
        longitud = 4.0;

    if(numVertices > 0 && numCaras == 0 && getIsFileReaded() && esElMismoPunto(vertices[0],vertices[vertices.size()-1])){
        // Quitamos el ultimo punto que es el mismo que el primero
        vertices.pop_back();
        verticesPerfil = vertices;
        generarBarrido(nSegmentos, longitud);
    }
    else
        setIsFileReaded(false);
}

void ObjetoPerfilBarrido::generarBarrido(const int &nSegmentos, const float &longitud){
    // Asignamos el nSegmentos
    this->nSegmentos = nSegmentos;

    // Asignamos la longitud del barrido
    this->longitud = longitud;

    // Asignamos el numero de vertices del perfil original
    numVerticesPerfil = verticesPerfil.size();

    // Actualizamos los vectores de vertices, caras y color en funcion de nSegmentos
    updateVerticesCarasColor(nSegmentos);
}

void ObjetoPerfilBarrido::updateVerticesCarasColor(const int nSegmentos){
    // Igualamos el vector de vertices del objeto al perfil para que tenga esos
    // vertices inicialmente
    vertices = verticesPerfil;

    float longitudEntreSegmentos = longitud / nSegmentos;

    // Añadimos los nuevos vertices generados por barrido
    for(unsigned int i = 0; i < nSegmentos; i++){
        for(unsigned int j = 0; j < verticesPerfil.size(); j++){
            float x = vertices[j].x;
            float y = vertices[j].y + (i+1)*longitudEntreSegmentos;
            float z = vertices[j].z;
            vertices.push_back(Vertice(x,y,z));
        }
    }

    // Actualizamos numVertices
    this->numVertices = (unsigned int) vertices.size();
    
    // Borramos el contenido del vector de caras
    caras.clear();

    // Lados para triangulo par e impar de cada cuadrado
    vector<unsigned int> ladosParesImpares;

    // Añadimos todas las caras menos las que se unen con el origen
    for(unsigned int i = 0; i < nSegmentos; i++){
        for(unsigned int j = i*numVerticesPerfil; j < (i*numVerticesPerfil)+numVerticesPerfil-1; j++){

        ladosParesImpares = {
            // Triangulo par
            j, j+1, j+numVerticesPerfil,
            // Triangulo impar
            j+numVerticesPerfil+1, j+numVerticesPerfil, j+1
        };

        // Añadimos las nuevas caras al vector de caras
        caras.push_back(Triangulo(ladosParesImpares[0],ladosParesImpares[1],ladosParesImpares[2]));
        caras.push_back(Triangulo(ladosParesImpares[3],ladosParesImpares[4],ladosParesImpares[5]));
        }
    }
    
    // Limpiamos el vector de lados pares e impares
    ladosParesImpares.clear();

    //Añadimos las caras que se unen con el origen
    unsigned int primerVerticePerfil = 0;
    unsigned int ultimoVerticePerfil = numVerticesPerfil - 1;
    for(unsigned int i = 0; i < nSegmentos; i++){
        ladosParesImpares = {
            // Triangulo par
            ultimoVerticePerfil, primerVerticePerfil, ultimoVerticePerfil+numVerticesPerfil,
            // Triangulo impar
            primerVerticePerfil+numVerticesPerfil, ultimoVerticePerfil+numVerticesPerfil, primerVerticePerfil
        };

        // Añadimos las nuevas caras al vector de caras
        caras.push_back(Triangulo(ladosParesImpares[0],ladosParesImpares[1],ladosParesImpares[2]));
        caras.push_back(Triangulo(ladosParesImpares[3],ladosParesImpares[4],ladosParesImpares[5]));

        // Actualizamos primer y ultimo vertice
        primerVerticePerfil += numVerticesPerfil;
        ultimoVerticePerfil += numVerticesPerfil;
    }

    // Actualizamos el numero de caras
    this->numCaras = caras.size();

    // Borramos el vector de color
    color.clear();

    // Creamos el vector de COLOR
    for(unsigned int i = 0 ; i < numVertices ; i++){
        this->color.push_back(Color(defaultColor.r, defaultColor.g, defaultColor.b));
    }
}

bool ObjetoPerfilBarrido::esElMismoPunto(const Vertice &vertice1, const Vertice &vertice2) const{
    return ((vertice1.x == vertice2.x) && (vertice1.y == vertice2.y) &&(vertice1.z == vertice2.z));
}

void ObjetoPerfilBarrido::incrementarNSegmentos(){
    updateVerticesCarasColor(++nSegmentos);
}

void ObjetoPerfilBarrido::decrementarNSegmentos(){
    // nSegmentos debe ser OBLIGATORIAMENTE >= 2
    if(nSegmentos > 2)
        updateVerticesCarasColor(--nSegmentos);
}