#include <Servo.h>
float sensor;
unsigned long tiempoActualTemp1, tiempoAnteriorTemp1 = 0;
unsigned long tiempoActualTemp2, tiempoAnteriorTemp2 = 0;

Servo myservo;
 
void setup() {
  Serial.begin(115200);
  myservo.attach(3);
}

void loop() {

  tiempoActualTemp1 = millis(); 
  tiempoActualTemp2= millis(); 
   
  if (tiempoActualTemp1 - tiempoAnteriorTemp1 >= 2) { //Tiempo en milisegundos;
      sensor = analogRead(A0);
      Serial.println(sensor);
    tiempoAnteriorTemp1 = tiempoActualTemp1; 
  }  
  if (tiempoActualTemp2 - tiempoAnteriorTemp2 >= 100) { //Tiempo en milisegundos;
    if (Serial.available() > 0) {
        // Leer los datos entrantes
        String dataString = Serial.readString();
        int data = dataString.toInt();
        if (data == 0) {
          myservo.write(55);
        }
        else if (data == 1) {
          myservo.write(5);
        }
        else{
          myservo.write(5);
        }
      }
        tiempoAnteriorTemp2 = tiempoActualTemp2; 
      } 
}


