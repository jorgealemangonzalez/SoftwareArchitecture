#ifndef ConverterGroup_hxx
#define ConverterGroup_hxx
#include <vector>
#include "Converter.hxx"
#include "Mp3Converter.hxx"
#include "OggConverter.hxx"
#include "Exceptions.hxx"

typedef std::vector<Converter*> v;

class ConverterGroup{           
	public:
	    ConverterGroup(){}
	    ~ConverterGroup(){ //we delete all the positions of the vector for memory leaks
	    	for(v::iterator it=converters.begin() ; it != converters.end() ; ++it ){
	    		delete(*it);
	    	}
	    }
	    void addConverter(const std::string &format ,int bitRate){	//we look which converter we want, and added to out list of converters
	    	if(format == "mp3"){ 							//we have to do downcast and upcast
	    		Converter* c = new Mp3Converter();
	    		c->bitRate(bitRate);
	    		converters.push_back(c);
	    	}else if(format == "ogg"){
	    		Converter* c = new OggConverter();
	    		c->bitRate(bitRate);
	    		converters.push_back(c);
	    	}else{	//throw an error if the converter format it's no supported
	    		throw NotypeConverterSupported();
	    	}	    	
	    } 
	    void convert(const std::string &file, const std::string &compressedFile , const std::string &format , int bitRate){ //we convert the specific file
	    	v::iterator it;	
	    	for(it = converters.begin() ; it != converters.end() ; ++it){		//we search in our list if we have added the specific converter 
	    		if(  ( (*it)->typeConverter() == format && (*it)->bpsInfo() == bitRate ) || ((*it)->typeConverter() == format && (*it)->bpsInfo() == bitRate ) )break;
	    	}
	    	if(it == converters.end() )throw NoConverterAdded(); //error if we don't have the converter in our list
	    	(*it)->convert(file,compressedFile);	//if we have the converter, we convert the file with his proper converter
	    }
	
	private:
		v converters;

	   	    
};

#endif