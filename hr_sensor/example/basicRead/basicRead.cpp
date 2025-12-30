/*!
 * @file basicRead.ino
 * @brief Output readings of red light and IR 
 * @n This library supports mainboards: ESP8266, FireBeetle-M0, UNO, ESP32, Leonardo, Mega2560
 * @copyright  Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @licence     The MIT License (MIT)
 * @author [YeHangYu](hangyu.ye@dfrobot.com)
 * @version  V0.1
 * @date  2020-05-29
 * @url https://github.com/DFRobot/DFRobot_MAX30102
 */

#include "DFRobot_MAX30102.h"
#include <iostream>
#include "pico/stdlib.h"

#define NOODS_PIN 14

DFRobot_MAX30102 particleSensor;

/*
Macro definition opions in sensor configuration 
sampleAverage: SAMPLEAVG_1 SAMPLEAVG_2 SAMPLEAVG_4 
               SAMPLEAVG_8 SAMPLEAVG_16 SAMPLEAVG_32
ledMode:       MODE_REDONLY  MODE_RED_IR  MODE_MULTILED
sampleRate:    PULSEWIDTH_69 PULSEWIDTH_118 PULSEWIDTH_215 PULSEWIDTH_411
pulseWidth:    SAMPLERATE_50 SAMPLERATE_100 SAMPLERATE_200 SAMPLERATE_400
               SAMPLERATE_800 SAMPLERATE_1000 SAMPLERATE_1600 SAMPLERATE_3200
adcRange:      ADCRANGE_2048 ADCRANGE_4096 ADCRANGE_8192 ADCRANGE_16384
*/

void nood_init()
{
    gpio_init(NOODS_PIN);
    gpio_set_dir(NOODS_PIN, GPIO_OUT);
}

int blink_nood()
{
    gpio_put(NOODS_PIN, 1);
    sleep_ms(1000);
    gpio_put(NOODS_PIN, 0);
    sleep_ms(1000);

    return 0;
}

int main()
{
  stdio_init_all;

  nood_init();
  blink_nood(); //#1 debug tool

  particleSensor.init();
  blink_nood();

  while (!particleSensor.begin()) {
    printf("MAX30102 was not found");
    sleep_ms(1000);
  }

  blink_nood();
  
  /*!
   *@brief Use macro definition to configure sensor
   *@param ledBrightness LED brightness, default value: 0x1F（6.4mA), Range: 0~255（0=Off, 255=50mA）
   *@param sampleAverage Average multiple samples then draw once, reduce data throughput, default 4 samples average
   *@param ledMode LED mode, default to use red light and IR at the same time 
   *@param sampleRate Sampling rate, default 400 samples every second 
   *@param pulseWidth Pulse width: the longer the pulse width, the wider the detection range. Default to be Max range
   *@param adcRange Measurement Range, default 4096 (nA), 15.63(pA) per LSB
   */

  blink_nood();
  particleSensor.sensorConfiguration(/*ledBrightness=*/0x1F, /*sampleAverage=*/SAMPLEAVG_4, \
                                  /*ledMode=*/MODE_MULTILED, /*sampleRate=*/SAMPLERATE_400, \
                                  /*pulseWidth=*/PULSEWIDTH_411, /*adcRange=*/ADCRANGE_4096);

  while(true)
  {
    printf("R= %d IR= %d\n", particleSensor.getRed(), particleSensor.getIR());
    blink_nood();
  }
  
  return 0;
}