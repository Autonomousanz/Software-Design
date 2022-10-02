/*
Authors : Sanskruti Jadhav, Dnyanesh Marne
*/
#ifndef COLORPIXEL_H
#define COLORPIXEL_H

#include <iostream>
#include <string>

using namespace std;

class ColorPixel {
    private:
      int Red;
      int Green;
      int Blue;

    public:
      ColorPixel(){}

      ~ColorPixel(){}

      int getRed(){return this->Red;}
      int getGreen(){return this->Green;}
      int getBlue(){return this->Blue;}

      void setRed(int rIntensity){this->Red = rIntensity;}
      void setGreen(int gIntensity){this->Green = gIntensity;}
      void setBlue(int bIntensity){this->Blue = bIntensity;}
};

#endif