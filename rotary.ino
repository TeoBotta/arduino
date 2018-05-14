#include <Servo.h> //Declaro librería para el servomotor

//Inicio declaración variables
Servo myservo; //Nombro la variable de tipo servo

int cambio = 84;
int counter = 0; 
int aState;
int aLastState;
//Fin declaración variables

void setup() {
  pinMode (8, INPUT); //Entrada del rotary ubicada en 8
  pinMode (9, INPUT); //Entrada del rotary ubicada en 9

  Serial.begin(9600);

  aLastState = digitalRead(8); //Doy un valor inicial a la posición del rotary

  myservo.attach(6); //Defino contacto con la señal del servo en 6
  myservo.write(84); //Doy valor incial al servo en 84
}

void loop() {
  aState = digitalRead(8); //Leo valor de cambio del rotary
  if (aState != aLastState){
    if (digitalRead(9) != aState){
        cambio ++;
        myservo.write(cambio);
        counter ++; //Aumento el contador de posición
      }else{
        cambio --;
        myservo.write(cambio);
        counter --; //Disminuyo el contador de posición
      }
      Serial.print("Position: "); //Muestro posición en pantalla
      Serial.println(counter);
    }
  aLastState - aState;
}
