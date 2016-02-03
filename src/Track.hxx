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
    	Title =_title;
    }
    unsigned int duration(){ //we declare the integrer as "unsigned", that's the meaning of the sufix "u".
        if(_duration != -1){ //(have to solve the problem with valgrind with variables):.
            return _duration;
        }
        //return 0;		discoment for pass the test
    }
    void duration(unsigned int durat){
        _duration = durat;
    }
private:
	std::string Title;
    unsigned int _duration=-1;
};  
