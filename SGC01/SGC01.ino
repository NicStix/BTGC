#include <SoftwareSerial.h>

SoftwareSerial BT(10, 11); //TX, RX respetively
String readdata;

int Mopen = 3;
int Mclose = 4;
int LswitchOpen = 5;
int LswitchClosed = 6;

boolean flag1 = false;

void setup() {
 BT.begin(9600);
 Serial.begin(9600);
  pinMode(Mopen, OUTPUT); //motor Open
  pinMode(Mclose, OUTPUT); //motor Close
  pinMode(LswitchOpen, INPUT); // Gate open limit switch
  pinMode(LswitchClosed, INPUT); //Gate closed limit switch
  

}
/*-----------------------------------------------------------------------// 

 Original code is from a robot
 congtrolling four motors

 modify code to include gate open stop sensor and gate closed sensor.
 reduce motors from four signals to two.
 signal one, forward, signal two reverse

 

//-----------------------------------------------------------------------*/ 
void loop() {
  while (BT.available()){  //Check if there is an available byte to read
  delay(10); //Delay added to make thing stable
  char c = BT.read(); //Conduct a serial read
  readdata += c; //build the string- "open" and "close"
  } 
  if (readdata.length() > 0) {
    Serial.println(readdata);

/*
if you click the open button, send signal to the arduino
activates motor
hits the limit switch
limit switch sends signal to arduino
stop motor
or stop after (X) seconds
delay for 40 seconds
activates motor
gate closes
hits limit switch turns off motor
or stop after (X) Secnds (THis is if the switch breaks)
*/

  if((readdata == "open")&& (flag1 == false))
  {
    digitalWrite(3, HIGH);
    digitalWrite(4,LOW);
    Serial.println("Gate is Open");
    delay(100);
  }
/*
 * Hit the close button, send signal to the arduino
 * activates motor
 * hits the limit switch
 * limit switch sends signal to arduino
 * stop motor
 */
  else if(readdata == "close")
  {
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
    delay(100);
  }
/*
 * immediate stop to motor
 */
 else if (readdata == "stop")
 {
   digitalWrite (3, LOW);
   digitalWrite (4, LOW);
   delay (100);
 }

 /*
  * Hit open for maintenance button
  * signal sent to arduino
  * activates motor
  * hits the limit switch
  * limit switch sends signal to arduino
  * stop motor
  * gate remains open
  */
  if((readdata == "open")&& (flag1 == false))
  {
    digitalWrite(3, HIGH);
    digitalWrite(4,LOW);
    Serial.println("Gate Open and Hold");
    delay(100);
  }
  


readdata="";}} //Reset the variable
