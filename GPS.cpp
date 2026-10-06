#include "AlertSystem.h"
#include <Arduino.h>

double convertNMEAtoDecimal(String value, String direction)
 {
   double nmeaValue = value.toDouble();//converts to floating point number
    // Get degrees 
    int degrees = (int)(nmeaValue / 100); 
    // Get minutes 
    double minutes = nmeaValue - (degrees * 100); 
    // Convert to decimal degrees 
    double decimalDegree = degrees + (minutes / 60.0); 
    // South and West are negative 
    if (direction == "S" || direction == "W")
    { 
    decimalDegree = -decimalDegree;
    }
    return decimalDegree;
  }
void gpsEvent()
{
  // GPS data handling logic
  while(gps.available() > 0){
    char ch =gps.read();
    gpsRespString += ch;

  //checking NMEA Sentence line termination
  if(ch =='\n'){
    if(gpsRespString.indexOf(gpsRefString)!=-1){ 
    get_gps();
    }
    else{
      gpsRespString=""; //Reset if not Contain $GPGGA
    }
  }
  }
  }
  void get_gps()
  {
    // Extract the latitude and longitude from the GPS Data
    int pointer = gpsRespString.indexOf(gpsRefString);
    if(pointer !=-1){
    //Splitting the GPS Data,Because it stored CSV format
    int c1=gpsRespString.indexOf(',',pointer);
    int c2=gpsRespString.indexOf(',',c1+1);
    int c3=gpsRespString.indexOf(',',c2+1);
    int c4=gpsRespString.indexOf(',',c3+1);
    int c5=gpsRespString.indexOf(',',c4+1);
    int c6=gpsRespString.indexOf(',',c5+1);

    String latval=gpsRespString.substring(c2+1,c3);
    String latDir =gpsRespString.substring(c3+1,c4);
    String longval=gpsRespString.substring(c4+1,c5);
    String longDir = gpsRespString.substring(c5+1,c6);

    if(latval.length() > 0 && longval.length() > 0){
      double latDecimal =convertNMEAtoDecimal(latval,latDir);
      double longDecimal =convertNMEAtoDecimal(longval,longDir);
      latitude = String(latDecimal, 6);
      longitude = String(longDecimal, 6);
      gps_status = true;    
    }
    else{
      latitude ="No Range ";
      longitude ="No Range ";
      gps_status = false;
    }
    }
    gpsRespString =""; //Reset Buffer
    }