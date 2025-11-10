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
    std::vector<void (&)(int)> recieve_events;
    std::vector<void (&)()> request_events;

    I2Cyan();
    I2Cyan(uint8_t addr);
    virtual void connect_invokers() = 0;
public:
    virtual void subscribe_to_receive(void (&)(int)) = 0;
    virtual void subscribe_to_request(void (&)(void)) = 0;
    virtual void unsub_from_recieve() = 0;
    virtual void unsub_from_request() = 0;
    void invoke_on_recive(int);
    void invoke_on_request();
    virtual ~I2Cyan();
};