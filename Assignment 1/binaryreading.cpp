#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "rotator.h"
#include "pgm.h"
typedef unsigned char BYTE;

using namespace std;

stringstream ss;
Rotator *Rotator::instance = 0;
vector<vector<BYTE>> OriginalMatrix;
vector<vector<BYTE>> RotatedMatrix;


vector<BYTE> readfile(const char* name){

    // open the file
    streampos filesize;
    ifstream MyReadFile(name, ios::binary);

    //get size
    MyReadFile.seekg(0, ios::end);
    filesize = MyReadFile.tellg();
    MyReadFile.seekg(0, ios::beg);

    //read the data

    vector<BYTE> ImgData(filesize);
    MyReadFile.read((char*) &ImgData[0], filesize);
    return ImgData;
}

int main(int argc, char** argv){  

    Rotator *s = s->getInstance(argv[1],argv[2],argv[3],atoi(argv[4]));

    
    ifstream MyReadFile(s->getInputFileName(), ios::binary | ios::in);

      if (MyReadFile) {

        unsigned int Mychar;
        for(int i=0;i<4;i++){
            getline(MyReadFile, s->fileLine);
            cout<<s->fileLine<<endl; 
             // just prints first 4 Variables 
        }
      /*  char buffer[1300];
        

        MyReadFile.read (buffer,1300);
        cout << buffer <<endl;*/ //this works can
        vector<BYTE> ImgData=readfile("chips-1.pgm");
        cout << ImgData.size() << endl;
        cout << ImgData[0] << endl;


        for (int i=0; i< )






    // get length of file:
   // MyReadFile.seekg (0, MyReadFile.end);

        // int length = 11;

        // MyReadFile.seekg (0, MyReadFile.beg);

        // char * buffer = new char [length];


        //cout << "Reading " << length << " characters... "<<endl;
        //char c='b';



    
        // MyReadFile.seekg (0, MyReadFile.end);
        // for(int i=0;i<1300;i++)
        
        //     ss >> Mychar;
        //     cout << static_cast <int> (Mychar);
        
        
        // //yMyReadFile.read (buffer);
        // buffer[length-1]= '\0';

        // if (MyReadFile)
        //     cout << "all characters read successfully.";
        // else
        //     cout << "error: only " << MyReadFile.gcount() << " could be read";
        // MyReadFile.close();

        // 

        // // ...buffer contains the entire file...

        // delete[] buffer;
    }
   
   return 0;
}