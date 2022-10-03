#ifndef PGM_H
#define PGM_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "grayPixel.h"
using namespace std;

class Pgm {

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
		
	
	// Defining matrix
	
	public:
		string tempLine;
		string filename=" ";
		int row = 0, col = 0, numrows = 0, numcols = 0, maxVal = 0;
		stringstream ss;
		vector<vector<GrayPixel*>> grayImage;
	
	
	/* Methods 
	vector GrayPixel objects in ASCII and binary
	*/
		Pgm(string filename);
		void storeFile(vector<vector<GrayPixel*>> rotatedMatrix, string outputFileName);
		//int vectorCreate(int arrayofValues);
		
		// getters or accessors 
		string getMagicNo() {return MagicNo;} //inline short functions here 
		int getImgHeight() {return ImgHeight;}
		int getImgWidth() {return ImgWidth;}
		int getMaxValue() {return MaxValue;}


		// setters or mutators to save pixel values >> when creating instance of the pixel
		void setMagicNo(string line1) {this->MagicNo = line1;}
		void setImgHeight(int ImgHeight) {this->ImgHeight = ImgHeight;}
		void setImgWidth(int ImgWidth) {this->ImgWidth = ImgWidth;}
		void setMaxValue(int MaxValue) {this->MaxValue = MaxValue;}


};
#endif
