// code source is refactoring.guru
// modified by Lana Drachova

#include <iostream>
#include <string>

using namespace std;

/**
 * The Target defines the domain-specific interface used by the client code.
 */
class Target {
 public:
  // virtual destructor to avoid problems with deleting from a base class ptr
  // instead of empty body can use keyword default.  
  virtual ~Target() = default;
  virtual string Request() const {
    return "Target: The default target's behavior.";
  }
};

/**
 * The Adaptee contains some useful behavior, but its interface is incompatible
 * with the existing client code. The Adaptee needs some adaptation before the
 * client code can use it.
 */
class Adaptee {
 public:
  string SpecificRequest() const {
    return ".eetpadA eht fo roivaheb laicepS";
  }
};

/**
 * The Adapter makes the Adaptee's interface compatible with the Target's
 * interface.
 */
class Adapter : public Target {
 private:
  Adaptee *adaptee;

 public:
  Adapter(Adaptee *tee) : adaptee(tee) {}
  string Request() const override {
    string to_reverse = (this->adaptee)->SpecificRequest();
    string reverse(to_reverse.begin(), to_reverse.end());
    return "Adapter: (TRANSLATED) " + to_reverse;
  }
};

/**
 * The client code supports all classes that follow the Target interface.
 */
void ClientCode(const Target *target) {
  cout << target->Request();
}

int main() {
  cout << "Client: I can work just fine with the Target objects:\n";
  Target *target = new Target;
  ClientCode(target);
  cout << "\n\n";

  Adaptee *adaptee = new Adaptee;
  cout << "Client: The Adaptee class has a weird interface. See, I don't understand it:\n";
  cout << "Adaptee: " << adaptee->SpecificRequest();
  cout << "\n\n";
  cout << "Client: But I can work with it via the Adapter:\n";

  Adapter *adapter = new Adapter(adaptee);
  ClientCode(adapter);
  cout << "\n";

  delete target;
  delete adaptee;
  delete adapter;

  return 0;
}
