#include "Artist.hxx"
#include "User.hxx"
#include "ConverterGroup.hxx"
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include "Style.hxx"

typedef std::vector<Artist*> Artists ;
typedef std::vector<Style*> Styles;
typedef std::vector<User*> Users;
class SingAlong{
public:
    SingAlong(){
        std::vector< std::pair< std::string, int> > fakeCompressions;
        defaultListOfConverters(&fakeCompressions);
        for(unsigned int i = 0 ; i < fakeCompressions.size() ; ++i){
            _converters.addConverter(fakeCompressions[i].first, fakeCompressions[i].second);    
        }
    }
    SingAlong(const std::string &string){
        
        std::ifstream conf(string.c_str());
        std::string type;
        int bps;
        while(conf>>type>>bps){
            try{
                _converters.addConverter(type,bps);
            }
            catch(std::exception & e){//throws exception if the format is not supported
                throw UnsupportedFormatConversion();
            }
        }
        conf.close();
    }
    ~SingAlong(){
        Artists::iterator it;
        for(it = _catalog.begin();it != _catalog.end() ; ++it){
            delete(*it);
        } 
        Styles::iterator it2;
        for(it2 = _styles.begin();it2 != _styles.end() ; ++it2){
            delete(*it2);
        }
        Users::iterator it3;
        for(it3 = _users.begin() ; it3 != _users.end() ; it3++){
            delete(*it3);
        }
    }
    void defaultListOfConverters(std::vector< std::pair< std::string, int> >  *fakeCompression){
        fakeCompression->push_back(std::make_pair("mp3",128));
        fakeCompression->push_back(std::make_pair("mp3",192));
        fakeCompression->push_back(std::make_pair("mp3",96));
        fakeCompression->push_back(std::make_pair("ogg",128));
        fakeCompression->push_back(std::make_pair("ogg",192));
        fakeCompression->push_back(std::make_pair("ogg",96));
    }
    std::string catalog(){          //Returns a list of artist with their description and the description of their tracks and albums
        Artists::iterator it;
        std::string result("");
        for(it = _catalog.begin();it != _catalog.end() ; ++it){ 
            result+= (*it)->descriptionCatalog();
        }
        return result;
    }
    void createNewUser(const std::string &nameUser, const std::string &email){
        for(Users::iterator it = _users.begin() ; it != _users.end() ; ++it){
            if((*it)->getName() == nameUser)throw UserAlreadyExists();
            if((*it)->getEmail() == email)throw EmailAlreadyExists();
        }
        _users.push_back(new User(nameUser,email));
    }

    void createArtist(const std::string &artist , bool isGroup){	//Create an artis and changes is status to grouped ( if isGroup is true ) and save it into the catalog
        Artist *a = new Artist();		
        a->name(artist);
        if(isGroup){			
        	a->createGroup();
        }
    	_catalog.push_back(a);			//Put the artist in the catalog
    }
    void createNewTrack(const std::string &nameArtist, const std::string &nameTrack, const std::string &nameFile, const std::string &format = "", int bps=-1){ //Creat a new track and it's added to the catalog of his artist
        Artist & a = this->findArtist(nameArtist); //find the artist in the catalog with this name, if the artist doesn't exist, throws an error of the function "findArtist"
        std::string newNameTrack = "masters/"+nameFile; 
        std::string compressed = "compressed/"+ a.name() + " - " +nameTrack; 
        a.newTrack(nameTrack ,readDuration("masters/",nameFile) , "masters/"+nameFile);
        if(format == "" && bps == -1){  //Creates a file with all formats
            for(unsigned int i = 0 ; i < _converters.converters.size() ; ++i){
             _converters.convert(newNameTrack,compressed,_converters.converters[i]->typeConverter(),_converters.converters[i]->bpsInfo());  
            }
        }else{
            _converters.convert(newNameTrack,compressed,format,bps);  
        }     
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
    Style& findStyle(const std::string &nameStyle){ //find if the style exists
        for(Styles::iterator it=_styles.begin() ; it != _styles.end() ; ++it){
            if(nameStyle == (*it)->getName())return(**it);
        }
        throw StyleDoesntExists(); //throw an error if the style does not exists
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
    void createNewStyle(const std::string &styleName){  //Creates a new style in the system
        for(Styles::iterator it= _styles.begin() ; it != _styles.end() ; ++it){ //look if the style already exist
            if( styleName == (*it)->getName() )throw StyleAlreadyExist();
        }
        _styles.push_back(new Style(styleName)); //if we don't have the style, we add it
    }
    std::string styleList(){                      //Returns a list of the different styles in the system
        std::string ret = "";
        for(unsigned int i = 0 ; i < _styles.size() ; ++i){
            ret += _styles[i]->getName() + "\n";
        }
        return ret;
    }
    std::string userList(){
        std::string ret = "";
        for(unsigned int i = 0; i < _users.size() ; ++i){
            ret += _users[i]->getName() + " <"+ _users[i]->getEmail() + ">\n";
        }
        return ret;
    }
    void associateStyleWithTrack(const std::string &style,const std::string &artist,const std::string &track){ //we put an specific style to a track
        this->findArtist(artist).assignStyleToTrack(track,findStyle(style));    //in every moment, we look if the artist, the track and the style exists
    }
private:
    Artists _catalog;		//List of different artists of the web page
    Styles _styles;         //List of different styles that could be in the system
    ConverterGroup _converters; //List of different converters
    Users _users;           //List of different users that have our webpage

};
