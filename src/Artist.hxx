class Artist{
public:
	Artist(){
		_name = "-- No name --";
		_grouped = false;
	}
	std::string name(const std::string &setName = "-- No name --"){//returns the name of the artist
		if(setName != "-- No name --"){				   //Compare if the name is set
			_name = setName;
		}
		return _name;
	}
	void createGroup(){
		_grouped = true;
	}
	bool isGroup(){//retuns if the entity is an artist or a group
		return _grouped;
	}
private:
	std::string _name;// The name of the artist
	bool _grouped;
};
