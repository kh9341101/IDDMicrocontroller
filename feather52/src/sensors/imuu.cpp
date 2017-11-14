#include "imuu.h"
#include <Arduino.h>

#define SIMULATION


IMUU::IMUU(int32_t sensorID, uint8_t address) {
	bno = Adafruit_BNO055(sensorID,address);
}



void IMUU::setup() {
//#ifndef SIMULATION
	// gyro.enableAutoRange(true);
	// if(!accel.begin()) {
	//     Serial.println("Ooops, no LSM303 detected ... Check your wiring!");
	//     while(1);
	// }
 //  	if(!gyro.begin()) {
	//     Serial.println("Ooops, no L3GD20 detected ... Check your wiring!");
 //    	while(1);
	// }
    if(!bno.begin())
  {
    /* There was a problem detecting the BNO055 ... check your connections */
    Serial.print("Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!");
    while(1);
  }
  bno.setExtCrystalUse(true);
//#endif
}



void IMUU::read_acc(float *acc) {
//#ifndef SIMULATION
    sensors_event_t event;
    bno.getEvent(&event);
    acc[0] = event.acceleration.x;
    acc[1] = event.acceleration.y;
    acc[2] = event.acceleration.z;
  
// #else
//     acc[0] = float(random(100)) / 100.0;
//     acc[1] = float(random(100)) / 100.0;
//     acc[2] = float(random(100)) / 100.0;
// #endif
}

void IMUU::read_gyr(float *gyr) {
//#ifndef SIMULATION	
	sensors_event_t event; 
    bno.getEvent(&event);
    gyr[0] = event.orientation.x;
    gyr[1] = event.orientation.y;
    gyr[2] = event.orientation.z;
  Serial.print("X: ");
  Serial.print(event.orientation.x, 4);
  Serial.print("\tY: ");
  Serial.print(event.orientation.y, 4);
  Serial.print("\tZ: ");
  Serial.print(event.orientation.z, 4);
  Serial.print("\t");
// #else
//     gyr[0] = float(random(100)) / 100.0;
//     gyr[1] = float(random(100)) / 100.0;
//     gyr[2] = float(random(100)) / 100.0;
// #endif
}