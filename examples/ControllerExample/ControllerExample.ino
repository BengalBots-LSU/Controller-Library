#include <ControllerLibrary.h>

Controler_Pinout pin_out = {
  .CH1 = 13,
  .CH2 = 12,
  .CH3 = 11,
  .CH4 = 10,
  .CH5 = 9,
  .CH6 = 8,
};

ControllerLibrary controller(pin_out);

void setup() {
  Serial.begin(921600);
  controller.init();
}

void loop() {
  Controler controler_struct_global = controller.getControler();
  controller.printControler(controler_struct_global);
}
