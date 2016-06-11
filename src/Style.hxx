
#include <string>
#include <vector>

#include "User.hxx"
#include "Exceptions.hxx"
#include "MailStub.hxx"
#include "Subject.hxx"

#ifndef HXX_STYLE
#define HXX_STYLE


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
		Subject::attach((Observer*)&user);
	}
	std::string usersSubscribed(){
		std::string ret = "";
		for(std::vector<Observer*>::iterator it = _observers.begin() ; it != _observers.end() ; ++it){ //return all the names of our users
			ret += ((User*)(*it))->getName() + "\n";									//that are subscribed to this style.
		}
		return ret;
	}
	/*void notifyUsers(const std::string &subject){			//notify all users with the specific subject
		for(Users::iterator it = _users.begin() ; it != _users.end() ; ++it){
			(*it)->notify(subject,"a");
		}
	}*/

	void notifyUsers(const std::string &artist, const std::string &track){	//store the information of the track		
		_trackInfo.first=artist;
		_trackInfo.second=track;
		Subject::notify();				//and notify that we have to upgrade
	}

	std::pair<std::string,std::string> getState(){ //return the state 
		return make_pair(_trackInfo.first , _trackInfo.second);
	}

private:
	std::pair<std::string,std::string> _trackInfo;
	std::string _name;	//Name of the style

};
#endif