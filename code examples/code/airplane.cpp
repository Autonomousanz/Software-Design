#include <iostream>
#include <string>

using namespace std;

class  Airplane {
private:
        static int numPlanes;
	string name;
	int capacity;
	int speed;
        int* ptr;
public:
        friend class Satellite;
        friend void printSomeMessage(Airplane);
	Airplane(){ 
           numPlanes++;
           name = "Boeing 777";
	   capacity =400;
	   speed = 600;
           ptr = new int(100); 
        }

	Airplane(string name, int speed, int capacity, int p) {
		numPlanes ++;
		this->name = name;
		this->speed = speed;
		this->capacity=capacity;
                this->ptr = new int(p); 
	}


	Airplane (const Airplane& a) { 
	      numPlanes ++;  
              name = a.name; 
              capacity = a.capacity; 
              speed = a.speed;
              ptr = new int(*(a.ptr));
        }

      static void getNumPlanes(){
              cout << "Number of planes: " << numPlanes << endl;}

      void takeoff(){ cout << name << " took off" << endl;}
      void land(){cout << name << " landed" << endl;}
      int getCapacity() {return capacity;}
      int getSpeed() {return speed;}
      string getName() {return name;}
      int getPtr() {return *ptr;} 
      void setPtr(int x){*ptr = x;}

      // inlined methods
      // implemented below to demo correct syntax
      Airplane& operator=(const Airplane&);

      Airplane operator+(Airplane right){
        Airplane cessna;
           cessna.speed = this->speed + right.speed; 
           cessna.capacity = this->capacity + right.capacity; 
           return cessna;
      }

      bool operator> (Airplane right){
           if((this->speed > right.speed)&&
                 (this->capacity > right.capacity))  
              return true;
           else return false;
      }
 
      friend ostream & operator<< (ostream &out, const Airplane &c) { 
         out << "Overloaded << demo: " << c.speed; 
         out << "  " << c.capacity << endl; 
         return out; 
      } 
  
};


class Satellite {
public:
   // default constructor will be provided by compiler
   void iSeePlanes(Airplane a){
       cout << endl << endl
            << "I am friend class Satellite!" << endl;
       cout << "I see " << a.name << " flying at "
            << a.speed << " mph" << endl << endl;
   }

}; // end class Satellite



//initialize static variaible numPlanes
int Airplane::numPlanes = 0;

// friend function has access to private data members of Airplane 
void printSomeMessage(Airplane coolPlane){
    cout << "I am a friend function!" << endl;
    cout << "I can access Airplane coolPlane's speed: " 
         << coolPlane.speed << endl;
}

Airplane& Airplane::operator=(const Airplane &p){
   if(this != &p){ // make sure not the same object   
      delete this->ptr;
      this->ptr = new int(*(p.ptr));
      this->name = p.name;
      this->capacity = p.capacity;
      this->speed = p.speed;
   }  
         return *this;
}



int main() {
        cout << "Before any objects are created ===>> " << endl 
             << "number of airplanes is: "; 
        Airplane::getNumPlanes();
        cout << endl << endl;

	Airplane plane ("Cessna-172",4, 160, 35);
        Airplane kingAir ("KingAir", 100, 200, 50);
	plane.takeoff();
        plane.land();
   
	cout << endl << "Plane 1" << endl;
	cout << "The name is: " << plane.getName() << endl;
	cout << "The capacity is: " << plane.getCapacity()<< endl; 
	cout << "The speed is: " << plane.getSpeed() << " Km/h" << endl;
        cout << "The pointer points to: " << plane.getPtr() << endl;

	cout << endl << "Plane newPlane" << endl;
// 1
//        cout << endl << "SHALLOW COPY: Dflt copy constr " << endl; 
//        Airplane newPlane(plane);

// 2
//        cout << endl << "SHALLOW COPY: operator = " << endl; 
        Airplane newPlane = plane;

	cout << "The name is: " << newPlane.getName() << endl;
	cout << "The capacity is: " << newPlane.getCapacity() << endl; 
	cout << "The speed is: " << newPlane.getSpeed() <<" Km/h" << endl;
        cout << "The pointer points to: " << newPlane.getPtr() << endl;

        cout << endl << endl<< "Now changing plane's pointer" << endl;
        plane.setPtr(171);
        cout << "plane 1 *pointer is: " << plane.getPtr() << endl;
        cout << "newPlane *pointer is: " << newPlane.getPtr() << endl;

        Airplane plane3, plane4, plane5;

        cout << endl << "Number of planes at the airport: " << endl;  
        Airplane::getNumPlanes();

        plane3 = kingAir + plane;
        cout << endl << endl << plane3 << endl;

        if (kingAir > plane) 
               cout << "KingAir is greater" << endl << endl;

        // calling friend function to print plane3's speed
        printSomeMessage(plane3);

        // an instance of friend class Satellite can access 
        // private members of another class's instance: plane3
        Satellite geo;
        geo.iSeePlanes(plane3);


}


