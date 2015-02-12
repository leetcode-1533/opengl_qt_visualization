#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include<QVector3D>
#include<QVector>
#include<glu.h>
#include <gl.h>
#include "filereader.h"
#include <QDebug>

class glwidget : public QGLWidget
{
    Q_OBJECT
public:
     glwidget(QWidget *parent = 0);

     void initializeGL();
     void paintGL();
     void resizeGL(int w, int h);

private:
     filereader * instruction;
signals:

public slots:

};

#endif // GLWIDGET_H
