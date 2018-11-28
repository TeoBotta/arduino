/*
 *  Simple Servidor Web que muestra la informacion de A0
 */
 
 
/*
#include <ESP8266WiFi.h>

const char* ssid = "atrwifi";
const char* password = "08940216";

// Create an instance of the server
// specify the port to listen on as an argument
WiFiServer server(80);
*/

void setup() {
  Serial.begin(9600);
  analogReference(INTERNAL);
  //delay(10);
/*
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  
  // Start the server
  server.begin();
  Serial.println("Server started");

  // Print the IP address
  Serial.println(WiFi.localIP());
*/
}


void loop() {
/*  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
  
  // Wait until the client sends some data
  Serial.println("new client");
  while(!client.available()){
    delay(1);
  }
  
  // Read the first line of the request
  String req = client.readStringUntil('\r');
  Serial.println(req);
  client.flush();
  //
  */
  float Irms=get_corriente(); //Corriente eficaz (A)
  float P=Irms*220.0; // P=IV (Watts)
  Serial.print("Corriente: ");
  Serial.println(Irms);
  Serial.print("Potencia: ");
  Serial.println(P);  
  delay(1000);
  /*
  // Prepare the response
  String s = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE HTML>\r\n<html><meta http-equiv='refresh' content='1' />\r\nAmperes = ";
  s += Irms;
  s += "<br>Potencia = ";
  s += P;
  s += " watts";
  s += "</html>\n";

  // Send the response to the client
  client.print(s);
  delay(1);
  Serial.println("Client disonnected");
*/
}


float get_corriente()
{
  float voltajeSensor;
  float corriente=0;
  float Sumatoria=0;
  long tiempo=millis();
  int N=0;
  //while(millis()-tiempo<500)//Duración 0.5 segundos(Aprox. 30 ciclos de 60Hz)
  while(millis()-tiempo<60)//Duración 0.2 segundos(Aprox. 30 ciclos de 50Hz)
  { 
    voltajeSensor = analogRead(A0) * (1.1 / 1023.0);////voltaje del sensor
    corriente=voltajeSensor*100.0; //corriente=VoltajeSensor*(30A/1V)
    Sumatoria=Sumatoria+sq(corriente);//Sumatoria de Cuadrados
    N=N+1;
    delay(1);
  }
  Sumatoria=Sumatoria*2;//Para compensar los cuadrados de los semiciclos negativos.
  corriente=sqrt((Sumatoria)/N); //ecuación del RMS
  return(corriente);
}


