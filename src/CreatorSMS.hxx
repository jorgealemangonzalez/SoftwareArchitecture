#ifndef CREATORSMS_HXX
#define CREATORSMS_HXX

#include "Creator.hxx"
#include "SendBySMS.hxx"


class CreatorSMS : public Creator{                                                  
    public:
    CreatorSMS(){}                              

    Strategy * FactoryMethod(){	 //return the Strategy method
    	
    	return new SendBySMS();
    }

    void CreateStrategy(){

    }

};

#endif