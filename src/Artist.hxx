#include<sstream>
#include<vector>
#include "Track.hxx"
#include "Exceptions.hxx"

typedef std::vector<Track*> Tracks;

class Artist{
public:
	Artist(){
		_name = "-- No name --";//Set the default name 
		_grouped = false;//Set the default kind of account
	}
	~Artist(){//Destructor
		for(Tracks::iterator it=_catalog.begin(); it != _catalog.end() ; it++){//Iterate the catalog vector and free the memory
			delete (*it);
		}
	}
	std::string name(const std::string &setName = "-- No name --"){//returns the name of the artist
		if(setName != "-- No name --"){				   //Compare if the name is set
			_name = setName;
		}
		return _name;
	}
	std::string description(){//A description fomed by the name and the type of account (solo or group)
		return _name+" "+(_grouped ? "[group]":"[solo]") + "\n"; //Form the description wile returning
	}
	void createGroup(){//Transform the artist account into a group account
		_grouped = true;
	}
	void disolveGroup(){//Transform the group account into an artist account
		_grouped = false;
	}
	bool isGroup(){//retuns if the entity is an artist or a group
		return _grouped;
	}
    std::string catalogTracks(){//Returns the diferent tracks of the catalog
    	try{
    		if(_catalog.size() == 0)
    			throw Exception();	//throw exception if the catalog is empty
    			
    		std::string result = "";
    		for(Tracks::iterator it=_catalog.begin(); it != _catalog.end() ; it++){ //Iterate through catalog and concatenate the info of different tracks
    			std::stringstream sDur;
    			sDur << (*it)->duration();
    			result += "\t"+(*it)->title()+" ["+sDur.str()+"s]\n\t\t"+(*it)->master()+"\n";
    		}
    		
    		return result;
    		
    	}
    	catch(Exception &e){
    		return e.emptyCatalog();
    	}
    	
    }
    void newTrack(const std::string &trackName ,const unsigned int &duration,const std::string &fileName){//Add new track to the catalog of the artist
    	Track *t = new Track();
    	t->title(trackName);
    	t->duration(duration);
    	t->master(fileName);
    	_catalog.push_back(t);
    }
    
private:
	std::string _name;// The name of the artist
	bool _grouped;// If the account is of an artist or of a group
	Tracks _catalog;//Catalog of all the tracks of the artist
};
