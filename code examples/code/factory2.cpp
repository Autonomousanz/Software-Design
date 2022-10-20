// code source :  ig.opengenus.org
#include <iostream>
using namespace std;

enum VehicleType {VT_Car, VT_Bus, VT_Horse};

// Library classes
class Vehicle {
   public:
      virtual void printVehicle() = 0;
      static Vehicle* Create(VehicleType type);
};

class Car : public Vehicle {
   public:
      void printVehicle() {cout << "I am a car" << endl;}
};

class Bus : public Vehicle {
   public:
      void printVehicle() {cout << "I am a bus" << endl;}
};

class Horse : public Vehicle {
    public:
      void printVehicle() { cout << "I am a horse and I eat hay" << endl; }
};

// Factory method to create objects of different types.
// Change is needed only in this function to  add a new vehicle type
Vehicle* Vehicle::Create(VehicleType type) {
    if (type == VT_Car)
        return new Car();
    else if (type == VT_Bus)
        return new Bus();
    else if (type == VT_Horse)
        return new Horse();
    else return NULL;
}

// Client class doesn't explicitly create objects
// but passes type to factory method Create()
class Client {
   public:
    Client(){
        VehicleType type = VT_Horse;
        myVehicle = Vehicle::Create(type);
    }
    ~Client() {if (myVehicle) { delete[] myVehicle; myVehicle = NULL;}}
    Vehicle* getVehicle()  { return myVehicle;}

   private:
      Vehicle *myVehicle;
};

// Main  program
int main() {
    Client *clientPtr = new Client();
    Vehicle * myVehicle = clientPtr->getVehicle();
    myVehicle->printVehicle();
    return 0;
}
