#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include<QVector3D>
#include<QVector>
#include<glu.h>


class glwidget : public QGLWidget
{
    Q_OBJECT
public:
     glwidget(QWidget *parent = 0);

     void initializeGL();
     void paintGL();
     void resizeGL(int w, int h);

private:

signals:

public slots:

};

#endif // GLWIDGET_H
