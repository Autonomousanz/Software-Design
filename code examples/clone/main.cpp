#include <iostream>
#include <memory>
#include "product.h"


int main() {
   Product * product = new Product();
   Product* clone = product->clone();

   print ("Product i = ", product->i);
   print ("Clone i = ", clone->i);
   print ("Product ptr = ", product->ptr);
   print ("Clone ptr = ", clone->ptr);
   print ("Product *ptr = ", *product->ptr);
   print ("Clone *ptr = ", *clone->ptr);



 return 0;
}
