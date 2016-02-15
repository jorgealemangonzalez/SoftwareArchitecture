class Exception : public std::exception{
	public:
		const char * emptyCatalog() const throw(){
			return "The catalog is empty";
		}
};
