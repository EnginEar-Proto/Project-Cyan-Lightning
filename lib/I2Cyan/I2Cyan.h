/**
 * Self-implemented I2C utility classes, following the Adapter pattern.
 * 
 * This feature implements
 * - `I2CAdapter` interface for uniting the useage of the I2C network.
 * - 
 * - 
 */
#include <cstdint>
class I2Cyan {
protected:
    uint8_t address;
public:
    void subscribe_to_receive();
    void subscribe_to_request();
    virtual ~I2Cyan() = 0;
};