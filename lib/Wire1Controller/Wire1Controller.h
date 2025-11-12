#include "Wire.h"

#ifndef WIRE1CONTROLLER_H

#define WIRE1CONTROLLER_H

class Wire1Controller{
    static std::vector<void (*)(int)> receive_callbacks;
    static std::vector<void (*)()> request_callbacks;
    static uint8_t address;
    static bool initialized;

    static void invoke_receiver(int);
    static void invoke_requesters();
    static void attach_invokers();
public:
    Wire1Controller();
    Wire1Controller(uint8_t);
    static void subscribe_to_receive(void (*)(int));
    static void subscribe_to_request(void (*)());
    ~Wire1Controller();
};

#endif