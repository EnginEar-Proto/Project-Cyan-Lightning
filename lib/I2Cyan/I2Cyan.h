/**
 * Self-implemented I2C utility classes, following the Adapter pattern.
 * 
 * This feature implements
 * - `I2CAdapter` interface for uniting the useage of the I2C network.
 * - 
 * - 
 */
#include <cstdint>
#include <Wire.h>
class I2Cyan {
protected:
    uint8_t address;

    I2Cyan();
    I2Cyan(uint8_t addr);
public:
    virtual void subscribe_to_receive() = 0;
    virtual void subscribe_to_request() = 0;
    virtual void unsub_from_recieve() = 0;
    virtual void unsub_from_request() = 0;
    virtual ~I2Cyan();
};