/*
Juan Carlos Ruiz Garcia - Grupo C1
*/

#include "luz.h"

Luz::Luz(_vertex4f ambiente, _vertex4f difuso, _vertex4f especular, _vertex4f direcPosi){
    cAmbiental = ambiente;
    cDifuso = difuso;
    cEspecular = especular;
    dirPos = direcPosi;

    rotarY = rotarZ = 0.0;
}

void Luz::posicionarLuz(int numLuz){
    switch(numLuz){
        case 0:
            glLightfv(GL_LIGHT0, GL_AMBIENT, &cAmbiental[0]);
            glLightfv(GL_LIGHT0, GL_DIFFUSE, &cDifuso[0]);
            glLightfv(GL_LIGHT0, GL_SPECULAR, &cEspecular[0]);
            glPushMatrix();
                glRotatef(rotarY,0.0,1.0,0.0);
                glLightfv(GL_LIGHT0, GL_POSITION, &dirPos[0]);
            glPopMatrix();
        break;
        case 1:
            glLightfv(GL_LIGHT1, GL_AMBIENT, &cAmbiental[0]);
            glLightfv(GL_LIGHT1, GL_DIFFUSE, &cDifuso[0]);
            glLightfv(GL_LIGHT1, GL_SPECULAR, &cEspecular[0]);
            glPushMatrix();
                glRotatef(rotarZ,0.0,0.0,1.0);
                glLightfv(GL_LIGHT1, GL_POSITION, &dirPos[0]);
            glPopMatrix();
        break;
        case 2:
            glLightfv(GL_LIGHT2, GL_AMBIENT, &cAmbiental[0]);
            glLightfv(GL_LIGHT2, GL_DIFFUSE, &cDifuso[0]);
            glLightfv(GL_LIGHT2, GL_SPECULAR, &cEspecular[0]);
            glLightfv(GL_LIGHT2, GL_POSITION, &dirPos[0]);
        break;
        case 3:
            glLightfv(GL_LIGHT3, GL_AMBIENT, &cAmbiental[0]);
            glLightfv(GL_LIGHT3, GL_DIFFUSE, &cDifuso[0]);
            glLightfv(GL_LIGHT3, GL_SPECULAR, &cEspecular[0]);
            glLightfv(GL_LIGHT3, GL_POSITION, &dirPos[0]);
        break;
        case 4:
            glLightfv(GL_LIGHT4, GL_AMBIENT, &cAmbiental[0]);
            glLightfv(GL_LIGHT4, GL_DIFFUSE, &cDifuso[0]);
            glLightfv(GL_LIGHT4, GL_SPECULAR, &cEspecular[0]);
            glLightfv(GL_LIGHT4, GL_POSITION, &dirPos[0]);
        break;
        case 5:
            glLightfv(GL_LIGHT5, GL_AMBIENT, &cAmbiental[0]);
            glLightfv(GL_LIGHT5, GL_DIFFUSE, &cDifuso[0]);
            glLightfv(GL_LIGHT5, GL_SPECULAR, &cEspecular[0]);
            glLightfv(GL_LIGHT5, GL_POSITION, &dirPos[0]);
        break;
        case 6:
            glLightfv(GL_LIGHT6, GL_AMBIENT, &cAmbiental[0]);
            glLightfv(GL_LIGHT6, GL_DIFFUSE, &cDifuso[0]);
            glLightfv(GL_LIGHT6, GL_SPECULAR, &cEspecular[0]);
            glLightfv(GL_LIGHT6, GL_POSITION, &dirPos[0]);
        break;
        case 7:
            glLightfv(GL_LIGHT7, GL_AMBIENT, &cAmbiental[0]);
            glLightfv(GL_LIGHT7, GL_DIFFUSE, &cDifuso[0]);
            glLightfv(GL_LIGHT7, GL_SPECULAR, &cEspecular[0]);
            glLightfv(GL_LIGHT7, GL_POSITION, &dirPos[0]);
        break;
    }
}

void Luz::activarLuz(int numLuz){
    switch(numLuz){
        case 0:
            glEnable(GL_LIGHT0);
        break;
        case 1:
            glEnable(GL_LIGHT1);
        break;
        case 2:
            glEnable(GL_LIGHT2);
        break;
        case 3:
            glEnable(GL_LIGHT3);
        break;
        case 4:
            glEnable(GL_LIGHT4);
        break;
        case 5:
            glEnable(GL_LIGHT5);
        break;
        case 6:
            glEnable(GL_LIGHT6);
        break;
        case 7:
            glEnable(GL_LIGHT7);
        break;
    }
}

void Luz::desactivarLuz(int numLuz){
    switch(numLuz){
        case 0:
            glDisable(GL_LIGHT0);
        break;
        case 1:
            glDisable(GL_LIGHT1);
        break;
        case 2:
            glDisable(GL_LIGHT2);
        break;
        case 3:
            glDisable(GL_LIGHT3);
        break;
        case 4:
            glDisable(GL_LIGHT4);
        break;
        case 5:
            glDisable(GL_LIGHT5);
        break;
        case 6:
            glDisable(GL_LIGHT6);
        break;
        case 7:
            glDisable(GL_LIGHT7);
        break;
    }
}

void Luz::incrementarRotacionLuz1(){
    rotarY += 5.0;
}

void Luz::incrementarRotacionLuz2(){
    rotarZ += 5.0;
}