class Album{
public:
    std::string title(const std::string Title = "-- Untitled --"){//Get the title of the album
        if(this->Title == "" || this->Title == "-- Untitled --")//If the title is not set we set it to the value of the parameter
       	{
       		this->Title = Title;
       	}
       	return this->Title;
    }
    bool isListed(){
    	return false;
    }
private:
	std::string Title;//Title of the album
};
