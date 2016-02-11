class Track
{
public:   
    Track(){
        _title = "-- Untitled --";
        _duration = (unsigned)0; //inicializamos los valors predefinidos
        _master = "";
    }  
    std::string title(const std::string& setTitle = ""){ //return untitle title
        if(setTitle != ""){
        	_title = setTitle;
        }	
        return _title;
    }
    unsigned int duration(const unsigned int& setDuration = 0 ){ //devolvemos 0 si no se ha asignado ningun valor
        if( setDuration != (unsigned)0  ){
            _duration = setDuration;
        }
        return _duration;
    }
    std::string master(){
            return "";
    }
    /*void master(const std::string& setMaster){
        _Master = setMaster;
    }*/

 
private:
	std::string _title;
    unsigned int _duration;
    std::string _master;
};  
