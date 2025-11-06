#include "I2C_Event_Subscriber.h"

#ifndef I2C_EQUEST_SUBSCRIBER_H
#define I2C_EQUEST_SUBSCRIBER_H

class I2C_Request_Subscriber : public I2C_Event_Subscriber{
private:
    I2C_Request_Subscriber *next;
    void (*function)();
public:
    I2C_Request_Subscriber();
    I2C_Request_Subscriber(void (*sub)());
    void invoke();
    ~I2C_Request_Subscriber();
};

#endif