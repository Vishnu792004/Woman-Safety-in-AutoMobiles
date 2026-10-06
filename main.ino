#include "AlertSystem.h"

LiquidCrystal_I2C lcd(0x27, 16, 2);

HardwareSerial gsm(1);//UART1 
HardwareSerial gps(2);//UART2

#define gps_rx 16
#define gps_tx 17
#define gsm_rx 26
#define gsm_tx 27

char *gpsRefString = "$GPGGA";
String gpsRespString = "";
String latitude = "No Range ";
String longitude = "No Range ";
int gpsRespCharCnt = 0;
bool gps_status = false;
int isGsmCmdReceived = 0;
const int buttonPin = 25;
bool btnState = HIGH;
void setup()
{
  // Initialize button and buzzer pins 
  pinMode(buttonPin,INPUT_PULLUP);   
  pinMode(BUZZER_PIN,OUTPUT);   
  digitalWrite(BUZZER_PIN,LOW);   //Disable the buzzer initially

  //Step 2:
  lcd.init();    //Initialize LCD using inbuilt library function from LiquidCrystal_I2C
  lcd.backlight();   //Enable the backlight of LCD

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("ESP32");
  lcd.setCursor(0,1);
  lcd.print("Initializing...");
  delay(2000);

  //Step 3:
  //Begin serial communication with appropriate baudrate
  Serial.begin(9600);  
  delay(500);
  Serial.println();
  Serial.println("==============================");
  Serial.println("ESP32 ALERT SYSTEM");
  Serial.println("==============================");

  //Step 4:
  //GPS and GSM UART
 gps.begin(9600, SERIAL_8N1, gps_rx, gps_tx);
 gsm.begin(9600, SERIAL_8N1, gsm_rx, gsm_tx);
 delay(3000);

 //Flush Boot Garbage
 while(gsm.available()){
  gsm.read();
 }
 while(gps.available()){
  gps.read();
 }

  // Initialize GSM module
  gsm_init();  
  lcd.clear();
  lcd.print("GSM CHECKING");
  Serial.println("Initializing GSM...");

  lcd.clear();
  lcd.print("Searching GPS");
  Serial.println("Searching GPS...");
  gpsEvent();
  delay(1000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("GPS is Ready");
  lcd.setCursor(0, 1);
  lcd.print("GPS Range Found");
  Serial.println("GPS is Ready");
  Serial.println("GPS Range Found");
  delay(2000);
  lcd.clear();
  lcd.print("System Ready");
  isGsmCmdReceived = 0;
}
  void loop()
{
    // Keep Updating a GPS 
    gpsEvent();
    check_gsm_sms();
    btnState = digitalRead(buttonPin);
  if (btnState == LOW)
  {
    delay(50);  // Debounce

    if (digitalRead(buttonPin) == LOW)
    {
        Serial.println("BUTTON PRESSED");
        Serial.println("EMERGENCY ALERT ACTIVATED");
        tracking(1);
    }
  }
}