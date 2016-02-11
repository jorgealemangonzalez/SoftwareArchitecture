class Artist{
public:
	Artist(){
		_name = "-- No name --";//Set the default name 
		_grouped = false;//Set the default kind of account
	}
	std::string name(const std::string &setName = "-- No name --"){//returns the name of the artist
		if(setName != "-- No name --"){				   //Compare if the name is set
			_name = setName;
		}
		return _name;
	}
	void createGroup(){//Transform the artist account into a group account
		_grouped = true;
	}
	void disolveGroup(){
		
	}
	bool isGroup(){//retuns if the entity is an artist or a group
		return _grouped;
	}
private:
	std::string _name;// The name of the artist
	bool _grouped;// If the account is of an artist or of a group
};
