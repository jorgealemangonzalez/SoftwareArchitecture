class Album{
    
public:
    Album (){
        _listed = false;
        _title = "-- Untitled --";
    }
    std::string title(const std::string &setTitle = "-- Untitled --"){//Get the title of the album
        if(setTitle != "-- Untitled --")//If the title is not set we set it to the value of the parameter
       	{
       		_title = setTitle;
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
	bool _listed;//Album is listed : true , or not : false
};
