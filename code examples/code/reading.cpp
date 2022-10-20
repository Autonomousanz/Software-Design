
#include <iostream>
#include <fstream>
#include <string>
#include <sys/stat.h>

int main () {
    std::ofstream outfile;
    std::ifstream infile;

    infile.open("data.txt");
    outfile.open("out.txt");

    std::string  mystring;
    int myint;

    if ( infile.is_open() ) {  // always check whether the file is open
       infile >> myint;
       std::cout << "myint is " << myint << std::endl;
       outfile << myint << std::endl;

       while (infile){
         std::getline(infile, mystring);    // pipe file's content into stream
         std::cout << mystring << std::endl; // pipe stream's content to standard output
         outfile << mystring << std::endl;
       }
    }

    infile.close();
    outfile.close();

   return 0;
}
