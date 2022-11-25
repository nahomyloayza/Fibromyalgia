#include "HX711.h"
#include "BluetoothSerial.h"
// Pin de datos
const int DOUT=23;
const int CLK=18;


HX711 algometro;


#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif
BluetoothSerial SerialBT;
void setup() {
  Serial.begin(9600);
  SerialBT.begin("ESP32test"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
  algometro.begin(DOUT, CLK);
  Serial.print("Lectura del valor del ADC:  ");
  Serial.println(algometro.read());
  Serial.println("No ponga ningun  objeto sobre la balanza");
  Serial.println("Destarando...");
  Serial.println("...");
  algometro.set_scale(-7050); // Establecemos la escala
  algometro.tare(20);  //El peso actual es considerado Tara.
  Serial.println("Listo para pesar");
}
void loop() {

  SerialBT.print("Peso: ");
  SerialBT.print(9.81*0.454*algometro.get_units(10),3);
  SerialBT.println(" N");

  delay(500);
}