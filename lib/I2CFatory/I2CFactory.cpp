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

I2Cyan& I2CFactory::create_I2Cyan(){
    if(sizeof(I2CFactory::products) / sizeof(*I2CFactory::products) == 0){
        
    }

    return *newLine;
}

I2Cyan& I2CFactory::create_I2Cyan(uint8_t address){
    I2Cyan *newLine = new I2Cyan(address);
}

#endif