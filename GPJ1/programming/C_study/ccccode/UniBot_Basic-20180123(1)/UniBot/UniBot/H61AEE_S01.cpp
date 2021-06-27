///////////////////////////////////////////////////////////////
//                                                           // 
// H61AEE: Dept. EEE, The University of Nottingham 2017      //
// Author: D. Fallows                                        //
//                                                           //
// H61AEE_S01.cpp: Basic Vehicle Control Library             //
//                                                           // 
///////////////////////////////////////////////////////////////

#include <TimerOne.h>
#include <H61AEE_S01.h>
#include "Arduino.h"

unsigned long leftEnc = 0;  //These variables contain the number of encoder pulses
unsigned long rightEnc = 0;

char leftMotorSpeed = 0;
char rightMotorSpeed = 0;
direction leftMotorDir = forwards;
direction rightMotorDir = forwards;

//Interrupt Service Routines
void incLeftEnc(void)
{
  leftEnc++;
}

void incRightEnc(void)
{
  rightEnc++;
}

void pwmControl(void)
{
  static char timerCount = 0;  //Variable to count how many times the interrupt has been called in a single PWM cycle
  static direction currentRightDir, currentLeftDir; 

  if(timerCount == leftMotorSpeed)
  {
    if(currentLeftDir == forwards)
    {
      PORTD |= B01000000;
    }
    else
    {
      PORTB |= B00000001;
    }
  }
  if(timerCount == rightMotorSpeed)
  {
    if(currentRightDir == forwards)
    {
      PORTB |= B00010000;
    }
    else
    {
      PORTB |= B00000100;
    }
  }

  timerCount--; //Decrement the count with each interrupt call

  if(timerCount <= 0)
  {
    timerCount = 100; //Reset the count when we hit zero

    PORTD &= B00011111; //Use PORT control to switch off the H-bridges
    PORTB &= B11100000;
    
    currentLeftDir = leftMotorDir;  //Update the motor directions for this cycle
    currentRightDir = rightMotorDir;
    
    if(currentLeftDir == forwards)  //Enable the low-side FETs based on direction
    {
      PORTD |= B10000000;
    }
    else
    {
      PORTD |= B00100000;
    }
    if(currentRightDir == forwards)
    {
      PORTB |= B00000010;
    }
    else
    {
      PORTB |= B00001000;
    }
  }
}

void Vehicle::setupVehicle(void)
{
	pinMode(leftPosHigh, OUTPUT); //Configure DIR pins
	pinMode(leftPosLow, OUTPUT);
	pinMode(leftNegHigh, OUTPUT);
	pinMode(leftNegLow, OUTPUT);

	pinMode(rightPosHigh, OUTPUT); //Configure PWM pins
	pinMode(rightPosLow, OUTPUT);
	pinMode(rightNegHigh, OUTPUT);
	pinMode(rightNegLow, OUTPUT);
	
	pinMode(2, INPUT_PULLUP);  //Configure encoder pins
	pinMode(3, INPUT_PULLUP);
	attachInterrupt(digitalPinToInterrupt(2), incLeftEnc, RISING);  //The encoder pins have interrupts so that each change is captured
	attachInterrupt(digitalPinToInterrupt(3), incRightEnc, RISING);

	Timer1.initialize(50);  //Setup a timer to control the PWM signal generation (period in microseconds)
	Timer1.attachInterrupt(pwmControl);
}

// Functions for vehicle class
Vehicle::Vehicle(void)
{
	
}
void Vehicle::setSpeed(char motor, char speed)
{
	direction dir;
	if(speed >= 0)
	{
		dir = forwards;
	}
	else
	{
		dir = backwards;
		speed = -speed;
	}
	
	switch(motor)
	{
		case LEFT:	leftMotorDir = dir;
					leftMotorSpeed = speed;
					break;
		case RIGHT:	rightMotorDir = dir;
					rightMotorSpeed = speed;
					break;
		case BOTH:	leftMotorDir = dir;
					rightMotorDir = dir;
					leftMotorSpeed = speed;
					rightMotorSpeed = speed;
					break;
	}
}

void Vehicle::setDirection(char motor, direction dir)
{	
	switch(motor)
	{
		case LEFT:	leftMotorDir = dir;
					break;
		case RIGHT:	rightMotorDir = dir;
					break;
		case BOTH:	leftMotorDir = dir;
					rightMotorDir = dir;
					break;
	}
}

unsigned long Vehicle::readEncoder(char motor)
{
	if(motor == LEFT)
		return leftEnc;
	else
		return rightEnc;
}