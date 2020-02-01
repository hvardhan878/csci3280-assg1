/*

CSCI 3280, Introduction to Multimedia Systems
Spring 2020

Assignment 01 Skeleton

halftone.cpp
Name: Harshavardhan
SID:1155068110

*/

#include "bmp.h"		//	Simple .bmp library
#include <iostream>

#define MAX_SHADES 3

#define SAFE_FREE(p)  { if(p){ free(p);  (p)=NULL;} }


int main(int argc, char** argv)
{
	//
	//	Your code goes here ....
	//
	//	1. Open BMP file 
	//  you can use the following parameters for testing,
	//  remember to modify it based on the user input.
	//printf("%d", atoi(argv[2]));
	int imagesize = atoi(argv[2]);
	int patchsize = atoi(argv[3]);
	Bitmap image_data(argv[1]); 
	image_data.resize(imagesize);
//	printf("%d", image_data.getHeight());
	//	2. Load image patches
	//



	Bitmap patch0("patch/0.bmp");
	Bitmap patch1("patch/1.bmp");
	Bitmap patch2("patch/2.bmp");
	patch0.resize(patchsize);
	patch1.resize(patchsize);
	patch2.resize(patchsize);
	//unsigned char r1, g2, b2;
	//patch0.getColor(0, 15, r1, g2, b2);
   // printf("%d\n", int(r1));
	//
	//	3. Obtain Luminance
	//
  //  printf("%d", patch0.getWidth());
	//int height = image_data.getHeight();
	//int width = image_data.getWidth();
	Bitmap newmap(image_data.getHeight()*patchsize, image_data.getWidth()*patchsize);
	//int** map = new int[height][width];
	int len1 = 0, len2 = 0;
	for (int i = 0; i < image_data.getHeight(); i++) {
		for (int j = 0; j < image_data.getWidth(); j++) {
			unsigned char r, g, b;
	
			double grayvalue;
			int quantizedvalue;
			image_data.getColor(i, j, r, g, b);
			//printf("%d %d %d\n", len1,j,i);
			grayvalue = 0.299 * r + 0.587 * g + 0.114 * b;
			quantizedvalue = floor(grayvalue / (256.0 / 3.0));
			if (quantizedvalue == 3) {
				printf("%d\n", quantizedvalue);
			}
			if (quantizedvalue == 0) {
			//	printf(" check1 ");
				for (int k = 0; k < patch0.getHeight(); k++) {
					for (int l = 0; l < patch0.getWidth(); l++) {
						unsigned char r1, g1, b1;
						patch0.getColor(k, l, r1, g1, b1);
						//printf("%d\n", (int)r1);
						newmap.setColor(len1 + k, len2 + l, r1, b1, g1);
						//newmap.getColor(len1 + k, len2 + l, r1, b1, g1);
						//printf("%d\n", (int)r1);
					}
				}
				
			}
			else if (quantizedvalue == 1) {
			//	printf(" check2 ");
				for (int k = 0; k < patch1.getHeight(); k++) {
					for (int l = 0; l < patch1.getWidth(); l++) {
						unsigned char r1, g1, b1;
						patch1.getColor(k, l, r1, g1, b1);
						//printf(" %d %d\n", len1 + k, len2 + l);
						newmap.setColor(len1 + k, len2 + l, r1, b1, g1);
					}
				}
			}
			else if (quantizedvalue == 2) {
				for (int k = 0; k < patch2.getHeight(); k++) {
					for (int l = 0; l < patch2.getWidth(); l++) {
						unsigned char r1, g1, b1;
						patch2.getColor(k, l, r1, g1, b1);
						newmap.setColor(len1 + k, len2 + l, r1, b1, g1);
					}
				}
			}
			len2 = len2 + patchsize;
			//printf("%d\n", r1);
		//	newmap.setColor(i, j, r1, g1, b1);
			//map[i][j] = quantizedvalue;


		}
		len1 = len1 + patchsize;
		len2 = 0;
	}
	//printf("finish");
	newmap.save("newimage.bmp");
	


	//
	//	4. Quantization
	//

	//
	//  5. Generate bmp image and parse patches according to quantized image
	//
	
	//  free memory

	return 0;
} 