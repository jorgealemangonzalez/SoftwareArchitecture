class Exception : public std::exception{
	public:
		const char * emptyCatalog() const throw(){//Exception of empty catalog
			return "";
		}
};
