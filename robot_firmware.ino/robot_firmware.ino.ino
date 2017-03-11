//By: ASCAS (Angelo S. Casimiro)
//Instructables.com & ASCAS.tk

#include "DualVNH5019MotorShield.h"
DualVNH5019MotorShield md;

#define LED_PIN       13 // user LED pin

//--------------------------------------------//

//#include <Servo.h>
//
//Servo myservo;  // create servo object to control a servo
//// twelve servo objects can be created on most boards
//
//int pos = 0;    // variable to store the servo position
//int state = 0;

//--------------------------------------------//

char dataIn = 'S'; char determinant; char det; int vel = 0; //Bluetooth Stuff
/*int power = 4;*/
int overdrive = 13;

void setup() {
  Serial.begin(9600); 
  md.init();
  /*pinMode(power , OUTPUT);*/ //toggle switch function
  pinMode(overdrive, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  //myservo.attach(13);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  det = check();

  while (det == 'F')   // F, move forward
  {
    md.setSpeeds(vel, vel);
    det = check();
  }

  while (det == 'B')   // B, move back
  {
    md.setSpeeds(-vel, -vel);
    det = check();
  }

  while (det == 'L')   // L, move wheels left
  {
    md.setSpeeds(vel / 4, vel);
    det = check();
  }

  while (det == 'R')   // R, move wheels right
  {
    md.setSpeeds(vel, vel / 4);
    det = check();
  }

  while (det == 'I')   // I, turn right forward
  {
    md.setSpeeds(vel, vel / 2);
    det = check();
  }

  while (det == 'J')   // J, turn right back
  {
    md.setSpeeds(-vel, -vel / 2);
    det = check();
  }

  while (det == 'G')   // G, turn left forward
  {
    md.setSpeeds(vel / 2, vel);
    det = check();
  }

  while (det == 'H')   // H, turn left back
  {
    md.setSpeeds(-vel / 2, -vel);
    det = check();
  }

  while (det == 'S')   // S, stop
  {
    md.setSpeeds(0, 0);
    det = check();
  }


  //---------------------Toggle switch code------------------//
  /* while (det == 'U')
    {digitalWrite(power, HIGH);det = check();}
    while (det == 'u')
    {digitalWrite(power, LOW);det = check();}*/
  //---------------------Mains Power------------------//
  while (det == 'W')
  {
    digitalWrite(overdrive, HIGH);
    det = check();
  }
  while (det == 'w')
  {
    digitalWrite(overdrive, LOW);
    det = check();
  }
  //---------------------LED Power------------------//
  while (det == 'X')
  {
    digitalWrite(LED_PIN, HIGH);
    det = check();
  }
  while (det == 'x')
  {
    digitalWrite(LED_PIN, LOW);
    det = check();
  }
  
  //---------------------Servo Power------------------//

//  while (det == 'U') {
//    state = 1;
//  }
//
//  if (state == 1)
//  {
//    for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
//      // in steps of 1 degree
//      myservo.write(pos);              // tell servo to go to position in variable 'pos'
//      delay(5);                       // waits 5ms for the servo to reach the position
//    }
//    for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
//      myservo.write(pos);              // tell servo to go to position in variable 'pos'
//      delay(5);                       // waits 5ms for the servo to reach the position
//    }
//  }
//
//  while (det == 'u') {
//    state = 0;
//  }
//
//  if (state == 0) {
//    myservo.write(0);
//  }
  
}


int check()
{ if (Serial.available() > 0) {
    dataIn = Serial.read();
    if (dataIn == 'F') {
      determinant = 'F';
    }
    else if (dataIn == 'B') {
      determinant = 'B';
    } else if (dataIn == 'L') {
      determinant = 'L';
    }
    else if (dataIn == 'R') {
      determinant = 'R';
    } else if (dataIn == 'I') {
      determinant = 'I';
    }
    else if (dataIn == 'J') {
      determinant = 'J';
    } else if (dataIn == 'G') {
      determinant = 'G';
    }
    else if (dataIn == 'H') {
      determinant = 'H';
    } else if (dataIn == 'S') {
      determinant = 'S';
    }
    else if (dataIn == '0') {
      vel = 400;
    } else if (dataIn == '1') {
      vel = 380;
    }
    else if (dataIn == '2') {
      vel = 340;
    } else if (dataIn == '3') {
      vel = 320;
    }
    else if (dataIn == '4') {
      vel = 280;
    } else if (dataIn == '5') {
      vel = 240;
    }
    else if (dataIn == '6') {
      vel = 200;
    } else if (dataIn == '7') {
      vel = 160;
    }
    else if (dataIn == '8') {
      vel = 120;
    } else if (dataIn == '9') {
      vel = 80;
    }
    else if (dataIn == 'q') {
      vel = 40;
    } else if (dataIn == 'U') {
      determinant = 'U';
    }
    else if (dataIn == 'u') {
      determinant = 'u';
    } else if (dataIn == 'W') {
      determinant = 'W';
    }
    else if (dataIn == 'w') {
      determinant = 'w';
    }
    else if (dataIn == 'X') {
      determinant = 'X';
    }
    else if (dataIn == 'x') {
      determinant = 'x';
    }
  } return determinant;
}
