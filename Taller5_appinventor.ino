// se incluye en github. arduinoIoT
#include<Servo.h>; // se usa la libreria de servo
# include <SoftwareSerial.h>; // se usa la libreria software serial para el bluetooth modulo HC05
SoftwareSerial Bluetooth (4,3); // se crea un objeto de la libreria pin 4 como RX, pin 3 como TX
Servo MotorServo; // se hace un objeto servo



void setup() {
  pinMode (13,OUTPUT); // se inicia el pin 13 como salida
  pinMode (5,OUTPUT); // se inicia el pin 5 como salida 
  MotorServo.attach(5); // se inidica el pin 5 como salida de control al servo
  Serial.begin(9600); // Se inicia el puerto a 9600 baudios
  digitalWrite(13,LOW); // el pin 13 sera la pinza,  0 cerrada, 1 abierta
  MotorServo.write(0); // se inicia en angulo 0 el servo
  Bluetooth.begin (9600); // se inicia el puerto serial bluetooth con 9600 baudios
  
  

}

void loop() {
  if (Bluetooth.available()>0){ // validamos si hay un dato en el puerto serial
    
      char Dato = Bluetooth.read(); // variable tipo char  de un byte para leer un dato del puerto serial 
      
      if (Dato== 'A') // se valida si es el dato A el escrito en el monitor serial.
    {
     MotorServo.write(100); // se es A se gira el servomotor 100 grados
    }
  
    if(Dato=='B') // se valida si es el dato B el escrito en el monitor serial.
    {
      digitalWrite(13,HIGH);// si es se abre la pinza
    }
    if(Dato =='C')
    {
      MotorServo.write(0);
    }
    if(Dato == 'D')
    {
      digitalWrite(13,LOW);
    }
  }
}
// se debe desconectar el arduino para alimentarlo con 5V fuente aparte.
// conectar primero el smartphone con el modulo HC05 por bluetooth.
// escanear el codigo QR de appInventor con cualquier lector de QR, para bajar la aplicacion e instalarla
// en la aplicacion de appInventor conectar el bluetooth desde el listado de dispositivos.

