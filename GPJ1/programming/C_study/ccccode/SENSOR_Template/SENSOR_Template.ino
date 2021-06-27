///////////////////////////////////////////////////////////////
//                                                           //
// H61AEE: Dept. EEE, The University of Nottingham 2018      //
// Author: D. Fallows                                        //
//                                                           //
// SENSOR_Template.ino: HMI Template Sketch                  //
//                      Session 4 - RF Remote Control        //
//                                                           //
///////////////////////////////////////////////////////////////

// Libraries
#include <Wire.h>
#include <SPI.h>
#include <RF24.h>
#include "SENSOR_Template.h"

RF24 radio(9, 10);  // Set up the nRF24L01+ radio (CE pin, CSN pin)

void setup()
{
  Wire.begin(SENSOR);           // join i2c bus as the Sensor board

  Serial.begin(9600);

  radio.begin();                    // Start the radio module
  radio.setPALevel(RF24_PA_MAX);    // Set the transmission power to max
  radio.setDataRate(RF24_250KBPS);  // Set the speed to 250kbps
  radio.setChannel(CHANNELNUMBER);  // Set the channel

  radio.openWritingPipe(rfAddresses[0]);    // Transmit to the remote address
  radio.openReadingPipe(1, rfAddresses[1]); // Recieve sensor addressed packets

  radio.setPayloadSize(PAYLOADSIZE); // Set the number of bytes for the data packet

  radio.startListening();

  /* TODO - configure any IO and libraries here */
}

void loop()
{
  /* TODO - add your own code to process the recieved RF data */
  if (radio.available())
  {
    while (radio.available())   //Read the full data packet
    {
      radio.read(&rfPacket, PAYLOADSIZE);  // rfPacket contains the data recieved from the remote as bytes
    }



















    int right = rfPacket[0];   // Do something with the data... e.g. reconstuct an integer and display on the serial monitor
    right |= rfPacket[1] << 8;
    int left = rfPacket[2];   // Do something with the data... e.g. reconstuct an integer and display on the serial monitor
    left |= rfPacket[3] << 8;
    Serial.print("Radio value Right: "); Serial.println(right);
    Serial.print("Radio value left: "); Serial.println(left);
    

    /* TODO - Transmit data to the car to control it (e.g. left/right motor base speeds) */
  }
}

void writeToI2C(char device, char command, int parameter)
{
  Wire.beginTransmission(device); // transmit to car
  Wire.write(command);  // send the command first
  Wire.write((byte)((parameter & 0xFF00) >> 8));  // send the parameter as two bytes
  Wire.write((byte)((parameter & 0x00FF)));
  Wire.endTransmission();    // stop transmitting
}

