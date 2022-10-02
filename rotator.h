/*
Authors : Sanskruti Jadhav, Dnyanesh Marne
*/
#ifndef ROTATOR_H
#define ROTATOR_H

#include <iostream>
#include <string>

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
      //string imageCharacteristics[4];

      // Private constructor so that no objects can be created.
      Rotator() {}
      Rotator(string inFile, string outFile, string direction, int degree){
         this->inputFileName = inFile;
         this->outputFileName = outFile;
         if(direction == "-r"){
            this->direction = "Right";
         }else{
            this->direction = "Left";
         }
         this->degree = degree;
      }

   public:
      string fileLine;
      // can be named anything, but recommended to have word Instance in the name
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

      /*void setInputFileName(string filename) { this->inputFileName = filename;}
      void setOutputFileName(string oFilename) { this->outputFileName = oFilename;}
      void setDirection(string direction) { 
         if(direction == "-r"){
            this->direction = "Right";
         }else{
            this->direction = "Left";
         }
          }
      void setDegree(int degree) { this->degree = degree; }*/
      void setExtension(string exten) { 
         this->MagicNo = exten;
         if(exten == "P2" or exten == "P5"){
            this->extension = "PGM";
         }else{
            this->extension = "PPM";
         }
      }
      //void setImageCharacteristics(int index, string value) { this->imageCharacteristics[index] = value;}
};
#endif