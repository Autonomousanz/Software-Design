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
      static Rotator* instance; 
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
         if(direction == "-r"){
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

     
      void setExtension(string exten) { 
         this->MagicNo = exten;
         if(exten == "P2" or exten == "P5"){
            this->extension = "PGM";
         }else{
            this->extension = "PPM";
         }
      }
     
};
#endif
