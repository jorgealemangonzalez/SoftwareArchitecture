class EmptyCatalogException : public std::exception{
	public:
		const char * what() const throw(){//Exception of empty catalog
			return "";
		}
};
class NoTrackInCatalogException : public std::exception{
	public:
		const char * what() const throw(){//Exception of empty catalog
			return "The track does not exist";
		}
};

class NoAlbumInCatalogException : public std::exception{
	public:
		const char * what() const throw(){//Exception of empty catalog
			return "The album does not exist";
		}
};

class trackExistInThisAlbum : public std::exception{
	public:
		const char * what() const throw(){//Exception of empty catalog
			return "The track already exist";
		}
};