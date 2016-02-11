class Track
{
public:   
    Track(){
        _title = "-- Untitled --";
        _duration = -1;
    }  
    std::string title(){ //return untitle title
        if(_title == "-- Untitled --"){
        	return "-- Untitled --";
        }	
        return _title;
    }
    void title(const std::string& title){ //we set the value of a title in out private variable Title
    	_title =title;
    }
    unsigned int duration(){
        if( _duration == (unsigned)-1  ){
            return 0;
        }
        return _duration;
    }
    void duration( const unsigned int& durat){
        _duration = durat;
    }
    /*std::string master(){
        if(_Master  == ""){
            return "";
        }
        return _Master;
    }
    void master(const std::string& setMaster){
        _Master = setMaster;
    }*/

 
private:
	std::string _title;
    unsigned int _duration;
    //std::string _Master;
};  
