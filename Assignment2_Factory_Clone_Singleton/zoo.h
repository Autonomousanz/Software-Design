
#ifndef ZOO_H
#define ZOO_H
#include <memory>
#include <iostream>
#include <fstream>
#include <string>
#include "animalfactory.h"
#include <map>
#include <vector>

using namespace std;

class Zoo {

   private:
      static Zoo* instance; // can be named other than instance
      string inputFileName;
      string outputFileName;  
      vector <string> print_talks ;
     

      // Private constructor so that no objects can be created.
      Zoo() {
         cout << "Zoo “WildThings” is home to the following animals: \n";
         cout << "__________________________________________________ \n\n";
      }
      ~Zoo();
   


   public:
      string animName;
      int count_anim;
      string fileLine; 
      string tiger_str;
      string wolf_str;
      string lemur_str;
      string kang_str;
      string serpent_str;

      static Zoo* getInstance() {
         if (!instance) instance = new Zoo();
         return instance;
      }

      string getInputFileName(){ return this->inputFileName; }
      string getOutputFileName(){ return this->outputFileName; }

      void outTalks(){
         for (int i=0; i < this->print_talks.size(); i++){
           cout <<  this->print_talks.at(i) << "\n" ;
      }
      }



      void createAnimal(string animName,int count_anim){
         
         map<string, int> referID;

         referID.insert (pair<string, int>("tiger",1));
         referID.insert (pair<string, int>("wolf",2));
         referID.insert (pair<string, int>("lemur",3));
         referID.insert (pair<string, int>("kangaroo",4));
         referID.insert (pair<string, int>("serpent",5));
         
         int animalId = referID[animName];
      
         switch (animalId){

         case 1:{

         
            shared_ptr<AnimalFactory> tiger_factory = make_shared<Factory1>();
            shared_ptr<Animal> tiger1 = tiger_factory->create();
            print_talks.push_back(tiger1->animTalk());
            for (int no = 1; no < count_anim; no ++ ){ 
                  tiger1->clone();
                  print_talks.push_back(tiger1->animTalk());
            
            }
            break;
         }

         case 2:{

         
            shared_ptr<AnimalFactory> wolf_factory = make_shared<Factory2>();
            shared_ptr<Animal> wolf1 = wolf_factory->create();
            print_talks.push_back(wolf1->animTalk());
            for (int no = 1; no < count_anim; no ++ ){ 
               wolf1->clone();
               print_talks.push_back(wolf1->animTalk());}
           
               
            break;
         }
         case 3:{

         
            shared_ptr<AnimalFactory> lemur_factory = make_shared<Factory3>();
            shared_ptr<Animal> lemur1 = lemur_factory->create();
            print_talks.push_back(lemur1->animTalk());
            for (int no = 1; no < count_anim; no ++ ){
               lemur1->clone();
               print_talks.push_back(lemur1->animTalk());}
                          
            break;
         }
         case 4:{

         
            shared_ptr<AnimalFactory> kangaroo_factory = make_shared<Factory4>();
            shared_ptr<Animal> kangaroo1 = kangaroo_factory->create();
            print_talks.push_back(kangaroo1->animTalk());
            for (int no = 1; no < count_anim; no ++ ){
               kangaroo1->clone();
               print_talks.push_back(kangaroo1->animTalk());}
            
               
            break;
         }
         case 5:{

         
            shared_ptr<AnimalFactory> serpent_factory = make_shared<Factory5>();
            shared_ptr<Animal> serpent1 = serpent_factory->create();
            print_talks.push_back(serpent1->animTalk());
            for (int no = 1; no < count_anim; no ++ ){
               serpent1->clone();
               print_talks.push_back(serpent1->animTalk());}
             
            break;
         }
         }
      }
          
};
#endif