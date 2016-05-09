#include "Style.hxx"
#include <vector>
typedef std::vector<Style*> Styles;
class Track
{
public:   
    Track(){
        _title = "-- Untitled --";
        _duration = (unsigned)0; //inicializamos los valors predefinidos
        _master = "";
        _noStyles = false;
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
    std::string master(const std::string &setMaster = ""){ //devolveremos valor por defecto a no ser que ya haya sido modificado
        if(setMaster != ""){
            _master = setMaster;
        }   
        return _master;
    } 
    std::string styles()const{  //returns the list of styles of the track
        std::string ret = "";
        if(!_noStyles)return ret;
        for(unsigned int i = 0 ; i < _styles.size() ; ++i){
            if(i==0)ret+="\n";
            ret += "\t\t"+_styles[i]->getName();
            if(i < _styles.size() - 1 )ret+="\n";
        }
        return ret;
    }
    void addStyle(Style & style) {  //adds a style to the Track
        _noStyles = true;
        _styles.push_back(&style);
    }
    bool noStyles(){ //to see if a track has any style
        return _noStyles;
    }
private:
    Styles _styles;                //Styles of the track
    bool _noStyles;
	std::string _title;
    unsigned int _duration;
    std::string _master;
};  
