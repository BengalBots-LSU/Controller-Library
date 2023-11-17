#include "ControllerLibrary.h"

ControllerLibrary::ControllerLibrary(Controler_Pinout pinnout) {
  pinout = pinnout;
}

void ControllerLibrary::init() {
  pinMode(pinout.CH1, INPUT);
  pinMode(pinout.CH2, INPUT);
  pinMode(pinout.CH3, INPUT);
  pinMode(pinout.CH4, INPUT);
  pinMode(pinout.CH5, INPUT);
  pinMode(pinout.CH6, INPUT);
}

Controler ControllerLibrary::getControler() {
  Controler controler_struct;

  unsigned long time1 = micros();  // Local variable for time1
  controler_struct.SWA = pulseIn(pinout.CH6, HIGH, 32768) > 1000;
  controler_struct.SWB = pulseIn(pinout.CH5, HIGH, 32768) > 1000;
  controler_struct.left_stick_vert = pulseIn(pinout.CH2, HIGH, 32768) - 969;
  controler_struct.left_stick_hor = pulseIn(pinout.CH4, HIGH, 32768) - 1460;
  controler_struct.right_stick_hor = pulseIn(pinout.CH1, HIGH, 32768) - 1460;
  controler_struct.right_stick_vert = pulseIn(pinout.CH3, HIGH, 32768) - 1460;

  unsigned long time2 = micros();  // Local variable for time2

  controler_struct.time_to_compute = time2 - time1;

  return controler_struct;
}

void ControllerLibrary::printControler(Controler controler_struct) {
  Serial.print("left_stick_hor:");
  Serial.print(controler_struct.left_stick_hor);
  Serial.print(",");
  Serial.print("Throttle:");
  Serial.print(controler_struct.left_stick_vert);
  Serial.print(",");
  Serial.print("right_stick_hor:");
  Serial.print(controler_struct.right_stick_hor);
  Serial.print(",");
  Serial.print("SWA:");
  Serial.print(controler_struct.SWA * 5000);
  Serial.print(",");
  Serial.print("SWB:");
  Serial.print(controler_struct.SWB * 5000);
  Serial.print(",");
  Serial.print("right_stick_vert:");
  Serial.print(controler_struct.right_stick_vert);
  Serial.print(",");
  Serial.print("Timeing:");
  Serial.print(controler_struct.time_to_compute >> 4);
  Serial.print("\n");
}
