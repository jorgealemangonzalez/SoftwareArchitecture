#ifndef PORTAL_HXX
#define PORTAL_HXX

#include<string>
class Portal{                           //Portal for group of fans
public:
    Portal(){}
    
    const std::string name(){           //returns the name of the portal
        return "NONE";
    }
    
    const std::string description(){    //returns the description of the portal
        return "NODESCRIPTION";
    }
};

#endif