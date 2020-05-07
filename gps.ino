#include <TinyGPS++.h> // library for GPS module
#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>
TinyGPSPlus gps;  // The TinyGPS++ object
SoftwareSerial ss(13, 15); // The serial connection to the GPS device // d7-- rx  ( tx of gps module )d8----tx ( rx of gps module )
float latitude , longitude;
int year , month , date, hour , minute , second;
String  gps_str , lat_str , lng_str;




void setup()
{
  Serial.begin(115200);
  ss.begin(9600);
  Serial.println();

}
void loop()
{
  while (ss.available() > 0) //while data is available
    if (gps.encode(ss.read())) //read gps data
    {
      if (gps.location.isValid()) //check whether gps location is valid
      {
        latitude = gps.location.lat();
       // Serial.println("latitude");
        //Serial.println(latitude);
        lat_str = String(latitude , 6); // latitude location is stored in a string
        //Serial.println("latitude string");
        //Serial.println(lat_str);
        longitude = gps.location.lng();
       // Serial.println("longitude");
        //Serial.println(longitude);
        lng_str = String(longitude , 6); //longitude location is stored in a string
       // Serial.println("longitude string");
        //Serial.println(lng_str);
        
        
        gps_str=lng_str+"*"+lat_str;
        Serial.println("Lon,Lat");
        Serial.println(gps_str);
      }

