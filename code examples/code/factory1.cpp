#include <iostream>
#include <string>
#include <memory>

using namespace std;
// interface
class Product{
   public: virtual string printname() const = 0;
};

class Product1 : public Product {
   public: string  printname() const { return "Product1"; }
};

class Product2 : public Product {
   public: string  printname() const  { return "Product2"; }
};

class Factory{
   private:
      Factory() {}
   public:
      static shared_ptr<Product> create(const string& name) {
         if (name == "Product1")
             return make_shared<Product1>();
         else 
             return make_shared<Product2>();
   };
};


int main(){
   shared_ptr<Product> product = Factory::create ("Product1");
   cout << "Product : " << product->printname() << endl;
return 0;

}
