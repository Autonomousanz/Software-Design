/*
Authors : Sanskruti Jadhav, Dnyanesh Marne
*/
#ifndef GRAYPIXEL_H
#define GRAYPIXEL_H

#include <iostream>
#include <string>

using namespace std;

class GrayPixel {
    private:
      int grayPixel;

    public:
      GrayPixel(){}

      ~GrayPixel(){}

      int getGrayPixel(){return this->grayPixel;}

      void setGrayPixel(int intensity){this->grayPixel = intensity;}
};

#endif