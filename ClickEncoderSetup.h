/************************************************************
/************************************************************
* 
* You can setup your Encoders here, define the number of 
* Encoders and add functionality for other Encoders
* TIP: Use place curso in front of block you want to edit
* and use "replace and find" for faster editing
* 
************************************************************
************************************************************/


#define MAXENCODER  3                                            // <-- Number of used encoders

volatile long   encVal[MAXENCODER]    = {0, 0, 0,},   // <-- Add ",0" if adding another encoder
                oldEnc[MAXENCODER]    = {0, 0, 0,};   // <-- Add ",0" if adding another encoder
                
volatile int8_t ISRab[MAXENCODER]     = {0, 0, 0,};   // <-- Add ",0" if adding another encoder

/************************************************************/

// 1/1 resolution
//int8_t stepTab[16] = {0,-1,1,0,1,0,0,-1,-1,0,0,1,0,1,-1,0};

// 1/2 resolution
//int8_t stepTab[16] = {0, 0,0,0,1,0,0,-1, 0,0,0,1,0,0,-1,0};

// 1/4 resolution
int8_t stepTab[16] = {0,0,0,0,0,0,0,-1,0,0,0,0,0,1,0,0}; 


/*************************************************************
* Rotary Encoder Buttons
*************************************************************/

  // Encoder0 Button 
  int enc0ButStat;       // current button status (button pushed or not)
  int lastEnc0ButStat;   // last button status 
  int enc0ButCount;      // counts button presses
  int enc0ButTog;        // toggles on/off button switch

  // Encoder1 Button 
  int enc1ButStat;       
  int lastEnc1ButStat;  
  int enc1ButCount;      
  int enc1ButTog;

  // Encoder2 Button 
  int enc2ButStat;       
  int lastEnc2ButStat;  
  int enc2ButCount;      
  int enc2ButTog;

  /*
  // Encoder3 Button 
  int enc3ButStat;       
  int lastEnc3ButStat;  
  int enc3ButCount;      
  int enc3ButTog;
  */

                                                        
/*************************************************************
* Encoder rotary interrupt randler routine (add encoders here)
*************************************************************/

void encHandler() {
  
  // Encoder 0
  ISRab [ 0] <<= 2;
  ISRab [ 0] &= B00001100;
  ISRab [ 0] |= (digitalRead(pinEnc0A) << 1) | digitalRead(pinEnc0B);
  encVal[ 0] += stepTab[ISRab[0]];  
  
  // Button 0
  enc0ButStat = (digitalRead(pinEnc0But));
  if (enc0ButStat != lastEnc0ButStat) {
    if (enc0ButStat == LOW) {
      enc0ButCount++;
      enc0ButTog++; }}    
  lastEnc0ButStat = enc0ButStat;    
  if (enc0ButTog > 1) {
    enc0ButTog = 0;}
    
/********************************/

  // Encoder 1
  ISRab [ 1] <<= 2;
  ISRab [ 1] &= B00001100;
  ISRab [ 1] |= (digitalRead(pinEnc1A) << 1) | digitalRead(pinEnc1B);
  encVal[ 1] += stepTab[ISRab[1]];

  // Button 1
  enc1ButStat = (digitalRead(pinEnc1But));
  if (enc1ButStat != lastEnc1ButStat) {
    if (enc1ButStat == LOW) {
      enc1ButCount++;
      enc1ButTog++; }}    
  lastEnc1ButStat = enc1ButStat;    
  if (enc1ButTog > 1) {
    enc1ButTog = 0;}

/********************************/

  // Encoder 2
  ISRab [ 2] <<= 2;
  ISRab [ 2] &= B00001100;
  ISRab [ 2] |= (digitalRead(pinEnc2A) << 1) | digitalRead(pinEnc2B);
  encVal[ 2] += stepTab[ISRab[2]];

  // Button 2
  enc2ButStat = (digitalRead(pinEnc2But));
  if (enc2ButStat != lastEnc2ButStat) {
    if (enc2ButStat == LOW) {
      enc2ButCount++;
      enc2ButTog++; }}    
  lastEnc2ButStat = enc2ButStat;    
  if (enc2ButTog > 2) {
    enc2ButTog = 0;}

/********************************/

  /*
  // Encoder 3
  ISRab [ 3] <<= 2;
  ISRab [ 3] &= B00001100;
  ISRab [ 3] |= (digitalRead(pinEnc3A) << 1) | digitalRead(pinEnc3B);
  encVal[ 3] += stepTab[ISRab[3]];

  // Button 3
  enc3ButStat = (digitalRead(pinEnc3But));
  if (enc3ButStat != lastEnc3ButStat) {
    if (enc3ButStat == LOW) {
      enc3ButCount++;
      enc3ButTog++; }}    
  lastEnc3ButStat = enc3ButStat;    
  if (enc3ButTog > 3) {
    enc3ButTog = 0;}

/********************************/

 
}


/***************************************************************************
* Sets encoder pin as pullup input and sets interrupt timer (add pins here) 
****************************************************************************/

void setupEncoder() {

   // Encoder 0
   pinMode(pinEnc0A, INPUT_PULLUP);   // Enc0A  
   pinMode(pinEnc0B, INPUT_PULLUP);   // Enc0B 
   pinMode(pinEnc0But, INPUT_PULLUP);  
       
   // Encoder 1
   pinMode(pinEnc1A, INPUT_PULLUP);   // Enc1A    
   pinMode(pinEnc1B, INPUT_PULLUP);   // Enc1B   
   pinMode(pinEnc1But, INPUT_PULLUP);
       
   // Encoder 2
   pinMode(pinEnc2A, INPUT_PULLUP);   // Enc2A    
   pinMode(pinEnc2B, INPUT_PULLUP);   // Enc2B  
   pinMode(pinEnc2But, INPUT_PULLUP);  

   /*
   // Encoder 3
   pinMode(pinEnc3A, INPUT_PULLUP);   // Enc3A     
   pinMode(pinEnc3B, INPUT_PULLUP);   // Enc3B  
   pinMode(pinEnc3But, INPUT_PULLUP); 
   */

   Timer1.attachInterrupt(encHandler);
   Timer1.start(20);                  // <-- Time the interrupt is called (Calls every ...µs)
}






