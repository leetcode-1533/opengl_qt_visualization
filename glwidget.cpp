#include "glwidget.h"

glwidget::glwidget(QWidget *parent) :
    QGLWidget(parent)
{
}

void glwidget::initializeGL(){
      glClearColor(0.0, 0.0, 0.0, 1.0);
      glEnable( GL_SMOOTH );
      glEnable( GL_DEPTH_TEST);

      float lightPos[4] = { 300.0, 184.0, 184.0, 1.0 };
      float lightColAmb[4] = { 0.2, 0.2, 0.2, 1.0 };
      float lightColDif[4] = { 0.8, 0.8, 0.8, 1.0 };
      float lightColSpe[4] = { 1.0, 1.0, 1.0, 1.0 };

      glEnable(GL_LIGHTING );
      glEnable( GL_LIGHT0 );
      glLightfv( GL_LIGHT0, GL_POSITION, lightPos);
      glLightfv( GL_LIGHT0, GL_AMBIENT, lightColAmb);
      glLightfv( GL_LIGHT0, GL_DIFFUSE, lightColDif);
      glLightfv( GL_LIGHT0, GL_SPECULAR, lightColSpe);


      glEnable(GL_COLOR_MATERIAL);
      glColorMaterial(GL_FRONT_AND_BACK, GL_DIFFUSE);
      glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, 1);
}

void glwidget::paintGL(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();
    gluLookAt( 150, 100, 350,  0, 0, 0,  0, 1, 0);

    glTranslatef(-400, -124, -124);

    /* THIS IS A STUB SHOWING AN ARTIFIAL SURFACE IN THE DATASET   */
    /* REPLACE THE VERTICES IN THE FOLLOWING BLOCK BEGIN-END WITH
       VERTICES GENERATED BY MARCHING CUBES.                       */

    for(int i= 0;i<=3;i++){
    glColor3f(1.0+i, 0.0+3*i, 0.0);
    glBegin(GL_TRIANGLES);
      glVertex3i(300+i*20,  0+i*20, 0  +i*20);
      glVertex3i(300+i*20,247+i*20, 0 +i*20 );
      glVertex3i(300+i*20,247+i*20, 247+i*20);

      glVertex3i(300+i*20,247+i*20, 247+i*20);
      glVertex3i(300+i*20,  0+i*20, 247+i*20);
      glVertex3i(300+i*20,  0+i*20, 0 +i*20 );
    glEnd();
    }
    /* Swap buffers over for smooth animation */
}

void glwidget::resizeGL(int w, int h){
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective( 80, (double)w / (double)h, 0.1, 1500);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}