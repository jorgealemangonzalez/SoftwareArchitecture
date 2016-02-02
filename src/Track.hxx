class Track
{
public:     
    std::string title(const std::string& _title="-- Untitled --"){ //return untitle title
        Title=_title;
        return Title;
    }
private:
	std::string Title;
};