#ifndef PORTAL_HXX
#define PORTAL_HXX

#include <string>
#include "MailStub.hxx"
#include "Observer.hxx"
#include "Subject.hxx"
#include <utility>

class Portal: public Observer{                           //Portal for group of fans
public:
    Portal():_name("NONE"),_description("NODESCRIPTION"){}            //default name
    
    const std::string name(const std::string &name = "NONE"){           //returns the name of the portal
        if(name != "NONE"){
            _name = name;
        }
        return _name;
    }
    
    const std::string description(const std::string &description = "NODESCRIPTION"){    //returns the description of the portal
        if(description != "NODESCRIPTION")
            _description = description;
    
        return _description;
    }
    const std::string resume(){                         //Returns a beautyfull description of the portal
        return _name+"\n"+"\t" +_description +"\n";
    }
    const std::string htmlResum(){  //return all the songs that our portal are interested
        std::string res ="";
        for(unsigned int i = 0 ; i < _Tracks.size(); ++i){
            res += "<item>\n<title>New track: '"+_Tracks[i].second+"' by '" + _Tracks[i].first + "'</title>\n";
            res += "<link>http://www.singalong.com/infoTrack?artist='"+ _Tracks[i].first + "'&title='"  + _Tracks[i].second + "'</link>\n</item>\n";
        }
        return res;
    }
    void update(Subject* subject){  //when new song it's created, we store the name of the artist and the name of the song
        std::pair<std::string,std::string> info;
        
        info = subject->getState();
        _Tracks.push_back(make_pair(info.first ,info.second) );
    }
private:
    std::vector<std::pair<std::string,std::string> > _Tracks;
    std::string _name ;     //name of the portal
    std::string _description;   //description of the portal
};

#endif