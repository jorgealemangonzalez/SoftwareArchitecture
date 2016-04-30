#ifndef ConverterGroup_hxx
#define ConverterGroup_hxx
#include <vector>
#include "Converter.hxx"
#include "Mp3Converter.hxx"
#include "OggConverter.hxx"

typedef std::vector<Converter*> v;

class ConverterGroup{           
	public:
	    ConverterGroup(){}
	    ~ConverterGroup(){
	    	for(v::iterator it=converters.begin() ; it != converters.end() ; ++it ){
	    		delete(*it);
	    	}
	    }
	    void addConverter(const std::string &format ,int bitRate){
	    	if(format == "mp3"){
	    		Converter* c = new Mp3Converter();
	    		c->bitRate(bitRate);
	    		converters.push_back(c);
	    	}else{
	    		Converter* c = new OggConverter();
	    		c->bitRate(bitRate);
	    		converters.push_back(c);
	    	}	    	
	    } 
	    void convert(const std::string &file, const std::string &compressedFile , const std::string &format , int bitRate){
	    	v::iterator it;
	    	for(it = converters.begin() ; it != converters.end() ; ++it){
	    		if(  ( (*it)->typeConverter() == 1 && (*it)->bpsInfo() == bitRate ) || ((*it)->typeConverter() == 0 && (*it)->bpsInfo() == bitRate ) )break;
	    	}
	    	if(it == converters.end() )return; //temporal
	    	(*it)->convert(file,compressedFile);
	    }
	
	private:
		v converters;

	   	    
};

#endif