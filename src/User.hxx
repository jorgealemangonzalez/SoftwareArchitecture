
#ifndef USER_HXX
#define USER_HXX
#include "MailStub.hxx"
#include "Observer.hxx"
#include "Subject.hxx"

#include<utility>

class User: public Observer{
public:
	User(const std::string &name, const std::string &email):_name(name), _email(email){

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
	void notify(const std::string &subject){ //use the MailStub library to "simulate" a message with this specific arguments
		std::string to = getName() + " <"+ getEmail() + ">";
		MailStub::theInstance().sendMail(to,subject);
	}

	void update(Subject* subject){					//When the state of the subject change we take the information of the new track and send a mail
		std::pair<std::string,std::string> info;
		
		info = subject->getState();
		MailStub::theInstance().sendMail(_name + " <"+ _email+">","new track " + info.second + " by " + info.first );
	}
	
private:
	std::string _name;	//Name of the user
	std::string _email; //email of the user
};
#endif