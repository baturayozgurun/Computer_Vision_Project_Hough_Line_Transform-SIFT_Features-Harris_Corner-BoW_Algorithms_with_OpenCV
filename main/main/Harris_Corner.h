//  Developer: Baturay Özgürün
//  Copyright © 2018 Baturay Özgürün
//  If you have any requests or questions please do not hesitate to contact me via baturay.ozgurun@gmail.com

//  Project Desciption: The Harris Corner Algorithm extracts corners in an input image and presents corner locations in a text file.

//Include Headers
#include <iostream>
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <opencv2/opencv.hpp>

//Include Namespaces
using namespace cv;
using namespace std;

//Define Global Variables
Mat Image, GryImage, CornerNorm;
int Thresh=145, boyut;

// Define the costom design fuctions for both Harris and SIFT.
void HarrisCornerDedection(); // Dedect the Harris Corners
void LocationText(int,Mat); // Write the Harris Corners to the text file

int main_harris(){
    
    Image=imread("data/scene.jpg"); //Read the image
    cvtColor(Image,GryImage,CV_BGR2GRAY ); //Convert the image into gray scale image
    HarrisCornerDedection(); //Calculate Harris Corners
    LocationText(boyut,CornerNorm); //Write the Harris Corners

    waitKey(1000); //wait to show images
    return 0;
}

//Harris Corner Dedection function
void HarrisCornerDedection(){
    Mat Corner, CornerNormScaled; //Define the matrix variables
    int BlockSize=2, Ksize=3, size=0;; //Define integer variables for the cornerHarris function
    double k=0.04; //Define the kapa for the cornerHarris function
    
    cornerHarris(GryImage, Corner, BlockSize, Ksize, k, BORDER_DEFAULT); //Find the Corners using opencv function
    normalize(Corner, CornerNorm, 0, 255, NORM_MINMAX,CV_32FC1, Mat()); //Normalize the image into [0 255]
    convertScaleAbs(CornerNorm, CornerNormScaled); //Make the CornerNorm values into decimal and absolute values
    
    //Draw circles onto the Original Image
    for(int j=0;j<CornerNorm.rows;j++){
        for(int i=0;i<CornerNorm.cols;i++){
            if( (int) CornerNorm.at<float>(j,i) > Thresh ){
                circle(Image,Point(i,j),3,Scalar(0,0,255),-1,8,0);
                size++;
            }
        }
    }
    boyut=size;
    //Show and write the original image with Harris edges
    imshow("Scene Image with Edges", Image);
    imwrite("results/Harris/Scene Image with Edges.jpg", Image);
}

//Write Locations into a text file
void LocationText(int b, Mat C){
    //Define variables
    Mat Location=Mat::zeros(b,2,CV_8UC1);
    int s=0;
    
    //Write the thresholded locations or corner locations
    for(int j=0;j<C.rows;j++){
        for(int i=0;i<C.cols;i++){
            if( (int) C.at<float>(j,i) > Thresh ){ //When the CornerNorm (or C) is above the threshold, register the location
                Location.at<uchar>(s,0)=j; //Row value
                Location.at<uchar>(s,1)=i; //Column Value
                s++;
            }
        }
    }
    
    //Write the corner locations onto the text file
    ofstream outputfile;
    outputfile.open("results/Harris/Scene Image with Edge Locations.txt");
    outputfile << "Location of the Corners:" << endl;
    outputfile << "  Row" << " Column   " << endl;
    outputfile << Location << endl;
}
