class Track
{
public:     
    std::string title(){ //return untitle title
        if(Title == ""){
        	return "-- Untitled --";
        }	
        return Title;
    }
    void title(const std::string& _title){ //we set the value of a title in out private variable Title
    	Title=_title;
    }
private:
	std::string Title;
};