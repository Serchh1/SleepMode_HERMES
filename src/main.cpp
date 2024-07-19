#include <Arduino.h>
#include <sleepMode.h>

sleepHermes::sleepHermes(int pinButton)
{
  m_pinButton = pinButton;
  pinMode(pinButton, INPUT);
}


void sleepHermes::begin() 
{
  esp_deep_sleep_enable_gpio_wakeup(1ULL << m_pinButton, ESP_GPIO_WAKEUP_GPIO_HIGH);
}

void sleepHermes::enabled() 
{
  int buttonState = digitalRead(m_pinButton);

  if (buttonState == HIGH) 
  {
    if (buttonPressStartTime == 0) 
    {
      buttonPressStartTime = millis();
    } 
    else if (millis() - buttonPressStartTime >= pressDuration) 
    {
      Serial.println("Going to sleep now");
      delay(1000);
      esp_sleep_disable_wakeup_source(ESP_SLEEP_WAKEUP_GPIO);
      delay(500);
      esp_sleep_enable_gpio_wakeup();
      esp_deep_sleep_start();
    }
  } 
  else 
  {
    buttonPressStartTime = 0;
  }
}
