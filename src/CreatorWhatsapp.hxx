#ifndef CREATORWHATSAPP_HXX
#define CREATORWHATSAPP_HXX

#include "Creator.hxx"
#include "SendByWhatsapp.hxx"

class Strategy;

class CreatorWhatsapp : public Creator{                                                  
    public:
    CreatorWhatsapp(){}


    Strategy *  FactoryMethod(){ //return the strategy he wants
    	return new SendByWhatsapp();
    }
    void CreateStrategy(){
    	
    }


};

#endif