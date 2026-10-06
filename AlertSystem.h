#ifndef ALERTSYSTEM_H
#define ALERTSYSTEM_H

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <HardwareSerial.h>

extern LiquidCrystal_I2C lcd;
extern HardwareSerial gps;
extern HardwareSerial gsm;

#define BUZZER_PIN 13
extern const int buttonPin;
extern char *gpsRefString;
extern String gpsRespString;
extern String latitude;
extern String longitude;

extern int gpsRespCharCnt;
extern bool gps_status;
extern int isGsmCmdReceived;
extern bool btnState;
// GSM functions
void gsm_init();
void init_sms(int mob_cnt);
void send_sms();
void check_gsm_sms();
// GPS functions
void get_gps();
void gpsEvent();
// Display functions
void lcd_status();
void tracking(int mob_cnt);
#endif