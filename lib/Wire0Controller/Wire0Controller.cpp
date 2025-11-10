#include "Wire0Controller.h"
#include "Wire.h"

#ifndef Wire0Controller_CPP

#define Wire0Controller_CPP

Wire0Controller::Wire0Controller(){
    Wire.begin();
}

Wire0Controller::Wire0Controller(uint8_t addr){
    this->address = addr;
    Wire.begin(this->address);
}

void Wire0Controller::subscribe_to_receive(I2C_Recieve_Subscriber& sub){
    void (*func)(int numBytes) = sub.invoke;
    Wire.onReceive((sub.invoke));
}

void Wire0Controller::subscribe_to_request(I2C_Request_Subscriber& sub){
    Wire.onRequest(sub.invoke);
}

void Wire0Controller::unsub_from_recieve(){

}

void Wire0Controller::unsub_from_request(){
    
} 

Wire0Controller::~Wire0Controller(){
    Wire.end();
}

#endif