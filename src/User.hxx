
#ifndef USER_HXX
#define USER_HXX
class User{
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
private:
	std::string _name;	//Name of the user
	std::string _email; //email of the user
};
#endif