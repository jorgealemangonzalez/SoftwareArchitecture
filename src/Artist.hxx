class Artist{
public:
	Artist(){
		_name = "-- No name --";
	}
	std::string name(const std::string &setName = "-- No name --"){//returns the name of the artist
		if(setName != "-- No name --"){				   //Compare if the name is set
			_name = setName;
		}
		return _name;
	}
	void createGroup(){
		return;
	}
	bool isGroup(){//retuns if the entity is an artist or a group
		return false;
	}
private:
	std::string _name;// The name of the artist
};
