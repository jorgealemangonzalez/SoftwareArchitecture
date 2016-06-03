#ifndef PORTAL_HXX
#define PORTAL_HXX

#include<string>
class Portal{                           //Portal for group of fans
public:
    Portal():_name("NONE"){}
    
    const std::string name(const std::string &name = "NONE"){           //returns the name of the portal
        if(name != "NONE"){
            _name = name;
        }
        return _name;
    }
    
    const std::string description(){    //returns the description of the portal
        return "NODESCRIPTION";
    }

private:
    std::string _name ;
};

#endif