///////////////////////////////////////////////////////////////
//                                                           // 
// H61AEE: Dept. EEE, The University of Nottingham 2018      //
// Author: D. Fallows                                        //
//                                                           //
// HMI_Template.h: HMI Template Sketch                       //
//                 Session 4 - RF Remote Control             // 
//                                                           // 
///////////////////////////////////////////////////////////////

#ifndef HMI_Template_h
#define HMI_Template_h

// Defines
#define HMI 0xA1	//I2C Addresses
#define CAR 0xA2
#define SENSOR 0xA3
#define REMOTE 0xA4

// Function declarations
void receiveEvent(int howMany);
void emptyBuffer(void);

// Global Variables

// List of commands available
#define NUM_COMMANDS 1
char commandList[NUM_COMMANDS] = {'D'};

#endif
