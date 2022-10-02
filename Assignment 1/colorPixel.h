#ifndef COLORPIXEL_H
#define COLORPIXEL_H
#include <iostream>
#include <string>



using namespace std;

class ColorPixel {
	
	
     private:
   /* red = 255,0,0;
    green = 0,255,0;
    blue = 0,0,255; of each color pixel */

    string Red;
    string Green;
    string Blue;

    
       
   
    public:
    
    // Definitions of constructors / functions
    
    ColorPixel(){ } //explicit default constructor
    
    ColorPixel(string Red,string Green,string Blue){
          this->Red = Red;
          this->Green = Green;
          this->Blue = Blue;

     } // parameterized constructor
    
    ~ColorPixel(); // Destructor
    
     // getters or accessors 
     string getRed() {return Red;} //inline short functions here 
     string getGreen() {return Green;}
     string getBlue() {return Blue;}


      
};
#endif
