// Include files for required libraries
#include <stdio.h>

#include "opencv_aee.hpp"
#include "main.hpp"     // You can use this file for declaring defined values and functions
#include "pi2c.h"

Pi2c car(0x22); // Configure the I2C interface to the Car as a global variable
using namespace std;
using namespace cv
void setup(void)
{
    setupCamera(320, 240);  // Enable the camera for OpenCV
}

int main( int argc, char** argv )
{
    setup();    // Call a setup function to prepare IO and devices

    cv::namedWindow("Photo");   // Create a GUI window called photo

    cv::namedWindow("BranStarkHSV");
    cvtcolor(frame£¬hsvimage,CV_BGR2HSV);
    while(1)    // Main loop to perform image processing
    {
        Mat frame;
        Mat h0svimage;
        while(frame.empty())
            frame = captureFrame(); // Capture a frame from the camera and store in a new matrix variable



        cv::imshow("Photo", frame); //Display the image in the window
        cv::imshow("BranStarkHSV", hsvimage);
        out << (int)hsvimage.at<Vec3b>(0, 0).type << endl;
        for (int i = 0; i < 10;++i){
        for (int j = 0; j < 10; ++j){
            cout << "B:" << (int)image.at<Vec3b>(i, j).val[0] << "  G:" << (int)image.at<Vec3b>(i, j).val[1] << "  R:" << (int)image.at<Vec3b>(i, j).val[2] << endl;
            cout << "H:" << (int)hsvimage.at<Vec3b>(i, j).val[0] << "  S:" << (int)hsvimage.at<Vec3b>(i, j).val[1] << "  V:" << (int)hsvimage.at<Vec3b>(i, j).val[2] << endl;
        }
    }

        int key = cv::waitKey(1);   // Wait 1ms for a keypress (required to update windows)

        key = (key==255) ? -1 : key;    // Check if the ESC key has been pressed
        if (key == 27)
            break;
	}

	closeCV();  // Disable the camera and close any windows

	return 0;
}



