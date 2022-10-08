#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "ppm.h"
#include "colorPixel.h"

using namespace std;

Ppm::Ppm(string filename,string EMagic){
    if (EMagic == "P3"){
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
            Ppm::Original_img.push_back(tempVec);
        }
        MyReadFile.close();
    }else {

        ifstream MyReadFile(filename, ios::binary | ios::in);
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
        MyReadFile.close();

        vector<BYTE> ImgData = Ppm::readfile(filename);

        //cout << "ImgData" << ImgData.size() << endl;

        chardiff = ImgData.size() - (numcols*numrows*3);

        //cout << " chardiff " <<chardiff<< endl;


        for(int i=0 ; i < numrows; i++ ){ 
            vector<BYTE> tempVec;
            for(int j=0; j< numcols*3; j++){
               // cout << chardiff+i+j << endl;
                tempVec.push_back((ImgData[chardiff+(i*numcols*3)+j]));
                
            }
            //cout <<"Temp Vec Sizes "<< tempVec.size() << endl;
            Ppm::OriginalMatrix.push_back(tempVec);
        }
        cout << "Matrix rows"<<Ppm::OriginalMatrix.size() << endl;
        cout << " Matrix columns"<<Ppm::OriginalMatrix[0].size() << endl;
    }

}

vector<BYTE> Ppm::readfile(string name){

    // open the file
    streampos filesize;
    ifstream MyReadFile(name, ios::binary);

    //get size
    MyReadFile.seekg(0, ios::end);
    filesize = MyReadFile.tellg();
    MyReadFile.seekg(0, ios::beg);

    //read the data

    vector<BYTE> ImgData(filesize);
    MyReadFile.read((char*) &ImgData[0], filesize);
    MyReadFile.close();
    return ImgData;
}

void Ppm::storeFile(vector<vector<ColorPixel*>> rotatedMatrix, string outputFileName, int width, int height){
         ofstream MyReadFile;
         MyReadFile.open(outputFileName);

         MyReadFile << Ppm::getMagicNo() << "\n";
         MyReadFile << "# this is rotated result" << "\n";
         MyReadFile << width << " " << height << "\n";
         MyReadFile << Ppm::getMaxValue() << "\n";

         for (int i=0; i< rotatedMatrix.size(); i++){
            for (int j=0; j< rotatedMatrix[0].size(); j++){
                ColorPixel* tempcolor = rotatedMatrix[i][j];                    
                MyReadFile << tempcolor->getRed() << "\n";
                MyReadFile << tempcolor->getGreen() << "\n";
                MyReadFile << tempcolor->getBlue() << "\n";
            }
         }
         MyReadFile.close();
}

void Ppm::storeFileBinary(vector<vector<BYTE>> matrix, string outputFileName, int width, int height){
    ofstream MyReadFile(outputFileName, ios::out | ios::binary);
    if(!MyReadFile){
        cout << "Cannot open file" <<endl;    
    }
    MyReadFile << Ppm::getMagicNo() << "\n";
    MyReadFile << "# this is rotated result" << "\n";
    MyReadFile << width << " "<< height <<"\n";
    MyReadFile << Ppm::getMaxValue() << "\n";

    for (int i=0; i< matrix.size() ; i++){
        for (int j=0; j< matrix[0].size(); j++){
            MyReadFile << matrix[i][j];
        }
    }
    MyReadFile.close();
}