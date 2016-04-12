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
		const char * what() const throw(){
			return "The artist does not exist";
		}
};
