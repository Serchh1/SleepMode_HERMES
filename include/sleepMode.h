#pragma once
#include <Arduino.h>

class sleepHermes
{
public:
    sleepHermes(int pinButton); // Pin de boton
    void begin();
    void enabled();

private:
    int m_pinButton;
    unsigned long pressDuration = 5000; // Tiempo de duración de la pulsación
    unsigned long buttonPressStartTime = 0; // Tiempo de inicio de la pulsación del botón
};
