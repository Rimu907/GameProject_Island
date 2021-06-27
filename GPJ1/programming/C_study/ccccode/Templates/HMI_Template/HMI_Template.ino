///////////////////////////////////////////////////////////////
//                                                           // 
// H61AEE: Dept. EEE, The University of Nottingham 2018      //
// Author: D. Fallows                                        //
//                                                           //
// HMI_Template.ino: HMI Template Sketch                     //
//                   Session 4 - RF Remote Control           // 
//                                                           // 
///////////////////////////////////////////////////S////////////

// Libraries
#include <Wire.h>
#include "HMI_Template.h"
#include <LiquidCrystal.h> 
#include <Kalman.h>
int getvoltage = 15; 
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2; 
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
void setup()
{
  Wire.begin(HMI);              // join i2c bus as the HMI
  Wire.onReceive(receiveEvent); // register function to be called whenever data is received
  
  Serial.begin(9600);

  /* TODO - configure IO and libraries */
}

void loop()
{
  
  /* TODO - Option 2 add code to display received MPU6050 data */
}

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

  // Process the received command
  /* TODO - add extra commands as required */
  switch(command)
  {
    case 'D': parameter;
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

