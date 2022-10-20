#include <iostream>
#include "Car.h"
#include "Garage.h"

using namespace std;

int main(){

   // if explicitly declared a default constructor, instantiate like this:
   // Car car1;
   // if compiler provides implicit default constructor, then use ():
   // Car car1();

   Car car1;
   Car car3;
   Car car2(2022, 120, "Ford");

   // 2 ways to call copy constructor
   //car3 = car2;  or below
   // copy constructor is used to init a NEW object
   // using some existing object
   Car car4(car2);

   car1.setSpeed(95);
   car1.setYear(1997);

   cout << "Total number of Car objects created: "
        << Car::getNumCars() << endl << endl;

   cout << "Now printing members of car4" << endl;
   cout << car4.getYear() << " "
        << car4.getSpeed()  <<  " "
        << car4.getMake()  << endl << endl;

   // this is overloaded << operator.
   //  There are 2 ways to call it:
   cout << car1;
   operator << (cout, car2);

   Car car5, car6, car7;

   // have user enter values for car5 and then print car5
   cin >> car5;
   cout << car5;

   cin >> car6;
   cout << car6;

   // will do some Car comparison here
     if (car5 > car6)
         cout  << endl << "car5 is newer "  << endl;
     else cout << endl << "car6 is newer " << endl;



   // doing some crazy math
   // for this to work you need overloaded operators + and =
   car7 = car5 + car6;
   cout << car7;

   cout << "Incrementing car7" << endl;
   ++car7;
   cout << car7;


return 0;
}
