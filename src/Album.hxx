#include<vector>
#include "Track.hxx"
#include "Exceptions.hxx"

typedef std::vector<Track*> Tracks;

class Album{    
public:
    Album (){
        _listed = false;
        _title = "-- Untitled --";
    }
    std::string title(const std::string &setTitle = "-- Untitled --"){//Get the title of the album
        if(setTitle != "-- Untitled --")//If the title is not set we set it to the value of the parameter
       	{
       		_title = setTitle;
       	}
       	return _title;
    }
    void list(){ // changes the status of the album to "Listed"
   		_listed = true;
    }
    void unlist(){// changes the status of the album to "unListed"
    	_listed = false;
    }
    bool isListed(){//Return if the album is listed
    	return _listed;
    }
    void addTrack(Track* newTrack)
    {
      try{
        Tracks::iterator it;
        for(it = _albumTracks.begin() ; it != _albumTracks.end(); ++it)
        {
          if( (*it)->title() == newTrack->title()) throw trackExistInThisAlbum();
        }
        _albumTracks.push_back(newTrack);
      }
      catch(trackExistInThisAlbum &e)
      {
        throw e;
      }

    }
    std::string trackList(){
      std::string result = "";
      int cont =1;
      for(Tracks::iterator it = _albumTracks.begin() ; it != _albumTracks.end() ; it++){
        std::stringstream sDur,sCont;
        sDur << (*it)->duration();
        sCont << cont ;
        result += sCont.str() +" - " + (*it)->title() + " [" + sDur.str() + "s" + "]\n"; 
        cont++;
      }
      return result;
    }
private:
	std::string _title;//Title of the album
	bool _listed;//Album is listed : true , or not : false
  Tracks _albumTracks;
};
