#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "pgm.h"
#include "grayPixel.h"

using namespace std;

Pgm::Pgm(string filename, string EMagic){

    if (EMagic == "P2"){

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
    else {

        ifstream MyReadFile(filename, ios::binary | ios::in);
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
        MyReadFile.close();

        vector<BYTE> ImgData = Pgm::readfile(filename);
        
        chardiff = ImgData.size() - (numcols*numrows);
        cout << "chardiff" <<chardiff<< endl;
        for(int i=0 ; i < numrows; i++ ){ 
            vector<BYTE> tempVec;
            for(int j=0; j< numcols; j++){
               // cout << chardiff+i+j << endl;
                tempVec.push_back(ImgData[chardiff+(i*numcols)+j]);
            }
            Pgm::OriginalMatrix.push_back(tempVec);
        }
        cout << Pgm::OriginalMatrix.size() << endl;
        cout << Pgm::OriginalMatrix[0].size() << endl;
    }
    
}

vector<BYTE> Pgm::readfile(string name){

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

void Pgm::storeFileBinary(vector<vector<BYTE>> matrix, string outputFileName){
    ofstream MyReadFile(outputFileName, ios::out | ios::binary);
    if(!MyReadFile){
        cout << "Cannot open file" <<endl;    
    }
    MyReadFile << Pgm::getMagicNo() << "\n";
    MyReadFile << "# this is rotated result" << "\n";
    MyReadFile << Pgm::getImgWidth() << " " << Pgm::getImgHeight() << "\n";
    MyReadFile << Pgm::getMaxValue() << "\n";

    for (int i=0; i< (Pgm::getImgHeight()); i++){
        for (int j=0; j< (Pgm::getImgWidth()); j++){
            MyReadFile << matrix[i][j];
        }
    }
    MyReadFile.close();
}


