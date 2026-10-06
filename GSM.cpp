#include <Arduino.h>  
#include "AlertSystem.h"

void gsm_init() {
  //Step 5: GSM module initialization logic 
  Serial.println("GSM INITIALIZATION");
  boolean at_flag = 1;
  while (at_flag) {
    gsm.println("AT");
    delay(1000);
    if (gsm.find("OK")) {
    lcd.clear();
    lcd.print("GSM Connected...");
    Serial.println("GSM Connected...");
    at_flag = 0;
    }
    else{
    Serial.print("GSM Not Connect..");
    lcd.clear();
    lcd.print("GSM Not Connect..");
    delay(1000);
  }
  }
  //Set text mode for SMS
  gsm.println("AT+CMGF=1");
  delay(1000);
  Serial.println("SMS TEXT MODE SET");
  gsm.println("AT+CNMI=2,2,0,0,0");
  delay(500);
Serial.println("GSM Initialization Complete");
}
void init_sms(int mob_cnt)
 {
  gsm.println("AT+CMGF=1");
  delay(500);
  gsm.print("AT+CMGS=\"+917012945554\"\r");
  delay(2000);
}

void send_sms() {
  // Logic to finalize SMS transmission
  gsm.print("EMERGENCY ALERT!\nLocation\nLat: ");
  gsm.print(latitude);
  gsm.print("\nLong: ");
  gsm.print(longitude);
  gsm.print("\nGoogle Maps: https://maps.google.com/?q=");
  gsm.print(latitude);
  gsm.print(",");
  gsm.print(longitude);

  delay(500);
  gsm.write(26); // Send SMS = Ctrl+Z (ASCII code 26)
  Serial.println("SMS Sending...");
  delay(5000);
  Serial.println("SMS SENT");
}
void check_gsm_sms() {
  //Check for incoming GSM Command
  while(gsm.available())
  {
  String inData = gsm.readString();
  if(inData.indexOf("STOP") >= 0 || inData.indexOf("stop") >= 0){
  digitalWrite(BUZZER_PIN, LOW); // Silence the buzzer
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("ALARM STOP");
  lcd.setCursor(0,1);
  lcd.print("WE GET RESPONSE");
  isGsmCmdReceived = 1;
  Serial.println("STOP COMMAND RECEIVED"); 
  Serial.println("BUZZER OFF");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("SYSTEM READY");
  lcd.setCursor(0, 1);
  lcd.print("PRESS BUTTON");
  }
}
}