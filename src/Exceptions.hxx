class EmptyCatalogException : public std::exception{
	public:
		const char * what() const throw(){//Exception of empty catalog
			return "";
		}
};