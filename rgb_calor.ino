int temp;
int rojo=6;
int verde=3;
int azul=5;

void setup()
{
  Serial.begin(9600);
  pinMode(rojo, OUTPUT);
  pinMode(azul, OUTPUT);
  pinMode(verde, OUTPUT);
}

void loop()
{
  temp=analogRead(0);
  Serial.println(temp);
  if(temp<120)
  {
    digitalWrite(azul, HIGH);
    digitalWrite(verde, LOW);
    digitalWrite(rojo, LOW);
  }
  else if((temp>120) and (temp<190))
  {
    digitalWrite(azul, LOW);
    digitalWrite(verde, HIGH);
    digitalWrite(rojo, LOW);
  }
  else
  {
    digitalWrite(azul, LOW);
    digitalWrite(verde, LOW);
    digitalWrite(rojo, HIGH);
  }
}