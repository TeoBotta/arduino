#include <IRremoteInterrupts.h>

#include <IRremote.h>

#include <Servo.h>

Servo myservo;

//Receptor IR
const int RECV_PIN = 3;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();  //Activa el IR
  myservo.attach(6);
}

void loop()
{
  if (irrecv.decode(&results)) {
    if (results.decode_type == NEC) {
      Serial.print("NEC: ");
    } else if (results.decode_type == SONY) {
      Serial.print("SONY: ");
    } else if (results.decode_type == RC5) {
      Serial.print("RC5: ");
    } else if (results.decode_type == RC6) {
      Serial.print("RC6: ");
    } else if (results.decode_type == UNKNOWN) {
      Serial.print("UNKNOWN: ");
    }
    
    Serial.println(results.value);
    if (results.value == 16584943)
    {
      myservo.write(45);
    }
    if (results.value == 16601263)
    {
      myservo.write(135);
    }   
    irrecv.resume(); // Receive the next value
  }
}