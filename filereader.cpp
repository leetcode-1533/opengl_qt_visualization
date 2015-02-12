#include "filereader.h"

filereader::filereader()
{
   // reader_table();
    reader_raw();
 //  qDebug()<<data[599][247][247];
//    QList<float> temp = gen_cubic(0,0,0);
//    qDebug()<<temp.value(0);
        interpolation_generator(5000.0);
  //  qDebug()<<gen_cubic(0,0,0);
}

float filereader::readfloat(FILE *f){
    float v;
    fread((void*)(&v),sizeof(v),1,f);
    return v;
}

void filereader::reader_raw(){
    FILE * file = fopen("/Users/y1275963/SciVis/scalarGFull.raw","r");
    for(int x=0;x<xsize;x++){
        for(int y=0;y<ysize;y++){
            for(int z=0;z<zsize;z++){
                data[x][y][z] = readfloat(file);
            }
        }
    }
}

void filereader::reader_table(){
    QFile file("/Users/y1275963/SciVis/table.txt");
    if(!file.open(QIODevice::ReadOnly)){
        QMessageBox::information(0,"error",file.errorString());
    }

    QTextStream in(&file);

    while(!in.atEnd()){
        QString line = in.readLine();
        QStringList fields = line.split("\t");
        QStringListIterator iter(fields);
        while(iter.hasNext()){
            table.insert(iter.next(),iter.next());
        }
    }
 //   qDebug()<<table.value(QString("0567")).trimmed().split(" ");
}

float filereader::interpolation_single(float start_value, float end_vaule, float start_location, float end_location, float parameter){
    return start_location + (end_location-start_location)*(parameter-start_value)/(end_vaule-start_value);
}

QVector3D filereader::interpolation_3d(QVector3D start, QVector3D end, float parameter, float start_value, float end_value){
    float xtemp = interpolation_single(start_value,end_value,start.x(),end.x(),parameter);
    float ytemp = interpolation_single(start_value,end_value,start.y(),end.y(),parameter);
    float ztemp = interpolation_single(start_value,end_value,start.z(),end.z(),parameter);
    return QVector3D(xtemp,ytemp,ztemp);
}

void filereader::interpolation_generator(float parameter){
    QList<float> cubic_temp;
    QString condition;
    int jump = 10;
    for(int x=0;x<xsize-1-jump;x+=jump){
        for(int y=0;y<ysize-1-jump;y+=jump){
            for(int z=0;z<zsize-1-jump;z+=jump){
                cubic_temp = gen_cubic(x,y,z);
                condition = gen_condition(parameter,cubic_temp);
          //      qDebug()<<condition;
        }
    }
}
}

QString filereader::gen_condition(float parameter,QList<float> cubic){
    QList<bool> cubic_logic;
    float float_temp;
    QList<int> con_list;
    QString string;

    foreach (float_temp,cubic){
        cubic_logic << (float_temp > parameter);
    }

    for(int iter =0;iter<=7;iter++){
        if(cubic_logic.value(iter)){
            con_list<<iter;
        }
    }
    qSort(con_list);

    for(int i =0;i<con_list.size();i++){
        string += QString::number(con_list[i]);
    }
    return string;
}

QList<float> filereader::gen_cubic( int x, int y, int z){
    QList<float> cubic;
    float val0 = data[x][y][z];
    float val1 = data[x+1][y][z];
    float val4 = data[x][y][z+1];
    float val3 = data[x][y+1][z];
    float val7 = data[x][y+1][z+1];
    float val6 = data[x+1][y+1][z+1];
    float val5 = data[x+1][y][z+1];
    float val2 = data[x+1][y+1][z];

    cubic<<val0<<val1<<val2<<val3<<val4<<val5<<val6<<val7;
    return cubic;
}

