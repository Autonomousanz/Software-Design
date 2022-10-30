#include <iostream>
#include <fstream>
#include <sstream>
#include "zoo.h"
#include "animalfactory.h"
#include <string>

using namespace std;

Zoo *Zoo::instance = 0;


int main(){

    stringstream ss;
    //use cin for dynamic file reading

    ss << cin.rdbuf();
    

    Zoo *WildThings = WildThings->getInstance(); 
    
    ss >> WildThings->animName >> WildThings->count_anim; 
    while (ss){

        if(ss.str().empty()){
            break;
        }
        WildThings->createAnimal(WildThings->animName,WildThings->count_anim) ;  
        ss >> WildThings->animName >> WildThings->count_anim; 

    }
    cout << "There are total " << Animal::numAnimals << " animals in the Zoo.\n" ; 


    (Tiger::tiger_tots>1)? WildThings->tiger_str = " tigers, " : WildThings->tiger_str = " tiger, ";
    (Wolf::wolf_tots>1)? WildThings->wolf_str = " wolves, " : WildThings->wolf_str = " wolf, ";
    (Lemur::lemur_tots>1)? WildThings->lemur_str = " lemurs, " : WildThings->lemur_str = " lemur, ";
    (Kangaroo::kang_tots > 1)? WildThings->kang_str = " kangaroos, " : WildThings->kang_str =" kangaroo, ";
    (Serpent::serp_tots> 1)? WildThings->serpent_str = " serpents.\n" : WildThings->serpent_str = " serpent.\n";

    cout << "There are " << Tiger::tiger_tots << WildThings->tiger_str<< Wolf::wolf_tots << WildThings->wolf_str<< Kangaroo::kang_tots << WildThings->kang_str <<Lemur::lemur_tots << WildThings->lemur_str<< Serpent::serp_tots << WildThings->serpent_str;  
    WildThings->outTalks();
    
    return 0;   

}