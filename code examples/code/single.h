#ifndef SINGLE_H
#define SINGLE_H

#include <iostream>

using namespace std;

// this class can have any name
class Singleton {

   private:
      static Singleton* instance; // can be named other than instance
      int myInt;

      // Private constructor so that no objects can be created.
      Singleton() {
         myInt = 0;
      }

   public:
      // can be named anything, but recommended to have word Instance in the name
      static Singleton* getInstance() {
         if (!instance) instance = new Singleton;
         return instance;
      }

      int getInt() { return this->myInt; }
      void setInt(int newInt) { this->myInt = newInt;}
};

#endif
