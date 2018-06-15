/*
Juan Carlos Ruiz Garcia - Grupo C1
*/

#include "cabeza.h"

Cabeza::Cabeza(){
    ojo = Ojo();
    nariz = ObjetoPLY("modeloJerarquico/ply_modJer/nariz.ply");
    oreja = ObjetoPLY("modeloJerarquico/ply_modJer/media_esfera.ply");
    pelo = ObjetoPLY("modeloJerarquico/ply_modJer/pelo.ply");
    cara = ObjetoPLY("modeloJerarquico/ply_modJer/cilindro.ply");
    boca = ObjetoPLY("modeloJerarquico/ply_modJer/boca.ply");
    cuello = ObjetoPLY("modeloJerarquico/ply_modJer/cuello.ply");

    grCabeza = 0.0;

    velocidadGlobal = 5.0;

    maxMovDerechaCabeza = -45.0;
    maxMovIzquierdaCabeza = 45.0;
}

void Cabeza::dibujarSolido(){
    glScalef(5.0,5.0,5.0); // Borrar
    
    // Cabeza con cuello
    glPushMatrix();
        glRotatef(grCabeza,0.0,1.0,0.0);
        glTranslatef(0.0,0.2,0.0);
        // Cuello
        glPushMatrix();
            cuello.modifyActualColor(Color(1.0,0.80,0.0)); // Color amarillo piel
            glTranslatef(0.0,-0.10,0.05);
            glScalef(0.75,0.35,0.70);
            cuello.dibujarSolido();
        glPopMatrix();
        //Cabeza sin cuello
        glTranslatef(0.0,0.5,0.2);
        glPushMatrix();
            // Cara
            glPushMatrix();
                cara.modifyActualColor(Color(1.0,0.80,0.0)); // Color amarillo piel
                cara.dibujarSolido();
            glPopMatrix();
            // Ojo Derecho
            glPushMatrix();
                glTranslatef(-0.2,0.1,0.4);
                glScalef(0.8,0.8,0.8);
                ojo.dibujarSolido();
            glPopMatrix();
            // Ojo Izquierdo
            glPushMatrix();
                glTranslatef(0.2,0.1,0.4);
                glScalef(0.8,0.8,0.8);
                ojo.dibujarSolido();
            glPopMatrix();
            // Oreja derecha
            glPushMatrix();
                oreja.modifyActualColor(Color(1.0,0.75,0.0)); // Color amarillo piel
                glTranslatef(-0.5,0.0,0.0);
                glScalef(0.25,0.25,0.3);
                glTranslatef(0.0,0.1,0.0);
                glRotatef(-90.0,1.0,0.0,0.0);
                glTranslatef(0.0,0.15,-0.5);
                oreja.dibujarSolido();
            glPopMatrix();
            // Oreja derecha
            glPushMatrix();
                oreja.modifyActualColor(Color(1.0,0.75,0.0)); // Color amarillo piel
                glTranslatef(0.5,0.0,0.0);
                glScalef(0.25,0.25,0.3);
                glTranslatef(0.0,0.1,0.0);
                glRotatef(-90.0,1.0,0.0,0.0);
                glTranslatef(0.0,0.15,-0.5);
                oreja.dibujarSolido();
            glPopMatrix();
            // Pelo
            glPushMatrix();
                pelo.modifyActualColor(Color(1.0,0.80,0.0)); // Color amarillo piel
                glTranslatef(0.0,0.5,0.0);
                glScalef(1.03,0.9,1.03);
                pelo.dibujarSolido();
            glPopMatrix();
            // Nariz
            glPushMatrix();
                nariz.modifyActualColor(Color(1.0,0.72,0.0)); // Color amarillo piel
                glTranslatef(0.0,-0.15,0.55);
                glScalef(0.14,0.14,0.2);
                nariz.dibujarSolido();
            glPopMatrix();
            // Boca
            glPushMatrix();
                boca.modifyActualColor(Color(1.0,0.70,0.0)); // Color amarillo piel
                glTranslatef(0.0,-0.45,0.0);
                glRotatef(14.0,1.0,0.0,0.0);
                glScalef(0.75,0.52,0.75);
                boca.dibujarSolido();
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();
}

void Cabeza::dibujarAlambre(){
    glScalef(5.0,5.0,5.0); // Borrar
    
    // Cabeza con cuello
    glPushMatrix();
        glRotatef(grCabeza,0.0,1.0,0.0);
        glTranslatef(0.0,0.2,0.0);
        // Cuello
        glPushMatrix();
            cuello.modifyActualColor(Color(1.0,0.80,0.0)); // Color amarillo piel
            glTranslatef(0.0,-0.10,0.05);
            glScalef(0.75,0.35,0.70);
            cuello.dibujarAlambre();
        glPopMatrix();
        //Cabeza sin cuello
        glTranslatef(0.0,0.5,0.2);
        glPushMatrix();
            // Cara
            glPushMatrix();
                cara.modifyActualColor(Color(1.0,0.80,0.0)); // Color amarillo piel
                cara.dibujarAlambre();
            glPopMatrix();
            // Ojo Derecho
            glPushMatrix();
                glTranslatef(-0.2,0.1,0.4);
                glScalef(0.8,0.8,0.8);
                ojo.dibujarAlambre();
            glPopMatrix();
            // Ojo Izquierdo
            glPushMatrix();
                glTranslatef(0.2,0.1,0.4);
                glScalef(0.8,0.8,0.8);
                ojo.dibujarAlambre();
            glPopMatrix();
            // Oreja derecha
            glPushMatrix();
                oreja.modifyActualColor(Color(1.0,0.75,0.0)); // Color amarillo piel
                glTranslatef(-0.5,0.0,0.0);
                glScalef(0.25,0.25,0.3);
                glTranslatef(0.0,0.1,0.0);
                glRotatef(-90.0,1.0,0.0,0.0);
                glTranslatef(0.0,0.15,-0.5);
                oreja.dibujarAlambre();
            glPopMatrix();
            // Oreja derecha
            glPushMatrix();
                oreja.modifyActualColor(Color(1.0,0.75,0.0)); // Color amarillo piel
                glTranslatef(0.5,0.0,0.0);
                glScalef(0.25,0.25,0.3);
                glTranslatef(0.0,0.1,0.0);
                glRotatef(-90.0,1.0,0.0,0.0);
                glTranslatef(0.0,0.15,-0.5);
                oreja.dibujarAlambre();
            glPopMatrix();
            // Pelo
            glPushMatrix();
                pelo.modifyActualColor(Color(1.0,0.80,0.0)); // Color amarillo piel
                glTranslatef(0.0,0.5,0.0);
                glScalef(1.03,0.9,1.03);
                pelo.dibujarAlambre();
            glPopMatrix();
            // Nariz
            glPushMatrix();
                nariz.modifyActualColor(Color(1.0,0.72,0.0)); // Color amarillo piel
                glTranslatef(0.0,-0.15,0.55);
                glScalef(0.14,0.14,0.2);
                nariz.dibujarAlambre();
            glPopMatrix();
            // Boca
            glPushMatrix();
                boca.modifyActualColor(Color(1.0,0.70,0.0)); // Color amarillo piel
                glTranslatef(0.0,-0.45,0.0);
                glRotatef(14.0,1.0,0.0,0.0);
                glScalef(0.75,0.52,0.75);
                boca.dibujarAlambre();
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();
}

void Cabeza::dibujarPuntos(){
    glScalef(5.0,5.0,5.0); // Borrar
    
    // Cabeza con cuello
    glPushMatrix();
        glRotatef(grCabeza,0.0,1.0,0.0);
        glTranslatef(0.0,0.2,0.0);
        // Cuello
        glPushMatrix();
            cuello.modifyActualColor(Color(1.0,0.80,0.0)); // Color amarillo piel
            glTranslatef(0.0,-0.10,0.05);
            glScalef(0.75,0.35,0.70);
            cuello.dibujarPuntos();
        glPopMatrix();
        //Cabeza sin cuello
        glTranslatef(0.0,0.5,0.2);
        glPushMatrix();
            // Cara
            glPushMatrix();
                cara.modifyActualColor(Color(1.0,0.80,0.0)); // Color amarillo piel
                cara.dibujarPuntos();
            glPopMatrix();
            // Ojo Derecho
            glPushMatrix();
                glTranslatef(-0.2,0.1,0.4);
                glScalef(0.8,0.8,0.8);
                ojo.dibujarPuntos();
            glPopMatrix();
            // Ojo Izquierdo
            glPushMatrix();
                glTranslatef(0.2,0.1,0.4);
                glScalef(0.8,0.8,0.8);
                ojo.dibujarPuntos();
            glPopMatrix();
            // Oreja derecha
            glPushMatrix();
                oreja.modifyActualColor(Color(1.0,0.75,0.0)); // Color amarillo piel
                glTranslatef(-0.5,0.0,0.0);
                glScalef(0.25,0.25,0.3);
                glTranslatef(0.0,0.1,0.0);
                glRotatef(-90.0,1.0,0.0,0.0);
                glTranslatef(0.0,0.15,-0.5);
                oreja.dibujarPuntos();
            glPopMatrix();
            // Oreja derecha
            glPushMatrix();
                oreja.modifyActualColor(Color(1.0,0.75,0.0)); // Color amarillo piel
                glTranslatef(0.5,0.0,0.0);
                glScalef(0.25,0.25,0.3);
                glTranslatef(0.0,0.1,0.0);
                glRotatef(-90.0,1.0,0.0,0.0);
                glTranslatef(0.0,0.15,-0.5);
                oreja.dibujarPuntos();
            glPopMatrix();
            // Pelo
            glPushMatrix();
                pelo.modifyActualColor(Color(1.0,0.80,0.0)); // Color amarillo piel
                glTranslatef(0.0,0.5,0.0);
                glScalef(1.03,0.9,1.03);
                pelo.dibujarPuntos();
            glPopMatrix();
            // Nariz
            glPushMatrix();
                nariz.modifyActualColor(Color(1.0,0.72,0.0)); // Color amarillo piel
                glTranslatef(0.0,-0.15,0.55);
                glScalef(0.14,0.14,0.2);
                nariz.dibujarPuntos();
            glPopMatrix();
            // Boca
            glPushMatrix();
                boca.modifyActualColor(Color(1.0,0.70,0.0)); // Color amarillo piel
                glTranslatef(0.0,-0.45,0.0);
                glRotatef(14.0,1.0,0.0,0.0);
                glScalef(0.75,0.52,0.75);
                boca.dibujarPuntos();
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();
}

void Cabeza::dibujarAjedrez(){
    glScalef(5.0,5.0,5.0); // Borrar
    
    // Cabeza con cuello
    glPushMatrix();
        glRotatef(grCabeza,0.0,1.0,0.0);
        glTranslatef(0.0,0.2,0.0);
        // Cuello
        glPushMatrix();
            cuello.modifyActualColor(Color(1.0,0.0,0.0)); // Color amarillo piel
            glTranslatef(0.0,-0.10,0.05);
            glScalef(0.75,0.35,0.70);
            cuello.dibujarAjedrez();
        glPopMatrix();
        //Cabeza sin cuello
        glTranslatef(0.0,0.5,0.2);
        glPushMatrix();
            // Cara
            glPushMatrix();
                cara.modifyActualColor(Color(1.0,0.0,0.0)); // Color amarillo piel
                cara.dibujarAjedrez();
            glPopMatrix();
            // Ojo Derecho
            glPushMatrix();
                glTranslatef(-0.2,0.1,0.4);
                glScalef(0.8,0.8,0.8);
                ojo.dibujarAjedrez();
            glPopMatrix();
            // Ojo Izquierdo
            glPushMatrix();
                glTranslatef(0.2,0.1,0.4);
                glScalef(0.8,0.8,0.8);
                ojo.dibujarAjedrez();
            glPopMatrix();
            // Oreja derecha
            glPushMatrix();
                oreja.modifyActualColor(Color(1.0,0.0,0.0)); // Color amarillo piel
                glTranslatef(-0.5,0.0,0.0);
                glScalef(0.25,0.25,0.3);
                glTranslatef(0.0,0.1,0.0);
                glRotatef(-90.0,1.0,0.0,0.0);
                glTranslatef(0.0,0.15,-0.5);
                oreja.dibujarAjedrez();
            glPopMatrix();
            // Oreja derecha
            glPushMatrix();
                oreja.modifyActualColor(Color(1.0,0.0,0.0)); // Color amarillo piel
                glTranslatef(0.5,0.0,0.0);
                glScalef(0.25,0.25,0.3);
                glTranslatef(0.0,0.1,0.0);
                glRotatef(-90.0,1.0,0.0,0.0);
                glTranslatef(0.0,0.15,-0.5);
                oreja.dibujarAjedrez();
            glPopMatrix();
            // Pelo
            glPushMatrix();
                pelo.modifyActualColor(Color(1.0,0.0,0.0)); // Color amarillo piel
                glTranslatef(0.0,0.5,0.0);
                glScalef(1.03,0.9,1.03);
                pelo.dibujarAjedrez();
            glPopMatrix();
            // Nariz
            glPushMatrix();
                nariz.modifyActualColor(Color(1.0,0.0,0.0)); // Color amarillo piel
                glTranslatef(0.0,-0.15,0.55);
                glScalef(0.14,0.14,0.2);
                nariz.dibujarAjedrez();
            glPopMatrix();
            // Boca
            glPushMatrix();
                boca.modifyActualColor(Color(1.0,0.0,0.0)); // Color amarillo piel
                glTranslatef(0.0,-0.45,0.0);
                glRotatef(14.0,1.0,0.0,0.0);
                glScalef(0.75,0.52,0.75);
                boca.dibujarAjedrez();
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();
}

void Cabeza::moverCabezaDerecha(){
    if(grCabeza > maxMovDerechaCabeza)
        grCabeza -= velocidadGlobal;
}
void Cabeza::moverCabezaIzquierda(){
    if(grCabeza < maxMovIzquierdaCabeza)
        grCabeza += velocidadGlobal;
}

void Cabeza::reset(){
    grCabeza = 0.0;
}

void Cabeza::incrementarVelocidadGlobal(GLfloat velocidadGlobalSup){
    velocidadGlobal = velocidadGlobalSup;
}

void Cabeza::decrementarVelocidadGlobal(GLfloat velocidadGlobalSup){
    velocidadGlobal = velocidadGlobalSup;
}