#include "Artist.hxx"
#include <vector>
#include <fstream>
#include <iostream>
#include <string>

typedef std::vector<Artist*> Artists ;

class SingAlong{
public:
    SingAlong(){
        
    }
    ~SingAlong(){
        Artists::iterator it;
        for(it = _catalog.begin();it != _catalog.end() ; ++it){
            delete(*it);
        } 
    }
    std::string catalog(){          //Returns a list of artist with their description and the description of their tracks and albums
        Artists::iterator it;
        std::string result("");
        for(it = _catalog.begin();it != _catalog.end() ; ++it){ 
            result+= (*it)->descriptionCatalog();
        }
        return result;
    }
    
    void createArtist(const std::string &artist , bool isGroup){	//Create an artis and changes is status to grouped ( if isGroup is true ) and save it into the catalog
        Artist *a = new Artist();		
        a->name(artist);
        if(isGroup){			
        	a->createGroup();
        }
    	_catalog.push_back(a);			//Put the artist in the catalog
    }
    void createNewTrack(const std::string &nameArtist, const std::string &nameTrack, const std::string &nameFile){ //Creat a new track and it's added to the catalog of his artist
        Artist & a = this->findArtist(nameArtist); //find the artist in the catalog with this name, if the artist doesn't exist, throws an error of the function "findArtist"
        unsigned int duration;
        std::ifstream infile;
        std::string _nameFile = "masters/" + nameFile;    
        infile.open(_nameFile.c_str());     //open the file and read the track duration
        if(!infile.is_open()){
            throw masterDoesNotExist();
            return;
        }
        infile >> duration; //use >> for read the data of the file and store it to "duration"
        infile.close(); //close the opened file
        a.newTrack(nameTrack ,duration ,_nameFile);
        
    }
    Artist& findArtist(const std::string &name ){		//Search for an artist inside the catalog	
		for(Artists::iterator it = _catalog.begin() ; it != _catalog.end() ; ++it){
			if(name == (*it)->name())return (**it);		//If the name is the same we found the artist
		}
		throw artistNotFoundInCatalogException(); 
    }
private:
    Artists _catalog;		//List of different artists of the web page

};
