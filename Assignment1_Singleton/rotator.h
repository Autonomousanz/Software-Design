/*
Authors :  Dnyanesh Marne, Sanskruti Jadhav
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
         (direction == "-r" )? this->direction = "Right" :  this->direction = "Left";
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


      // Rotate 90 :)
      template <typename T, class C>
      void rotate1ASCII(T* imgObj){
               vector<vector<C*>> rotatedMatrix;
               for (int j=0; j< imgObj->getImgWidth(); j++){
                  vector<C*> tempVec;
                  for (int i=(imgObj->getImgHeight())-1; i >=0 ; i--){
                        C* tempcolor = imgObj->Original_img[i][j];
                        tempVec.push_back(tempcolor);
                  }
                  rotatedMatrix.push_back(tempVec);
               } 
               imgObj->storeFile(rotatedMatrix,getOutputFileName(),imgObj->getImgHeight(),imgObj->getImgWidth());
         
      }

      template <typename T, typename C>
      void rotate1Binary(T* imgObj){
               vector<vector<C>> rotatedMatrix;
               for (int j=0; j< imgObj->getImgWidth(); j++){
                  vector<C> tempVec;
                  for (int i=(imgObj->getImgHeight())-1; i >=0 ; i--){
                     if(getMagicNo() == "P5"){
                        tempVec.push_back(imgObj->OriginalMatrix[i][j]);
                     }else{
                        tempVec.push_back(imgObj->OriginalMatrix[i][j*3]); 
                        tempVec.push_back(imgObj->OriginalMatrix[i][3*j+1]);
                        tempVec.push_back(imgObj->OriginalMatrix[i][3*j+2]);
                     } 
                  }
                  rotatedMatrix.push_back(tempVec);
               }   
               imgObj->storeFileBinary( rotatedMatrix,getOutputFileName(),imgObj->getImgHeight(),imgObj->getImgWidth());     
      }

      //rotate 270
      template <typename T, class C>
      void rotate2ASCII(T* imgObj){
               vector<vector<C*>> rotatedMatrix;
               for (int j=imgObj->getImgWidth()-1; j>=0; j--){
                  vector<C*> tempVec;
                  for (int i=0; i <(imgObj->getImgHeight()) ; i++){
                        C* tempcolor = imgObj->Original_img[i][j];
                        tempVec.push_back(tempcolor);
                  }
                  rotatedMatrix.push_back(tempVec);
               } 
               imgObj->storeFile(rotatedMatrix,getOutputFileName(),imgObj->getImgHeight(),imgObj->getImgWidth());
         
      }

      template <typename T, typename C>
      void rotate2Binary(T* imgObj){
               vector<vector<C>> rotatedMatrix;
               for (int j=imgObj->getImgWidth()-1; j>=0; j--){
                  vector<C> tempVec;
                  for (int i=0; i <(imgObj->getImgHeight()) ; i++){
                     if(getMagicNo() == "P5"){
                        tempVec.push_back(imgObj->OriginalMatrix[i][j]);
                     }else{
                        tempVec.push_back(imgObj->OriginalMatrix[i][j*3]); 
                        tempVec.push_back(imgObj->OriginalMatrix[i][3*j+1]);
                        tempVec.push_back(imgObj->OriginalMatrix[i][3*j+2]);
                     } 
                  }
                  rotatedMatrix.push_back(tempVec);
               }   
               imgObj->storeFileBinary( rotatedMatrix,getOutputFileName(),imgObj->getImgHeight(),imgObj->getImgWidth());     
      }

      //rotate 180
       
      template <typename T, class C>
      void rotate3ASCII(T* imgObj){
               vector<vector<C*>> rotatedMatrix;
               for (int i=(imgObj->getImgHeight())-1; i >=0 ; i--){
                  vector<C*> tempVec;
                  for (int j=imgObj->getImgWidth()-1; j>=0; j--){
                        C* tempcolor = imgObj->Original_img[i][j];
                        tempVec.push_back(tempcolor);
                  }
                  rotatedMatrix.push_back(tempVec);
               } 
               imgObj->storeFile(rotatedMatrix,getOutputFileName(),imgObj->getImgWidth(),imgObj->getImgHeight());    
      }

      template <typename T, typename C>
      void rotate3Binary(T* imgObj){
               vector<vector<C>> rotatedMatrix;
               for (int i=(imgObj->getImgHeight())-1; i >=0 ; i--){
                  vector<BYTE> tempVec;
                  for (int j=imgObj->getImgWidth()-1; j>=0; j--) {
                     if(getMagicNo() == "P5"){
                        tempVec.push_back(imgObj->OriginalMatrix[i][j]);
                     }else{
                        tempVec.push_back(imgObj->OriginalMatrix[i][3*j]); 
                        tempVec.push_back(imgObj->OriginalMatrix[i][3*j+1]);
                        tempVec.push_back(imgObj->OriginalMatrix[i][3*j+2]);
                     } 
                  }
                  rotatedMatrix.push_back(tempVec);
               }   
               imgObj->storeFileBinary( rotatedMatrix,getOutputFileName(),imgObj->getImgWidth(),imgObj->getImgHeight());     
      } 


      void rotateImage(){
         if ((getDirection() == "Right" and getDegree()== 90) or (getDirection() == "Left" and getDegree()== 270)){
            if(getMagicNo()=="P2"){
               Pgm* Image = new Pgm(getInputFileName(),getMagicNo());
               rotate1ASCII<Pgm,GrayPixel>(Image);
            }else if(getMagicNo()=="P3"){
               Ppm* Image = new Ppm(getInputFileName(),getMagicNo());
               rotate1ASCII<Ppm,ColorPixel>(Image);
            }else if(getMagicNo()=="P5") {
               Pgm* Image = new Pgm(getInputFileName(),getMagicNo());
               rotate1Binary<Pgm,BYTE>(Image);
            }else  if(getMagicNo()=="P6") {
               Ppm* Image = new Ppm(getInputFileName(),getMagicNo());
               rotate1Binary<Ppm,BYTE>(Image);
            }      
         }else if ((getDirection() == "Right" and getDegree()== 270) or (getDirection() == "Left" and getDegree()== 90)){
            //right 270 and left 90 math rotation
            if(getMagicNo()=="P2"){
               Pgm* Image = new Pgm(getInputFileName(),getMagicNo());
               rotate2ASCII<Pgm,GrayPixel>(Image);
            }else if(getMagicNo()=="P3"){
               Ppm* Image = new Ppm(getInputFileName(),getMagicNo());
               rotate2ASCII<Ppm,ColorPixel>(Image);
            }else if(getMagicNo()=="P5") {
               Pgm* Image = new Pgm(getInputFileName(),getMagicNo());
               rotate2Binary<Pgm,BYTE>(Image);
            }else  if(getMagicNo()=="P6") {
               Ppm* Image = new Ppm(getInputFileName(),getMagicNo());
               rotate2Binary<Ppm,BYTE>(Image);
            }   

          // 180 ROTATION LOGIC


         }else if(getDegree()== 180){
            // right left 180 math rotation
            if(getMagicNo()=="P2"){
               Pgm* Image = new Pgm(getInputFileName(),getMagicNo());
               rotate3ASCII<Pgm,GrayPixel>(Image);
            }else if(getMagicNo()=="P3"){
               Ppm* Image = new Ppm(getInputFileName(),getMagicNo());
               rotate3ASCII<Ppm,ColorPixel>(Image);
            }else if(getMagicNo()=="P5") {
               Pgm* Image = new Pgm(getInputFileName(),getMagicNo());
               rotate3Binary<Pgm,BYTE>(Image);
            }else  if(getMagicNo()=="P6") {
               Ppm* Image = new Ppm(getInputFileName(),getMagicNo());
               rotate3Binary<Ppm,BYTE>(Image);
            }  



         ///   

         }else{
            /// 0 or 360 nothing to do
            cout << " Degrees not 90 180 270 !  " << endl;
         }
         cout << " Rotation Done ! " << endl;
      }


     
};
#endif