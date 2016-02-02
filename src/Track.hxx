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
    unsigned int duration(){ //we declare the integrer as "unsigned", that's the meaning of the sufix "u".
        return 0;
    }
private:
	std::string Title;
};