#ifndef ControllerLibrary_h
#define ControllerLibrary_h

#include <Arduino.h>

struct Controler {
  unsigned long time_to_compute;
  signed long right_stick_hor;
  signed long right_stick_vert;
  signed long left_stick_vert;
  signed long left_stick_hor;
  bool SWA;
  bool SWB;
};

struct Controler_Pinout {
  int CH1;
  int CH2;
  int CH3;
  int CH4;
  int CH5;
  int CH6;
};

class ControllerLibrary {
public:
  ControllerLibrary(Controler_Pinout pinnout);
  void init();
  Controler getControler();
  void printControler(Controler controler_struct);

private:
  Controler_Pinout pinout;
};

#endif
