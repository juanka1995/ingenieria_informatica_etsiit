/*
Juan Carlos Ruiz Garcia - Grupo C1
*/

#ifndef _OBJETO3D_H
#define _OBJETO3D_H
#define NMAXPUNTOS 200
#include <vector>
#include <GL/gl.h>
#include <GL/glut.h>

struct Color{
  float r,g,b;
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

class Object3D{

  protected:
    unsigned int numVertices, numLados;
    std::vector<Vertice> vertices;
    std::vector<Triangulo> lados;
    std::vector<Color> color;
    void modifyColor(std::vector<Color> &arrayColores, const Color &nuevoColor);

  public:
    Object3D(){};
    unsigned int getNumVertices();
    unsigned int getNumLados();
    void dibujarPuntos();
    void dibujarAlambre();
    void dibujarSolido();
    void dibujarAjedrez();
};

#endif
