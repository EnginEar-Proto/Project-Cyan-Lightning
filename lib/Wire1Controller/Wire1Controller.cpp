#include "Wire1Controller.h"

#ifndef WIRE1CONTROLLER_CPP
#define WIRE1CONTROLLER_CPP

Wire1Controller::Wire1Controller(){
    Wire1.begin();
    this->connect_invokers();
}


Wire1Controller::Wire1Controller(uint8_t addr) {
    this->address = addr;
    Wire1.begin(addr);
    this->connect_invokers();
}

void Wire1Controller::connect_invokers(){
    Wire1.onReceive((void (*)(int))&Wire1Controller::invoke_on_recive);
    Wire1.onRequest((void (*)())&Wire1Controller::invoke_on_request);
}


void Wire1Controller::subscribe_to_receive(void (&sub)(int numBytes)){
    this->recieve_events.push_back(sub);
}

void Wire1Controller::subscribe_to_request(void (&sub)()){
    this->request_events.push_back(sub);
}

#endif