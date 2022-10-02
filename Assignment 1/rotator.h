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

      void rightNinety(){
         cout << "Right 90 Left 270" << endl;
      }

      void leftNinety(){
         cout << "Right 270 Left 90" << endl;
      }

      void upsideDown(){
         cout << "Right 180 Left 180" << endl;
      }

      ~Rotator() {}

   public:
      string fileLine;
      
      static Rotator* getInstance(string inFile, string outFile, string direction, int degree) {
         if (!instance) instance = new Rotator(inFile, outFile, direction, degree);
         return instance;
      }

      void rotate(){
         if((this->direction == "Right" and this->degree == 90) or (this->direction == "Left" and this->degree == 270)){
               rightNinety();
         }else if((this->direction == "Right" and this->degree == 270) or (this->direction == "Left" and this->degree == 90)){
               leftNinety();
         }else if(this->degree == 180){
               upsideDown();
         }else{
            cout << "Rotation is either 360 or 0." << endl;
         }
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
