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
		_creator = (Creator*)new CreatorEmail(); //default creator
		_strategy = NULL; //by default
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
	void addNumber(const std::string &strategy, const std::string &number){ //if a user wants to receive notifications in the cellphone
		if(strategy == "Whatsapp"){
			delete(_creator);
			_creator = (Creator*)new CreatorWhatsapp();			//change the creator depending what the user wants
		}else if(strategy == "SMS"){
			delete(_creator);	
			_creator = (Creator*)new CreatorSMS();
		}
		_phone= number;
	}


	void update(Subject* subject){					//When the state of the subject change we take the information of the new track and notify the users
		std::pair<std::string,std::string> info;
		
		info = subject->getState();
		std::string _info = "new track " + info.second + " by " + info.first ;

		_strategy = _creator->FactoryMethod(); 		 //get the strategy of how to notificate this user
		_strategy->Notificate(_name,_email, _info,_phone); //notificate the user depending of the method he wants
	}
	
private:
	Creator *_creator;
	std::string _info;
	Strategy *_strategy;
	std::string _phone;
	std::string _name;	//Name of the user
	std::string _email; //email of the user
};
#endif