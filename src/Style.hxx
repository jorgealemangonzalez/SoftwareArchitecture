#include<string>

class Style{
public:
	Style(const std::string name):_name(name){

	}
	const std::string getName(){		//returns the name of the style
		return _name;
	}
private:
	std::string _name;	//Name of the style
};