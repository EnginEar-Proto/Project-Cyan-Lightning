#include "I2C_Request_Subscriber.h"

#ifndef I2C_REQUST_SUBSCRIBER_CPP

#define I2C_REQUST_SUBSCRIBER_CPP

I2C_Request_Subscriber::I2C_Request_Subscriber(): function(nullptr), next(nullptr) {}
I2C_Request_Subscriber::I2C_Request_Subscriber(void (*sub)()): function(sub), next(nullptr) {}

void I2C_Request_Subscriber::invoke(){
    try{
        if(function != nullptr){
            function();
        }
    } catch(...) {
        return;
    }
}

I2C_Request_Subscriber::~I2C_Request_Subscriber(){
    delete &function;
}

#endif