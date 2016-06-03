#ifndef PORTAL_HXX
#define PORTAL_HXX

#include<string>
class Portal{                           //Portal for group of fans
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
    const std::string resume(){
        return _name+"\n"+"\t" +_description +"\n";
    }
private:
    std::string _name ;     //name of the portal
    std::string _description;   //description of the portal
};

#endif