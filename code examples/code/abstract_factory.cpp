#include <iostream>
#include <string>
#include <memory>

using namespace std;


// Create Product Families
class Product {
   public:
      virtual string printname() const = 0;
}; // end class Product

class Product1 : public Product {
   public:
      string printname() const { return "Product1";}
}; // end class Product1

class Product2 : public Product {
   public:
      string printname() const { return "Product2";}
}; // end class Product2


// Create Factories
class AbstractFactory {
   public:
      virtual shared_ptr<Product> create() const = 0;
};

class Factory1 : public AbstractFactory {
   public:
      virtual shared_ptr<Product> create() const {
        return make_shared<Product1>();
      };
};

class Factory2 : public AbstractFactory {
   public:
      virtual shared_ptr<Product> create() const {
        return make_shared<Product2>();
      };
};


int main(){
   // create manually Factory1 and Factory2
   shared_ptr<AbstractFactory> factory1 = make_shared<Factory1>();
   shared_ptr<AbstractFactory> factory2 = make_shared<Factory2>();

   shared_ptr<Product> product1 = factory1->create();
   shared_ptr<Product> product2 = factory2->create();

   cout << product1->printname() << endl;
   cout << product2->printname() << endl;

   return 0;
}








