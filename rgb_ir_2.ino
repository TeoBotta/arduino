//#include <IRremoteInterrupts.h>

#include <IRremote.h>

//Pines del RGB
int rojo=2;
int verde=4;
int azul=3;

//Receptor IR
const int RECV_PIN=11;


IRrecv irrecv(RECV_PIN);

decode_results results;

// the setup routine runs once when you press reset:
void setup()
  {
  // initialize the digital pin as an output.
  Serial.begin(9600);
  pinMode(rojo, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(azul, OUTPUT);
  irrecv.enableIRIn();
  irrecv.blink13(true);
  }

// the loop routine runs over and over again forever:
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
    //0, apaga el rgb
    if (results.value == 16738455)
    {
      digitalWrite(rojo, LOW);
      digitalWrite(verde, LOW);
      digitalWrite(azul, LOW);
    }
    //1, activa rojo
    if (results.value == 16724175)
    {
      digitalWrite(rojo, HIGH);
      digitalWrite(verde, LOW);
      digitalWrite(azul, LOW);
    }
    //2, activa verde
    if (results.value == 16718055)
    {
      digitalWrite(rojo, LOW);
      digitalWrite(verde, HIGH);
      digitalWrite(azul, LOW);
    }
    //3, activa azul
    if (results.value == 16743045)
    {
      digitalWrite(rojo, LOW);
      digitalWrite(verde, LOW);
      digitalWrite(azul, HIGH);
    } 
    // Flecha hacia arriba, cambia al color siguiente
    if (results.value == 16761405)
    {
      if(digitalRead(rojo) == HIGH)
      {
        digitalWrite(rojo, LOW);
        digitalWrite(verde, HIGH);
        digitalWrite(azul, LOW);
      }else if(digitalRead(verde) == HIGH)
      {
        digitalWrite(rojo, LOW);
        digitalWrite(verde, LOW);
        digitalWrite(azul, HIGH);
      }else if(digitalRead(azul) == HIGH)
      {
        digitalWrite(rojo, HIGH);
        digitalWrite(verde, LOW);
        digitalWrite(azul, LOW);
      }      
    } 
    //Flecha hacia abajo, cambia al color anterior
    if (results.value == 16712445)
    {
      if(digitalRead(rojo) == HIGH)
      {
        digitalWrite(rojo, LOW);
        digitalWrite(verde, LOW);
        digitalWrite(azul, HIGH); 
      }else if(digitalRead(verde) == HIGH)
      {
        digitalWrite(rojo, HIGH);
        digitalWrite(verde, LOW);
        digitalWrite(azul, LOW);
      }else if(digitalRead(azul) == HIGH)
      {
        digitalWrite(rojo, LOW);
        digitalWrite(verde, HIGH);
        digitalWrite(azul, LOW);
      }      
    }     
    irrecv.resume(); // Receive the next value
  }
}
