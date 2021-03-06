#include <sstream>
#include <vector>
//#include "Track.hxx"
#include "Album.hxx"
#include "Style.hxx"
//#include "Exceptions.hxx"
#include "Subject.hxx"
#include "Observer.hxx"
typedef std::vector<Track*> Tracks;
typedef std::vector<Album*> Albums;

class Artist: public Subject{
public:
	Artist(){
		_name = "-- No name --";//Set the default name 
		_grouped = false;//Set the default kind of account
	}
	~Artist(){//Destructor
		for(Tracks::iterator it=_catalog.begin(); it != _catalog.end() ; it++){//Iterate the catalog vector and free the memory
			delete (*it);
		}
        for(Albums::iterator it=_albumCatalog.begin() ; it != _albumCatalog.end() ; it++){
            delete (*it); //free all the vector of albums
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
    			throw EmptyCatalogException();	//throw exception if the catalog is empty
    			
    		std::string result = "";
    		for(Tracks::iterator it=_catalog.begin(); it != _catalog.end() ; it++){ //Iterate through catalog and concatenate the info of different tracks
    			std::stringstream sDur;
    			sDur << (*it)->duration();
    			result += "\t"+(*it)->title()+" ["+sDur.str()+"s]\n\t\t"+(*it)->master() + (*it)->styles()+ "\n" ;
    		}
    		
    		return result;
    		
    	}
    	catch(EmptyCatalogException &e){
    		return e.what();
    	}
    	
    }
    std::string catalogAlbum(){//Returns the diferent albums of the catalogAlbums
        try{
            if(_albumCatalog.size() == 0 )
                throw EmptyCatalogException();  //throw exception if the catalog is empty
                
            std::string result = "";
            for(Albums::iterator it=_albumCatalog.begin(); it != _albumCatalog.end() ; it++){ //Iterate through catalog and concatenate the info of different albums
                result += "Album: " + (*it)->title() + ((*it)->isListed() ? "":" [unlisted]") + "\n";   //unlisted will be a variable, not now
                result += (*it)->trackList(); //add the list of tracks in an album
            }
            
            return result;
            
        }
        catch(EmptyCatalogException &e){
            return e.what();
        }
        
    }
    void newTrack(const std::string &trackName ,const unsigned int &duration,const std::string &fileName){//Add new track to the catalog of the artist
    	Track *t = new Track();
    	t->title(trackName);
    	t->duration(duration);
    	t->master(fileName);
    	_catalog.push_back(t);
    	_lastTrack = t;                     //set the last track
    	Subject::notify();                  //notify the subscriptors
    }
    void newAlbum(const std::string &albumName){
        Album *a = new Album();
        a->title(albumName);
        _albumCatalog.push_back(a);
    }
    Track & findTrack(const std::string &nameTrack){  //Search a track by title , it returns a reference to this track
    	try{
	    	Tracks::iterator it;
	    	for(it =_catalog.begin(); it != _catalog.end() ; it++){ //iterate through the catalog and compare the title
	    		if((*it)->title() == nameTrack)break;
	    	}
	    	if(it == _catalog.end())throw NoTrackInCatalogException(); //If the track wasn't in the catalog we throw an exception
	    	return **it;
    	}
    	catch(NoTrackInCatalogException &e)
    	{
    		throw e;
    	}
    }
    void assignStyleToTrack(const std::string &nameTrack, Style &nameSytyle){ //assign a style to a track
        findTrack(nameTrack).addStyle(nameSytyle);

    }

    const std::string descriptionCatalog(){ //if a catalog it's empty it throws the error correct
    	return description()+ catalogTracks() + catalogAlbum(); // The description of the catalog is the result of the convination of the artist description and catalogTracks
    }
    Album & findAlbum(const std::string &nameAlbum){ //always return the reference to an Object with tipe "Album"
        try{
            Albums::iterator it;
            for(it = _albumCatalog.begin(); it != _albumCatalog.end() ; ++it) //we iterate all the vector in search of an album
            {
                if((*it)->title() == nameAlbum)break;       //if the album exist, we breack the search and we return the reference to an Album
            }
            if(it == _albumCatalog.end())throw NoAlbumInCatalogException(); //if at the end of the iterator it's at the end of the array,  
            return **it;                                                    //we throw an error.
        }
        catch(NoAlbumInCatalogException &e)
        {
            throw e;
        }
    }
    void assignTrackToAlbum(const std::string &nameTrack, const std::string &nameAlbum) //puts a track into an album
    {
        try{
           Albums::iterator it;
           for(it = _albumCatalog.begin() ; it != _albumCatalog.end() ; ++it){
                if( (*it)->title() == nameAlbum ) break;
           }
           if( it == _albumCatalog.end() ) throw NoAlbumInCatalogException();
           Tracks::iterator it2;
           for(it2 = _catalog.begin() ; it2 != _catalog.end() ; ++it2)
           {
            if( (*it2)->title() == nameTrack) break;
           }
           (*it)->addTrack(*it2);
        }
        catch(NoAlbumInCatalogException &e)
        {
            throw e;
        }

    }
    
    std::pair<std::string,std::string> getState(){                      //returns the name of the artist and the name of the track to the observer
        return make_pair(this->_name , this->_lastTrack->title());     //artist name , name of last track
    }
    
private:
	std::string _name;// The name of the artist
	bool _grouped;// If the account is of an artist or of a group
	Tracks _catalog;//Catalog of all the tracks of the artist
    Albums _albumCatalog; //Catalog of all the albums of the artist
    Track *_lastTrack;      //last track added
};  
