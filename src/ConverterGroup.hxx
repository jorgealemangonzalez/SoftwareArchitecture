#ifndef ConverterGroup.hxx
#define ConverterGroup.hxx
#include <vector>
#include "Converter.hxx"
#include "Mp3Converter.hxx"
#include "OggConverter.hxx"

typedef std::vector<Converter *> v;

class ConverterGroup.hxx{           
	public:
	    ConverterGroup(){}
	    ~ConverterGroup(){
	    	for(v::iterator it=converters.beguin() ; it != converters.end() ; ++it ){
	    		delete(*it);
	    	}
	    }
	    //virtual void convert(const std::string &file, const std::string &compressedFile) = 0;    
	    void addConverter(const std::string &format , int &bitRate){
	    	if(format == "mp3"){
	    		Converter *c = new Mp3Converter();
	    		c->bitRate(bitRate);
	    	}else{
	    		Converter *c = new OggConverter();
	    		c->bitRate(bitRate) ;
	    	}
	    	converters.push_back(c);
	    } 
	 
	private:
		v converters;

	   	    
};

#endif