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
#include <Kalman.h>
#include "SENSOR_Template.h"

RF24 radio(9, 10);  // Set up the nRF24L01+ radio (CE pin, CSN pin)
float fRad2Deg = 57.295779513f; 
const int MPU = 0x68; 
const int nValCnt = 7; 

const int nCalibTimes = 1000; 
int calibData[nValCnt];

unsigned long nLastTime = 0; 
float fLastRoll = 0.0f; 
float fLastPitch = 0.0f; 
Kalman kalmanRoll; 
Kalman kalmanPitch; 

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
  int readouts[nValCnt];
  ReadAccGyr(readouts);
  float realVals[7];
  Rectify(readouts, realVals); 

  float fNorm = sqrt(realVals[0] * realVals[0] + realVals[1] * realVals[1] + realVals[2] * realVals[2]);
  float fRoll = GetRoll(realVals, fNorm); //calculate Roll angle
  if (realVals[1] > 0) {
    fRoll = -fRoll;
  }
  float fPitch = GetPitch(realVals, fNorm); //calculate Pitch angle
  if (realVals[0] < 0) {
    fPitch = -fPitch;
  }
  unsigned long nCurTime = micros();
  float dt = (double)(nCurTime - nLastTime) / 1000000.0;

  float fNewRoll = kalmanRoll.getAngle(fRoll, realVals[4], dt);
  float fNewPitch = kalmanPitch.getAngle(fPitch, realVals[5], dt);

  float fRollRate = (fNewRoll - fLastRoll) / dt;
  float fPitchRate = (fNewPitch - fLastPitch) / dt;
 

  fLastRoll = fNewRoll;
  fLastPitch = fNewPitch;

  nLastTime = nCurTime;

  Serial.print("Roll:");
  Serial.print(fNewRoll); Serial.print('(');
  Serial.print(fRollRate); Serial.print("),\tPitch:");
  Serial.print(fNewPitch); Serial.print('(');
  Serial.print(fPitchRate); Serial.print(")\n");
  delay(10);
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
    int carRight=(int)map(right,0,1023,-100,100);
    int carLeft=(int)map(left,0,1023,-100,100);
    
    Serial.print("Right: "); Serial.println(carRight);
    Serial.print("Left: "); Serial.println(carLeft);

    writeToI2C(CAR,"R",carRight);
    writeToI2C(CAR,"L",carLeft);
    
    

    /* TODO - Transmit data to the car to control it (e.g. left/right motor base speeds) */
  }

}
void WriteMPUReg(int nReg, unsigned char nVal) {
  Wire.beginTransmission(MPU);
  Wire.write(nReg);
  Wire.write(nVal);
  Wire.endTransmission(true);
}
unsigned char ReadMPUReg(int nReg) {
  Wire.beginTransmission(MPU);
  Wire.write(nReg);
  Wire.requestFrom(MPU, 1, true);
  Wire.endTransmission(true);
  return Wire.read();
}
void ReadAccGyr(int *pVals) {
  Wire.beginTransmission(MPU);
  Wire.write(0x3B);
  Wire.requestFrom(MPU, nValCnt * 2, true);
  Wire.endTransmission(true);
  for (long i = 0; i < nValCnt; ++i) {
    pVals[i] = Wire.read() << 8 | Wire.read();
  }
}
void Calibration()
{
  float valSums[7] = {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0};

  for (int i = 0; i < nCalibTimes; ++i) {
    int mpuVals[nValCnt];
    ReadAccGyr(mpuVals);
    for (int j = 0; j < nValCnt; ++j) {
      valSums[j] += mpuVals[j];
    }
  }

  for (int i = 0; i < nValCnt; ++i) {
    calibData[i] = int(valSums[i] / nCalibTimes);
  }
  calibData[2] += 16384; 
}

float GetRoll(float *pRealVals, float fNorm) {
  float fNormXZ = sqrt(pRealVals[0] * pRealVals[0] + pRealVals[2] * pRealVals[2]);
  float fCos = fNormXZ / fNorm;
  return acos(fCos) * fRad2Deg;
}

float GetPitch(float *pRealVals, float fNorm) {
  float fNormYZ = sqrt(pRealVals[1] * pRealVals[1] + pRealVals[2] * pRealVals[2]);
  float fCos = fNormYZ / fNorm;
  return acos(fCos) * fRad2Deg;
}


void Rectify(int *pReadout, float *pRealVals) {
  for (int i = 0; i < 3; ++i) {
    pRealVals[i] = (float)(pReadout[i] - calibData[i]) / 16384.0f;
  }
  pRealVals[3] = pReadout[3] / 340.0f + 36.53;
  for (int i = 4; i < 7; ++i) {
    pRealVals[i] = (float)(pReadout[i] - calibData[i]) / 131.0f;
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

