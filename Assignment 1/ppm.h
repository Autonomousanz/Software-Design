#ifndef PPM_H
#define PPM_H
#include <iostream>
#include <string>
#include "colorPixel.h"
#include <sstream>
#include <vector>
using namespace std;

class Ppm {

	private:
	/* Magic Number
	Height
	Width
	max_value for each pixel 
	...*/
	string MagicNo;
	int ImgHeight;
	int ImgWidth;
	int MaxValue;

	public:
	
	/* Methods for
	vector ColorPixel objects in ASCII and Binary
	*/

	string tempLine1;
	string tempLine2;
	string tempLine3;

	string filename=" ";
	int row = 0, col = 0, numrows = 0, numcols = 0, maxVal = 0;
	stringstream ss;
	vector<vector<ColorPixel*>> colorImage;
	
	
	/* Methods 
	vector colorPixel objects in ASCII and binary
	*/
	Ppm(string filename);
	void storeFile(vector<vector<ColorPixel*>> rotatedMatrix, string outputFileName);
		
	
	string getMagicNo() {return MagicNo;} //inline short functions here 
	int getImgHeight() {return ImgHeight;}
	int getImgWidth() {return ImgWidth;}
	int getMaxValue() {return MaxValue;}


	// setters or mutators to save pixel values >> when creating instance of the pixel
	void setMagicNo(string MagicNo) {this->MagicNo = MagicNo;}
	void setImgHeight(int ImgHeight) {this->ImgHeight = ImgHeight;}
	void setImgWidth(int ImgWidth) {this->ImgWidth = ImgWidth;}
	void setMaxValue(int MaxValue) {this->MaxValue = MaxValue;}

};
#endif
