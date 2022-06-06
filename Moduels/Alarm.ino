// Init the DS3231 using the hardware interface
#include <DS3231.h>
DS3231  rtc(4,3);

// Initialise the player, it defaults to using Serial.
#include <Arduino.h>
#include "DYPlayerArduino.h"
DY::Player player;

int volume = 20; // 30 = 100% Volume
int turnOffPin = 2;
String alarmMode = "";
String currentTime = "";
int soundLength = 2000;
int alarmFile = 5; //1=Hejdå Dennis 2=*** 3=Eye of the tiger, 4=långt skrik, 5=kort skrik
String alarmTime = "12:31:30";


void setup()
{
  
  // Initialize the rtc object
  rtc.begin();
  player.begin();
  player.setVolume(volume); 
  
  pinMode(turnOffPin, INPUT);
}


void loop()
{
  alarmMode = "run";
  
  // Starts the alarm
  currentTime = rtc.getTimeStr();
  if (currentTime == alarmTime){
    Alarm();
  }
  // Wait one second before repeating :)
  delay (1000);
}


void Alarm (){
  while (alarmMode == "run"){
    player.playSpecified(alarmFile);
    int delayCounter = 0;
    while (delayCounter < soundLength){
      delay(1);
      delayCounter++;
      if (digitalRead(turnOffPin)== HIGH){
        alarmMode = "stop";
        player.stop();
        break;
      }
      
    }
  }
  }
