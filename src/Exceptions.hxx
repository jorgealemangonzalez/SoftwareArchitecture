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
class InexistentMaster : public std::exception{
	public:
		const char * what() const throw(){ //exception if master file desn't exist
			return "The master file does not exist";
		}	
};
