///////////////////////////////////////////////////////////////
//                                                           // 
// H61AEE: Dept. EEE, The University of Nottingham 2017      //
//                                                           //
// UniBot_Basic: Arduino code to directly control H-bridges  //
// Left output on PWM                                        //
// Right output on DIR                                       //
//                                                           // 
///////////////////////////////////////////////////////////////
#include <H61AEE_S01.h>

//Global Variables
Vehicle car;

//Main Code
void setup()
{
  Serial.begin(9600); //Configure the serial port to communicate with the PC
  
  pinMode(4, OUTPUT); //Configure LED pins
  pinMode(13, OUTPUT);

  car.setupVehicle();
}

void loop()
{
  Serial.println("Start Test Program");
  delay(3000);  // 3000ms delay before start
  car.setSpeed(LEFT, 50);
  Serial.println("Motors 1 and 3 forwards 50%");
  delay(3000);
  car.setDirection(LEFT,backwards);
  Serial.println("Motors 1 and 3 backwards 50%");
  delay(3000);
  car.setSpeed(LEFT,0);
  Serial.println("Motors 1 and 3 stop");

  car.setSpeed(RIGHT, 50);
  Serial.println("Motors 2 and 4 forwards 50%");
  delay(3000);
  car.setDirection(RIGHT,backwards);
  Serial.println("Motors 2 and 4 backwards 50%");
  delay(3000);
  car.setSpeed(RIGHT,0);
  Serial.println("Motors 2 and 4 stop");
  
  Serial.print("Left Enc = ");  //Print the encoder values from the left and right motors
  Serial.print(car.readEncoder(LEFT));
  Serial.print(", Right Enc = ");
  Serial.println(car.readEncoder(RIGHT));

  while(1); //Wait forever doing nothing
}
