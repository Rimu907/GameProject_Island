#include <LiquidCrystal.h> 
 #include "pitches.h" 
 #define outputA 6 
 #define outputB 7 
 int getvoltage = 15; 
 const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2; 
 LiquidCrystal lcd(rs, en, d4, d5, d6, d7); 
 int counter = 0;  
 int aState; 
 int aLastState; 
 int sensorvalue= analogRead(getvoltage); 
 float voltage = sensorvalue *(5.0/1023.0); 
 int melody[] = { 
  NOTE_F7, NOTE_A5, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4 
}; 
 
// note durations: 4 = quarter note, 8 = eighth note, etc.: 
int noteDurations[] = { 
  4, 8, 8, 4, 4, 4, 4, 4 
}; 
   
 void setup() {  
   pinMode (outputA,INPUT_PULLUP); 
   pinMode (outputB,INPUT_PULLUP); 
   lcd.begin(16,2); 
    // iterate over the notes of the melody: 
  for (int thisNote = 0; thisNote < 8; thisNote++) { 
 
    // to calculate the note duration, take one second divided by the note type. 
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc. 
    int noteDuration = 1000 / noteDurations[thisNote]; 
    tone(8, melody[thisNote], noteDuration); 
    // to distinguish the notes, set a minimum time between them. 
    // the note's duration + 30% seems to work well: 
    int pauseBetweenNotes = noteDuration * 1.30; 
    delay(pauseBetweenNotes); 
    // stop the tone playing: 
    noTone(8); 
   Serial.begin (9600); 
   // Reads the initial state of the outputA 
   aLastState = digitalRead(outputA);    
 }  
 } 
 void loop() {  
   aState = digitalRead(outputA); // Reads the "current" state of the outputA 
   // If the previous and the current state of the outputA are different, that means a Pulse has occured 
   if (aState != aLastState){      
     // If the outputB state is different to the outputA state, that means the encoder is rotating clockwise 
     if (digitalRead(outputB) != aState) {  
       counter ++; 
     } else { 
       counter --; 
     } 
lcd.setCursor(0,1); 
     lcd.print("positon :");                                            ; 
     lcd.println(counter); 
   }  
   aLastState = aState; // Updates the previous state of the outputA with the current state 
voltage = (float)analogRead(A1); 
voltage = voltage*(5.0/1023.0); 
  lcd.setCursor(0,0); 
  if (voltage < 1.49 & voltage > 1.35) 
 { 
  lcd.clear(); 
  lcd.setCursor(0,0); 
  lcd.print("go forward"); 
  int lastbutton = 1; 
  delay(300);  
 } 
  voltage = (float)analogRead(A2); 
voltage = voltage*(5.0/1023.0); 
  lcd.setCursor(0,0); 
  if (voltage < 3.2 & voltage > 2.85 ) 
 { 
  lcd.clear(); 
  lcd.setCursor(0,0); 
  lcd.print("go backward"); 
  int lastbutton = 2; 
  delay(300); 
 } 
  voltage = (float)analogRead(A3); 
voltage = voltage*(5.0/1023.0); 
  lcd.setCursor(0,0); 
  if (voltage < 1.30 & voltage > 1.20 ) 
 { 
  lcd.clear(); 
  lcd.setCursor(0,0); 
  lcd.print("go Left"); 
  int lastbutton = 2; 
  delay(300); 
 } 
  voltage = (float)analogRead(A4); 
voltage = voltage*(5.0/1023.0); 
  lcd.setCursor(0,0); 
  if (voltage < 1.7 & voltage > 1.5 ) 
 { 
  lcd.clear(); 
  lcd.setCursor(0,0); 
  lcd.print("go right"); 
  int lastbutton = 2; 
  delay(300); 
 } 
voltage = (float)analogRead(A5) 
voltage = voltage*(5.0/1023.0); 
  lcd.setCursor(0,0); 
  if (voltage < 2.1 & voltage > 2.0 ) 
 { 
  lcd.clear(); 
  lcd.setCursor(0,0); 
  lcd.print("Enter"); 
  int lastbutton = 2; 
  delay(300); 
 } 
voltage = (float)analogRead(A6); 
voltage = voltage*(5.0/1023.0); 
  lcd.setCursor(0,0); 
  if (voltage < 2.83 & voltage > 2.5 ) 
 { 
  lcd.clear(); 
  lcd.setCursor(0,0); 
  lcd.print("return"); 
  int lastbutton = 2; 
  delay(300); 
 } 
 }
