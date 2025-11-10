#include "I2Cyan.h"

class Wire0Controller : public I2Cyan {
private:
    static bool initialized;

public:
    Wire0Controller();
    Wire0Controller(uint8_t addr);
    void subscribe_to_receive(void (&)(int)) override;
    void subscribe_to_request(void (&)()) override;
    void unsub_from_recieve() override;
    void unsub_from_request() override;
    ~Wire0Controller();
private:
    void connect_invokers() override;
};