#include <Servo.h> 
 
//1 is to set it to 180*
//2 is to set it to 0*
 
Servo myservo;  
 
int pos = 0;  
int incomingByte = 0;  

void setup() 
{ 
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
  Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
}

 
void loop(){ 
 
  if (Serial.available()) {
     // read the incoming byte:
     incomingByte = Serial.read();
     if (incomingByte == 49){
          // say what you got:
          Serial.print("I received: ");
          Serial.println(incomingByte, DEC);
          pos = 180;                        
          myservo.write(pos);              // tell servo to go to position in variable 'pos' 
          delay(5);                       // waits 15ms for the servo to reach the position 
    }
     else if(incomingByte == 50){
       pos = 0;
       myservo.write(pos);              // tell servo to go to position in variable 'pos' 
       delay(5);                       // waits 15ms for the servo to reach the position 
     }
}
         
//---------------------------------------------------------------

} 




