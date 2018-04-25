 /*  
 *  Controlling a RGB LED with a TV Remote
 *  
 *  Modified IRrecvDemo example from Ken Shirriff IRremote Library
 *  Ken Shirriff
 *  http://arcfn.com
 *  
 *  Modified by Eric Mutua,
 *  www.github.com/ertush
 *  
 */

#include <IRremote.h>

int RECV_PIN = 8; // IR Receiver - Arduino Pin Number 8

IRrecv irrecv(RECV_PIN);

decode_results results;

int greenLed = 5;
int redLed = 6;
int blueLed = 3;
 
void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  pinMode(greenLed, OUTPUT);
  pinMode(redLed, OUTPUT);       
  pinMode(blueLed, OUTPUT);  
}
 
void loop() {
  
  if (irrecv.decode(&results)) {   
    
    if (results.value == 0xFF02FD) { // Red Button
      setColor(0, 255, 0);  // Sets Red Color to the RGB LED
      delay(100);
      }
    if (results.value == 0xFF12ED) { // Green Button
       setColor(255, 0, 0);  // Green Color
      delay(100);
      }
    if (results.value == 0xFF0AF5) { // Yellow Button
      setColor(255, 255, 255);  // Yellow Color
      delay(100);
      }   
    if (results.value == 0xFF1AE5) { // Blue Button
      setColor(0, 0, 255);  // Blue Color
      delay(100);
      }
     if (results.value == 0xFFFFFFFF) { // Stop Button
      setColor(0, 0, 0);  // OFF
      delay(100);
      }
      
    irrecv.resume(); // Receive the next value
  }
  delay(100);
}
// Custom made function for activating the RGB LED 
void setColor(int green, int red, int blue)
{
  analogWrite(greenLed, green); // Sends PWM signal to the Red pin
  analogWrite(redLed, red);
  analogWrite(blueLed, blue);  
}
