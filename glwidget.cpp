#include "glwidget.h"

glwidget::glwidget(QWidget *parent) :
    QGLWidget(parent)
{
    setAutoBufferSwap(true);
    instruction = new filereader(5000.0);

}

void glwidget::initializeGL(){
    float lightPos[4] = { 300.0, 184.0, 184.0, 1.0 };
    float lightColAmb[4] = { 0.2, 0.2, 0.2, 1.0 };
    float lightColDif[4] = { 0.8, 0.8, 0.8, 1.0 };
    float lightColSpe[4] = { 1.0, 1.0, 1.0, 1.0 };



      glClearColor(0.0, 0.0, 0.0, 1.0);

      glEnable( GL_SMOOTH );
       glEnable( GL_DEPTH_TEST);

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
    qDebug() << instruction->drawlist[0];
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

     glLoadIdentity();
     gluLookAt( 150, 100, 350,  0, 0, 0,  0, 1, 0);

     glTranslatef(-400, -124, -124);

     glColor3f(1.0, 0.0, 0.0);
     glBegin(GL_TRIANGLES);
       glVertex3i(0,  0, 0  );
       glVertex3i(0,0, 300  );
       glVertex3i(300,0,0 );
     glEnd();



}

void glwidget::resizeGL(int w, int h){
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective( 80, (double)w / (double)h, 0.1, 1500);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
