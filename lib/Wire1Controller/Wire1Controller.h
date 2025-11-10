#include "I2Cyan.h"

#ifndef WIRE1CONTROLLER_H

#define WIRE1CONTROLLER_H

class Wire1Controller : public I2Cyan {
    static bool initialized;
public:
    Wire1Controller();
    Wire1Controller(uint8_t addr);
    void subscribe_to_receive(void (&)(int numBytes)) override;
    void subscribe_to_request(void (&)()) override;
    void unsub_from_recieve() override;
    void unsub_from_request() override;
    ~Wire1Controller();
private:
    void connect_invokers() override;
};

#endif