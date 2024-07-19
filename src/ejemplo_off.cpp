#include <Arduino.h>
#include <sleepMode.h>

#define PINOFF 1 // Cambia este valor al pin donde has conectado el botón

sleepHermes testHermes(PINOFF);

void setup() 
{
  Serial.begin(115200);
  testHermes.begin();
}

void loop() 
{
  testHermes.enabled();
}