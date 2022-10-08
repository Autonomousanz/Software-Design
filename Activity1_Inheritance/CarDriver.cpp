#include <iostream>
#include <string>
#include "Car.h"
#include "Vehicle.h"
#include "Minicooper.h"
using namespace std;


int main(){    

    // Creating new instance of class Minicooper

    MiniCooper* mini = new MiniCooper();

    mini->setYear(2001);
    mini->setSpeed(150);
    mini->setMake("BMW MiniCooper");
    mini->setColor("Blue");
    mini->setFueltype("Petrol");

    cout << "  Now printing members of minicooper\n";

    cout << "Year of Car : " << mini->getYear() << " \n " ;
    cout << "Speed of Car :"<< mini->getSpeed() << " \n";
    cout << " Make of Car : " << mini->getMake() << " \n";
    cout << " Color of Car : "<<mini->getColor() << " \n";
    cout <<" Fueltype of Car : "<< mini->getFueltype() << endl<<endl;

    // calling out overloaded operator

    operator << (cout, *mini);
    delete mini;

return 0;
}




