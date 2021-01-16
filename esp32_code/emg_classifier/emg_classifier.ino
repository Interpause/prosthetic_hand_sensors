//#include "BluetoothSerial.h"

#define CH0 36
#define CH1 39
#define CH2 34
#define CH3 32
#define sampling 2000

unsigned short sampling_period_us;
//BluetoothSerial SerialBT;
String nameBT = "ESP32_emg";
char buf[25];

void setup() {
  adcAttachPin(CH0);
  adcAttachPin(CH1);
  adcAttachPin(CH2);
  adcAttachPin(CH3);
  Serial.begin(2000000);
  //SerialBT.begin(nameBT);
  sampling_period_us = round(1.0/sampling*1000000);
}

short raw[4];
unsigned short reads;
unsigned long microseconds;

//Sample rate: 200000Hz
void loop() {
  microseconds = micros();    //Overflows after around 70 minutes!
  raw[0] = analogRead(CH0);
  raw[1] = analogRead(CH1);
  raw[2] = analogRead(CH2);
  raw[3] = analogRead(CH3);
  sprintf(buf,"%d\t%d\t%d\t%d",raw[0],raw[1],raw[2],raw[3]);
  Serial.println(buf);
  //SerialBT.println(raw);
  while(micros() < (microseconds + sampling_period_us)){}
}



/* Tuning functions that matter
 * analogSetCycles(default 8); cycles per sample (affects accuracy) 1 to 255
 * analogSetSamples(default 1); number of sample in range (affects precision) int any
 * analogSetClockDiv(default 1); precision across time (increase div to reduce small blips aka noise) 1 to 255
 * ^(not recommended, getting rid of noise should be left to filter function, else just increase samples)
 * IMPT: SetSamples affects duration of clocktick, meaning even if clockDiv is 1, it takes longer
 * 
 * BTW maxing cycles + maxing samples + minimize clock div, while it sounds good in theory...
 * well, it probably causes more distortion than it fixes
 * defaults are probably good enough
 *  
 * adcStart(CH0);
 * resultadcEnd(CH0);
 * ^somehow more specific controls over when you want to sample
 */
