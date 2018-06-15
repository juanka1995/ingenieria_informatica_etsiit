/*
Juan Carlos Ruiz Garcia - Grupo C1
*/

#ifndef _OBJETO_PERFIL_BARRIDO_H
#define _OBJETO_PERFIL_BARRIDO_H

#include "objetoPLY.h"

// Barrido sobre el eje Y de un perfil 
class ObjetoPerfilBarrido : public ObjetoPLY{
private:
    // Función encargada de generar el barrido
    void generarBarrido(const int &nSegmentos, const float &longitud);

    // Vector que contiene los vertices originales del perfil
    vector<Vertice> verticesPerfil;
        
    // Contiene el numero de vertices del perfil original
    int numVerticesPerfil;

    // Contiene el número de segmentos usado
    int nSegmentos;

    // Contiene la longitud del barrido
    float longitud;

    // Actualiza el vector de vertices, de caras y de color en funcion del nSegmentos
    void updateVerticesCarasColor(const int nSegmentos);

    // Comprueba si dos vertices son el mismo
    bool esElMismoPunto(const Vertice &vertice1, const Vertice &vertice2) const;

public:
    // Constructor por defecto
    ObjetoPerfilBarrido(){};

    // Constructor manual
    ObjetoPerfilBarrido(int nSegmentos, float longitud);

    // Constructor a traves de fichero .ply
    ObjetoPerfilBarrido(const string &ficheroPLY, int nSegmentos, float longitud);

    // Incrementa el valor de nSegmentos en 1
    void incrementarNSegmentos();
    
    // Decrementa el valor de nSegmentos en 1
    void decrementarNSegmentos();
};

#endif