#include <iostream>
#include <string>
#include "Car.h"

using namespace std;

 Car::Car(){
   cout << "Calling no-arg Car constructor" << endl;
   year = 1900;
   speed = 100.00;
   make = "chevy";
   numCars ++;
}


Car::Car(int year, double speed, string make){
   cout << "Calling arg constructor2" << endl;
   this->year = year;
   this->speed = speed;
   this->make = make;
   numCars ++;
}


Car::Car(const Car &rhs){
   cout << "Calling copy constructor3" << endl;
   this->year = rhs.year;
   this->speed = rhs.speed;
   this->make = rhs.make;
   numCars ++;
}


Car::~Car (){
    cout << "Calling  Car destructor\n";
 }


// static member MUST be initialized here
// need static function to access static member
int Car::numCars = 0;
int Car::getNumCars(){ return numCars; }


// overloaded operator "="
Car& Car::operator= (const Car& rhs){
   if (&rhs != this){ // make sure not the same object
      this->year = rhs.year;
      this->speed = rhs.speed;
      this->make = rhs.make;
   }
   return *this;
}


Car Car::operator+ (const Car& rhs ){
  cout << endl << "Inside operator+" << endl;
   Car temp;
   temp.year = this->year + rhs.year;
   temp.speed = this->speed + rhs.speed;
   temp.make = this->make + rhs.make;
   return temp;
}


// compare two cars based on year
bool Car::operator> (const Car& rhs){
   if (this->year  > rhs.year)
      return true;
   else
      return false;
}


// Preincrement year
Car& Car::operator++ (){
   ++(this->year);
      return *this;
}

// Postincrement year
Car Car::operator++ (int){
   cout << "Inside postincrement operator function" << endl;
   (this->year)++;
      return *this;
}




// second parameter is const, so we do not overwrite it
ostream & operator<< (ostream &out, const Car& car){
   out << endl << "Overloaded  operator<< " << endl
       << "I am a " << car.make << " made in "
       << car.year  << " and I can go "
       << car.speed << "mph " << endl << endl;
   return out;
}

// second parameter is NOT const, because we want to overwrite it
istream & operator>> (istream &in, Car& car){
   cout << endl << "Overloaded  operator>> " << endl;
   cout << "Please enter car year, speed and make: " ;
   in >> car.year >> car.speed >> car.make;
   return in;
}

void printSomeMessage (Car car){
  cout << "I am a friend function!" << endl
       << " I can access Car's year, make and speed: "
       << car.year << "  "  << car.speed << "  "
       << car.make << endl;
}

// please note that all functions have not been implemented yet.






