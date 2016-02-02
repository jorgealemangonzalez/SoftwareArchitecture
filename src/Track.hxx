class Track
{
public:     
    std::string title(){ //return untitle title
        if(Title == ""){
        	return "-- Untitled --";
        }	
        return Title;
    }
    void title(std::string _title){
    	Title=_title;
    }
private:
	std::string Title;
};