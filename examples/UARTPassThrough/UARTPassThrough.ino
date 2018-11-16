//-------------------------------------------------------------------------------
//  TinyCircuits ST BLE TinyShield UART Example Sketch
//  Last Updated 16 November 2018
//
//  This demo sets up the BlueNRG-MS chipset of the ST BLE module for compatiblity
//  with Nordic's virtual UART connection, and can pass data between the Arduino
//  serial monitor and Nordic nRF UART V2.0 app or another compatible BLE
//  terminal. This example is written specifically to be fairly code compatible
//  with the Nordic NRF8001 example, with a replacement UART.ino file with
//  'aciLoop' and 'BLEsetup' functions to allow easy replacement.
//
//  Written by Ben Rose, TinyCircuits http://tinycircuits.com
//
//-------------------------------------------------------------------------------


#include <SPI.h>
#include <TinyCircuits_BLE.h>

//Debug output adds extra flash and memory requirements!
#ifndef BLE_DEBUG
#define BLE_DEBUG true
#endif

#if defined (ARDUINO_ARCH_AVR)
#define SerialMonitorInterface Serial
#elif defined(ARDUINO_ARCH_SAMD)
#define SerialMonitorInterface SerialUSB
#endif

TinyCircuits_BLE ble = TinyCircuits_BLE();

uint8_t * blebuff;

void setup() {
  SerialMonitorInterface.begin(9600);
  while (!SerialMonitorInterface); //This line will block until a serial monitor is opened with TinyScreen+!

  ble.init();
}


void loop() {
  // SerialMonitorInterface.print("Connected: ");
  // SerialMonitorInterface.println(ble.isConnected());
  if (ble.available())
  {
    SerialMonitorInterface.println("data available!!");
    blebuff = ble.getBuffer();
    SerialMonitorInterface.println((char*)blebuff);
    ble.writeUART((char*)blebuff);
  }
}

