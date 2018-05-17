// Defino posiciones para el trigger y el echo del ultra
const int trigPin = 6;
const int echoPin = 4;
// Defino variables a usar
long duration;
int distance;
void setup() {
pinMode(trigPin, OUTPUT); // Seteo el trigger como salida
pinMode(echoPin, INPUT); // Seteo el echo como entrada
Serial.begin(9600);
}
void loop() {
// Limpio los datos del trigger
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Doy pulso al trigger
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Leo los valores que toma el echo
duration = pulseIn(echoPin, HIGH);
// Realizo calculo de distancia
distance= duration*0.034/2;
// Imprimo distancia en el serial
Serial.print("Distance: ");
Serial.print(distance);
Serial.println(" cm");
}
