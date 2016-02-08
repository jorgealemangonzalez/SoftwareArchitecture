class Album{
public:
    std::string title(const std::string Title = "-- Untitled --"){//Get the title of the album
        if(_title == "" || _title == "-- Untitled --")//If the title is not set we set it to the value of the parameter
       	{
       		_title = Title;
       	}
       	return _title;
    }
    void list(){ // changes the status of the album to "Listed"
   		_listed = true;
    }
    void unlist(){// changes the status of the album to "unListed"
    	_listed = false;
    }
    bool isListed(){//Return if the album is listed
    	return _listed;
    }
private:
	std::string _title;//Title of the album
	bool _listed = false;//Album is listed : true , or not : false
};
