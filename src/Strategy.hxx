#ifndef STRATEGY_HXX
#define STRATEGY_HXX

#include "MailStub.hxx"


class Strategy {                                                  
    public:
    Strategy(){}	//Strategy class, all specific methods inheratance from this
    virtual ~Strategy(){};                         

    virtual void Notificate(const std::string &name, const std::string &mail,const std::string &info,const std::string &phone) = 0;	
   
};

#endif