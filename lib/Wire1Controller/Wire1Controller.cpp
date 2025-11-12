#include "Wire1Controller.h"
#include "Wire.h"

#ifndef Wire1Controller_CPP

#define Wire1Controller_CPP

std::vector<void (*)(int)> Wire1Controller::receive_callbacks;
std::vector<void (*)()> Wire1Controller::request_callbacks;
uint8_t Wire1Controller::address;
bool Wire1Controller::initialized;


Wire1Controller::Wire1Controller(){
    if(initialized) return;

    Wire1Controller::initialized = true;
    Wire1.begin();
    Wire1Controller::attach_invokers();
}

Wire1Controller::Wire1Controller(uint8_t addr){
    if(Wire1Controller::initialized) return;

    Wire1Controller::initialized = true;
    Wire1Controller::address = addr;
    Wire1.begin(Wire1Controller::address);
    Wire1Controller::attach_invokers();
}

void Wire1Controller::subscribe_to_receive(void (*sub)(int)){
    receive_callbacks.push_back(sub);
}

void Wire1Controller::subscribe_to_request(void (*sub)()){
    request_callbacks.push_back(sub);
}

void Wire1Controller::invoke_receiver(int numBytes){
    for(void (*event)(int): receive_callbacks){
        event(numBytes);
    }
}

void Wire1Controller::invoke_requesters(){
    for(void (*event)(): request_callbacks){
        event();
    }
}

void Wire1Controller::attach_invokers(){
    Wire1.onReceive(invoke_receiver);
    Wire1.onRequest(invoke_requesters);
}

Wire1Controller::~Wire1Controller(){
    Wire1.end();
}

#endif