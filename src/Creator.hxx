#ifndef CREATOR_HXX
#define CREATOR_HXX

#include <utility>
#include <string>
#include "Strategy.hxx"


class Creator{                                                  
    public:
    Creator(){}
    virtual ~Creator(){};
                                
    virtual Strategy *  FactoryMethod() = 0;
    virtual void CreateStrategy() = 0;   

};

#endif