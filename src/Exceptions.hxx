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