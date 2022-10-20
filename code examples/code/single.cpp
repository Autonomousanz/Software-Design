#include <iostream>
#include "single.h"

using namespace std;

// Initialize pointer to zero so that it can be initialized 
// in first call to getInstance

Singleton *Singleton::instance = 0;

// should implement functions here, unless they are inlined
