#include "Wire.h"

#ifndef WIRE0CONTROLLER_H

#define WIRE0CONTROLLER_H

class Wire0Controller{
    static std::vector<void (*)(int)> receive_callbacks;
    static std::vector<void (*)()> request_callbacks;
    static uint8_t address;
    static bool initialized;

    static void invoke_receiver(int);
    static void invoke_requesters();
    static void attach_invokers();
public:
    Wire0Controller();
    Wire0Controller(uint8_t);
    static void subscribe_to_receive(void (*)(int));
    static void subscribe_to_request(void (*)());
    ~Wire0Controller();
};

#endif