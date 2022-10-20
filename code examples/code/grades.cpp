#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;


class Student {
  public:
    Student( string name )
      : name_(name)
    {}
    virtual void grades()
    { cout << name_ << " with no grades " << endl; }
    virtual ~Student()
    {}

  protected:
    string name_;
};


class UG: public Student {
  public:
    UG( string name, double homework, double exam )
      : Student(name), homework_(homework), exam_(exam)
    {}
    virtual void grades()
    { cout << name_ << ", UG average is " << (homework_+exam_)/2.0 << endl; }

  private:
    double homework_;
    double exam_;
};


class GR: public Student {
  public:
    GR( string name, double homework, double exam, double project )
      : Student(name), homework_(homework), exam_(exam), project_(project)
    {}
    virtual void grades()
    { cout << name_ << ", GR average is " << (homework_+exam_+project_)/3.0
      << endl; }

  private:
    double homework_;
    double exam_;
    double project_;
};


int main(void) {
  
  UG *p1 = new UG {"Amy", 80.0, 90.0 };
  GR *p2 = new GR {"Ann", 80.0, 92.0, 95.0 };

  vector<Student *> students { p1, p2 };

  for( auto s: students ) s->grades();

  return 0;
}
