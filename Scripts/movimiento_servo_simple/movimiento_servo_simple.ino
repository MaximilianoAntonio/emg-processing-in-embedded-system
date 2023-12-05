#include <Servo.h>
float sensor;
unsigned long tiempoActualTemp1, tiempoAnteriorTemp1 = 0;
unsigned long tiempoActualTemp2, tiempoAnteriorTemp2 = 0;
int processedValue;
float s_lim=370;
float i_lim=220;

Servo servoMotor;
 
void setup() {
  Serial.begin(115200);
  servoMotor.attach(3);
}

void loop() {

  tiempoActualTemp1 = millis(); 
  tiempoActualTemp2= millis(); 
   
  if (tiempoActualTemp1 - tiempoAnteriorTemp1 >= 2) { //Tiempo en milisegundos;
    tarea1();
    tiempoAnteriorTemp1 = tiempoActualTemp1; 
  }  
  if (tiempoActualTemp2 - tiempoAnteriorTemp2 >= 1000) { //Tiempo en milisegundos;
    tarea2();
    tiempoAnteriorTemp2 = tiempoActualTemp2; 
  } 
}

void tarea1() { // Envía datos a Python
  sensor = analogRead(A0);
  Serial.println(sensor);


  if (sensor > s_lim ||  i_lim > sensor){
    processedValue = 1;
  }
   else {  //if (sensor > 265 ||  335 > sensor)
    processedValue = 0;
  }
}

void tarea2() {

    if (processedValue == 0){
      servoMotor.write(50);
    }
    else{
      servoMotor.write(0);
    }
    
}