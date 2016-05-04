#include<string>

class Style{
public:
	Style(const std::string name):_name(name){

	}
	const std::string getName(){
		return _name;
	}
private:
	std::string _name;
};