#ifndef FILEREADER_H
#define FILEREADER_H

#define xsize 600
#define ysize 248
#define zsize 248

#include<iostream>
#include<fstream>
#include<QVector>
#include<QString>

class filereader
{
public:
    filereader();
private:
    float readfloat(FILE *f);
    float data[xsize][ysize][zsize];

};

#endif // FILEREADER_H
