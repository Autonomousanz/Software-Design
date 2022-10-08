#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <string>

using namespace std;

class Car {

   protected:
     int year;
     double speed;
     string make;
     static int numCars;    

   public:
     Car();// explicit default constructor
     Car(int y, double s, string m); // can have overloaded constructors
     Car(double s, string m, int y);
     Car (const Car &rhs);  // copy constructor

    ~Car();

      Car& operator= (const Car& rhs); // overloaded operator "="
      Car operator+ (const Car& rhs );
      bool operator> (const Car& rhs);

     // preincrement
     Car& operator++();

     // postincrement - just like any overloaded function
     Car operator++(int);

     friend ostream & operator<< (ostream &out, const Car& car);
     friend istream & operator>> (istream &in, Car& car);

     friend class Gps;
     friend void printSomeMessage (Car);


     // getters or accessors
     int getYear() {return year;} //inline short functions here 
     double getSpeed() {return speed;}
     string getMake() {return make;}

     static int getNumCars();

     // setters or mutators
     void setYear(int year) {this->year = year;}
     void setSpeed(double speed) {this->speed = speed;}
     void setMake(string make) {this->make = make;}

     // other functions
     int  showAge();
     void accellerate();
     void deccelerate();
     void stop();

};

#endif
