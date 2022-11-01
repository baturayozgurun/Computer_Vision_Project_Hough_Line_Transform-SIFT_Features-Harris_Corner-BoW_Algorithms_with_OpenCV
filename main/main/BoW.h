//  Developer: Baturay Özgürün
//  Copyright © 2018 Baturay Özgürün
//  If you have any requests or questions please do not hesitate to contact me via baturay.ozgurun@gmail.com

//  Project Desciption: The Bag of Visual Words (BoW) Algorithm extracts image features as words, presenting the histogram and vocabulary of an input image.

//Include Headers
#include <iostream>
#include <opencv/highgui.h>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/xfeatures2d.hpp>
#include <opencv2/features2d.hpp>

cv::Mat DictionaryBuilding(); //Function for Vocabulary Building

//Include Namespaces
using namespace cv;
using namespace std;

int main_bow(){
    Mat Dictionary=DictionaryBuilding(); //Get the dictionary or vacabularies computed in the costom design file
    
    Ptr<FeatureDetector> detector = xfeatures2d::SiftFeatureDetector::create(); //Define feature extacter
    Ptr<DescriptorExtractor> extractor = cv::xfeatures2d::SurfDescriptorExtractor::create(); //Define descriptor
    Ptr<DescriptorMatcher> matcher = DescriptorMatcher::create("FlannBased"); //Define a matcher
    BOWImgDescriptorExtractor bowide(extractor,matcher); //Define BOW extracter
    bowide.setVocabulary(Dictionary); //Set the vocabularies
    
    //for(int i=0;i<=2;++i){
        vector<KeyPoint> keypoints; //Define keypoint variable for the SIFT
        ostringstream filename; //Create string variable
        filename << "data/scene.jpg"; //Define the image name
        
        Mat BOWHistogram; //Create matrix variable for the histogram
        Mat LineH=Mat::zeros(500, 200, CV_8UC3);
        Mat img=imread(filename.str(),CV_LOAD_IMAGE_GRAYSCALE); //Get the image
        detector->detect(img, keypoints); //Detect keypoints
        bowide.compute(img,keypoints,BOWHistogram);//Get the BOWHistogram
        
        //Draw the obtained histogram values as bar image. To do it, 'line' function can be used.
        //Histogram values are multiplied with keypoint size because of the unnormalization.
        for(int k=0; k<BOWHistogram.cols;k++){
            line(LineH, Point(k,499-BOWHistogram.at<float>(0,k)*keypoints.size()), Point(k,499), Scalar(0,0,255), 3);
        }
        
        //Write the obtained Histograms to the text files, and show the histograms
        //if(i==0){
            imshow("Histogram for Scene Image",LineH); //Show the histogram for the Sunny image
            imwrite("results/BoW/Histogram for Scene Image.jpg", LineH); //Write the histogram image
            FileStorage fs1("results/BoW/Histogram for Scene Image.txt", FileStorage::WRITE); //Open the file
            fs1 << "Histogram" << BOWHistogram*keypoints.size(); //Write histograms to the text file
            fs1.release();
    
    waitKey(1000);
    return 0;
}

//Function for Vocabulary Building
Mat DictionaryBuilding(){
    Mat input,descriptor,featuresUnclustered; //Define matrix variables
    vector<KeyPoint> keypoints; //Define keypoint variable for the SIFT
    cv::xfeatures2d::SiftDescriptorExtractor detector; //Define detector
    
    ostringstream filename;
    Ptr<Feature2D> f2d = xfeatures2d::SIFT::create();
    filename << "data/scene.jpg"; //Define the image name
    input = imread(filename.str(),CV_LOAD_IMAGE_GRAYSCALE); //Read the image
    f2d->detect(input,keypoints); //Detect features
    f2d->compute(input, keypoints,descriptor); //Compute descriptors for each feature point
    featuresUnclustered.push_back(descriptor); //Compress all feature points into a Mat object

    int dictionarySize=200,retries=1,flags=KMEANS_PP_CENTERS; //Define variables for the bow trainer
    TermCriteria tc(CV_TERMCRIT_ITER,100,0.001); //Define term criterial
    BOWKMeansTrainer bowTrainer(dictionarySize,tc,retries,flags); //Obtain Bow Trainer
    Mat Dictionary=bowTrainer.cluster(featuresUnclustered); //Cluster Features
    FileStorage fs("results/BoW/Vocabulary.txt", FileStorage::WRITE); //Write the vacabularies into a text file
    fs << "Vocabulary" << Dictionary;
    fs.release();
    return Dictionary; //Take the obtained dictionary to the main file in order to camputer histogram
}
