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
    //PGM file ext p2 p5
    // Read from the image file
    //ifstream MyReadFile('myfile.pgm');  instantiate the file using filename/directory 
    ifstream MyReadFile(s->getInputFileName()); 
    if(!MyReadFile.is_open()){
        cout<<"open file failed"<<endl;
        exit(1);
    }
    getline(MyReadFile, s->fileLine);
    s->setMagicNo(s->fileLine);
    s->setExtension(s->fileLine);
    MyReadFile.close();

    cout << s->getInputFileName() << " " << s->getOutputFileName() << " " << s->getDegree() << " " << s->getDirection() << " " << s->getExtension() << endl;
    s->rotateImage();
    //Pgm* mini = new Pgm(s->getInputFileName());

   
   
   return 0;
}