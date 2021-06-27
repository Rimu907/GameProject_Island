// Include files for required libraries
#include <stdio.h>

#include "opencv_aee.hpp"
#include "main.hpp"     // You can use this file for declaring defined values and functions
#include "pi2c.h"

Pi2c car(0x22); // Configure the I2C interface to the Car as a global variable

void setup(void)
{
    setupCamera(320, 240);  // Enable the camera for OpenCV
}

int main( int argc, char** argv)
{
    setup();    // Call a setup function to prepare IO and devices

    cv::namedWindow("Photo");   // Create a GUI window called photo
    cv::namedWindow("black");    while(1)    // Main loop to perform image processing
    {
        Mat frame;
        Mat imgHSV;
        Mat black;

        while(frame.empty())
            frame = captureFrame(); // Capture a frame from the camera and store in a new matrix variable



        int key = cv::waitKey(1);// Wait 1ms for a keypress (required to update windows)
        cvtColor(frame,imgHSV,COLOR_BGR2HSV);
        inRange(imgHSV,Scalar(0,0,0),Scalar(180,255,46),black);
        cv::imshow("black",black);


        std::vector< std::vector<cv::Point> > contours; // Variable for list of contours
        std::vector<Vec4i> hierarchy; // Variable for image topology data
        cv::findContours(black, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE,Point(0, 0)); // Calculate the contours and store them

        for(int i = 0; i < contours.size(); i++) // Loop through the contours
      {
       drawContours( frame, contours, i, Scalar(0,0,255), 2, LINE_8, noArray(), 0,Point() ); // Draw each in red
      }
        cv::imshow("Photo", frame); //Display the image in the window
      /*for (int i=0,i<contours.size();i++)
        {
            point regionCentre  =  findContourCentre(contours[i]);
            printf("\ncontour center x=%d px, y=%d px \n  ",regionCentre.x,regionCentre.y);
        }

        if(regionCentre.x>140&&regionCentre.x<180)
        {
            char packet[3]={'L',0,5};
            car.i2cWrite(packet,3);
            char packet[3]={'R',0,7};
            car.i2cWrite(packet,3);
        }
        if(regionCentre.x<140&&regionCentre.x>0)
        {
            char packet[3]={'L',0,5};
            car.i2cWrite(packet,3);
            char packet[3]={'R',0,0};
            car.i2cWrite(packet,3);
        }
        if(regionCentre.x>180)
        {
            char packet[3]={'L',0,0};
            car.i2cWrite(packet,3);
            char packet[3]={'R',0,10};
            car.i2cWrite(packet,3);
        }*/
        //int key = cv::waitKey(1);
        key = (key==255) ? -1 : key;    // Check if the ESC key has been pressed
        if (key == 27)
            break;
	}

	closeCV();  // Disable the camera and close any windows

	return 0;
}



