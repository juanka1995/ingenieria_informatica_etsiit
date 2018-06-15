/*
Juan Carlos Ruiz Garcia - Grupo C1
*/

#ifndef _OBJETO3D_H
#define _OBJETO3D_H
#define NMAXPUNTOS 200
#include <vector>
#include "vertex.h"
#include <GL/gl.h>
#include <GL/glut.h>

struct Color{
  float r,g,b;
  Color(){ // Color por defecto
    r = 1.0; g = 0.0; b = 0.0;
  }
  Color(float red, float green, float blue){
    r = red; g = green; b = blue;
  }
};

struct Vertice{
  float x,y,z;
  Vertice(float x1, float y1, float z1){
    x = x1; y = y1; z = z1;
  }
};

struct Triangulo{
  unsigned int l1,l2,l3;
  Triangulo(unsigned int ld1, unsigned int ld2, unsigned int ld3){
    l1 = ld1; l2 = ld2; l3 = ld3;
  }
};

struct Material{
  GLfloat emision[4], ambiente[4], difuso[4], especular[4], brillo;
};

extern int materialActivo;

class Object3D{
  friend class Pierna; 
  friend class Zapatilla;
  friend class Cabeza;
  friend class Ojo; 
  friend class Brazo;
  friend class Cuerpo;
  friend class Escena;
  protected:
    unsigned int numVertices, numCaras;
    std::vector<Vertice> vertices;
    std::vector<Triangulo> caras;
    std::vector<_vertex3f> normalesCaras;
    std::vector<_vertex3f> normalesVertices;
    Material materialRubi, materialDorado, materialTurquesa, materialPorDefecto;
    std::vector<Color> color;
    Color defaultColor;
    void modifyToDifferentColor(std::vector<Color> &arrayColores, const Color &nuevoColor);
    void modifyActualColor(const Color &nuevoColor);

  public:
    Object3D();
    unsigned int getNumVertices();
    unsigned int getNumCaras();
    void dibujarPuntos();
    void dibujarAlambre();
    void dibujarSolido();
    void dibujarAjedrez();
    void calcularNormalesCaras();
    void calcularNormalesVertices();

    void dibujarSinSuavizado();
    void dibujarConSuavizado();

    static void setMaterialActivo(int material);

};

#endif
