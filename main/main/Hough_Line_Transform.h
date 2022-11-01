//  Developer: Baturay Özgürün
//  Copyright © 2018 Baturay Özgürün
//  If you have any requests or questions please do not hesitate to contact me via baturay.ozgurun@gmail.com

//  Project Desciption: The Hough Line Transform detects straight lines in an input image and presents line parameters in a text file.

//Include Headers
#include <iostream>
#include <opencv/highgui.h>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>

//Include Namespaces
using namespace cv;
using namespace std;

int main_hough(){
    Mat Image,LineImage,EdgeImage; //Define the matrix variables
    //Define vectors
    vector<Vec2f> Parameters;
    vector<Vec4i> Lines;
    
    Image=imread("data/scene.jpg"); //Read the image
    
    Canny(Image,EdgeImage,50,200,3); //Detect the image edges using Canny method
    cvtColor(EdgeImage,LineImage,CV_GRAY2BGR); //Copy the edge image to the line image
    
    //In the following functions: 1 (1 pixel) are pi/180 (1 angle) resolution in pixel and radian, respectively. 50 is the intersection threshold to form a line.
    HoughLines(EdgeImage, Parameters, 1, CV_PI/180,50); //HoughLines Function provides Rho and Theta paramaters. Detected edges used to define the parameters.
    HoughLinesP(EdgeImage, Lines, 1, CV_PI/180,50); //HoughLinesP Function is probabilistic method to define lines. Detected edges used to define the lines.
    
    //Draw the lines onto the edge-detected-image
    for(size_t i=0;i<Lines.size();i++){
        Vec4i l = Lines[i];
        line(LineImage, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0,0,255), 1); //Draw red (0,0,255) line from the pixel Point(l[0], l[1]) to Point(l[2], l[3])
    }
    
    FileStorage fs("results/Hough/Lines and Parameters Scene Image.txt", FileStorage::WRITE); //Create file for the parameters and lines
    write(fs,"Parameters - First Column Rho - Second Column Theta",Parameters); //Write parameters to the file
    write(fs,"Lines of the Image",Lines); //Write line locations to the file
    fs.release();
    imshow("Scene Image", Image);
    imshow("Scene Image with Detected Edges", EdgeImage);
    imshow("Scene Image with Detected Lines", LineImage);
    imwrite("results/Hough/Scene Image with Detected Edges.jpg", EdgeImage);
    imwrite("results/Hough/Scene Image with Detected Lines.jpg", LineImage);
    
    waitKey(1000); //wait to show images
    return 0;
}
