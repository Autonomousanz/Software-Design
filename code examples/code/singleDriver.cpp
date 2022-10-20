#include <iostream>
#include "single.h"

using namespace std;

int main(){
   Singleton *s = s->getInstance();
   cout << s->getInt() << endl;
   s->setInt(17);
   cout << s->getInt() << endl;
   return 0;
}
