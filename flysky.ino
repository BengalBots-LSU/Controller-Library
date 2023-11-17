
struct Controler {
  unsigned long time_to_compute;
  signed long right_stick_hor;
  signed long right_stick_vert;
  signed long  left_stick_vert;
  signed long  left_stick_hor;
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


signed long time1;
signed long time2;

void initControler (Controler_Pinout pinnout){

  pinMode(pinnout.CH1, INPUT);
  pinMode(pinnout.CH2, INPUT);
  pinMode(pinnout.CH3, INPUT);
  pinMode(pinnout.CH4, INPUT);
  pinMode(pinnout.CH5, INPUT);
  pinMode(pinnout.CH6, INPUT);


}

Controler controler_struct_global;


Controler getControler(Controler_Pinout pinnout){
Controler controler_struct;
  time1 = micros();
  controler_struct.SWA = pulseIn(pinnout.CH6, HIGH,32768 ) > 1000;
  controler_struct.SWB = pulseIn(pinnout.CH5, HIGH,32768 ) > 1000;
  controler_struct.left_stick_vert = pulseIn(pinnout.CH2, HIGH,32768 ) -  969;
  controler_struct.left_stick_hor =  pulseIn(pinnout.CH4, HIGH,32768 ) -  1460;
  controler_struct.right_stick_hor = pulseIn(pinnout.CH1, HIGH,32768 ) - 1460;
  controler_struct.right_stick_vert = pulseIn(pinnout.CH3, HIGH,32768 ) - 1460;
  time2 = micros();


  controler_struct.time_to_compute = time2 -time1;

  return controler_struct;

}

void printControler(Controler controler_struct){
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
  Serial.print( controler_struct.SWA * 5000);
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


 Controler_Pinout pin_out {
    .CH1 = 13,
    .CH2 = 12,
    .CH3 = 11,
    .CH4 = 10,
    .CH5 = 9,
    .CH6 = 8,
  };


/*

Useage

void setup() {
  Serial.begin(921600);
  initControler(pin_out);
}

void loop() {
  controler_struct_global = getControler(pin_out);
  printControler(controler_struct_global);
 
}

*/