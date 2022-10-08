#ifndef MINICOOPER_H
#define MINICOOPER_H

#include <iostream>
#include <string>
#include "Car.h"
#include "Vehicle.h"

using namespace std;

// Minicooper Derived class of Car and Vehicle

class MiniCooper: public Car, public Vehicle {

   protected:
      string color;

   public:

      MiniCooper(){
            year = 1900;
            speed = 100.00;
            make = "chevy";
            color = "blue";
            fueltype = "nothing";
            cout<< "Calling Minicooper no-arg Constructor"<< endl;

      } // explicit default constructor
      MiniCooper(int year, double speed,string make,string color,string fueltype){   
      this->year = year;
      this->speed = speed;
      this->make = make;
      this->color = color;
      this->fueltype = fueltype;
      }
      ~MiniCooper(){cout <<"Calling MiniCooper destructor"<< endl;}
      // getters or accessors
      string getColor() {return color;} //inline short functions here 

      // setters or mutators
      void setColor(string color) {this->color = color;}

      friend ostream & operator<< (ostream &out, const MiniCooper& mini){
                  out << endl << "Overloaded  operator<< " << endl
                  << "I am a " << mini.make << " made in "
                  << mini.year  << " and I can go "
                  << mini.speed << "mph " 
                  << " I run on " << mini.fueltype
                  <<  " I am " << mini.color << " in color "<< endl << endl;
            return out;
      }


};

#endif
