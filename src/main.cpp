#include <Arduino.h>
#include <esp_sleep.h>

#include <RTC/rtc.h>



const int INT_PIN=14;

const int MININTERVAL=1;
const int HOURINTERVAL=0;
const int DAYINTERVAL=0;

int loopnumber=0;

void wakeuproutine(){
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);  
  delay(1000);


}

void setup()
{
  Wire.begin();
  Serial.begin(115200);

  rtcConnect();
  attachInterrupt(digitalPinToInterrupt(INT_PIN), wakeuproutine, LOW); // attach interrupt to pin 14

}


void loop()
{
  loopnumber+=MININTERVAL;

  setAlarmInterval(MININTERVAL,HOURINTERVAL,DAYINTERVAL);
  wakeuproutine();
  esp_sleep_enable_ext0_wakeup(GPIO_NUM_14, LOW); // enable wakeup from deep sleep using interrupt pin
  // esp_sleep_pd_config(ESP_PD_DOMAIN_RTC_PERIPH, ESP_PD_OPTION_OFF); // turn off RF calibration during deep sleep
  esp_deep_sleep_start(); 
  
}

