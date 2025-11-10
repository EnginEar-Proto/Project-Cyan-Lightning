/**
 * Factory class for creating I2Cyan objects.
 */
#include <cstdint>
#include "I2Cyan.h"
#include "Wire0Controller.h"
#include "Wire1Controller.h"

#ifndef I2FACTORY_H

#define I2CFACTORY_H

class I2CFactory{
    static I2Cyan *products[2];
public:
    I2CFactory();
    I2Cyan& create_I2Cyan(uint8_t interface);
    I2Cyan& create_I2Cyan(uint8_t address, uint8_t interface);
    ~I2CFactory();
};

#endif