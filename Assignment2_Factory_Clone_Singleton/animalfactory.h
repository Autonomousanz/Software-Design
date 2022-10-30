#ifndef ANIMALFACTORY_H
#define ANIMALFACTORY_H
#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <set>
#include <vector>
#include <time.h>
using namespace std;



// Abstract Factory Method

class Animal{

    // Abstract or Interface class
    public:


    Animal (){numAnimals++;}
    ~Animal (){}

    virtual Animal* clone() = 0;
    virtual string animTalk() = 0;
    static int numAnimals; 
    string name;
    vector <string> name_pool{"Mark","Ronaldo","Rex", "Fluffy", "Jack", "George","Missy", "Sheldon", "Natalia","Gordon", "James", "Manny","Dylan","Ashton","Mila", "Rihanna","Drake", "Kim","Kylie","Kendall", "Kevin","Dan","Ryan","Phil","Luke","Jay" };
    string random_name(){
        srand(time(0));
        return name_pool[rand() % name_pool.size()];
    }
};


class Tiger: public Animal{

    public:
    static int tiger_tots;
    static set <string> tiger_sub;

    Tiger(){tiger_tots++; }   
    Tiger(const Tiger &rhs){ tiger_tots++;}

    string animTalk() {
        name = random_name();
        while (tiger_sub.count(name) ){
            name = random_name();
        }
        tiger_sub.insert(name);
        return "I am a tiger, my name is "+ name + ", I roar, and I eat meat.\n";
    }

    Animal* clone() { return new Tiger(*this);}
    ~Tiger(){}

    
};     


class Wolf: public Animal{
    public:
    static int wolf_tots;
    static set <string> wolf_sub;

    Wolf() {wolf_tots++; }
    Wolf(const Wolf &rhs){wolf_tots++; }

    string animTalk() {
        name = random_name();
        while (wolf_sub.count(name) ){
            name = random_name();
        }
        wolf_sub.insert(name);
        return "I am a wolf, my name is "+ name + ", I growl, and I eat chicken.\n";
    }
    Animal* clone() { return new Wolf(*this);}
    ~Wolf(){}
    
};

class Lemur: public Animal {
    public:
    static int lemur_tots;
    static set <string> lemur_sub;

    Lemur(){ lemur_tots++;}
    Lemur(const Lemur &rhs){ lemur_tots++;}

    string animTalk() {
        name = random_name();
        while (lemur_sub.count(name) ){
            name = random_name();
        }
        lemur_sub.insert(name);
        return "I am a lemur, my name is "+ name + ", I squeak, and I eat fruit.\n";
    }

    
    Animal* clone() { return new Lemur(*this);}
    ~Lemur(){}
};

class Kangaroo: public Animal{
    public:
    static int kang_tots;
    static set <string> kang_sub;

    Kangaroo(){ kang_tots++;}
    Kangaroo(const Kangaroo &rhs){kang_tots++;}

    string animTalk() {
        name = random_name();
        while (kang_sub.count(name) ){
            name = random_name();
        }
        kang_sub.insert(name);
        return "I am a kangaroo, my name is "+ name + ", I click, and I eat carrots.\n";
    }

   
    Animal* clone() { return new Kangaroo(*this);}
    ~Kangaroo(){}
};

class Serpent: public Animal{
    public:
    static int serp_tots;
    static set <string> serp_sub;

    Serpent(){serp_tots++;}
    Serpent(const Serpent &rhs){serp_tots++;}
    string animTalk() {
        name = random_name();
        while (serp_sub.count(name) ){
            name = random_name();
        }
        serp_sub.insert(name);
        return "I am a serpent, my name is "+ name + ", I hiss and I eat mice.\n";
    }

    Animal* clone() { return new Serpent(*this);}
    ~Serpent(){}
     
};
int Animal::numAnimals = 0;
int Tiger::tiger_tots=0;
int Wolf::wolf_tots=0;
int Lemur::lemur_tots=0;
int Kangaroo::kang_tots=0;
int Serpent :: serp_tots=0;
set <string> Tiger::tiger_sub;
set <string> Wolf::wolf_sub;
set <string> Lemur::lemur_sub;
set <string> Kangaroo::kang_sub;
set <string> Serpent::serp_sub;

class AnimalFactory {
       public:
       virtual shared_ptr<Animal> create() const = 0;     
};

class Factory1 : public AnimalFactory {
   public:
  
    virtual shared_ptr<Animal> create() const {return make_shared<Tiger>();};
    
};

class Factory2 : public AnimalFactory {
   public:
      virtual shared_ptr<Animal> create() const {return make_shared<Wolf>();};
};

class Factory3 : public AnimalFactory {
   public:
      virtual shared_ptr<Animal> create() const {return make_shared<Lemur>();};
};
class Factory4 : public AnimalFactory {
   public:
      virtual shared_ptr<Animal> create() const {return make_shared<Kangaroo>();};
};
class Factory5 : public AnimalFactory {
   public:
      virtual shared_ptr<Animal> create() const {return make_shared<Serpent>();};
};

#endif