///////////////////////////////////////////////////////////////
//                                                           // 
// H61AEE: Dept. EEE, The University of Nottingham 2017      //
// Author: D. Fallows                                        //
//                                                           //
// H61AEE_S01.h: Basic Vehicle Control Library             //
//                                                           // 
///////////////////////////////////////////////////////////////

#ifndef H61AEEVehicleWk1_h
#define H61AEEVehicleWk1_h

#define leftPosHigh 6 //Create 'nice' names for the MOSFET gate signals
#define leftNegHigh 8
#define leftPosLow 5
#define leftNegLow 7

#define rightPosHigh 10
#define rightNegHigh 12
#define rightPosLow 9
#define rightNegLow 11

#define LEFT 0
#define RIGHT 1
#define BOTH 2

enum direction {  //Create a new variable type for the motor direction
  forwards,
  backwards
};

void setupVehicle(void);

class Vehicle
{
	public:
		Vehicle(void);
		void setSpeed(char motor, char speed);
		void setDirection(char motor, direction dir);
		unsigned long readEncoder(char motor);
		void setupVehicle(void);
};

#endif