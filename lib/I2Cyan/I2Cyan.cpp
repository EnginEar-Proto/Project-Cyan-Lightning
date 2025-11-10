#include "I2Cyan.h"

#ifndef I2Cyan_CPP

#define I2Cyan_CPP

void I2Cyan::invoke_on_recive(int numBytes){
    for(void (&event)(int numBytes) : this->recieve_events){
        event(numBytes);
    }
}

void I2Cyan::invoke_on_request(){
    for(void (&event)() : this->request_events){
        event();
    }
}

#endif