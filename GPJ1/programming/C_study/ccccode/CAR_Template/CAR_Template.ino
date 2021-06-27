///////////////////////////////////////////////////////////////
//                                                           // 
// H61AEE: Dept. EEE, The University of Nottingham 2018      //
// Author: D. Fallows                                        //
//                                                           //
// CAR_Template.ino: Vehicle Template Sketch                 //
//                   Session 4 - RF Remote Control           //
//                                                           // 
///////////////////////////////////////////////////////////////

// Libraries
#include <Wire.h>
#include <H61AEE_S04.h>
#include "CAR_Template.h"

void setup()
{
  Wire.begin(CAR);              // join i2c bus as the car
  Wire.onReceive(receiveEvent); // register function to be called whenever data is received
  Wire.onRequest(requestEvent); // register function to be called when data needs to be transmitted
  
  Serial.begin(9600);           // start serial for output

  pinMode(YELLOW_LED, OUTPUT);   // Configure LED outputs
  pinMode(RED_LED, OUTPUT);

  car.setupVehicle();

  /* TODO - Configure IO and libraries as required */
}

void loop()
{  
  /* TODO - Option 1: Integrate code from library examples to read the MPU6050 and implement a PID routine */
}

// This function executes whenever I2C data is received
void receiveEvent(int howMany)
{
  char command = 0;
  int parameter = 0;

  if(howMany != 3)  // Commands should be 3 bytes long. Anything else is an error
  {
    emptyBuffer();
    return;
  }
  
  command = Wire.read(); // Read the first byte (the command character)

  boolean commandFound = false;   // Check the received command against the list of valid commands
  for(int i = 0; i < NUM_COMMANDS; i++)
  {
    if(command == commandList[i])
    {
      commandFound = true;
    }
  }
  if(!commandFound)   // If the command isn't on the list then ignore
  {
    emptyBuffer();
    return;
  }
  
  byte MSB = Wire.read();   // receive MSB of parameter
  byte LSB = Wire.read();   // receive LSB of parameter

  parameter = (MSB << 8) | LSB; // combine the two bytes into an integer

  // Process recieved command
  /* TODO - Set up commands as is sutiable for your chosen objective */
  switch(command)
  {
    case 'L': car.setSpeed(LEFT, parameter);
              break;
    case 'R': car.setSpeed(RIGHT, parameter);
              break;
    case 'S': car.setSpeed(ALL, 0);
              break;
    case 'D': returnData = parameter;
              break;
  }
}

// Function to clear the I2C buffer
void emptyBuffer(void)
{
  while(Wire.available())
  {
    Wire.read();
  }
}

// This function is executed whenever data is requested
void requestEvent(void) {
  // Check what data is required based on the last Data command
  if(returnData == 1)
  {
    unsigned long encoder = car.readEncoder(LEFT);  // the encoder value is a 4 byte number
    
    Wire.write((byte)((encoder & 0xFF000000) >> 24)); // send each byte separately from MSB to LSB
    Wire.write((byte)((encoder & 0x00FF0000) >> 16));
    Wire.write((byte)((encoder & 0x0000FF00) >> 8));
    Wire.write((byte)(encoder & 0x000000FF));
  }
  else if(returnData == 2)
  {
    unsigned long encoder = car.readEncoder(RIGHT);  // the encoder value is a 4 byte number
    
    Wire.write((byte)((encoder & 0xFF000000) >> 24)); // send each byte separately from MSB to LSB
    Wire.write((byte)((encoder & 0x00FF0000) >> 16));
    Wire.write((byte)((encoder & 0x0000FF00) >> 8));
    Wire.write((byte)(encoder & 0x000000FF));
  }
}

