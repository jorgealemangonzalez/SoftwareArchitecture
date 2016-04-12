#include "Artist.hxx"
#include<vector>

class SingAlong{
public:
    SingAlong(){
        
    }
    ~SingAlong(){
        std::vector<Artist*>::iterator it;
        for(it = _catalog.begin();it != _catalog.end() ; ++it){
            delete(*it);
        } 
    }
    std::string catalog(){          //Returns a list of artist with their description
        std::vector<Artist*>::iterator it;
        std::string result("");
        for(it = _catalog.begin();it != _catalog.end() ; ++it){
            result+= (*it)->description();
        }
        return result;
    }
    
    void createArtist(const std::string &artist , bool isGroup){	//Create an artis and changes is status to grouped ( if isGroup is true ) and save it into the catalog
    if(_catalog.size() > 0)return;
        Artist *a = new Artist();		
        a->name(artist);
        if(isGroup){			
        	a->createGroup();
        }
        _catalog.push_back(a);
    }
private:
    std::vector<Artist*> _catalog;		//List of different artists of the web page
};
