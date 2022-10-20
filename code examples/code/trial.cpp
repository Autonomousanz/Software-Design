#include<iostream>
using namespace std;
  
// A class without user defined assignment operator
class Test
{
    int *ptr;
public:
    Test (int i)      { ptr = new int(i); }
    void setValue (int i) { *ptr = i; }
    void print()          { cout << *ptr << endl; }
};
  
int main()
{
    Test t1(5);
    Test t2();
    t2 = t1;
    t1.setValue(10);
    t2.print();
    return 0;
}