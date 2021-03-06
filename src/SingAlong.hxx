#include "Artist.hxx"
#include "User.hxx"
#include "ConverterGroup.hxx"
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include "Style.hxx"
#include "Portal.hxx"
#include <QObject>
#include "gui/Model.hxx"

typedef std::vector<Artist*> Artists ;
typedef std::vector<Style*> Styles;
typedef std::vector<User*> Users;
typedef std::vector<Portal*> Portals;

class SingAlong : public Model{

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
        
        Portals::iterator it4;
        for(it4 = _portals.begin() ; it4 != _portals.end() ; it4++){
            delete(*it4);
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
    std::string catalog() const {          //Returns a list of artist with their description and the description of their tracks and albums
        std::string result = ("");
        for( Artists::const_iterator it = _catalog.begin() ; it != _catalog.end() ; ++it){ 
            result += (*it)->descriptionCatalog();
        }
        return result;
        //return "aaa";
    }

    void createNewUser(const std::string &nameUser, const std::string &email){ //we create a new user to the system
        for(Users::iterator it = _users.begin() ; it != _users.end() ; ++it){
            if((*it)->getName() == nameUser)throw UserAlreadyExists(); //extra exception in our system
            if((*it)->getEmail() == email)throw EmailAlreadyExists();
        }
        _users.push_back(new User(nameUser,email)); //we push the user in the vector
    }

    void createArtist(const std::string & name , bool group){	//Create an artis and changes is status to grouped ( if isGroup is true ) and save it into the catalog
        Artist *a = new Artist();		
        a->name(name);
        if(group){			
        	a->createGroup();
        }
        for(Artists::iterator it = _catalog.begin() ; it != _catalog.end() ; ++it){
            if(name == (*it)->name())return;     //If the name is the same we found the artist
        }
    	_catalog.push_back(a);			//Put the artist in the catalog
    }
    void createNewTrack(const std::string & artistName, const std::string & title, const std::string & master){
         Artist & a = findArtist(artistName); //find the artist in the catalog with this name, if the artist doesn't exist, throws an error of the function "findArtist"
        std::string newNameTrack = "masters/"+master; 
        std::string compressed = "compressed/"+ a.name() + " - " +title; 
        a.newTrack(title ,readDuration("masters/",master) , "masters/"+master);
        for(unsigned int i = 0 ; i < _converters.converters.size() ; ++i){
            _converters.convert(newNameTrack,compressed,_converters.converters[i]->typeConverter(),_converters.converters[i]->bpsInfo());  
        }
    }

    void createNewTrack(const std::string & artistName, const std::string & title, const std::string & master, const std::string &format , int bps){ //Creat a new track and it's added to the catalog of his artist
        Artist & a = findArtist(artistName); //find the artist in the catalog with this name, if the artist doesn't exist, throws an error of the function "findArtist"
        std::string newNameTrack = "masters/"+master; 
        std::string compressed = "compressed/"+ a.name() + " - " +title; 
        a.newTrack(title ,readDuration("masters/",master) , "masters/"+master);
        if(format == "" && bps == -1){  //Creates a file with all formats
            for(unsigned int i = 0 ; i < _converters.converters.size() ; ++i){
             _converters.convert(newNameTrack,compressed,_converters.converters[i]->typeConverter(),_converters.converters[i]->bpsInfo());  
            }
        }else{
            _converters.convert(newNameTrack,compressed,format,bps);  
        }     
    }
    
    void createNewAlbum(const std::string &nameArtist, const std::string &nameAlbum){ //Creat an album and add to his artist
        Artist & a = findArtist(nameArtist);   //find the artist
        a.newAlbum(nameAlbum);  //create the new album
    }
    void listAlbum( const std::string &nameArtist, const std::string &nameAlbum){//We list a given album from an artist
        Artist & artist = findArtist(nameArtist); //first we find the artist 
        Album & album = artist.findAlbum(nameAlbum);    //when we have the artist, we find if he has an album with that name
        album.list();   //when we have the album, we put it as listed
    }

    void unlistAlbum( const std::string &nameArtist, const std::string &nameAlbum){//We unlist a given album from an artist
        Artist & artist = findArtist(nameArtist); //first we find the artist 
        Album & album = artist.findAlbum(nameAlbum);    //when we have the artist, we find if he has an album with that name
        album.unlist();   //when we have the album, we put it as unlisted
    }
    void includeTrackOnAlbum( const std::string &nameArtist, const std::string &nameTrack , const std::string &nameAlbum ){ //include a track to a specific album from an artist
        Artist & artist = findArtist(nameArtist); //finde the artist 
        artist.assignTrackToAlbum(nameTrack,nameAlbum);     //assign a track to an album, specification in Artist class
    }
    Artist& findArtist(const std::string &name ){		//Search for an artist inside the catalog	
		for(Artists::iterator it = _catalog.begin() ; it != _catalog.end() ; ++it){
			if(name == (*it)->name())return (**it);		//If the name is the same we found the artist
		}
		throw artistNotFoundInCatalogException(); 
    }
    User& findUser (const std::string &userName){
        for(Users::iterator it = _users.begin() ; it != _users.end() ; ++it){
            if(userName == (*it)->getName())return(**it);
        }
        throw UserDontExist();
    }
    Style& findStyle(const std::string &nameStyle){ //find if the style exists
        for(Styles::iterator it=_styles.begin() ; it != _styles.end() ; ++it){
            if(nameStyle == (*it)->getName())return(**it);
        }
        throw StyleDoesntExists(); //throw an error if the style does not exists
    }
    Portal& findPortal(const std::string &namePortal){ //find if the portal exists
        for(Portals::iterator it=_portals.begin() ; it != _portals.end() ; ++it){
            if(namePortal == (*it)->name())return(**it);
        }
        throw PortalNotFound(); //Throws exception if the portal hasn't found
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
        std::string ret = "";   //we return a string with all the information of all the users
        for(unsigned int i = 0; i < _users.size() ; ++i){
            ret += _users[i]->getName() + " <"+ _users[i]->getEmail() + ">\n";
        }
        return ret;
    }
    void associateStyleWithTrack(const std::string &style,const std::string &artist,const std::string &track){ //we put an specific style to a track
        findArtist(artist).assignStyleToTrack(track,findStyle(style));    //in every moment, we look if the artist, the track and the style exists 
        std::string subject = "new track " + track + " by " + artist; //the subject of our message that will notify our users
        //findStyle(style).notifyUsers(subject); //in older tests
        findStyle(style).notifyUsers(artist,track);     //notify that a track has style and need to upgrade
    }
    void subscribeUserToStyle(const std::string &nameUser, const std::string &nameStyle ){
        findStyle(nameStyle).subscribeUser(findUser(nameUser)); //subscribe an user to an specific style
    }
    std::string listSubscribedToStyle(const std::string &nameStyle){ //return the string of all users subscribed in this style
        return findStyle(nameStyle).usersSubscribed();
    }
    
    void subscribeUserToArtist(const std::string &user ,const std::string &artist){ //user is subscribed to an artist
        User & u = findUser(user);
        findArtist(artist).attach((Observer*)&u);
    }
    
    void createNewPortal(const std::string &name , const std::string &description){ //create a new portal
        Portal * p = new Portal();
        p->name(name);
        p->description(description);
        _portals.push_back(p);
    }
    const std::string listPortals(){    //returns a beautifull list of all portals
        std::string fullResume = "";
        for(Portals::iterator it = _portals.begin() ; it != _portals.end() ; ++it){
            fullResume += (*it)->resume();
        }
        return fullResume;
    }
    const std::string rssByPortal(const std::string &portal){       //Returns xml page of the portal
        std::string result = "<?xml version='1.0' encoding='ISO-8859-15'?>\n<!DOCTYPE rss PUBLIC '-//Netscape Communications//DTD RSS 0.91//EN'\n'http://my.netscape.com/publish/formats/rss-0.91.dtd'>\n<rss version='0.91'>\n<channel>\n";
        Portal p = findPortal(portal);
        result += "<title>SingAlong: "+portal+"</title>\n";
        result += "<link>http://www.singalong.com/"+ portal+ "</link>\n";
        result += "<description>"+ p.description() +"</description>\n";
        result += p.htmlResum() + "</channel>\n</rss>\n";
        return result ;
    }
    void subscribePortalToArtist(const std::string &portal , const std::string &artist){ //attach an observer of portal type to the observers
        Portal & p = findPortal(portal);
        findArtist(artist).attach((Observer*)&p);
    }
    void subscribePortalToStyle(const std::string &portal, const std::string &style){ //attach an observer of portal  to the observers
        Portal & p = findPortal(portal);
        findStyle(style).attach((Observer*)&p);
    }
    void userPrefersSms(const std::string &username, const std::string &number){ //user wants SMS notifications
        findUser(username).addNumber("SMS",number);
    }
    void userPrefersWhatsapp(const std::string &username, const std::string &number){ //user wants whatsapp notifications
        findUser(username).addNumber("Whatsapp",number);
    }

private:
    Artists _catalog;		//List of different artists of the web page
    Styles _styles;         //List of different styles that could be in the system
    ConverterGroup _converters; //List of different converters
    Users _users;           //List of different users that have our webpage
    Portals _portals;       //List of different portals that were made
};
