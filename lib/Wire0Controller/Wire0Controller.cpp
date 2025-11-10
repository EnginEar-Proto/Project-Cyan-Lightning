#include "Wire0Controller.h"
#include "Wire.h"

#ifndef Wire0Controller_CPP

#define Wire0Controller_CPP

Wire0Controller::Wire0Controller(){
    if(Wire0Controller::initialized) return;

    Wire0Controller::initialized = true;
    Wire.begin();
    this->connect_invokers();
}

Wire0Controller::Wire0Controller(uint8_t addr){
    if(Wire0Controller::initialized) return;
    
    Wire0Controller::initialized = true;
    this->address = addr;
    Wire.begin(this->address);
    this->connect_invokers();
}

void Wire0Controller::connect_invokers(){
    Wire.onReceive((void (*)(int))&Wire0Controller::invoke_on_recive);
    Wire.onRequest((void (*)())&Wire0Controller::invoke_on_request);
}

void Wire0Controller::subscribe_to_receive(void (&sub)(int numBytes)){
    this->recieve_events.push_back(sub);
}

void Wire0Controller::subscribe_to_request(void (&sub)()){
    this->request_events.push_back(sub);
}

void Wire0Controller::unsub_from_recieve(){
    throw "Incomplete function";
}

void Wire0Controller::unsub_from_request(){
    throw "Incomplete function";
} 

Wire0Controller::~Wire0Controller(){
    Wire.end();
}

#endif