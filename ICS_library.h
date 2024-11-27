#ifndef ICS_LIBRARY_H
#define ICS_LIBRARY_H

#include <Arduino.h>
#include <libmaple/usart.h>
#include <libmaple/timer.h>

class IcsCommunication {
public:
    IcsCommunication(HardwareSerial &serial, int baudrate);
    void changeBaudrate(uint32_t brate);
    void changeTimeout(uint16_t timeout);
    int transceive(uint8_t *txbuf, uint8_t *rxbuf, uint8_t txsize, uint8_t rxsize);
    int setPosition(uint8_t servoID, int value);
    int readParam(uint8_t servoID, uint8_t paramCode);
    int writeParam(uint8_t servoID, uint8_t paramCode, int value);
private:
    HardwareSerial &serialPort;
    int baudRate;
    uint16_t timeout;
    void debugPrint(const String &msg);
};

#endif
