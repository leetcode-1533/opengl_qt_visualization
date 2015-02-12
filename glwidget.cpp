#include "glwidget.h"

glwidget::glwidget(QWidget *parent) :
    QGLWidget(parent)
{
    setAutoBufferSwap(true);
}

void glwidget::initializeGL(){
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling
    glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

}

void glwidget::paintGL(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    gluLookAt(0.0, 0.0, 0.0, 0.0, 0.0, -100.0, 0.0, 1.0, 0.0);
    /*
     * That is, EYE=(0,0,0) at the origin,, AT = (0,0-100) pointing at negative
     * z axis (into the screen) . and up = (0,1,0) correspoends to y-axis.
    */

    glLoadIdentity();

    glBegin(GL_TRIANGLES);
    // Front
    glVertex3f( 0,0,   -1.1);
    glVertex3f(1,0,   -1.1);
    glVertex3f( 0,1, -1.1);
    glEnd();
}

void glwidget::resizeGL(int w, int h){
    QGLWidget::resize(w,h);
}
