#include <SPI.h>
#include <mcp2515.h>

//-------LCD-----
#include "Waveshare_LCD1602_RGB.h"
Waveshare_LCD1602_RGB lcd(16,2);

//-------CUSTOM VALUE-----
const byte PulsesPerRevolution = 20;
#define WheelDiameter 0.065
#define SensorDiameter 0.025
#define WheelRadius 0.0325
#define WheelCircumference (2 * PI * WheelRadius)

float RPM;

//-------PULSE-----
const unsigned long ZeroTimeout = 100000;

volatile unsigned long LastTimeWeMeasured;
volatile unsigned long PeriodBetweenPulses = ZeroTimeout + 1000;
volatile unsigned long PeriodAverage = ZeroTimeout + 1000;
unsigned long FrequencyRaw;
unsigned long FrequencyReal;
unsigned int PulseCounter = 1;
unsigned long PeriodSum;

unsigned long LastTimeCycleMeasure = LastTimeWeMeasured;
unsigned long CurrentMicros = micros();
unsigned int AmountOfReadings = 1;
unsigned int ZeroDebouncingExtra;

//-------CAN-----
struct can_frame canMsg;
MCP2515 mcp2515(9);

void packFloat(byte *data, float value) {
    byte *valueBytes = (byte*)&value;  
    for (int i = 0; i < sizeof(float); i++) {
        data[i] = valueBytes[i];
        Serial.print(data[i]);
    }
}

void setup() {
  Serial.begin(115200);
 
  attachInterrupt(digitalPinToInterrupt(3), Pulse_Event, RISING);

  mcp2515.reset();
  mcp2515.setBitrate(CAN_500KBPS,MCP_16MHZ);
  mcp2515.setNormalMode();

  canMsg.can_id = 0x000;
  canMsg.can_dlc = 4;  // Changing to 8 bytes since we are now sending two float values
  for(int i = 0; i < 4; i++){
    canMsg.data[i] = 0;
  }  
}

float getRPM(){
  LastTimeCycleMeasure = LastTimeWeMeasured;
  CurrentMicros = micros();
  if (CurrentMicros < LastTimeCycleMeasure) {
    LastTimeCycleMeasure = CurrentMicros;
  }
  FrequencyRaw = 10000000000 / PeriodAverage;
  if (PeriodBetweenPulses > ZeroTimeout - ZeroDebouncingExtra || CurrentMicros - LastTimeCycleMeasure > ZeroTimeout - ZeroDebouncingExtra) {
    FrequencyRaw = 0;
    ZeroDebouncingExtra = 2000;
  } else {
    ZeroDebouncingExtra = 0;
  }

  RPM = ((float)FrequencyRaw / PulsesPerRevolution * 60) / 10000.0;
  RPM = RPM * (SensorDiameter / WheelDiameter);
 
  return RPM;
}

void loop() {  
  RPM = getRPM();
  RPM = RPM / 60.0;

  Serial.print(RPM, 2);  // Print RPM with 2 decimal places

  packFloat(canMsg.data, RPM);
  mcp2515.sendMessage(&canMsg);
  
  Serial.println();
  delay(100);
}

void Pulse_Event() {
  PeriodBetweenPulses = micros() - LastTimeWeMeasured;
  LastTimeWeMeasured = micros();
  if (PulseCounter >= AmountOfReadings)  {
    PeriodAverage = PeriodSum / AmountOfReadings;
    PulseCounter = 1;
    PeriodSum = PeriodBetweenPulses;

    int RemapedAmountOfReadings = map(PeriodBetweenPulses, 40000, 5000, 1, 10);
    RemapedAmountOfReadings = constrain(RemapedAmountOfReadings, 1, 10);
    AmountOfReadings = RemapedAmountOfReadings;
  } else {
    PulseCounter++;
    PeriodSum = PeriodSum + PeriodBetweenPulses;
  }
}
