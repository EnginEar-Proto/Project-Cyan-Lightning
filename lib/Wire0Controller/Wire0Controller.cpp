#include "Wire0Controller.h"
#include "Wire.h"

#ifndef Wire0Controller_CPP

#define Wire0Controller_CPP

std::vector<void (*)(int)> Wire0Controller::receive_callbacks;
std::vector<void (*)()> Wire0Controller::request_callbacks;
uint8_t Wire0Controller::address;
bool Wire0Controller::initialized;

Wire0Controller::Wire0Controller(){
    if(initialized) return;

    Wire0Controller::initialized = true;
    Wire.begin();
    Wire0Controller::attach_invokers();
}

Wire0Controller::Wire0Controller(uint8_t addr){
    if(Wire0Controller::initialized) return;

    Wire0Controller::initialized = true;
    Wire0Controller::address = addr;
    Wire.begin(Wire0Controller::address);
    Wire0Controller::attach_invokers();
}

void Wire0Controller::subscribe_to_receive(void (*sub)(int)){
    Wire0Controller::receive_callbacks.push_back(sub);
}

void Wire0Controller::subscribe_to_request(void (*sub)()){
    Wire0Controller::request_callbacks.push_back(sub);
}

void Wire0Controller::invoke_receiver(int numBytes){
    for(void (*event)(int): Wire0Controller::receive_callbacks){
        event(numBytes);
    }
}

void Wire0Controller::invoke_requesters(){
    for(void (*event)(): Wire0Controller::request_callbacks){
        event();
    }
}

void Wire0Controller::attach_invokers(){
    Wire.onReceive(Wire0Controller::invoke_receiver);
    Wire.onRequest(Wire0Controller::invoke_requesters);
}

Wire0Controller::~Wire0Controller(){
    Wire.end();
}

#endif