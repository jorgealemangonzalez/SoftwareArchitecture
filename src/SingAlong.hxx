#include "Artist.hxx"
#include <vector>
#include <fstream>
#include <iostream>
#include <string>

typedef std::vector<Artist*> Artists ;

class SingAlong{
public:
    SingAlong(){
        //const char * fakeCompressions[] = {
        std::vector< std::string > fakeCompressions;
        std::string common = "compressed/An artist - A track ";
        fakeCompressions.push_back(common + "[128].mp3");
        fakeCompressions.push_back(common + "[128].ogg");
        fakeCompressions.push_back(common + "[192].mp3");
        fakeCompressions.push_back(common + "[192].ogg");
        fakeCompressions.push_back(common + "[96].mp3");
        fakeCompressions.push_back(common + "[96].ogg");

        for(unsigned int i = 0 ; i < fakeCompressions.size() ; ++i){
            std::ofstream newfile( fakeCompressions[i].c_str() );
        }
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
        a.newTrack(nameTrack ,readDuration("masters/",nameFile) , "masters/"+nameFile);
        
    }
    void createNewAlbum(const std::string &nameArtist, const std::string &nameAlbum){ //Creat an album and add to his artist
        Artist & a = this->findArtist(nameArtist);   //find the artist
        a.newAlbum(nameAlbum);  //create the new album
    }
    void listAlbum( const std::string &nameArtist, const std::string &nameAlbum){//We list a given album from an artist
        Artist & artist = this->findArtist(nameArtist); //first we find the artist 
        Album & album = artist.findAlbum(nameAlbum);    //when we have the artist, we find if he has an album with that name
        album.list();   //when we have the album, we put it as listed
    }

    void unlistAlbum( const std::string &nameArtist, const std::string &nameAlbum){//We unlist a given album from an artist
        Artist & artist = this->findArtist(nameArtist); //first we find the artist 
        Album & album = artist.findAlbum(nameAlbum);    //when we have the artist, we find if he has an album with that name
        album.unlist();   //when we have the album, we put it as unlisted
    }
    void includeTrackOnAlbum( const std::string &nameArtist, const std::string &nameTrack , const std::string &nameAlbum ){ //include a track to a specific album from an artist
        Artist & artist = this->findArtist(nameArtist); //finde the artist 
        artist.assignTrackToAlbum(nameTrack,nameAlbum);     //assign a track to an album, specification in Artist class
    }
    Artist& findArtist(const std::string &name ){		//Search for an artist inside the catalog	
		for(Artists::iterator it = _catalog.begin() ; it != _catalog.end() ; ++it){
			if(name == (*it)->name())return (**it);		//If the name is the same we found the artist
		}
		throw artistNotFoundInCatalogException(); 
    }
    unsigned int readDuration(const std::string &nameDirectory, const std::string &nameFile){
        unsigned int duration;
        std::ifstream infile;
        std::string name = nameDirectory + nameFile;
        infile.open(name.c_str());
        if(!infile.is_open()){
            throw masterDoesNotExist();
        }
        infile >> duration;
        if(duration == 0){
            throw trackHasNoLenght();
        }
        infile.close();
        return duration;
    }
private:
    Artists _catalog;		//List of different artists of the web page

};
