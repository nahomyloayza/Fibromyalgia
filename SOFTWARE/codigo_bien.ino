#include "HX711.h"

// HX711 circuit wiring
const int LOADCELL_DOUT_PIN = 2;
const int LOADCELL_SCK_PIN = 3;

HX711 scale;

void setup() {
  Serial.begin(57600);
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
}

void loop() {

  if (scale.is_ready()) {
    long reading = scale.read();
    Serial.print("HX711 reading: ");
    Serial.println(reading);
  } else {
    Serial.println("HX711 not found.");
  }

  delay(1000);
  
}
#include "HX711.h"
 
// Pin de datos 
const int DOUT=23;
const int CLK=19;
// int escala (valor de lectura)/(peso real); 
// Objeto HX711
HX711 algometro;

 
void setup() {
  // Iniciar comunicación 
  Serial.begin(115200);
  // Iniciar sensor
  algometro.begin(DOUT, CLK);
  Serial.print("Lectura actual del dispositivo:  ");
  Serial.println(algometro.read());
  // No tiene que haber nada sobre la barra
  Serial.println("Aún no ejerza presión sobre la barra");
  Serial.println("Destarando");
  // Aplicar la calibración
  algometro.set_scale(escala);
  // Iniciar la tara
  algometro.tare(20);
  Serial.println("Ya puede usarse");
}
 
void loop() {
  Serial.print("Medida: ");
  Serial.print((algometro.get_units(20),3));
  Serial.println(" kg");
}
