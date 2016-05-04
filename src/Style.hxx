#include<string>

class Style{
public:
	Style(const std::string &name):_name(name){

	}
	std::string getName(){		//returns the name of the style
		return _name;
	}
	void setName(const std::string &name){	//changes the name of the style
		_name = name;
	}
private:
	std::string _name;	//Name of the style
};