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

I2Cyan& I2CFactory::create_I2Cyan(uint8_t interface){
    if(interface != 0 || interface != 1) {
        throw "Only 0 and 1 are accepted as interface identifiers";
    }

    if(interface == 0) {
        return new Wire0Controller();
    }else {

    }
}

#endif