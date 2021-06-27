///////////////////////////////////////////////////////////////
//                                                           // 
// H61AEE: Dept. EEE, The University of Nottingham 2018      //
// Author: D. Fallows                                        //
//                                                           //
// REMOTE_Template.h: HMI Template Sketch                    //
//                    Session 4 - RF Remote Control          // 
//                                                           // 
///////////////////////////////////////////////////////////////

#ifndef REMOTE_Template_h
#define REMOTE_Template_h

// Defines
#define HMI 0xA1	//I2C Addresses
#define CAR 0xA2
#define SENSOR 0xA3
#define REMOTE 0xA4

#define GROUPNUMBER 1
#define CHANNELNUMBER 129 - (2*GROUPNUMBER)
#define PAYLOADSIZE 32

// Function declarations
void writeToI2C(char device, char command, int parameter);

// Global Variables
byte rfAddresses[][6] = {"1NODE", "2NODE"};
byte rfPacket[PAYLOADSIZE];

#endif
