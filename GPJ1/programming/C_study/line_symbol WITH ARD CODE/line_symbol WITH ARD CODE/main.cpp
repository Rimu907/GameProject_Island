// Include files for required libraries
#include <stdio.h>

#include "opencv_aee.hpp"
#include "main.hpp"
#include "pi2c.h"
#include <iostream>
#include "MiniPID.h" //PID Library header file

#define baseSpeed 12

Pi2c car(0x22); // Configure the I2C interface to the Car as a global variable
Pi2c servo(0x03); // Configure the I2C interface to the Servo Arduino as a global variable
Pi2c arduino(0x07)

using namespace std;
using namespace cv;

Mat library[4];
char packets[3];
int colourFlag = 0;
int counter = 0;
char data[1];



void colourBlack(Mat* lineImage, Mat* targetImage)
{
    inRange(*lineImage, Scalar(0, 0, 0), Scalar(179, 77, 64), *targetImage); //inRange(image, min, max, mask)
}

void colourRed(Mat* lineImage, Mat* targetImage)
{
    Mat red1;
    Mat red2;
    inRange(*lineImage, Scalar(0, 50, 50), Scalar(7, 255, 255), red1); //inRange(image, min, max, mask)
    inRange(*lineImage, Scalar(173, 50, 50), Scalar(179, 255, 255), red2); //inRange(image, min, max, mask)
    *targetImage = red1|red2;
}

void colourGreen(Mat* lineImage, Mat* targetImage)
{
    inRange(*lineImage, Scalar(38, 50, 50), Scalar(79, 255, 255), *targetImage); //inRange(image, min, max, mask)
}

void colourBlue(Mat* lineImage, Mat* targetImage)
{
    inRange(*lineImage, Scalar(80, 50, 50), Scalar(134, 255, 255), *targetImage); //inRange(image, min, max, mask)
}

void colourYellow(Mat* lineImage, Mat* targetImage)
{
    inRange(*lineImage, Scalar(24, 50, 50), Scalar(37, 255, 255), *targetImage); //inRange(image, min, max, mask)
}

void setup(void)
{
    setupCamera(320, 240);  // Enable the camera for OpenCV

    //Read library pictures
    library[0] = imread("BlueShortCut.PNG");
    library[1] = imread("GreenShortCut.PNG");
    library[2] = imread("RedShortCut.PNG");
    library[3] = imread("YellowShortCut.PNG");
    library[4] = imread("StopLight.PNG");
    library[5] = imread("ShapeCounter.PNG");
    library[6] = imread("InclineMeasurement.PNG");
    library[7] = imread("Football.PNG");
    library[8] = imread("DistanceMeasurement.PNG");

    //Convert library pictures to black and white pixels
    for (int i = 0; i <= 3; i++)
    {
        cvtColor(library[i], library[i], COLOR_BGR2HSV);
        inRange(library[i],Scalar(150,100,110),Scalar(160,255,255),library[i]);
    }

    //Let the camera point to ground
    packets[0] = 'A';
    servo.i2cWrite(packets, 3);

    //Make sure the car is stopped anyway
    packets[0] = 'R';
    packets[1] = 0;
    packets[2] = 0;
    car.i2cWrite(packets, 3);

    packets[0] = 'L';
    packets[1] = 0;
    packets[2] = 0;
    car.i2cWrite(packets, 3);
}

int main( int argc, char** argv )
{
    setup();    // Call a setup function to prepare IO and devices

    int currentWidth = 0;
    int targetWidth = 0;
    int pinkWidth = 0;
    int centrePoint = 0;
    int on = 0;

    MiniPID pid = MiniPID(0.5,0,0); //Set pid weight values
    pid.setOutputLimits(-25, 25); //Constrain speed change

    while(1)    // Main loop to perform image processing
    {
        while (on == 0)
        {
            Mat frame; //raw frame from the camera
            Mat lineImage; //flipped frame from the camera
            Mat targetImage; //HSV frame from camera
            Mat targetImageCropped; //cropped HSV frame from camera
            Mat pinkSquare; //the frame used to detect pink square

            while(frame.empty())
                frame = captureFrame(); // Capture a frame from the camera and store in a new matrix variable
            cvtColor(frame, lineImage, COLOR_BGR2HSV); //convert colour space from GBR to HSV
            rotate(lineImage, lineImage, ROTATE_180); //rotate the image 180 degrees

            //switch to determine clour range
            switch (colourFlag)
            {
            case 0:
                colourBlack(&lineImage, &targetImage);
                break;
            case 1:
                colourRed(&lineImage, &targetImage);
                break;
            case 2:
                colourGreen(&lineImage, &targetImage);
                break;
            case 3:
                colourBlue(&lineImage, &targetImage);
                break;
            case 4:
                colourYellow(&lineImage, &targetImage);
                break;
            }

            cv::imshow("HSV Stream", targetImage);
            inRange(lineImage,Scalar(155,68,57),Scalar(170,255,230),pinkSquare); //get another copy of frame to detect pink square

            targetImageCropped = targetImage(Rect(0, 20, 320, 1)); //crop the image to get the 21st row of pixels
            cv::imshow("pinkSquare",pinkSquare);
            pinkSquare = pinkSquare(Rect(0, 0, 320, 1)); //x,y,width,height


            pinkWidth = countNonZero(pinkSquare);
            //cout << pinkWidth << endl;
            if (pinkWidth > 10)
            {
                //Lift the camera
                packets[0] = 'B';
                servo.i2cWrite(packets, 3);

                //stop the car
                packets[0] = 'R';
                packets[1] = 0;
                packets[2] = 0;
                car.i2cWrite(packets, 3);

                packets[0] = 'L';
                packets[1] = 0;
                packets[2] = 0;
                car.i2cWrite(packets, 3);

                on = 1;
                counter = counter + 1;
                break;
            }

            targetWidth = countNonZero(targetImageCropped); //count the number of white pixels
            if (targetWidth > 0)
            {
                for (int x = 319; x >= 0; x--)
                {
                    if (targetImageCropped.at<char>(0,x) == 255)
                    {
                        centrePoint = (x + 20);
                    }
                }
            }

            //cv::imshow("Camera Stream", frame); //Display the image in the window
            //cv::imshow("HSV Stream", targetImage);
            cv::imshow("Target Cropped Stream", targetImageCropped);

            /*Ensures window updates*/
            int key = cv::waitKey(1);   // Wait 1ms for a keypress (required to update windows)

            key = (key==255) ? -1 : key;    // Check if the ESC key has been pressed
            if (key == 27)
                break;

            double speedChange = pid.getOutput(centrePoint,160);
            //cout << "Speed Change: " << speedChange << endl;

            int leftSpeed = baseSpeed + speedChange;
            int rightSpeed = baseSpeed - speedChange;

            //cout << "L: " << leftSpeed << "   " << "R: " << rightSpeed << endl;

            char MSB;
            char LSB;

            MSB = (leftSpeed & 0xFF00) >> 8;
            LSB = leftSpeed & 0x00FF;
            packets[0] = 'L';
            packets[1] = MSB;
            packets[2] = LSB;
            car.i2cWrite(packets, 3);

            MSB = (rightSpeed & 0xFF00) >> 8;
            LSB = rightSpeed & 0x00FF;
            packets[0] = 'R';
            packets[1] = MSB;
            packets[2] = LSB;
            car.i2cWrite(packets, 3);
        }

        if (on = 1)
        {
            Mat frame;
            int state = 0;
            waitKey(500);
            for (int i = 0; i <= 19; i ++)
            {
                Mat detected; //frame with pink colour only
                Mat transformed; //frame for enlarged signs
                while(frame.empty())
                    frame = captureFrame(); // Capture a frame from the camera and store in a new matrix variable

                rotate(frame, frame, ROTATE_180);

                cvtColor(frame, frame, COLOR_BGR2HSV);
                inRange(frame,Scalar(145,68,57),Scalar(170,255,255),detected);

                std::vector< std::vector<cv::Point> > contours;
                std::vector<Vec4i> hierarchy;
                cv::findContours(detected, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0));

                //find the largest contour(the outline of the detected sign)
                if (contours.size() > 0)
                {
                    cvtColor(frame, frame, COLOR_HSV2BGR);
                    std::vector< std::vector<cv::Point> > approxedcontours(contours.size());
                    int a = 0;
                    int maxcontour = -1;
                    for (int i = 0; i < contours.size(); i++)
                    {
                        approxPolyDP(contours[i], approxedcontours[i], 30,true);

                        int area = cv::contourArea(contours[i]);
                        if (area > a)
                        {
                            a = area;
                            maxcontour = i;
                        }
                    }

                    drawContours( frame, contours, maxcontour, Scalar(255, 0, 0), 2, LINE_8, noArray(), 0, Point() );
                    cv::imshow("Photo", frame);

                    if (maxcontour != -1)
                        transformed = transformPerspective(approxedcontours[maxcontour], detected, 320, 240);

                    //compare the captured sign with the library(recognize the detected sign)
                    float b = 0;
                    if (transformed.rows > 0 && transformed.cols > 0)
                    {
                        cv::imshow("transformed", transformed);

                        for (int i = 0; i <= 3; i++)
                        {
                            float match = compareImages(transformed,library[i]);
                            if (match >= b)
                            {
                                b = match;
                                state = i + 1;
                            }
                        }
                    }
                }
            }

            //Things to do when a sign is recognized
            switch (state)
            {
            case 0:
                cout << "\nNo Symbol" <<endl;
                colourFlag = 0;
                packets[0] = 'A';
                servo.i2cWrite(packets, 3);
                on = 0;
                break;
            case 1:
                cout << "\nBlue Shortcut" <<endl;
                colourFlag = 3;
                packets[0] = 'A';
                servo.i2cWrite(packets, 3);
                on = 0;
                break;
            case 2:
                cout << "\nGreen Shortcut" <<endl;
                colourFlag = 2;
                packets[0] = 'A';
                servo.i2cWrite(packets, 3);
                on = 0;
                break;
            case 3:
                cout << "\nRed Shortcut" <<endl;
                colourFlag = 1;
                packets[0] = 'A';
                servo.i2cWrite(packets, 3);
                on = 0;
                break;
            case 4:
                cout << "\nYellow Shortcut" <<endl;
                colourFlag = 4;
                packets[0] = 'A';
                servo.i2cWrite(packets, 3);
                on = 0;
                break;
            case 5:
                cout << "\nStop Light" <<endl;
                break;
            case 6:
                cout << "\nShape Counter" <<endl;
                break;
            case 7:
                cout << "\nIncline Measurement" <<endl;
                break;
            case 8:
                cout << "\nFootball" <<endl;
                break;
            case 9:
                cout << "\nDistance Measurement" <<endl;
                break;
            }

            packets[0] = 'R';
            packets[1] = 0;
            packets[2] = 10;
            car.i2cWrite(packets, 3);

            packets[0] = 'L';
            packets[1] = 0;
            packets[2] = 10;
            car.i2cWrite(packets, 3);

            while(frame.empty())
                frame = captureFrame();

            waitKey(500);

            /*int key = cv::waitKey(1);   // Wait 1ms for a keypress (required to update windows)

            key = (key==255) ? -1 : key;    // Check if the ESC key has been pressed
            if (key == 27)
                break;*/
        }

        arduino.i2cRead(data, 1);
        char command = data[0]
        if(command =='N')
        {
                packets[0] = 'R';
                packets[1] = 0;
                packets[2] = 0;
                car.i2cWrite(packets, 3);

                packets[0] = 'L';
                packets[1] = 0;
                packets[2] = 0;
                car.i2cWrite(packets, 3);
        }
        else if(command=='U')
        {
                packets[0] = 'R';
                packets[1] = 20;
                packets[2] = 20;
                car.i2cWrite(packets, 3);

                packets[0] = 'L';
                packets[1] = 20;
                packets[2] = 20;
                car.i2cWrite(packets, 3);
        }
        else if(command=='D')
        {
                packets[0] = 'R';
                packets[1] = 0;
                packets[2] = 0;
                car.i2cWrite(packets, 3);

                packets[0] = 'L';
                packets[1] = 0;
                packets[2] = 0;
                car.i2cWrite(packets, 3);
        }
        else
        {

        }
    }
    closeCV();  // Disable the camera and close any windows

    return 0;
}
