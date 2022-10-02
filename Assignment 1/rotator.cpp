/*
Authors : Sanskruti Jadhav, Dnyanesh Marne
*/
#include <iostream>
#include <fstream>
#include "rotator.h"

using namespace std;

Rotator *Rotator::instance = 0;

int main(int argc, char** argv){

    if(argc==5){
        Rotator *s = s->getInstance(argv[1],argv[2],argv[3],atoi(argv[4]));
        //PPM p3 p6
        //Pgm p2 p5
        // Read from the image file

        ifstream MyReadFile(s->getInputFileName());
        getline(MyReadFile, s->fileLine);
        s->setExtension(s->fileLine);
        MyReadFile.close();

        cout << s->getInputFileName() << " " << s->getOutputFileName() << " " << s->getDegree() << " " << s->getDirection() << " " << s->getExtension() << endl;
        cout << s->getMagicNo() << endl;
    }else{
        cout << "Please put all required inputs (Execution binary, Input file name, Output file name, Rotation direction, Rotation degree)." << endl;
    }
   return 0;
}