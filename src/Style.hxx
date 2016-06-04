
#include <string>
#include <vector>

#include "User.hxx"
#include "Exceptions.hxx"
#include "MailStub.hxx"
#include "Subject.hxx"

#ifndef HXX_STYLE
#define HXX_STYLE

typedef std::vector<User*> Users;

class Style: public Subject{

public:
	Style(const std::string &name):_name(name){

	}
	std::string getName()const{		//returns the name of the style
		return _name;
	}
	void setName(const std::string &name){	//changes the name of the style
		_name = name;
	}
	void subscribeUser(User &user){ //add the reference of a user to out vector
		_users.push_back(&user);
	}
	std::string usersSubscribed(){
		std::string ret = "";
		for(Users::iterator it = _users.begin() ; it != _users.end() ; ++it){ //return all the names of our users
			ret += (*it)->getName() + "\n";									//that are subscribed to this style.
		}
		return ret;
	}
	void notifyUsers(const std::string &subject){			//notify all users with the specific subject
		for(Users::iterator it = _users.begin() ; it != _users.end() ; ++it){
			(*it)->notify(subject);
		}
	}

	void notifyUsers(const std::string &artist, const std::string &track){			
		_trackInfo.first=artist;
		_trackInfo.second=track;
		Subject::notify();
	}

	std::pair<std::string,std::string> getState(){
		return make_pair(_trackInfo.first , _trackInfo.second);
	}

private:
	std::pair<std::string,std::string> _trackInfo;
	std::string _name;	//Name of the style
	Users _users;

};
#endif