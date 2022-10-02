#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "pgm.h"
#include "grayPixel.h"

using namespace std;

Pgm::Pgm(string filename){

    ifstream MyReadFile(filename);
	if(!MyReadFile.is_open()){
        cout<<"open file failed"<<endl;
        exit(1);
    }
    
    getline(MyReadFile,Pgm::tempLine); // pgm public variable
    Pgm::setMagicNo(Pgm::tempLine);
    getline(MyReadFile,Pgm::tempLine);// ignore this comment
    ss << MyReadFile.rdbuf();
  
    ss >> numcols >> numrows;   // Third line : size
    Pgm::setImgHeight(numrows);
    Pgm::setImgWidth(numcols);
    ss >> maxVal;
    Pgm::setMaxValue(maxVal);
   
    cout << Pgm::getImgHeight() <<" "<< Pgm::getImgWidth() <<" "<< Pgm::getMagicNo() <<" "<<Pgm::getMaxValue() << endl;

    for(row; row < Pgm::getImgHeight(); row++){
        vector<GrayPixel*> tempVec;
        for(col; col < Pgm::getImgWidth(); col++){
            ss >> Pgm::tempLine;
            GrayPixel* grayPix = new GrayPixel(Pgm::tempLine);
            tempVec.push_back(grayPix);
        }
        Pgm::grayImage.push_back(tempVec);
    }

    cout << "vector rows" << Pgm::grayImage.size() << endl;
    cout << "vector cols" << Pgm::grayImage[0].size() << endl;
    GrayPixel* tempGray = Pgm::grayImage[0][1];
    cout << "value " << tempGray->getGray() << endl;


    MyReadFile.close();
    

}
