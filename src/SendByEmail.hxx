#ifndef SENDBYEMAIL_HXX
#define SENDBYEMAIL_HXX

#include "Strategy.hxx"
#include "MailStub.hxx"


class SendByEmail : public Strategy{                                                  
    public:
    SendByEmail(){}                              

    void Notificate(const std::string &name, const std::string &mail,const std::string &info,const std::string &phone){
    	std::string to = name + " <" + mail +">";
    	MailStub::theInstance().sendMail(to,info);
    }

};

#endif