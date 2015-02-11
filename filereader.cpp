#include "filereader.h"

filereader::filereader()
{
    FILE * file = fopen("/Users/y1275963/SciVis/scalarGFull.raw","r");
    for(int x=0;x<xsize;x++){
        for(int y=0;y<ysize;y++){
            for(int z=0;z<zsize;z++){
                data[x][y][z] = readfloat(file);
            }
        }
    }
}


float filereader::readfloat(FILE *f){
    float v;
    fread((void*)(&v),sizeof(v),1,f);
    return v;
}
