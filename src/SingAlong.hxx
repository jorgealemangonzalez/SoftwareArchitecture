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
    std::string catalog(){          //Returns a list of artist with their description
        Artists::iterator it;
        std::string result("");
        for(it = _catalog.begin();it != _catalog.end() ; ++it){
            //result += (*it)->description();
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
    void createNewTrack(const std::string &nameArtist, const std::string &nameTrack, const std::string &nameFile){
        //Artist a = this->findArtist(nameArtist);
        Artist *a = new Artist();
        for(Artists::iterator it = _catalog.begin() ; it != _catalog.end() ; ++it){
            if(nameArtist == (*it)->name()){
                a = *it;
            }      
        }
        unsigned int duration;
        std::ifstream infile;
        std::string _nameFile = "masters/ " + nameFile;    
        infile.open("masters/aMasterFile.wav"); //pasar la variable para abrir el fichero
        infile >> duration;
        infile.close();
        a->newTrack(nameTrack ,duration ,_nameFile);
        
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
