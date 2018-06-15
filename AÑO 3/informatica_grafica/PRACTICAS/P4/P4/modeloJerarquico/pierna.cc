/*
Juan Carlos Ruiz Garcia - Grupo C1
*/

#include "pierna.h"

Pierna::Pierna(){
    // Inicializo los objetos que forman la pierna de tamaño unitario
    zapatilla = Zapatilla();
    tobillo = ObjetoPLY("modeloJerarquico/ply_modJer/esfera.ply");
    gemelo = ObjetoPLY("modeloJerarquico/ply_modJer/cilindro.ply");
    rodilla = ObjetoPLY("modeloJerarquico/ply_modJer/esfera.ply");
    pantalon = ObjetoPLY("modeloJerarquico/ply_modJer/cilindro.ply");

    grCadera = grRodilla = grTobillo = 0.0;

    maxMovDelanteCadera = -60.0;
    maxMovDelanteRodilla = 0.0;
    maxMovArribaTobillo = -10.0;

    maxMovDetrasCadera = 60.0;
    maxMovDetrasRodilla = 100.0;
    maxMovAbajoTobillo = 45.0;

    velocidadGlobal = velocidadPierna = 5.0;

    tobillo.calcularNormalesCaras();
    tobillo.calcularNormalesVertices();

    gemelo.calcularNormalesCaras();
    gemelo.calcularNormalesVertices();

    rodilla.calcularNormalesCaras();
    rodilla.calcularNormalesVertices();

    pantalon.calcularNormalesCaras();
    pantalon.calcularNormalesVertices();
}

void Pierna::dibujarSolido(){
    glPushMatrix();
        glRotatef(grCadera,1.0,0.0,0.0);       // Grado de libertad Cadera
        glTranslatef(0.0,-1.1,0.0);
        // Zapatilla + Tobillo + Gemelo + Rodilla + Pantalon
        glPushMatrix();
            // Zapatilla + Tobillo + Gemelo + Rodilla
            glPushMatrix();
                // Zapatilla + Tobillo + Gemelo
                glPushMatrix();
                    glRotatef(grRodilla,1.0,0.0,0.0);     // Grado de libertad Rodilla
                    glTranslatef(0.0,-1.1,0.0);
                    // Zapatilla + Tobillo
                    glPushMatrix();
                        // Zapatilla
                        glPushMatrix();
                            glRotatef(grTobillo,1.0,0.0,0.0);       // Grado de libertad Tobillo
                            glTranslatef(0.0,-0.7,0.3);
                            zapatilla.dibujarSolido();
                        glPopMatrix();

                        // Tobillo
                        glPushMatrix();
                            tobillo.modifyActualColor(Color(1.0,0.80,0.0)); // Color amarillo piel
                            glScalef(0.5,0.5,0.5);
                            tobillo.dibujarSolido();
                        glPopMatrix();
                    glPopMatrix();
                
                    // Gemelo
                    glPushMatrix();
                        gemelo.modifyActualColor(Color(1.0,0.80,0.0)); // Color amarillo piel
                        glTranslatef(0.0,0.6,0.0);
                        glScalef(0.4,0.9,0.4);
                        gemelo.dibujarSolido();
                    glPopMatrix();
                glPopMatrix();

                //Rodilla
                glPushMatrix();
                    rodilla.modifyActualColor(Color(1.0,0.80,0.0)); // Color amarillo piel
                    glScalef(0.6,0.6,0.6);
                    rodilla.dibujarSolido();
                glPopMatrix();
            glPopMatrix();

            // Pantalon
            glPushMatrix();
                pantalon.modifyActualColor(Color(0.11,0.60,0.85)); // Color azul zapatillas y pantalon
                glTranslatef(0.0,0.7,0.0);
                glScalef(0.9,1.2,0.9);
                pantalon.dibujarSolido();
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();
}

void Pierna::dibujarSinSuavizado(){
    glPushMatrix();
        glRotatef(grCadera,1.0,0.0,0.0);       // Grado de libertad Cadera
        glTranslatef(0.0,-1.1,0.0);
        // Zapatilla + Tobillo + Gemelo + Rodilla + Pantalon
        glPushMatrix();
            // Zapatilla + Tobillo + Gemelo + Rodilla
            glPushMatrix();
                // Zapatilla + Tobillo + Gemelo
                glPushMatrix();
                    glRotatef(grRodilla,1.0,0.0,0.0);     // Grado de libertad Rodilla
                    glTranslatef(0.0,-1.1,0.0);
                    // Zapatilla + Tobillo
                    glPushMatrix();
                        // Zapatilla
                        glPushMatrix();
                            glRotatef(grTobillo,1.0,0.0,0.0);       // Grado de libertad Tobillo
                            glTranslatef(0.0,-0.7,0.3);
                            zapatilla.dibujarSinSuavizado();
                        glPopMatrix();

                        // Tobillo
                        glPushMatrix();
                            tobillo.modifyActualColor(Color(1.0,0.80,0.0)); // Color amarillo piel
                            glScalef(0.5,0.5,0.5);
                            tobillo.dibujarSinSuavizado();
                        glPopMatrix();
                    glPopMatrix();
                
                    // Gemelo
                    glPushMatrix();
                        gemelo.modifyActualColor(Color(1.0,0.80,0.0)); // Color amarillo piel
                        glTranslatef(0.0,0.6,0.0);
                        glScalef(0.4,0.9,0.4);
                        gemelo.dibujarSinSuavizado();
                    glPopMatrix();
                glPopMatrix();

                //Rodilla
                glPushMatrix();
                    rodilla.modifyActualColor(Color(1.0,0.80,0.0)); // Color amarillo piel
                    glScalef(0.6,0.6,0.6);
                    rodilla.dibujarSinSuavizado();
                glPopMatrix();
            glPopMatrix();

            // Pantalon
            glPushMatrix();
                pantalon.modifyActualColor(Color(0.11,0.60,0.85)); // Color azul zapatillas y pantalon
                glTranslatef(0.0,0.7,0.0);
                glScalef(0.9,1.2,0.9);
                pantalon.dibujarSinSuavizado();
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();
}

void Pierna::dibujarConSuavizado(){
    glPushMatrix();
        glRotatef(grCadera,1.0,0.0,0.0);       // Grado de libertad Cadera
        glTranslatef(0.0,-1.1,0.0);
        // Zapatilla + Tobillo + Gemelo + Rodilla + Pantalon
        glPushMatrix();
            // Zapatilla + Tobillo + Gemelo + Rodilla
            glPushMatrix();
                // Zapatilla + Tobillo + Gemelo
                glPushMatrix();
                    glRotatef(grRodilla,1.0,0.0,0.0);     // Grado de libertad Rodilla
                    glTranslatef(0.0,-1.1,0.0);
                    // Zapatilla + Tobillo
                    glPushMatrix();
                        // Zapatilla
                        glPushMatrix();
                            glRotatef(grTobillo,1.0,0.0,0.0);       // Grado de libertad Tobillo
                            glTranslatef(0.0,-0.7,0.3);
                            zapatilla.dibujarConSuavizado();
                        glPopMatrix();

                        // Tobillo
                        glPushMatrix();
                            tobillo.modifyActualColor(Color(1.0,0.80,0.0)); // Color amarillo piel
                            glScalef(0.5,0.5,0.5);
                            tobillo.dibujarConSuavizado();
                        glPopMatrix();
                    glPopMatrix();
                
                    // Gemelo
                    glPushMatrix();
                        gemelo.modifyActualColor(Color(1.0,0.80,0.0)); // Color amarillo piel
                        glTranslatef(0.0,0.6,0.0);
                        glScalef(0.4,0.9,0.4);
                        gemelo.dibujarConSuavizado();
                    glPopMatrix();
                glPopMatrix();

                //Rodilla
                glPushMatrix();
                    rodilla.modifyActualColor(Color(1.0,0.80,0.0)); // Color amarillo piel
                    glScalef(0.6,0.6,0.6);
                    rodilla.dibujarConSuavizado();
                glPopMatrix();
            glPopMatrix();

            // Pantalon
            glPushMatrix();
                pantalon.modifyActualColor(Color(0.11,0.60,0.85)); // Color azul zapatillas y pantalon
                glTranslatef(0.0,0.7,0.0);
                glScalef(0.9,1.2,0.9);
                pantalon.dibujarConSuavizado();
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();
}

void Pierna::dibujarPuntos(){
    glPushMatrix();
        glRotatef(grCadera,1.0,0.0,0.0);       // Grado de libertad Cadera
        glTranslatef(0.0,-1.1,0.0);
        // Zapatilla + Tobillo + Gemelo + Rodilla + Pantalon
        glPushMatrix();
            // Zapatilla + Tobillo + Gemelo + Rodilla
            glPushMatrix();
                // Zapatilla + Tobillo + Gemelo
                glPushMatrix();
                    glRotatef(grRodilla,1.0,0.0,0.0);     // Grado de libertad Rodilla
                    glTranslatef(0.0,-1.1,0.0);
                    // Zapatilla + Tobillo
                    glPushMatrix();
                        // Zapatilla
                        glPushMatrix();
                            glRotatef(grTobillo,1.0,0.0,0.0);       // Grado de libertad Tobillo
                            glTranslatef(0.0,-0.7,0.3);
                            zapatilla.dibujarPuntos();
                        glPopMatrix();

                        // Tobillo
                        glPushMatrix();
                            tobillo.modifyActualColor(Color(1.0,0.80,0.0)); // Color amarillo piel
                            glScalef(0.5,0.5,0.5);
                            tobillo.dibujarPuntos();
                        glPopMatrix();
                    glPopMatrix();
                
                    // Gemelo
                    glPushMatrix();
                        gemelo.modifyActualColor(Color(1.0,0.80,0.0)); // Color amarillo piel
                        glTranslatef(0.0,0.6,0.0);
                        glScalef(0.4,0.9,0.4);
                        gemelo.dibujarPuntos();
                    glPopMatrix();
                glPopMatrix();

                //Rodilla
                glPushMatrix();
                    rodilla.modifyActualColor(Color(1.0,0.80,0.0)); // Color amarillo piel
                    glScalef(0.6,0.6,0.6);
                    rodilla.dibujarPuntos();
                glPopMatrix();
            glPopMatrix();

            // Pantalon
            glPushMatrix();
                pantalon.modifyActualColor(Color(0.11,0.60,0.85)); // Color azul zapatillas y pantalon
                glTranslatef(0.0,0.7,0.0);
                glScalef(0.9,1.2,0.9);
                pantalon.dibujarPuntos();
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();
}

void Pierna::dibujarAlambre(){
    glPushMatrix();
        glRotatef(grCadera,1.0,0.0,0.0);       // Grado de libertad Cadera
        glTranslatef(0.0,-1.1,0.0);
        // Zapatilla + Tobillo + Gemelo + Rodilla + Pantalon
        glPushMatrix();
            // Zapatilla + Tobillo + Gemelo + Rodilla
            glPushMatrix();
                // Zapatilla + Tobillo + Gemelo
                glPushMatrix();
                    glRotatef(grRodilla,1.0,0.0,0.0);     // Grado de libertad Rodilla
                    glTranslatef(0.0,-1.1,0.0);
                    // Zapatilla + Tobillo
                    glPushMatrix();
                        // Zapatilla
                        glPushMatrix();
                            glRotatef(grTobillo,1.0,0.0,0.0);       // Grado de libertad Tobillo
                            glTranslatef(0.0,-0.7,0.3);
                            zapatilla.dibujarAlambre();
                        glPopMatrix();

                        // Tobillo
                        glPushMatrix();
                            tobillo.modifyActualColor(Color(1.0,0.80,0.0)); // Color amarillo piel
                            glScalef(0.5,0.5,0.5);
                            tobillo.dibujarAlambre();
                        glPopMatrix();
                    glPopMatrix();
                
                    // Gemelo
                    glPushMatrix();
                        gemelo.modifyActualColor(Color(1.0,0.80,0.0)); // Color amarillo piel
                        glTranslatef(0.0,0.6,0.0);
                        glScalef(0.4,0.9,0.4);
                        gemelo.dibujarAlambre();
                    glPopMatrix();
                glPopMatrix();

                //Rodilla
                glPushMatrix();
                    rodilla.modifyActualColor(Color(1.0,0.80,0.0)); // Color amarillo piel
                    glScalef(0.6,0.6,0.6);
                    rodilla.dibujarAlambre();
                glPopMatrix();
            glPopMatrix();

            // Pantalon
            glPushMatrix();
                pantalon.modifyActualColor(Color(0.11,0.60,0.85)); // Color azul zapatillas y pantalon
                glTranslatef(0.0,0.7,0.0);
                glScalef(0.9,1.2,0.9);
                pantalon.dibujarAlambre();
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();
}

void Pierna::dibujarAjedrez(){
    glPushMatrix();
        glRotatef(grCadera,1.0,0.0,0.0);       // Grado de libertad Cadera
        glTranslatef(0.0,-1.1,0.0);
        // Zapatilla + Tobillo + Gemelo + Rodilla + Pantalon
        glPushMatrix();
            // Zapatilla + Tobillo + Gemelo + Rodilla
            glPushMatrix();
                // Zapatilla + Tobillo + Gemelo
                glPushMatrix();
                    glRotatef(grRodilla,1.0,0.0,0.0);     // Grado de libertad Rodilla
                    glTranslatef(0.0,-1.1,0.0);
                    // Zapatilla + Tobillo
                    glPushMatrix();
                        // Zapatilla
                        glPushMatrix();
                            glRotatef(grTobillo,1.0,0.0,0.0);       // Grado de libertad Tobillo
                            glTranslatef(0.0,-0.7,0.3);
                            zapatilla.dibujarAjedrez();
                        glPopMatrix();

                        // Tobillo
                        glPushMatrix();
                            tobillo.modifyActualColor(Color(1.0,0.0,0.0)); // Color amarillo piel
                            glScalef(0.5,0.5,0.5);
                            tobillo.dibujarAjedrez();
                        glPopMatrix();
                    glPopMatrix();
                
                    // Gemelo
                    glPushMatrix();
                        gemelo.modifyActualColor(Color(1.0,0.0,0.0)); // Color amarillo piel
                        glTranslatef(0.0,0.6,0.0);
                        glScalef(0.4,0.9,0.4);
                        gemelo.dibujarAjedrez();
                    glPopMatrix();
                glPopMatrix();

                //Rodilla
                glPushMatrix();
                    rodilla.modifyActualColor(Color(1.0,0.0,0.0)); // Color amarillo piel
                    glScalef(0.6,0.6,0.6);
                    rodilla.dibujarAjedrez();
                glPopMatrix();
            glPopMatrix();

            // Pantalon
            glPushMatrix();
                pantalon.modifyActualColor(Color(1.0,0.0,0.0)); // Color amarillo piel
                glTranslatef(0.0,0.7,0.0);
                glScalef(0.9,1.2,0.9);
                pantalon.dibujarAjedrez();
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();
}

void Pierna::moverTobilloAbajo(){
    if(grTobillo < maxMovAbajoTobillo)
        grTobillo += velocidadGlobal;
}

void Pierna::moverTobilloArriba(){
    if(grTobillo > maxMovArribaTobillo)
        grTobillo -= velocidadGlobal;
}

void Pierna::moverRodillaDetras(){
    if(grRodilla < maxMovDetrasRodilla)
        grRodilla += velocidadGlobal;
}

void Pierna::moverRodillaDelante(){
    if(grRodilla > maxMovDelanteRodilla)
        grRodilla -= velocidadGlobal;
}

void Pierna::moverCaderaDetras(){
    if(grCadera < maxMovDetrasCadera)
        grCadera += velocidadPierna;
}

void Pierna::moverCaderaDelante(){
    if(grCadera > maxMovDelanteCadera)
        grCadera -= velocidadPierna;
}

void Pierna::reset(){
    grCadera = grRodilla = grTobillo = 0.0;
}

void Pierna::setGrCadera(GLfloat nuevosGRCadera){
    grCadera = nuevosGRCadera;
}

bool Pierna::getTopeDetrasCaderaAlcanzado() const{
    return (grCadera >= maxMovDetrasCadera);
}

bool Pierna::getTopeDelanteCaderaAlcanzado() const{
    return (grCadera <= maxMovDelanteCadera);
}

void Pierna::incrementarVelocidadGlobal(GLfloat velocidadGlobalSup){
    velocidadGlobal = velocidadPierna = velocidadGlobalSup;
}

void Pierna::decrementarVelocidadGlobal(GLfloat velocidadGlobalSup){
    velocidadGlobal = velocidadPierna = velocidadGlobalSup;
}

bool Pierna::incrementarVelocidadPierna(){
    bool incrementado = false;
    if(velocidadPierna < 15.0){
        velocidadPierna += 5.0;
        incrementado = true;
    }
    return incrementado;
}

bool Pierna::decrementarVelocidadPierna(){
    bool decrementado = false;
    if(velocidadPierna > 5.0){
        velocidadPierna -= 5.0;
        decrementado = true;
    }
    return decrementado;
}