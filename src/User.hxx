#ifndef USER_HXX
#define USER_HXX

#include "Creator.hxx"
#include "CreatorWhatsapp.hxx"
#include "CreatorEmail.hxx"
#include "CreatorSMS.hxx"
#include "SendByEmail.hxx"
#include "SendByWhatsapp.hxx"
#include "SendBySMS.hxx"
#include "Observer.hxx"
#include "Subject.hxx"

#include <utility>

class User: public Observer{
public:
	User(const std::string &name, const std::string &email):_name(name), _email(email){
		_creator = (Creator*)new CreatorEmail(); 
		_strategy = NULL;
	}
	~User(){
		if(_strategy != NULL)
			delete(_strategy);
		delete(_creator);

	}
	std::string getName()const{		//returns the name of the user
		return _name;
	}
	std::string getEmail()const{ 	//returns the mail of the user
		return _email;
	}
	void setName(const std::string &name){	//changes the name of the user
		_name = name;
	}
	void setEmail(const std::string &email){ //changes the email
		_email = email;
	}
	void addNumber(const std::string &strategy, const std::string &number){
		if(strategy == "Whatsapp"){
			delete(_creator);
			_creator = (Creator*)new CreatorWhatsapp();
		}else if(strategy == "SMS"){
			delete(_creator);	
			_creator = (Creator*)new CreatorSMS();
		}
		_phone= number;
	}

	/*void notify(const std::string &subject,const std::string &a){ //use the MailStub library to "simulate" a message with this specific arguments
		std::string to = getName() + " <"+ getEmail() + ">";
		std::cout << "AAAAAAAAA-" <<_whichstrategy.first << std::endl;
		MailStub::theInstance().sendMail(to,subject);
	}*/

	void update(Subject* subject){					//When the state of the subject change we take the information of the new track and send a mail
		std::pair<std::string,std::string> info;
		
		info = subject->getState();
		std::string _info = "new track " + info.second + " by " + info.first ;

		_strategy = _creator->FactoryMethod();
		_strategy->Notificate(_name,_email, _info,_phone);
	}
	
private:
	Creator *_creator;
	std::string _info;
	Strategy *_strategy = NULL;
	std::string _phone;
	std::string _name;	//Name of the user
	std::string _email; //email of the user
};
#endif