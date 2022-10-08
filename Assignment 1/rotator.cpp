/*
Authors : Sanskruti Jadhav, Dnyanesh Marne
*/
#include <iostream>
#include <fstream>
#include "rotator.h"
#include "pgm.h"

using namespace std;




Rotator *Rotator::instance = 0;

int main(int argc, char** argv){


    Rotator *s = s->getInstance(argv[1],argv[2],argv[3],atoi(argv[4])); //getinstance(inFile, outFile, direction, degree)
    //PPM p3 p6
    //PGM p2 p5



    ifstream MyReadFile(s->getInputFileName()); 
    if(!MyReadFile.is_open()){
        cout<<"open file failed"<<endl;
        exit(1);
    }
    getline(MyReadFile, s->fileLine);
    s->setMagicNo(s->fileLine);
    MyReadFile.close();
    s->rotateImage();
   
   return 0;
}