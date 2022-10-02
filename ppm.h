/*
Authors : Sanskruti Jadhav, Dnyanesh Marne
*/
#ifndef PPM_H
#define PPM_H

#include <iostream>
#include <string>

using namespace std;

class Ppm {

    private:
      int magicNumber;
      int height;
      int width;
      int maxValue;

    public:
      Ppm(){}

      ~Ppm(){}

      int getMagicNumber(){return this->magicNumber;}
      int getHeight(){return this->height;}
      int getWidth(){return this->width;}
      int getMaxValue(){return this->maxValue;}
      
      void setMagicNumber(int magic){this->magicNumber = magic;}
      void setHeight(int height){this->height = height;}
      void setWidth(int width){this->width = width;}
      void setMaxValue(int maxVal){this->maxValue = maxVal;}



};

#endif