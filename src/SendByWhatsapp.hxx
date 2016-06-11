#ifndef SENDBYWHATSAPP_HXX
#define SENDBYWHATSAPP_HXX

#include "Strategy.hxx"
#include "MailStub.hxx"


class SendByWhatsapp : public Strategy{                                                  
    public:
    SendByWhatsapp(){}                               

    void Notificate(const std::string &name, const std::string &mail,const std::string &info,const std::string &phone){
    	std::string text = "[SingAlong] " + info;
    	WhatsappStub::theInstance().sendWhatsapp(phone,text);
    }

};

#endif