//  Developer: Baturay Özgürün
//  Copyright © 2018 Baturay Özgürün
//  If you have any requests or questions please do not hesitate to contact me via baturay.ozgurun@gmail.com

//  Project Name: Computer Vision Project -- Hough Line Transform - SIFT Features - Harris Corner - BoW Algorithms with OpenCV
//  Project Desciption: This project performs 4 algorithms sequentially to extract and present image features; (1) Hough Line Transform, (2) SIFT, (3) Harris Corner, and (4) BoW. The aims of these algorithms are as follows

//  - The Hough Line Transform detects straight lines in an input image and presents line parameters in a text file.

//  - The Scale-Invariant Feature Transform (SIFT) Algorithm detects local features of an input image and presents 128-dimensional vectors in a text file.

//  - The Harris Corner Algorithm extracts corners in an input image and presents corner locations in a text file.

//  - The Bag of Visual Words (BoW) Algorithm extracts image features as words, presenting the histogram and vocabulary of an input image.


//Include Headers
#include "Hough_Line_Transform.h"
#include "Harris_Corner.h"
#include "SIFT.h"
#include "BoW.h"

int main(){
    
    main_hough();
    main_sift();
    main_harris();
    main_bow();
    
}

