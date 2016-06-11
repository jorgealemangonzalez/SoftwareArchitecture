#ifndef SENDBYSMS_HXX
#define SENDBYSMS_HXX

#include "Strategy.hxx"
#include "MailStub.hxx"


class SendBySMS : public Strategy{                                                  
    public:
    SendBySMS(){}                              

    void Notificate(const std::string &name, const std::string &mail,const std::string &info,const std::string &phone){
    	std::string text = "[SingAlong] " + info;
    	SmsStub::theInstance().sendSms(phone,text);
    }

};

#endif