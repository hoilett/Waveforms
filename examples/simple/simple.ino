#include "Waveforms.h"

int wave0 = 0;
int wave1 = 1;

int i = 0;
int j = 1;

int sample = 5;

unsigned long timer = 0;
unsigned long lastTime = 0;

void setup() {
  Serial.begin(115200);
  analogWriteResolution(12);
}

void loop() {
  analogWrite(DAC1, waveformsTable[wave0][i]);
  //analogWrite(DAC0, waveformsTable[wave0][i]);
  //analogWrite(DAC1, waveformsTable[wave1][i]);

//  if ((micros() - lastTime) >= sample*100)
//  {
//    lastTime = micros();
//    analogWrite(DAC1, waveformsTable[wave1][j]);
//    j++;
//  }

  i++;
  
  if(i == maxSamplesNum) i = 0;
  if(j == maxSamplesNum) j = 0;

  delayMicroseconds(sample);
}
