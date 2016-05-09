#ifndef Exception_hxx
#define Exception_hxx 

class EmptyCatalogException : public std::exception{
	public:
		const char * what() const throw(){//Exception of empty catalog
			return "";
		}
};
class NoTrackInCatalogException : public std::exception{
	public:
		const char * what() const throw(){//Exception of empty catalog, no tracks
			return "The track does not exist";
		}
};

class NoAlbumInCatalogException : public std::exception{
	public:
		const char * what() const throw(){ //Exception of empty catalog, no album 
			return "The album does not exist";
		}
};

class trackExistInThisAlbum : public std::exception{
	public:
		const char * what() const throw(){//Exception of existing track in album
			return "The track already exist";
		}
};

class artistNotFoundInCatalogException : public std::exception{
	public:
		const char * what() const throw(){	//Exception of error finding artist on the catalog of SingAlong
			return "The artist does not exist";
		}
};

class masterDoesNotExist : public std::exception{
	public:
		const char * what() const throw(){ //exception if we can't open a master file
			return "The master file does not exist";
		}
};

class trackHasNoLenght : public std::exception{
	public:
		const char * what() const throw(){ //exception if we can't open a master file
			return "The track has no lenght";
		}
};
class UnsupportedFormat : public std::exception{
	public:
		const char * what() const throw(){ //exception if the bps is not a valid format
			return "Not valid format";
		}	
};

class NoConverterAdded : public std::exception{ //exception if no converter been found 
	public:
		const char * what() const throw(){
			return "No converted added";
		}
};

class NotypeConverterSupported : public std::exception{  //exceotion if the format of the converter its no supported
	public:
		const char * what() const throw(){
			return "No converter type accepted";
		}
};
class UnsupportedFormatConversion : public std::exception{  //exception if the format of the converter is not supported
	public:
		const char * what() const throw(){
			return "Unsupported format";
		}
};
class StyleDoesntExists : public std::exception{  //exception if the style doesn't exists in the system
	public:
		const char * what() const throw(){
			return "The style does not exist";
		}
};
class StyleAlreadyExist : public std::exception{  //exception if the style exists in the system
	public:
		const char * what() const throw(){
			return "The style already exist";
		}
};
class UserAlreadyExists : public std::exception{  //exception if the user exist in the system
	public:
		const char * what() const throw(){
			return "The user already exists";
		}
};
class EmailAlreadyExists : public std::exception{  //exception if the email exist in the system
	public:
		const char * what() const throw(){
			return "The style already exist";
		}
};
#endif
