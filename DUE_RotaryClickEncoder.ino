/************************************************************
* Example scetch for rotary click encoders for the 
* Arduinio DUE. If you want to add more encoders make sure
* to edit "ClickEncoderSetup.h" accordingly.
* ***
* Oliver Hannemann
* April 2016
************************************************************/

#include <DueTimer.h>
#include "ClickEncoderSetup.h"   //  get encoder value with "encVal[ #]" (# = Encoder number)
     
                                 //  button state: "enc#ButStat"  /  button count: "enc#ButCount" / toggle IO: "enc#ButTog"
// Encoder 0
#define pinEnc0A   3  // Encoder0 A Pin 
#define pinEnc0B   4  // Encoder0 B Pin
#define pinEnc0But 5  // Encoder0 button
 
// Encoder 1
#define pinEnc1A   6  // Encoder1 A Pin 
#define pinEnc1B   7  // Encoder1 B Pin
#define pinEnc1But 8  // Encoder1 button

// Encoder 2
#define pinEnc2A   9   // Encoder2 A Pin 
#define pinEnc2B   10  // Encoder2 B Pin
#define pinEnc2But 11  // Encoder2 button

/*
// Encoder 3
#define pinEnc3A   3  // Encoder3 A Pin 
#define pinEnc3B   4  // Encoder3 B Pin
#define pinEnc3But 5  // Encoder3 button
*/

void setup() {
   setupEncoder();  

   Serial.begin(115200);
   Serial.println( "safety delay before start");
   delay(1000);  // safety delay before start
   Serial.println();
}


void loop() {
  
  Serial.print(" | R0: ");
  Serial.print(encVal[ 0]);
  Serial.print(" | B0: ");
  Serial.print(enc0ButCount);
  Serial.print("  ||  R1: ");
  Serial.print(encVal[ 1]);
  Serial.print(" | B1: ");
  Serial.print(enc1ButCount);
  Serial.print("  ||  R2: ");
  Serial.print(encVal[ 2]);
  Serial.print(" | B2: ");
  Serial.println(enc2ButCount);
  
}
