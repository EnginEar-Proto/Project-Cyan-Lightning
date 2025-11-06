#include "I2C_Event_Subscriber.h"

#ifndef I2C_RECIEVE_SUBSCRIBER_H

#define I2C_RECIEVE_SUBSCRIBER_H

class I2C_Recieve_Subscriber : public I2C_Event_Subscriber{
private:
    I2C_Recieve_Subscriber *next;
    void (*function)(int numBytes);
public:
    I2C_Recieve_Subscriber();
    I2C_Recieve_Subscriber(void (*sub)(int numBytes));
    void invoke(int numBytes);
    ~I2C_Recieve_Subscriber();
};

#endif