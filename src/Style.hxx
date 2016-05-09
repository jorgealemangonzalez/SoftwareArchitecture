
#include<string>
#include "User.hxx"
#include "Exceptions.hxx"
#include <vector>
#ifndef HXX_STYLE
#define HXX_STYLE
typedef std::vector<User*> Users;
class Style{
public:
	Style(const std::string &name):_name(name){

	}
	std::string getName()const{		//returns the name of the style
		return _name;
	}
	void setName(const std::string &name){	//changes the name of the style
		_name = name;
	}
	void subscribeUser(User &user){
		_users.push_back(&user);
	}
	std::string usersSubscribed(){
		std::string ret = "";
		for(Users::iterator it = _users.begin() ; it != _users.end() ; ++it){
			ret += (*it)->getName() + "\n";
		}
		return ret;
	}
private:
	std::string _name;	//Name of the style
	Users _users;
};
#endif