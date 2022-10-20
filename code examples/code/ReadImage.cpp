#include <iostream>
#include <string>
#include <fstream>
#include <sys/stat.h>
#include <vector>
using namespace std;

class ImageType{

   private:
        int rows;  // N : no of rows
        int columns; // M : no of columns
        int Q;
        int **pixelvalue;



   public:
      ImageTYpe();
      ~ImageType();
      void getImageInfo(int&, int&, int&);
      void setImageInfo(int,int,int);




}

void ReadImage(char fname[], ImageType& image){
   
   int i,j;
   int N,M,Q;

   unsigned char *charImage;
   char header[100], *ptr;

}

ifstream.open (fname, ios::out | ios::binary)
if (!ifstream){
    cout << "cant read image: " << fname << endl;
    exit(1);
}

ifstream.getline(header,100,"\n");
if (header[0]!=80) || (header[1] !=53) {
     cout << "Image " << fname << " is not PGM" << endl;
      exit(1);
else:
   cout << "Image " << fname << " is  PGM" << endl;

}