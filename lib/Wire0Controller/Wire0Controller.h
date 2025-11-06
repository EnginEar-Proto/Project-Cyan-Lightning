#include "I2Cyan.h"

class Wire0Controller : public I2Cyan {
public:
    Wire0Controller();
    Wire0Controller(uint8_t addr);
    void subscribe_to_receive(void (*function)(int numBytes));
    void subscribe_to_request();
    void unsub_from_recieve();
    void unsub_from_request();
    ~Wire0Controller();
};