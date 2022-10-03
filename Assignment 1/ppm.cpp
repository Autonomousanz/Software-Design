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

    for(row=0; row < Ppm::getImgHeight(); row++){
        vector<ColorPixel*> tempVec;
        for(col=0; col < Ppm::getImgWidth(); col++){
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

void Ppm::storeFile(vector<vector<ColorPixel*>> rotatedMatrix, string outputFileName){
         ofstream MyReadFile;
         MyReadFile.open(outputFileName);

         MyReadFile << Ppm::getMagicNo() << "\n";
         MyReadFile << "# this is rotated result" << "\n";
         MyReadFile << Ppm::getImgWidth() << " " << Ppm::getImgHeight() << "\n";
         MyReadFile << Ppm::getMaxValue() << "\n";

         for (int i=0; i< (Ppm::getImgHeight()); i++){
            for (int j=0; j< (Ppm::getImgWidth()); j++){
                ColorPixel* tempcolor = rotatedMatrix[i][j];                    
                MyReadFile << tempcolor->getRed() << "\n";
                MyReadFile << tempcolor->getGreen() << "\n";
                MyReadFile << tempcolor->getBlue() << "\n";
            }
         }
         MyReadFile.close();
}
