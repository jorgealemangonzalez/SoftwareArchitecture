class Album{
public:
    std::string title(const std::string Title = "-- Untitled --"){//Get the title of the album
        if(this->Title == "" || this->Title == "-- Untitled --")//If the title is not set we set it to the value of the parameter
       	{
       		this->Title = Title;
       	}
       	return this->Title;
    }
    void list(){ // changes the status of the album to "Listed"
   		Listed = true;
    }
    void unlist(){// changes the status of the album to "unListed"
    	Listed = false;
    }
    bool isListed(){//Return if the album is listed
    	return Listed;
    }
private:
	std::string Title;//Title of the album
	bool Listed = false;//Album is listed : true , or not : false
};
