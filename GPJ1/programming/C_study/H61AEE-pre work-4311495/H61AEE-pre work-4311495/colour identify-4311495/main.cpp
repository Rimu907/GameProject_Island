#include <stdio.h>
#include <iostream>
#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

int main()
{
    int rownumber=0;
    Mat image = imread("RedCar.bmp",1);
    namedWindow("image",CV_WINDOW_FREERATIO);
    imshow("image",image);
    waitKey(0);

    Mat photo;//red
    Mat image2;
    uchar* p = photo.ptr<uchar>(rownumber);
    for(int x = 0; x < photo.cols; x++)
   {
    p[x]; // This is our B&W pixel data we can read it or write it
    uchar pixel = p[x]; // read the data into pixel
    p[x] = 255; // make the pixel white
   };
    int numred = 0; // Create a integer to store the result
    countNonZero(photo); // Count the number of non-zero pixels

    cvtColor(image, image2, COLOR_BGR2HSV);
    inRange(image2,Scalar(0,43,46),Scalar(10,255,255),photo);

    Mat photo2;//blue
    uchar* e = photo2.ptr<uchar>(rownumber);
    for(int n = 0; n < photo2.cols; n++)
   {
    e[n]; // This is our B&W pixel data we can read it or write it
    uchar pixel = e[n]; // read the data into pixel
    e[n] = 255; // make the pixel white
   };
    int numblue = 1; // Create a integer to store the result
    numblue = countNonZero(photo2); // Count the number of non-zero pixels

    cvtColor(image, image2, COLOR_BGR2HSV);
    inRange(image2,Scalar(100,43,46),Scalar(125,255,255),photo2);

    Mat photo3;//green
    uchar* h = photo3.ptr<uchar>(rownumber);
    for(int m = 0; m <photo3.cols; m++)
   {
    h[m]; // This is our B&W pixel data we can read it or write it
    uchar pixel = h[m]; // read the data into pixel
    h[m] = 255; // make the pixel white
   };
    int numgreen = 2; // Create a integer to store the result
    numgreen = countNonZero(photo3); // Count the number of non-zero pixels

    cvtColor(image, image2, COLOR_BGR2HSV);
    inRange(image2,Scalar(65,43,46),Scalar(75,255,255),photo3);


    int a,b,c;
    a=countNonZero(photo);
    b=countNonZero(photo2);
    c=countNonZero(photo3);

    if(a>b&&a>c)
    {
        cout<<"The colour is red  \n";
    }
    else if(b>a&&b>c)
    {
        cout<<"The colour is blue  \n";
    }
    else if(c>a&&c>b)
    {
        cout<<"The colour is green  \n";
    }
    cout<<a<<" "<<b<<" "<<c;

    namedWindow("Output",CV_WINDOW_FREERATIO);
    imshow("Output",photo);
    waitKey(0);

    namedWindow("Output",CV_WINDOW_FREERATIO);
    imshow("Output",photo2);
    waitKey(0);

    namedWindow("Output",CV_WINDOW_FREERATIO);
    imshow("Output",photo3);
    waitKey(0);

}
