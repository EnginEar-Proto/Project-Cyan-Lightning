/**
 * Factory class for creating I2Cyan objects.
 */
#include <cstdint>
#include "I2Cyan.h"
class I2CFactory{
    static I2Cyan products[2];
public:
    I2CFactory();
    I2Cyan create_I2Cyan();
    I2Cyan create_I2Cyan(uint8_t address);
    ~I2CFactory();
};