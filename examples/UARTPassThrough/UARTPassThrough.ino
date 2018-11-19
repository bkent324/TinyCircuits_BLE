//-------------------------------------------------------------------------------
//  TinyCircuits ST BLE TinyShield UART Example Sketch
//  Last Updated 19 November 2018
//
//  This demo sets up the BlueNRG-MS chipset of the ST BLE module for compatiblity
//  with Nordic's virtual UART connection, and can pass data between the Arduino
//  serial monitor and Nordic nRF UART V2.0 app or another compatible BLE
//  terminal.
//
//  Written by Ben Rose, TinyCircuits http://tinycircuits.com
//  Modified by Ben Kent (https://github.com/bkent324) 19 November 2018
//
//-------------------------------------------------------------------------------


#include <SPI.h>
#include <TinyCircuits_BLE.h>

#if defined (ARDUINO_ARCH_AVR)
#define SerialMonitorInterface Serial
#elif defined(ARDUINO_ARCH_SAMD)
#define SerialMonitorInterface SerialUSB
#endif

// initialize TinyCircuits_BLE object
// debug mode enabled by default, can be turned off via BLE_DEBUG in TinyCircuits_BLE.h
TinyCircuits_BLE ble = TinyCircuits_BLE();

// BLE buffer contents
uint8_t * buff;

void setup() {
  SerialMonitorInterface.begin(9600);
  while (!SerialMonitorInterface); //This line will block until a serial monitor is opened with TinyScreen+!

  // initialize BLE Module
  ble.init();
}

void loop() {
  // SerialMonitorInterface.print("Connected: ");
  // SerialMonitorInterface.println(ble.isConnected());

  // check for incoming data, ble.available() must be run in main loop
  if (ble.available())
  {
    SerialMonitorInterface.println("data available!!");

    // read contents of buffer
    buff = ble.getBuffer();

    SerialMonitorInterface.print("BLE buffer: ");
    SerialMonitorInterface.println((char*)buff);

    // echo received data back to central
    ble.writeUART((char*)buff);
  }
}

