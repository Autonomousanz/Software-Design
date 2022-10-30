#include <iostream>
#include <memory>

class Product {
   public:
      int i = 1;
      std::shared_ptr<int> ptr = std::make_shared<int>(3);
      Product* clone() const {
          // use default constructor to copy all member vars
          // and then update the member you want (ptr)

          Product* product = new Product(*this);
          product->ptr = std::make_shared<int>(*ptr);
          return product;
      }
};

template <typename T1, typename T2>
void print(const T1& t1, const T2& t2) {
        std::cout << t1 << t2 << std::endl;
}
