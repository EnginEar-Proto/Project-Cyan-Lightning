#include "I2CFactory.h"

#ifndef I2CFactory_CPP

#define I2CFactory_CPP

I2CFactory::I2CFactory(){

}

I2CFactory::~I2CFactory(){
    for(int i; i < sizeof(I2CFactory::products) / sizeof(*I2CFactory::products); i++)
        delete products[i];
    delete[] I2CFactory::products;
}

const I2Cyan& I2CFactory::create_I2Cyan(uint8_t interface) {
    if(interface != 0 || interface != 1) {
        throw "Only 0 and 1 are accepted as interface identifiers";
    }

    I2Cyan *product;

    if(interface == 0) {
        product = new Wire0Controller();
        products[0] = product;
    }else {
        product = new Wire1Controller();
        products[1] = product;
    }

    return *product;
}

const I2Cyan& I2CFactory::create_I2Cyan(uint8_t interface, uint8_t address) {
    if(interface != 0 || interface != 1) {
        throw "Only 0 and 1 are accepted as interface identifiers";
    }

    I2Cyan *product;

    if(interface == 0) {
        product = new Wire0Controller(address);
        products[0] = product;
    }else {
        product = new Wire1Controller(address);
        products[1] = product;
    }

    return *product;
}

#endif