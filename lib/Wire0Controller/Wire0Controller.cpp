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

void Wire0Controller::subscribe_to_receive(void (*subscriber)(int numBytes)){
    Wire.onReceive(subscriber);
}

void Wire0Controller::subscribe_to_request(){

}

void Wire0Controller::unsub_from_recieve(){

}

void Wire0Controller::unsub_from_request(){
    
} 

Wire0Controller::~Wire0Controller(){
    Wire.end();
}

#endif