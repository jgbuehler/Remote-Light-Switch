#include <PestoLink-Receive.h>
#include <Alfredo_NoU3.h>

NoU_Servo flippy(2);

//int servoAngle;
bool on = false;
bool lastButtonState = false;


void setup() {
    PestoLink.begin("Overhead Light");
    Serial.begin(115200);
    
    NoU3.begin();

    //servoAngle = 0;
}

void loop() {

/*  if (on) {

     if (PestoLink.buttonHeld(0)) {
      servoAngle = 0;
      on = false;
     } 
     else {
      servoAngle = 90;
     }

  }
  else {
    if (PestoLink.buttonHeld(0)) {
      servoAngle = 90;
      on = true;
    }
    else {
      servoAngle = 0;
    }
  }

  flippy.write(servoAngle); */

  bool currentButtonState = PestoLink.buttonHeld(0);

    // Detect button press (transition from not pressed to pressed)
    if (currentButtonState && !lastButtonState) {
        on = !on;/////
        Serial.println("boo");
    }

    lastButtonState = currentButtonState;

    if (on) {
        flippy.write(135);
        Serial.println("hi");
    } else {
        flippy.write(45);
        Serial.println("yo");
    }
}
