class Artist{
public:
	std::string name(const std::string &setName = "-- No name --"){//returns the name of the artist
		if(_name == "" || _name == "--No name--"){
			_name = setName;
		}
		return _name;
	}
private:
	std::string _name;
};
