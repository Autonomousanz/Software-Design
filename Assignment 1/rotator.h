/*
Authors : Sanskruti Jadhav, Dnyanesh Marne
*/
#ifndef ROTATOR_H
#define ROTATOR_H
#include "ppm.h"
#include <iostream>
#include <string>
#include "pgm.h"
#include "colorPixel.h"
#include "grayPixel.h"


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
            Ppm* ppmFile = new Ppm(getInputFileName());

            cout << "vector rows" << ppmFile->colorImage.size() << endl;
            cout << "vector cols" << ppmFile->colorImage[0].size() << endl;
            ColorPixel* tempcolor = ppmFile->colorImage[0][1];
            cout << "value " << tempcolor->getRed() << endl;
            cout << "value " << tempcolor->getGreen() << endl;
            cout << "value " << tempcolor->getBlue() << endl;



         }else if ((getDirection() == "Right" and getDegree()== 270) or (getDirection() == "Left" and getDegree()== 90)){
            //right 270 and left 90 math rotation

            Pgm* pgmFile = new Pgm(getInputFileName());

            cout << "vector rows" << pgmFile->grayImage.size() << endl;
            cout << "vector cols" << pgmFile->grayImage[0].size() << endl;
            GrayPixel* tempcolor = pgmFile->grayImage[0][1];
            cout << "value " << tempcolor->getGray() << endl;
  


         }else if(getDegree()== 180){
            // right left 180 math rotation
         }else{
            /// 0 or 360 nothing to do
         }
      }

      
     
};
#endif