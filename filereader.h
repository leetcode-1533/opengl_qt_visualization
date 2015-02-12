#ifndef FILEREADER_H
#define FILEREADER_H

#define xsize 600
#define ysize 248
#define zsize 248

#include<iostream>
#include<fstream>
#include<QVector>
#include<QString>
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QMessageBox>
#include <QStringListIterator>

#include<QHash>

#include <QVector3D>
#include <QList>

#include <QDebug>

class filereader
{
public:
    filereader();
private:
    float readfloat(FILE *f);
    float data[xsize][ysize][zsize];

    QHash<QString,QString> table;

    void reader_table();
    void reader_raw();

    float interpolation_single(float start_value, float end_vaule, float start_location, float end_location, float parameter);
    QVector3D interpolation_3d(QVector3D start, QVector3D end, float parameter, float start_value,float end_value);

    QList<float> gen_cubic(int x, int y, int z);

    void interpolation_generator(float parameter);
    QString gen_condition(float parameter,QList<float> cubic);
};

#endif // FILEREADER_H
