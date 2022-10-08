#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <string>

using namespace std;

class Vehicle {

   protected:
     string fueltype;

   public:

     Vehicle(){cout <<" Calling Vehicle no-arg Constructor"<< endl;}// explicit default constructor
     Vehicle(string fueltype){this->fueltype=fueltype;}// parameterized 
    
     ~Vehicle(){cout << "Calling Vehicle destructor"<< endl;}

     // getters or accessors
     string getFueltype() {return fueltype;} //inline short functions here 

     // setters or mutators
     void setFueltype(string f) {this->fueltype= f;}

};
#endif
