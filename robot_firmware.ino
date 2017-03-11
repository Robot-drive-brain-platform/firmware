//By: ASCAS (Angelo S. Casimiro)
//Instructables.com & ASCAS.tk

#include "DualVNH5019MotorShield.h"
DualVNH5019MotorShield md;
//#include "SoftwareSerial.h"

//SoftwareSerial Bluetooth(2,3);


//char dataIn='S';char determinant;char det;int vel = 200; //Bluetooth Stuff
/*int power = 4;*/
//int overdrive = 13;
//char incomingByte;

void setup() {
  Serial.begin(9600);
  md.init();


}

void loop() {if(Serial.available() > 0){
    char inChar = Serial.read();
    if (inChar == 'S') {
      md.setSpeeds(200, 200);
    } else {
      md.setSpeeds(-100, -200);
    }
 Serial.println(inChar); 
}
}

