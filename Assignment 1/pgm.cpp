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
   
    
    for(row=0; row < Pgm::getImgHeight(); row++){
        vector<GrayPixel*> tempVec;
        for(col=0; col < Pgm::getImgWidth(); col++){
            ss >> Pgm::tempLine;
            GrayPixel* grayPix = new GrayPixel(Pgm::tempLine);
            tempVec.push_back(grayPix);
        }
        Pgm::grayImage.push_back(tempVec);
    }



    MyReadFile.close();
    
}

void Pgm::storeFile(vector<vector<GrayPixel*>> rotatedMatrix, string outputFileName){
         ofstream MyReadFile;
         MyReadFile.open(outputFileName);

         MyReadFile << Pgm::getMagicNo() << "\n";
         MyReadFile << "# this is rotated result" << "\n";
         MyReadFile << Pgm::getImgWidth() << " " << Pgm::getImgHeight() << "\n";
         MyReadFile << Pgm::getMaxValue() << "\n";

         for (int i=0; i< (Pgm::getImgHeight()); i++){
            for (int j=0; j< (Pgm::getImgWidth()); j++){
                GrayPixel* tempcolor = rotatedMatrix[i][j];                    
                MyReadFile << tempcolor->getGray() << "\n";
            }
         }
         MyReadFile.close();
}



