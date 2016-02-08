class Album{
public:
    std::string title(const std::string Title = "-- Untitled --"){//Get the title of the album
        if(this->Title == "" || this->Title == "-- Untitled --")
       	{
       		this->Title = Title;
       	}
       	return this->Title;
    }
private:
	std::string Title;
};
