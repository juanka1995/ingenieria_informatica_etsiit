/*
Juan Carlos Ruiz Garcia - Grupo C1
*/

#ifndef _OBJETO_PERFIL_REVOLUCION_H
#define _OBJETO_PERFIL_REVOLUCION_H

#define _USE_MATH_DEFINES

#include "objetoPLY.h"
#include <math.h>
#include <string>
#include <cstdio>

// Revolucion de un perfil sobre el eje Y
class ObjetoPerfilRevolucion : public ObjetoPLY{
private:
    // Funcion encargada de generar la revolucion, llamada por los distintos constructores
    void generarRevolucion(const int &nSegmentos);

    // Vector que contiene los vertices originales del perfil
    vector<Vertice> verticesPerfil;

    // Contiene el numero de vertices del perfil original
    int numVerticesPerfil;

    // Contiene el eje sobre el que se hace la revolucion
    // Puede vale X, Y o Z
    string ejeRevolucion;

    // Pasa de grados a radianes
    float degreesToRadians(float degrees);
    
    // Contiene el número de segmentos usado
    int nSegmentos;

    // Puede tomar valores:
    //   0-->Tapa superior || 1-->Tapa inferior || 2-->Ambas tapas || 3--> No pueden despintarse tapas
    //      0 significa que la tapa inferior ya existia (puede pintarse/despintarse la superior)
    //      1 significa que la tapa superior ya existia (puede pintarse/despintarse la inferior)
    //      2 significa que no existia ninguna de las dos tapas (pueden pintarse/despintarse ambas)
    //      3 significa que existian las dos tapas (no pueden despintarse)
    int queTapaPuedoPintarODespintar;

    // Informa de si las tapas posibles a pintar/despintar estan ya pintadas o no
    bool estanTapasPintadas;
    
    // Asigna que tapas pueden pintarse o despintarse
    void setQueTapaPuedoPintarODespintar();
    
    // Comprueba si el perfil tiene tapa superior (util durante el constructor)
    bool tienePerfilTapaSuperior() const;
    
    // Comprueba si el perfil tiene tapa inferior (util durante el constructor)
    bool tienePerfilTapaInferior() const;
    
    // Inserta la tapa superior en el perfil
    void insertarTapaSuperiorAlPerfil();
    
    // Inserta la tapa inferior en el perfil
    void insertarTapaInferiorAlPerfil();

    // Actualiza el vector de vertices y de caras en funcion del nSegmentos
    void updateVerticesCarasColor(const int nSegmentos);

    // Realiza la revolucion del perfil dependiendo del eje de rotacion
    void insertarVerticesSegunEjeRevolucion(const int nSegmentos);

public:
    // Constructor por defecto
    ObjetoPerfilRevolucion(){};

    // Constructor manual
    ObjetoPerfilRevolucion(int nSegmentos);

    // Constructor a traves de fichero .ply
    ObjetoPerfilRevolucion(const string &ficheroPLY, int nSegmentos, string eje);

    // Incrementa el valor de nSegmentos en 1
    void incrementarNSegmentos();

    // Decrementa el valor de nSegmentos en 1
    void decrementarNSegmentos();
    
    // Duelve que tapa/s se puede/n pintar o despintar
    int getQueTapaPuedoPintarODespintar() const;

    // Devuelve si las tapas que pueden pintarse/despintarse estan pintadas o no
    bool getEstanTapasPintadas() const;

    // Cambia el valor de estanTapasPintadas
    void setEstanTapasPintadas();

    // Añade las caras de las tapas posibles a pintar/despintar al vector de caras
    void addTapasCorrespondientes(const int tapaAPintar);
        
    // Elimina las caras de las tapas posibles a pintar/despintar del vector de caras
    void deleteTapasCorrespondientes(const int tapaADespintar);

};

#endif