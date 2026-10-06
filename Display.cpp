#include "AlertSystem.h"
#include <Arduino.h>
void tracking(int mob_cnt)
{
  
  //Trigger the buzzer
  digitalWrite(BUZZER_PIN,HIGH);      
  //send GPS details for Serialmonitor.
  Serial.println("================================");
  Serial.println("EMERGENCY ALERT!");
  Serial.println("================================");
  Serial.println("Location");
  Serial.print("Lat: ");
  Serial.println(latitude);
  Serial.print("Long: ");
  Serial.println(longitude);
  Serial.print("Google Maps: https://maps.google.com/?q=");
  Serial.print(latitude);
  Serial.print(",");
  Serial.println(longitude);
  Serial.println("================================");
  //Initialize SMS
  init_sms(mob_cnt);
  //Send SMS using SMS function
  send_sms();
  //Update LCD status after sending message
  lcd_status();
  }
  void lcd_status()
  {
    // LCD update to show system status after SMS
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("ALERT SENDING...");
    lcd.setCursor(0,1);
    lcd.print("SUCCESS SENT!!");
    }