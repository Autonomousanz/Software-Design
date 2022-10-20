#include <iostream>
#include <memory>

using namespace std;

//Adaptee class
class Interface_NotGood {
   public: 
      int * ng_a;
      void set(int a) {ng_a = new int(a);}
};

// Adapter class
class Interface_Good {
   // Adaptee's instance is a private member of adaptor
   Interface_NotGood i_ng;
   public:
      Interface_Good (int a) { i_ng.ng_a = new int(a);}
      ~Interface_Good() {delete i_ng.ng_a;}
      int get() const {return * i_ng.ng_a;}
};

int main() {
    Interface_Good ig(3);
    cout << ig.get() << endl;
   return 0;
}
