/*
Authors : Sanskruti Jadhav, Dnyanesh Marne
*/
#ifndef ROTATOR_H
#define ROTATOR_H
#include "ppm.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "pgm.h"
#include "colorPixel.h"
#include "grayPixel.h"
typedef unsigned char BYTE;

using namespace std;

class Rotator {

   private:
      static Rotator* instance; // can be named other than instance
      string inputFileName;
      string outputFileName;
      string direction;
      int degree;
      string extension;
      string MagicNo;
     

      // Private constructor so that no objects can be created.
      Rotator() {}
      Rotator(string inFile, string outFile, string direction, int degree){
         this->inputFileName = inFile;
         this->outputFileName = outFile;
         if(direction == "-r" ){
            this->direction = "Right";
         }else{
            this->direction = "Left";
         }
         this->degree = degree;
      }

   public:
      string fileLine;
      
      static Rotator* getInstance(string inFile, string outFile, string direction, int degree) {
         if (!instance) instance = new Rotator(inFile, outFile, direction, degree);
         return instance;
      }

      string getInputFileName(){ return this->inputFileName; }
      string getOutputFileName(){ return this->outputFileName; }
      string getDirection(){ return this->direction; }
      int getDegree(){ return this->degree; }
      string getExtension(){ return this->extension; }
      string getMagicNo(){ return this->MagicNo; }

      void setMagicNo(string magic) { this->MagicNo = magic; }
      void setExtension(string magic){
          if(magic == "P2" or magic == "P5"){
            this->extension = "PGM";
         }else{
            this->extension = "PPM";
         }
      }




      void rotateImage(){

         if ((getDirection() == "Right" and getDegree()== 90) or (getDirection() == "Left" and getDegree()== 270)){
            //right 90 and left 270 math rotation
               if(getMagicNo()=="P2"){
               Pgm* Image = new Pgm(getInputFileName(),getMagicNo());
               vector<vector<GrayPixel* >> rotatedMatrix(Image->getImgWidth(),vector<GrayPixel* > (Image->getImgHeight()));
               for (int i=0; i< Image->getImgHeight(); i++){
                  for (int j=0; j< Image->getImgWidth(); j++){

                     GrayPixel* tempcolor = Image->grayImage[i][j];
                     rotatedMatrix[j][Image->getImgWidth()-1-i] = tempcolor;

                  }
               }
               Image->storeFile(rotatedMatrix,getOutputFileName(),Image->getImgHeight(),Image->getImgWidth());

            }else if(getMagicNo()=="P3"){
               Ppm* Image = new Ppm(getInputFileName(),getMagicNo());
               vector<vector<ColorPixel* >> rotatedMatrix(Image->getImgWidth(),vector<ColorPixel* > (Image->getImgHeight()));
               for (int i=0; i< Image->getImgHeight(); i++){
                  for (int j=0; j< Image->getImgWidth(); j++){
                     ColorPixel* tempcolor = Image->colorImage[i][j];
                     rotatedMatrix[j][Image->getImgWidth()-1-i] = tempcolor;
                  }
               }
               Image->storeFile(rotatedMatrix,getOutputFileName(),Image->getImgHeight(),Image->getImgWidth());

            }else if(getMagicNo()=="P5") {
               Pgm* Image = new Pgm(getInputFileName(),getMagicNo());
               vector<vector<BYTE>> rotatedMatrix;

               for (int j=0; j< Image->getImgWidth(); j++){
                  vector<BYTE> tempVec;
                  for (int i=(Image->getImgHeight())-1; i >=0 ; i--){
                     tempVec.push_back(Image->OriginalMatrix[i][j]);    
                  }
                  rotatedMatrix.push_back(tempVec);

               }

               Image->storeFileBinary( rotatedMatrix,getOutputFileName());
            }else  if(getMagicNo()=="P6") {

               Ppm* Image = new Ppm(getInputFileName(),getMagicNo());
               vector<vector<BYTE>> rotatedMatrix;

               for(int j=0; j< Image->getImgWidth() -1 ; j++) {
                  vector<BYTE> tempVec;
                  for (int i= Image->getImgHeight()-1; i>=0; i--) {
                     tempVec.push_back(Image->OriginalMatrix[i][j*3]); 
                     tempVec.push_back(Image->OriginalMatrix[i][3*j+1]);
                     tempVec.push_back(Image->OriginalMatrix[i][3*j+2]); 
 
                  }
                  rotatedMatrix.push_back(tempVec);

               }

               Image->storeFileBinary(rotatedMatrix,getOutputFileName(),Image->getImgHeight(),Image->getImgWidth());
            }      



         }else if ((getDirection() == "Right" and getDegree()== 270) or (getDirection() == "Left" and getDegree()== 90)){
            //right 270 and left 90 math rotation
            if(getMagicNo()=="P2"){
               Pgm* Image = new Pgm(getInputFileName(),getMagicNo());
               vector<vector<GrayPixel* >> rotatedMatrix(Image->getImgWidth(),vector<GrayPixel* > (Image->getImgHeight()));
               for (int i=0; i< Image->getImgWidth(); i++){
                  for (int j=0; j< Image->getImgHeight(); j++){

                     GrayPixel* tempcolor = Image->grayImage[j][Image->getImgWidth()-1-i];
                     rotatedMatrix[i][j] = tempcolor;

                  }
               }
               Image->storeFile(rotatedMatrix,getOutputFileName(),Image->getImgHeight(),Image->getImgWidth());

            }else if(getMagicNo()=="P3"){
               Ppm* Image = new Ppm(getInputFileName(),getMagicNo());
               vector<vector<ColorPixel* >> rotatedMatrix(Image->getImgWidth(),vector<ColorPixel* > (Image->getImgHeight()));
               for (int i=0; i< Image->getImgWidth(); i++){
                  for (int j=0; j< Image->getImgHeight(); j++){
                     ColorPixel* tempcolor = Image->colorImage[j][Image->getImgWidth()-1-i];
                     rotatedMatrix[i][j] = tempcolor;
                  }
               }
               Image->storeFile(rotatedMatrix,getOutputFileName(),Image->getImgHeight(),Image->getImgWidth());

            }else if(getMagicNo()=="P5") {
               Pgm* Image = new Pgm(getInputFileName(),getMagicNo());
               vector<vector<BYTE>> rotatedMatrix;

               for (int j=Image->getImgWidth()-1; j>=0; j--){
                  vector<BYTE> tempVec;
                  for (int i=0; i <(Image->getImgHeight()) ; i++){
                     tempVec.push_back(Image->OriginalMatrix[i][j]);    
                  }
                  rotatedMatrix.push_back(tempVec);

               }
     
               Image->storeFileBinary( rotatedMatrix,getOutputFileName());
            }else  if(getMagicNo()=="P6") {

               Ppm* Image = new Ppm(getInputFileName(),getMagicNo());
               vector<vector<BYTE>> rotatedMatrix;

               for (int j=Image->getImgWidth()-1; j>=0; j--){
                  vector<BYTE> tempVec;
                  for (int i=0; i <(Image->getImgHeight()) ; i++) {
                     tempVec.push_back(Image->OriginalMatrix[i][3*j]); 
                     tempVec.push_back(Image->OriginalMatrix[i][3*j+1]);
                     tempVec.push_back(Image->OriginalMatrix[i][3*j+2]); 
 
                  }
                  rotatedMatrix.push_back(tempVec);

               }
               Image->storeFileBinary(rotatedMatrix,getOutputFileName(),Image->getImgHeight(),Image->getImgWidth());
            }   

          // 180 ROTATION LOGIC


         }else if(getDegree()== 180){
            // right left 180 math rotation
                           if(getMagicNo()=="P2"){
               Pgm* Image = new Pgm(getInputFileName(),getMagicNo());

               vector<vector<GrayPixel* >> rotatedMatrix(Image->getImgHeight(),vector<GrayPixel* > (Image->getImgWidth()));

               for (int i=0; i< Image->getImgHeight(); i++){
                  for (int j=0; j< Image->getImgWidth(); j++){

                     GrayPixel* tempcolor = Image->grayImage[i][j];
                     rotatedMatrix[Image->getImgHeight()-1-i][Image->getImgWidth()-1-j] = tempcolor;

                  }
               }
               Image->storeFile(rotatedMatrix,getOutputFileName(),Image->getImgWidth(),Image->getImgHeight());

            }else if(getMagicNo()=="P3"){
               Ppm* Image = new Ppm(getInputFileName(),getMagicNo());
               vector<vector<ColorPixel* >> rotatedMatrix(Image->getImgHeight(),vector<ColorPixel* > (Image->getImgWidth()));
               for (int i=0; i< Image->getImgHeight(); i++){
                  for (int j=0; j< Image->getImgWidth(); j++){
                     ColorPixel* tempcolor = Image->colorImage[i][j];
                     rotatedMatrix[Image->getImgHeight()-1-i][Image->getImgWidth()-1-j] = tempcolor;
                  }
               }
               Image->storeFile(rotatedMatrix,getOutputFileName(),Image->getImgWidth(),Image->getImgHeight());

            }else if(getMagicNo()=="P5") {
               Pgm* Image = new Pgm(getInputFileName(),getMagicNo());
               vector<vector<BYTE>> rotatedMatrix;

               for (int i=(Image->getImgHeight())-1; i >=0 ; i--){
                  vector<BYTE> tempVec;
                  for (int j=Image->getImgWidth()-1; j>=0; j--){
                     tempVec.push_back(Image->OriginalMatrix[i][j]);    
                  }
                  rotatedMatrix.push_back(tempVec);

               }
               
               Image->storeFileBinary( rotatedMatrix,getOutputFileName());
            }else  if(getMagicNo()=="P6") {

               Ppm* Image = new Ppm(getInputFileName(),getMagicNo());
               vector<vector<BYTE>> rotatedMatrix;

               for (int i=(Image->getImgHeight())-1; i >=0 ; i--){
                  vector<BYTE> tempVec;
                  for (int j=Image->getImgWidth()-1; j>=0; j--) {
                     tempVec.push_back(Image->OriginalMatrix[i][3*j]); 
                     tempVec.push_back(Image->OriginalMatrix[i][3*j+1]);
                     tempVec.push_back(Image->OriginalMatrix[i][3*j+2]); 
 
                  }
                  rotatedMatrix.push_back(tempVec);

               }


               
               Image->storeFileBinary(rotatedMatrix,getOutputFileName(),Image->getImgWidth(),Image->getImgHeight());
            }  



         ///  THIS IS NOT GONNA ACCEPT   

         }else{
            /// 0 or 360 nothing to do
            cout << " Degrees not 90 180 270 !  " << endl;
         }
         cout << " Rotation Done ! " << endl;
      }


     
};
#endif