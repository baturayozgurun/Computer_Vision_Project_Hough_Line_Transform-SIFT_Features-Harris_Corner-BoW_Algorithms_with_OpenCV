//  Developer: Baturay Özgürün
//  Copyright © 2018 Baturay Özgürün
//  If you have any requests or questions please do not hesitate to contact me via baturay.ozgurun@gmail.com

//  Project Desciption: The Scale-Invariant Feature Transform (SIFT) Algorithm detects local features of an input image and presents 128-dimensional vectors in a text file.

//Include Headers
#include <iostream>
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <opencv2/opencv.hpp>
#include <opencv2/xfeatures2d.hpp>

//Include Namespaces
using namespace cv;
using namespace std;

//Define Global Variables
Mat Input, FeatureImage, Descriptors;
vector<KeyPoint> Keypoints;

// Define the costom design fuctions for both Harris and SIFT.
void KeypointsText(); //Dedect the SIFT Keypoints
void SIFTDedection(); //Write the keypoints and 128 dimension vector for each keypoint to the text file

int main_sift(){
    
    Input=imread("data/scene.jpg"); //Read the image
    SIFTDedection(); //Calculate SIFT keypoints
    KeypointsText(); //Write SIFT keypoints

    waitKey(1000); //wait to show images
    return 0;
}

//SIFT Feature Dedection Function
void SIFTDedection(){
    Ptr<Feature2D> f2d = xfeatures2d::SIFT::create(); //Define f2d variable in Feature2D. Here, nonfree opencv module (xfeatures2d.hpp) is used.
    f2d->detect(Input,Keypoints); //Dedect Keypoints
    cv::drawKeypoints(Input, Keypoints, FeatureImage); //Draw keypoints onto the image
    f2d->compute(Input, Keypoints, Descriptors); //Compute 128 dimensional vector associated with the keypoint locations
    
    //Show and write the original image with SIFT features
    imshow("Scene Image with SIFT Features",FeatureImage);
    imwrite("results/SIFT/Scene Image with SIFT Features.jpg",FeatureImage);
}

//Write keypoints and assosiated 128 dimensional vector into a text file
void KeypointsText(){
    ofstream file; //Create file for the 128 dimensional vector
    FileStorage fs("results/SIFT/Scene Image - Keypoints.txt", FileStorage::WRITE); //Create file for the features
    write(fs,"Key Points of the Image",Keypoints); //Write keypoints to the file
    fs.release();
    file.open("results/SIFT/Scene Image - 128 Dimension.txt"); //Open the file

    file << Descriptors << endl; //Write the 128 dimenasional vector to the file
}
