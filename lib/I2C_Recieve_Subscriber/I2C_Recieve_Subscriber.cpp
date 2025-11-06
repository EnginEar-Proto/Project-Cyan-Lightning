#include "I2C_Recieve_Subscriber.h"

#ifndef I2C_REVICE_SUBSCRIBER_CPP
#define I2C_REVICE_SUBSCRIBER_CPP

I2C_Recieve_Subscriber::I2C_Recieve_Subscriber(): function(nullptr), next(nullptr){}
I2C_Recieve_Subscriber::I2C_Recieve_Subscriber(void (*sub)(int numBytes)): function(sub), next(nullptr){}

void I2C_Recieve_Subscriber::invoke(int numBytes) {
    try{
        if(function != nullptr){
            this->function(numBytes);
        }
    } catch(...){
        return;
    }
}

I2C_Recieve_Subscriber::~I2C_Recieve_Subscriber(){
    delete &function;
}

#endif