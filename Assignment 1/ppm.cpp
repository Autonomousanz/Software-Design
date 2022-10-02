#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "ppm.h"
#include "colorPixel.h"

using namespace std;

Ppm::Ppm(string filename){

    ifstream MyReadFile(filename);
	if(!MyReadFile.is_open()){
        cout<<"open file failed"<<endl;
        exit(1);
    }
    
    getline(MyReadFile,Ppm::tempLine1); // Ppm public variable
    Ppm::setMagicNo(Ppm::tempLine1);
    getline(MyReadFile,Ppm::tempLine1);// ignore this comment
    ss << MyReadFile.rdbuf();
  
   ss >> numcols >> numrows;   // Third line : size
    Ppm::setImgHeight(numrows);
    Ppm::setImgWidth(numcols);
    ss >> maxVal;
    Ppm::setMaxValue(maxVal);
   
    cout << Ppm::getImgHeight() <<" "<< Ppm::getImgWidth() <<" "<< Ppm::getMagicNo() <<" "<<Ppm::getMaxValue() << endl;

    for(row; row < Ppm::getImgHeight(); row++){
        vector<ColorPixel*> tempVec;
        for(col; col < Ppm::getImgWidth(); col++){
            ss >> Ppm::tempLine1;
            ss >> Ppm::tempLine2;
            ss >> Ppm::tempLine3;
            ColorPixel* colorPix = new ColorPixel(Ppm::tempLine1,Ppm:: tempLine2,Ppm:: tempLine3);
            tempVec.push_back(colorPix);
        }
        Ppm::colorImage.push_back(tempVec);
    }



    MyReadFile.close();
    

}
