/*
Juan Carlos Ruiz Garcia - Grupo C1
*/

#include "brazo.h"

Brazo::Brazo(){
    
    antebrazo_mano = ObjetoPLY("modeloJerarquico/ply_modJer/antebrazo_mano.ply");
    codo = ObjetoPLY("modeloJerarquico/ply_modJer/esfera.ply");
    hombro = ObjetoPLY("modeloJerarquico/ply_modJer/hombro.ply");

    grCodo = grHombro = 0.0;

    maxMovAbajoCodo = 0.0;
    maxMovArribaCodo = -120.0;

    velocidadGlobal = 5.0;

    velocidadHombro = velocidadGlobal;
}

void Brazo::dibujarSolido(){
    // Brazo completo
    glPushMatrix();
    glScalef(5,5,5);
        glRotatef(grHombro,1.0,0.0,0.0);
        glRotatef(-50.0,0.0,0.0,1.0);
        glTranslatef(0.0,-0.6,0.0);
        // Antebrazo + Mano + Codo + Hombro
        glPushMatrix();
            // Hombro
            glPushMatrix();
                hombro.modifyActualColor(Color(1.0,0.5,0.0)); // Color naranja camiseta
                glTranslatef(0.0,0.35,0.0);
                glScalef(0.35,0.65,0.35);
                hombro.dibujarSolido();
            glPopMatrix();
            // Antebrazo + Mano + Codo
            glPushMatrix();
                //Antebrazo + Mano
                glPushMatrix();
                    antebrazo_mano.modifyActualColor(Color(1.0,0.80,0.0)); // Color amarillo piel
                    glRotatef(grCodo,1.0,0.0,0.0);
                    glTranslatef(0.0,-0.35,0.0);
                    glRotatef(180.0,1.0,0.0,0.0);
                    glScalef(0.6,0.8,0.6);
                    antebrazo_mano.dibujarSolido();
                glPopMatrix();
                // Codo
                glPushMatrix();
                    codo.modifyActualColor(Color(1.0,0.80,0.0)); // Color amarillo piel
                    glScalef(0.26,0.26,0.26);
                    codo.dibujarSolido();
                glPopMatrix();
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();
}

void Brazo::dibujarAlambre(){
    // Brazo completo
    glPushMatrix();
    glScalef(5,5,5);
        glRotatef(grHombro,1.0,0.0,0.0);
        glRotatef(-50.0,0.0,0.0,1.0);
        glTranslatef(0.0,-0.6,0.0);
        // Antebrazo + Mano + Codo + Hombro
        glPushMatrix();
            // Hombro
            glPushMatrix();
                hombro.modifyActualColor(Color(1.0,0.5,0.0)); // Color naranja camiseta
                glTranslatef(0.0,0.35,0.0);
                glScalef(0.35,0.65,0.35);
                hombro.dibujarAlambre();
            glPopMatrix();
            // Antebrazo + Mano + Codo
            glPushMatrix();
                //Antebrazo + Mano
                glPushMatrix();
                    antebrazo_mano.modifyActualColor(Color(1.0,0.80,0.0)); // Color amarillo piel
                    glRotatef(grCodo,1.0,0.0,0.0);
                    glTranslatef(0.0,-0.35,0.0);
                    glRotatef(180.0,1.0,0.0,0.0);
                    glScalef(0.6,0.8,0.6);
                    antebrazo_mano.dibujarAlambre();
                glPopMatrix();
                // Codo
                glPushMatrix();
                    codo.modifyActualColor(Color(1.0,0.80,0.0)); // Color amarillo piel
                    glScalef(0.26,0.26,0.26);
                    codo.dibujarAlambre();
                glPopMatrix();
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();
}

void Brazo::dibujarPuntos(){
    // Brazo completo
    glPushMatrix();
    glScalef(5,5,5);
        glRotatef(grHombro,1.0,0.0,0.0);
        glRotatef(-50.0,0.0,0.0,1.0);
        glTranslatef(0.0,-0.6,0.0);
        // Antebrazo + Mano + Codo + Hombro
        glPushMatrix();
            // Hombro
            glPushMatrix();
                hombro.modifyActualColor(Color(1.0,0.5,0.0)); // Color naranja camiseta
                glTranslatef(0.0,0.35,0.0);
                glScalef(0.35,0.65,0.35);
                hombro.dibujarPuntos();
            glPopMatrix();
            // Antebrazo + Mano + Codo
            glPushMatrix();
                //Antebrazo + Mano
                glPushMatrix();
                    antebrazo_mano.modifyActualColor(Color(1.0,0.80,0.0)); // Color amarillo piel
                    glRotatef(grCodo,1.0,0.0,0.0);
                    glTranslatef(0.0,-0.35,0.0);
                    glRotatef(180.0,1.0,0.0,0.0);
                    glScalef(0.6,0.8,0.6);
                    antebrazo_mano.dibujarPuntos();
                glPopMatrix();
                // Codo
                glPushMatrix();
                    codo.modifyActualColor(Color(1.0,0.80,0.0)); // Color amarillo piel
                    glScalef(0.26,0.26,0.26);
                    codo.dibujarPuntos();
                glPopMatrix();
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();
}

void Brazo::dibujarAjedrez(){
    // Brazo completo
    glPushMatrix();
    glScalef(5,5,5);
        glRotatef(grHombro,1.0,0.0,0.0);
        glRotatef(-50.0,0.0,0.0,1.0);
        glTranslatef(0.0,-0.6,0.0);
        // Antebrazo + Mano + Codo + Hombro
        glPushMatrix();
            // Hombro
            glPushMatrix();
                hombro.modifyActualColor(Color(1.0,0.0,0.0)); // Color amarillo piel
                glTranslatef(0.0,0.35,0.0);
                glScalef(0.35,0.65,0.35);
                hombro.dibujarAjedrez();
            glPopMatrix();
            // Antebrazo + Mano + Codo
            glPushMatrix();
                //Antebrazo + Mano
                glPushMatrix();
                    antebrazo_mano.modifyActualColor(Color(1.0,0.0,0.0)); // Color amarillo piel
                    glRotatef(grCodo,1.0,0.0,0.0);
                    glTranslatef(0.0,-0.35,0.0);
                    glRotatef(180.0,1.0,0.0,0.0);
                    glScalef(0.6,0.8,0.6);
                    antebrazo_mano.dibujarAjedrez();
                glPopMatrix();
                // Codo
                glPushMatrix();
                    codo.modifyActualColor(Color(1.0,0.0,0.0)); // Color amarillo piel
                    glScalef(0.26,0.26,0.26);
                    codo.dibujarAjedrez();
                glPopMatrix();
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();
}

void Brazo::moverHombroArriba(){
    if(grCodo >= -10.0)
        grHombro -= velocidadHombro;
}

void Brazo::moverHombroAbajo(){
    if(grCodo >= -10.0)
        grHombro += velocidadHombro;
}

void Brazo::moverCodoArriba(){
    if(grCodo > maxMovArribaCodo)
        grCodo -= velocidadGlobal;
}

void Brazo::moverCodoAbajo(){
    if(grCodo < 0.0)
        grCodo += velocidadGlobal;
}

void Brazo::reset(){
    grCodo = grHombro = 0.0;
}

void Brazo::setGradosHombro(GLfloat gradosHombro){
    grHombro = gradosHombro;
}

void Brazo::incrementarVelocidadGlobal(GLfloat velocidadGlobalSup){
    velocidadGlobal = velocidadHombro = velocidadGlobalSup;
}

void Brazo::decrementarVelocidadGlobal(GLfloat velocidadGlobalSup){
    velocidadGlobal = velocidadHombro = velocidadGlobalSup;
}

bool Brazo::incrementarVelocidadHombro(){
    bool incrementado = false;
    if(velocidadHombro < 15.0){
        velocidadHombro += 5.0;
        incrementado = true;
    }
    return incrementado;
}

bool Brazo::decrementarVelocidadHombro(){
    bool decrementado = false;
    if(velocidadHombro > 5.0){
        velocidadHombro -= 5.0;
        decrementado = true;
    }
    return decrementado;
}