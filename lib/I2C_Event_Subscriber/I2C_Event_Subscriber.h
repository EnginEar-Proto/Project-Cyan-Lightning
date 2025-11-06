#ifndef I2C_EVENT_SUBSCRIBER_H

#define I2C_EVENT_SUBSCRIBER_H

class I2C_Event_Subscriber{
protected:
    I2C_Event_Subscriber *next;
public:
    virtual ~I2C_Event_Subscriber() = 0;
    virtual void invoke() = 0;
};

#endif