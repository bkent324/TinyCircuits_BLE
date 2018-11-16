#ifndef BLE_DEBUG
#define BLE_DEBUG true
#endif

// #include "TInyCircuits_BLE.h"
#include "Arduino.h"
#include "STBlueNRG\hci.h"
#include "arduino_bluenrg_ble.h"
#include "STBlueNRG\bluenrg_aci.h"
#include "STBlueNRG\bluenrg_gap.h"
#include "STBlueNRG\hci_le.h"

#include "arduino_bluenrg_ble.h"
#include "arduino_hal.h"

#ifdef __cplusplus
 extern "C" {
#endif
	#include "STBlueNRG/bluenrg_utils.h"
	#include "STBlueNRG/hal_types.h"
	#include "STBlueNRG/ble_status.h"
	#include "STBlueNRG/hci.h"
	#include "STBlueNRG/hci_le.h"
	#include "STBlueNRG/bluenrg_aci.h"
	#include "STBlueNRG/gp_timer.h"
	#include "STBlueNRG/bluenrg_gap.h"
	#include "STBlueNRG/sm.h"
#ifdef __cplusplus
}
#endif

#if defined(ARDUINO_ARCH_AVR)
#define SerialMonitorInterface Serial
#elif defined(ARDUINO_ARCH_SAMD)
#define SerialMonitorInterface SerialUSB
#endif

class TinyCircuits_BLE
{
public:
  TinyCircuits_BLE();
  ~TinyCircuits_BLE();

  int init();
  bool isConnected();
  bool writeUART(char* msg);
  bool available();
  bool reset();
  uint8_t *getBuffer();

private:
  void aciLoop();
  uint8_t addUARTService(void);
  void setConnectable(void);
  uint8_t writeUARTTx(char* TXdata, uint8_t datasize);
  uint8_t libAciSendData(uint8_t ignore, uint8_t* sendBuffer, uint8_t sendLength);
};