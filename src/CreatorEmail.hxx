#ifndef CREATOREMAIL_HXX
#define CREATOREMAIL_HXX

#include "Creator.hxx"
#include "Strategy.hxx"
#include "SendByEmail.hxx"

class Strategy;

class CreatorEmail : public Creator{                                                  
    public:
    CreatorEmail(){}                              

    Strategy * FactoryMethod(){
    	return new SendByEmail();
    }
    void CreateStrategy(){
    	
    }

};

#endif