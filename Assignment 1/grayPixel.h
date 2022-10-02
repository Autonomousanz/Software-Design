#ifndef GRAYPIXEL_H
#define GRAYPIXEL_H
#include <iostream>
#include <string>

using namespace std;

class GrayPixel {
	
	
     private:
     /*
    gray = 0,0,255; of each gray pixel */
          string Gray;
   
    public:
    
    // Definitions of constructors / functions
    
          GrayPixel(){}//explicit default constructor
          
          GrayPixel (string Gray){ this->Gray = Gray;}// parameterized constructor
          
          ~GrayPixel(); // Destructor
     
          // getters or accessors 
          string getGray() {return Gray;} //inline short functions here 

          // setters or mutators to save pixel values >> when creating instance of the pixel
          //void setGray(char Gray) {this->Gray = Gray;}

};
#endif
